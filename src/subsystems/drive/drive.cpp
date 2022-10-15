#include "main.h"

/////////////////////////////////
//DRIVER CONTROL
/////////////////////////////////


void setDrive(int left, int right)
{
    leftChassis.move(left);
    rightChassis.move(right);
}

void drive()
{
    while (true)
    {

    //TANK DRIVE CODE
    /*
    int leftJoystick = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int rightJoystick = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
    if (abs(leftJoystick) < 10)
    {
        leftJoystick = 0;
    }
    if (abs(rightJoystick) < 10)
    {
        rightJoystick = 0;
    }
    setDrive(leftJoystick, rightJoystick);
    */

    int power = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int turn = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
        //hi ---- hello :O
    int left = power + turn;
    int right = power - turn;

    //BREAK FUNCTION
    /*
    while(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2) == 1)
    {   
        leftFront.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
        leftBack.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
        rightFront.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
        rightBack.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);

        leftFront.brake();
        leftBack.brake();
        rightFront.brake();
        rightBack.brake();
    }
    */

    setDrive(left, right);

    pros::delay(10);

    }
}


/////////////////////////////////
//INITIALIZE
/////////////////////////////////


void driveInit()
{

    leftEncoder.reset();
    rightEncoder.reset();
    inertial.tare();
    leftFront.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    leftBack.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    rightFront.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    rightBack.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    //indexer.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
   

}