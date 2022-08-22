#include "pros/motors.hpp"
#include "pros/misc.hpp"

extern pros::Motor leftFront;
extern pros::Motor rightFront;
extern pros::Motor leftBack;
extern pros::Motor rightBack;

extern pros::Controller controller;


/////////////////////////////////
//DRIVER CONTROL FUNCTIONS
/////////////////////////////////
void setDrive(int left, int right);
void driveInit();
void drive();


///////////////////////////
//PID FUNCTIONS
///////////////////////////
void drivePID();
extern bool enablePID;
extern bool resetMotors;

