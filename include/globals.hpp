#include "pros/motors.hpp"
#include "pros/misc.hpp"


/////////////////////////////////
//DEVICES
/////////////////////////////////

//controller
extern pros::Controller controller;

//drivetrain motors
extern pros::Motor leftFront; //1 :1
extern pros::Motor rightFront; //2 :2
extern pros::Motor leftBack; //3 :3
extern pros::Motor rightBack; //4 :4

//flywheel motors
extern pros::Motor flywheelMotor1; //5 :11
extern pros::Motor flywheelMotor2; //6 :12


/////////////////////////////////
//GLOBAL VARIABLES
/////////////////////////////////

extern bool enablePID;
extern bool resetMotors;
extern int autoSelected;