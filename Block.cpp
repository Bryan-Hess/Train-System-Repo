#include "Block.h"

//Init statics
int Block::instanceCounter = 0;
string Block::branchesList = "abcdefghijklmnopqrstuvwxyz";
int Block::branchIndex = 0;

//Constructors:
//Default constructor
Block::Block(){
	id = instanceCounter;
	instanceCounter++;
	line = "green";
	branch = "a";
	type = "rail";
	direction = "north";
	nextBranches = "bc";
	length = 10.0;
	grade = 1.0;
	height = 5.0;
	temperature = 50.0;
	speedLimit = 45.0;
	suggestedSpeed = 45.0;
	railStatus = true;
	circuitStatus = true;
	powerStatus = true;
	heaterStatus = true;
	crossingStatus = false;
	switchStatus = true;
}

//Full input constructor
Block::Block(string lineIN, string branchIN, string typeIN, string directionIN, string nextBranchesIN, double lengthIN, double gradeIN, double heightIN, double temperatureIN,
double speedLimitIN, double suggestedSpeedIN, bool railStatusIN, bool circuitStatusIN, bool powerStatusIN, bool heaterStatusIN, bool crossingStatusIN, bool switchStatusIN){
	id = instanceCounter;
	instanceCounter++;
	line = lineIN;
	branch = branchIN;
	type = typeIN;
	direction = directionIN;
	nextBranches = nextBranchesIN;
	length = lengthIN;
	grade = gradeIN;
	height = heightIN;
	temperature = temperatureIN;
	speedLimit = speedLimitIN;
	suggestedSpeed = suggestedSpeedIN;
	railStatus = railStatusIN;
	circuitStatus = circuitStatusIN;
	powerStatus = powerStatusIN;
	heaterStatus = heaterStatusIN;
	crossingStatus = crossingStatusIN;
	switchStatus = switchStatusIN;
}
//Functional constructor
Block::Block(string lineIN, string typeIN, string directionIN, double lengthIN, double gradeIN, double temperatureIN, double heightIN,
double speedLimitIN, double suggestedSpeedIN){
	id = instanceCounter;
	instanceCounter++;
	line = lineIN;
	branch = branchesList[branchIndex];
	type = typeIN;
	direction = directionIN;
	if(type == "switch"){
		nextBranches = branchesList.substr(branchIndex,2);
		branchIndex++;
	}else{
		nextBranches = "";
	}
	length = lengthIN;
	grade = gradeIN;
	height = heightIN;
	temperature = temperatureIN;
	speedLimit = speedLimitIN;
	suggestedSpeed = suggestedSpeedIN;
	railStatus = true;
	circuitStatus = true;
	powerStatus = true;
	heaterStatus = true;
	crossingStatus = false;
	switchStatus = true;
}

//Attributes:
//id -------------------------------------------------------------------
//Params: None
//Returns: int
//Desc: returns the value of the attribute id as an integer
int Block::getId(){
	return id;
}

//line -----------------------------------------------------------------
//Params: string
//Returns: None
//Desc: sets the value of the attribute line = to inputted string
//Notes: line should be set to "green" or "red" function assumes no user error
void Block::setLine(string lineIN){
	line = lineIN;
}
//Params: None
//Returns: string
//Desc: returns the value of the attribute line as a string
string Block::getLine(){
	return line;
}

//branch ---------------------------------------------------------------
//Params: string
//Returns: None
//Desc: sets the value of the attribute branch = to inputted string
void Block::setBranch(string branchIN){
	branch = branchIN;
}
//Params: None
//Returns: string
//Desc: returns the value of the attribute branch as a string
string Block::getBranch(){
	return branch;
}

//type -----------------------------------------------------------------
//Params: string
//Returns: None
//Desc: sets the value of the attribute type = to inputted string
//Notes: type should be set to "rail", "yard", "station", "switch", or "crossing" function assumes no user error
void Block::setType(string typeIN){
	type = typeIN;
}
//Params: None
//Returns: string 
//Desc: returns the value of the attribute type as a string
string Block::getType(){
	return type;
}

//direction ------------------------------------------------------------
//Params: string
//Returns: None
//Desc: sets the value of the attribute direction = to inputted string
//Notes: direction should be set to "north", "east", "south", or "west" fucntion assumes no user error
void Block::setDirection(string directionIN){
	direction = directionIN;
}
//Params: None
//Returns: string
//Desc: returns the value of the attribute direction as a string
string Block::getDirection(){
	return direction;
}

//nextBranches ---------------------------------------------------------
//Params: string
//Returns: None
//Desc: sets the value of the attribute nextBranches = to inputted string
void Block::setNextBranches(string nextBranchesIN){
	nextBranches = nextBranchesIN;
}
//Params: None
//Returns: string
//Desc: returns the value of the attribute nextBranches as a string
string Block::getNextBranches(){
	return nextBranches;
}

//length ---------------------------------------------------------------
//Params: double
//Returns: None
//Desc: sets the value of the attribute length = to inputted double
void Block::setLength(double lengthIN){
	length = lengthIN;
}
//Params: None
//Returns: double
//Desc: returns the value of the attribute length as a double
double Block::getLength(){
	return length;
}

//grade ----------------------------------------------------------------
//Params: double
//Returns: None
//Desc: sets the value of the attribute grade = to inputted double
void Block::setGrade(double gradeIN){
	grade = gradeIN;
}
//Params: None
//Returns: double
//Desc: returns the value of the attribute grade as a double
double Block::getGrade(){
	return grade;
}

