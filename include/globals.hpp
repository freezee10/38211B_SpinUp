#include "pros/adi.hpp"
#include "pros/imu.hpp"
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
extern pros::Motor_Group leftChassis;
extern pros::Motor leftBack; //3 :3
extern pros::Motor rightBack; //4 :4
extern pros::Motor_Group rightChassis;

//flywheel motors
//extern pros::Motor flywheelMotor1; //5 :11
//extern pros::Motor flywheelMotor2; //6 :12

//indexer motors
//extern pros::Motor indexer; //7 :13

extern pros::ADIEncoder leftEncoder; //:A+B 
extern pros::ADIEncoder rightEncoder; //:C+D 
extern pros::ADIEncoder backEncoder; //:E+F 

extern pros::Imu inertial; //:5

/////////////////////////////////
//GLOBAL VARIABLES
/////////////////////////////////

extern bool enablePID; //drive.cpp
extern bool resetMotors; //drive.cpp

extern int autoSelected; //gui.cpp