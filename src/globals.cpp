#include "main.h"


/////////////////////////////////
//DEVICES
/////////////////////////////////

//controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);

//drivetrain motors
pros::Motor leftFront(1, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_ROTATIONS); //1
pros::Motor leftBack(2, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_ROTATIONS); //2
pros::Motor rightFront(3, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_ROTATIONS); //3
pros::Motor rightBack(4, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_ROTATIONS); //4

//flywheel motors
pros::Motor flywheelMotor1(11, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_ROTATIONS); //5
pros::Motor flywheelMotor2(12, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_ROTATIONS); //6