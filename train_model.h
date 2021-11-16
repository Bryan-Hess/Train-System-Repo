#ifndef Train_Model_H
#define Train_Model_H
#include <iostream>
#include <vector>

/* Class Train is the main class of the module
   and contains all needed functions for the
   Train module */
class Train_Model{
  private:

    //ID of train and next station
    double ID;
    std::string nextStation;

    //speed variables
    double actualSpeed;
    double suggestedSpeed;
    double acceleration;
    double power;

    //passenger variable
    int numPassengers;	//number of passengers

    //metrics of the train
    double mass; //in Kg
    double modelMass = 4000;
    double width,length,height;
    int carCount;
    int crewCount;

    //boolean operation values
    bool brakes,eBrakes;
    bool brakeFail,engineFail,signalFail;
    bool interiorLights,exteriorLights;
    bool leftDoor,rightDoor;

    //authority
    int authority;

    //temperature
    double temperature;

  public:
    Train_Model();
    Train_Model(double sS,int t,int a);
    ~Train_Model();

    //IDs
    void setID(int id);
    std::string getNextStation();

    //speed functions
    void setSpeed(double power);
    double getSpeed();
    double getAcceleration();
    double getPower();

    //passenger functions
    void setPassengers(int num);
    int getPassengers();
    void updatePassengers();

    //constant values
    void setCrew(int size);
    void setCars(int num);
    int getCrew();
    int getCars();

    //brakes
    void setBrakes(bool b);
    bool getBrakes();
    void setEbrakes(bool Eb);
    bool getEbrakes();

    //failures
    void setFailures(bool eF,bool sF, bool bF);
    bool getEngineFail();
    bool getSignalFail();
    bool getBrakeFail();

    //authority
    void setAuthority(int mba);
    int getAuthority();

    //lights
    void setLights(bool interiorLights,bool exteriorLights);
    bool getInteriorLights();
    bool getExteriorLights();

    //doors
    void setDoors(bool leftdoor,bool rightdoor);
    bool getLeftDoor();
    bool getRightDoor();

    //gps
    double getGPS();

    //temp
    void setTemperature(double temperature);
    double getTemperature();
};

#endif
