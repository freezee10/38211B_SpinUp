#include "main.h"
#include "pros/misc.h"


/////////////////////////////////
//DRIVER CONTROL
/////////////////////////////////


void setDrive(int left, int right)
{
    leftFront.move(left);
    leftBack.move(left);
    rightFront.move(right);
    rightBack.move(right);
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




///////////////////////////
//PID
///////////////////////////


float kP = 1;
//float kI = 0.0;
float kD = 0.0;
float turnkP = 0.0;
//float turnkI = 0.0;
float turnkD = 0.0;

int desiredValue = 20;
int desiredTurnValue = 0;

int error; //Sensor Value - Desired Value || Positional Value
int prevError; //Pos 10ms ago
int derivative; //error - prevError || Speed
int totalError; //totalError + error

int turnError; //Sensor Value - Desired Value || Positional Value
int turnPrevError; //Pos 10ms ago
int turnDerivative; //turnError - turnPrevError || Speed
int turnTotalError; //turnTotalError + turnError


void drivePID()
{
    enablePID = true;
    resetMotors = true;

    while(enablePID)
    {

        while(resetMotors)
        {
            leftFront.set_zero_position(0);
            leftBack.set_zero_position(0);
            rightFront.set_zero_position(0);
            rightBack.set_zero_position(0);

            leftFront.tare_position();
            leftBack.tare_position();
            rightFront.tare_position();
            rightBack.tare_position();

            resetMotors = false;
        }

        float leftMotorPosition = leftBack.get_position();
        float rightMotorPosition = rightBack.get_position();

        float averagePosition = (leftMotorPosition + rightMotorPosition)/2;
        
        //Potential
        error = averagePosition - desiredValue;
        //Derivative
        derivative = error - prevError;
        //Integral
        //totalError += error;

        int lateralMotorPower =  error * kP + derivative * kD;




        float turnDiff = (leftMotorPosition - rightMotorPosition);

        //Potential
        turnError = turnDiff - desiredTurnValue;
        //Derivative
        turnDerivative = turnError - turnPrevError;
        //Integral
        //turnTotalError += turnError;

        int turnMotorPower =  turnError * turnkP + turnDerivative * turnkD;



        setDrive(lateralMotorPower + turnMotorPower, lateralMotorPower - turnMotorPower);



        prevError = error;
        turnPrevError = turnError;
        pros::delay(10);

    }
}




/////////////////////////////////
//INITIALIZE
/////////////////////////////////


void driveInit()
{
    leftFront.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    leftBack.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    rightFront.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    rightBack.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
}