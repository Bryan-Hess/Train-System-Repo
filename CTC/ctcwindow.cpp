#include "ctcwindow.h"
#include "./ui_ctcwindow.h"
#include <QFileDialog>
#include "Block.h"
#include <QGraphicsTextItem>
#include <QGraphicsRectItem>
#include "ScheduleManager.h"

CTCWindow::CTCWindow(std::vector<WayStruct>* sw_waystructs, WayStruct* hw_waystruct, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CTCWindow)
    , ctc(sw_waystructs, hw_waystruct)
{
    ui->setupUi(this);
    this->setFixedSize(this->size().width(), this->size().height());

    ctc.update(0);

    //TODO: Add switch list to drop-down here

    //Graphics setup
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    QBrush redBrush(Qt::red);
    QBrush yellowBrush(Qt::yellow);
    QPen blackPen(Qt::black);
    blackPen.setWidth(2);

    testRect = new QGraphicsRectItem*[100];
    for(int i = 0; i < 50; i++){
        if(i % 15 == 0 && i != 0){
            testRect[i] = scene->addRect(-250+10*i, 0, 10, 10, blackPen, yellowBrush);
        }else{
            testRect[i] = scene->addRect(-250+10*i, 0, 10, 10, blackPen, redBrush);
        }
    }
    testRect[50] = scene->addRect(-100, 10, 10, 10, blackPen, redBrush);
    for(int i = 51; i < 100; i++){
        if(i % 15 == 0 && i != 0){
            testRect[i] = scene->addRect(-250+10*(i-51), 20, 10, 10, blackPen, yellowBrush);
        }else{
            testRect[i] = scene->addRect(-250+10*(i-51), 20, 10, 10, blackPen, redBrush);
        }
    }
    testText = scene->addText("This view will display a graphical map of the track.\nEach box represents a track block.\nColors will represent various block states.");
    testText->setPos(-250, -75);
}

CTCWindow::~CTCWindow()
{
    delete ui;
    delete[] testRect;
    delete testText;
}

void CTCWindow::on_button_chooseSchedule_clicked()
{
    QString filepath = QFileDialog::getOpenFileName(this, "Open Schedule File");

    std::string s = "Opening Schedule file " + filepath.toStdString() + "\n";
    for(int i = 0; i < 10; i++){
        //ctc.addSchedule(CTCSchedule(i, i, (double)i));
    }
    s += ctc.displaySchedule();
    ui->textBrowser_schedule->setText(QString::fromStdString(s));
}


void CTCWindow::on_horizontalSlider_mode_sliderMoved(int position)
{
    if(position == 0){
        ctc.setCTCMode(false);
    }else if(position == 1){
        ctc.setCTCMode(true);
    }
}


void CTCWindow::on_lineEdit_selectBlock_returnPressed()
{
    std::string text = ui->lineEdit_selectBlock->text().toStdString();
    int blockId;
    try{
        blockId = std::stoi(text);

        ui->textBrowser_blockPropertiesId->setText(QString::fromStdString(std::to_string(blockId)));

        bool m = ctc.getTrackMaintenence(blockId);
        if(m){
            ui->textBrowser_blockPropertiesMaintenence->setText("Closed");
        }else{
            ui->textBrowser_blockPropertiesMaintenence->setText("Open");
        }

        bool tp = ctc.getBlockHasTrainPresent(blockId);
        if(tp){
            ui->textBrowser_blockPropertiesTrainPresent->setText("Yes");
        }else{
            ui->textBrowser_blockPropertiesTrainPresent->setText("No");
        }

        ui->textBrowser_blockPropertiesThroughput->setText("0");
    }catch(std::exception e){
        ui->textBrowser_blockPropertiesId->setText("");
        ui->textBrowser_blockPropertiesMaintenence->setText("");
        ui->textBrowser_blockPropertiesTrainPresent->setText("");
        ui->textBrowser_blockPropertiesThroughput->setText("");
        return;
    }

}

void CTCWindow::on_pushButton_openCloseForMaintenecnce_clicked()
{
    std::string text = ui->lineEdit_selectBlock->text().toStdString();
    int blockId;
    try{
        blockId = std::stoi(text);
        if(ctc.getTrackMaintenence(blockId)){
            ctc.setTrackMaintenence(blockId, false);
        }else{
            ctc.setTrackMaintenence(blockId, true);
        }

        bool m = ctc.getTrackMaintenence(blockId);
        if(m){
            ui->textBrowser_blockPropertiesMaintenence->setText("Closed");
        }else{
            ui->textBrowser_blockPropertiesMaintenence->setText("Open");
        }
    }catch(std::exception){

    }
}

void CTCWindow::on_pushButton_selectBlockGo_clicked()
{
    on_lineEdit_selectBlock_returnPressed();
}

void CTCWindow::on_pushButton_dispatchTrain_clicked()
{
    int trainNo;
    int destinationBlockId;
    double destinationTime;

    try{
        trainNo = std::stoi(ui->label_manualDispatchtrain->text().toStdString());
        destinationBlockId = std::stoi(ui->label_manualDispatchTo->text().toStdString());
        destinationTime = std::stod(ui->label_manualDispatchToTime->text().toStdString());
    }catch(std::exception){
        return;
    }
    //ctc.dispatchTrain(CTCSchedule(trainNo, destinationBlockId, destinationTime));
}


void CTCWindow::on_comboBox_activated(int index)
{
    int blockId = ui->comboBox->currentData().Int;
    ui->textBrowser_switchId->setText(QString::fromStdString(std::to_string(blockId)));

    char direction = ctc.getBlockDirection(blockId);
    QString directionText;
    if(direction == 'e'){
        directionText = "Normal";
    }else{
        directionText = "Reverse";
    }
    ui->textBrowser_switchDirection->setText(directionText);
}


void CTCWindow::on_pushButton_openCloseSwitch_clicked()
{
    int blockId = ui->comboBox->currentData().Int;
    char direction = ctc.getBlockDirection(blockId);
    if(direction == 'e'){
        ctc.setTrackSwitch(blockId, 'w');
    }else{
        ctc.setTrackSwitch(blockId, 'e');
    }
    on_comboBox_activated(ui->comboBox->currentIndex());
}
