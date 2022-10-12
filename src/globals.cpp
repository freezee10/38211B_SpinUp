#include "main.h"
#include "pros/motors.h"


/////////////////////////////////
//DEVICES
/////////////////////////////////

//controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);

//drivetrain motors
pros::Motor leftFront(1, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_DEGREES); //1
pros::Motor leftBack(2, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_DEGREES); //2
pros::Motor rightFront(3, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES); //3
pros::Motor rightBack(4, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES); //4

//flywheel motors
//pros::Motor flywheelMotor1(11, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES); //5
//pros::Motor flywheelMotor2(12, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_DEGREES); //6

//indexer motor
//pros::Motor indexer(13, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES); //7

pros::ADIEncoder leftEncoder(1, 2, false); //:A+B 
pros::ADIEncoder rightEncoder(3, 4, true); //:C+D 
pros::ADIEncoder backEncoder(5, 6, false);  //:E+F 

pros::Imu inertial (8);