//height ---------------------------------------------------------------
//Params: double
//Returns: None
//Desc: sets the value of the attribute height = to inputted double
void Block::setHeight(double heightIN){
	height = heightIN;
}
//Params: None
//Returns: double
//Desc: returns the value of the attribute height as a double
double Block::getHeight(){
	return height;
}

//temperature ----------------------------------------------------------
//Params: double
//Returns: None
//Desc: sets the value of the attribute temperature = to inputted double
void Block::setTemperature(double temperatureIN){
	temperature = temperatureIN;
}
//Params: None
//Returns: double 
//Desc: returns the value of the attribute temperature as a double
double Block::getTemperature(){
	return temperature;
}

//speedLimit -----------------------------------------------------------
//Params: double
//Returns: None
//Desc: sets the value of the attribute speedLimit = to inputted double
void Block::setSpeedLimit(double speedLimitIN){
	speedLimit = speedLimitIN;
}
//Params: None
//Returns: double 
//Desc: returns the value of the attribute speedLimit as a double
double Block::getSpeedLimit(){
	return speedLimit;
}

//suggestedSpeed -------------------------------------------------------
//Params: double
//Returns: None
//Desc: sets the value of the attribute suggestedSpeed = to inputted double
void Block::setSuggestedSpeed(double suggestedSpeedIN){
	suggestedSpeed = suggestedSpeedIN;
}
//Params: None
//Returns: double
//Desc: returns the value of the attribute suggestedSpeed as a double
double Block::getSuggestedSpeed(){
	return suggestedSpeed;
}

//railStatus -----------------------------------------------------------
//Notes: bool true == no rail failures bool false = rail failure
//Params: bool
//Returns: None
//Desc: sets the value of the attribute railStatus = to inputted bool
void Block::setRailStatus(bool railStatusIN){
	railStatus = railStatusIN;
}
//Params: None
//Returns: bool
//Desc: returns the value of the attribute railStatus as a bool
bool Block::getRailStatus(){
	return railStatus;
}
//Params: None
//Returns: None
//Desc: toggles the bool value of the attribute railStatus 
void Block::toggleRailStatus(){
	railStatus = ~railStatus;
}

//circuitStatus --------------------------------------------------------
//Notes: bool true = no circuit failures bool false = circuit failure
//Params: bool 
//Returns: None
//Desc: sets the value of the attribute circuitStatus = to inputted bool
void Block::setCircuitStatus(bool circuitStatusIN){
	circuitStatus = circuitStatusIN;
}
//Params: None
//Returns: bool
//Desc: returns the value of the attribute circuitStatus as a bool
bool Block::getCircuitStatus(){
	return circuitStatus;
}
//Params: None
//Returns: None
//Desc: toggles the bool value of the attribute circuitStatus
void Block::toggleCircuitStatus(){
	circuitStatus = ~circuitStatus;
}

//powerStatus ----------------------------------------------------------
//Notes: bool true = no power failures bool false = power failure
//Params: bool
//Returns: None
//Desc: sets the value of the attribute powerStatus = to inputted bool
void Block::setPowerStatus(bool powerStatusIN){
	powerStatus = powerStatusIN;
}
//Params: None
//Returns: bool
//Desc: returns the value of the attribute powerStatus as a bool
bool Block::getPowerStatus(){
	return powerStatus;
}
//Params: None
//Returns: None
//Desc: toggles the bool value of the attribute powerStatus
void Block::togglePowerStatus(){
	powerStatus = ~powerStatus;
}

//heaterStatus ---------------------------------------------------------
//Notes: bool true = heater is active bool false = heater is inactive
//Params: bool 
//Returns: None
//Desc: sets the value of the attribute heaterStatus = to inputted bool
void Block::setHeaterStatus(bool heaterStatusIN){
	heaterStatus = heaterStatusIN;
}
//Params: None
//Returns: bool 
//Desc: returns the value of the attribute heaterStatus as a bool
bool Block::getHeaterStatus(){
	return heaterStatus;
}
//Params: None
//Returns: None
//Desc: toggles the bool value of the attribute heaterStatus
void Block::toggleHeaterStatus(){
	heaterStatus = ~heaterStatus;
}

//crossingStatus -------------------------------------------------------
//Notes: bool true = crossing is active bool false = crossing is inactive
//Params: bool
//Returns: None
//Desc: sets the value of the attribute crossingStatus = to inputted bool
void Block::setCrossingStatus(bool crossingStatusIN){
	crossingStatus = crossingStatusIN;
}
//Params: None
//Returns: bool
//Desc: returns the value of the attribute crossingStaus as a bool
bool Block::getCrossingStatus(){
	return crossingStatus;
}
//Params: None
//Returns: None
//Desc: toggles the bool value of the attribute crossingStatus
void Block::toggleCrossingStatus(){
	crossingStatus = ~crossingStatus;
}

//switchStatus ---------------------------------------------------------
//Notes: bool true = crossing is pointed upwards towards nextBranch[0] bool false = crossing is pointed downwards towards nextBranch[1]
//Params: bool
//Returns: None
//Desc: sets the value of the attribute switchStatus = to inputted bool
void Block::setSwitchStatus(bool switchStatusIN){
	switchStatus = switchStatusIN;
}
//Params: None
//Returns: bool
//Desc: returns the value of the attribute switchStatus as a bool
bool Block::getSwitchStatus(){
	return switchStatus;
}
//Params: None
//Returns: None
//Desc: toggles the bool value of the attribute switchStatus
void Block::toggleSwitchStatus(){
	switchStatus = ~switchStatus;
}


