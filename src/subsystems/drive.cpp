#include "main.h"
#include "pros/misc.h"
#include <string>


bool enablePID;
bool resetMotors;

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




///////////////////////////
//PID
///////////////////////////


double kP = 0.0; //0.285
double kI = 0.0; //0.0
double kD = 0.0; //0.0
double turnkP = 0.4; //0.7
double turnkI = 0.0; //0.0001
double turnkD = 0.0; //0.07

double revolutions(double numOfRev) //makes 360deg of rotation = 1 revolution
{
    double answer = numOfRev * 360;

    return answer;
}

double inches(double numOfInches) //converts inches to motor revolutioins
{
    double answer = numOfInches / 8.6393797974; //12.9590696961" is the circumfrence of the 4" omnis
    
    return revolutions(answer);
}



int desiredValue = inches(12);
int desiredTurnValue = 350; //counts | testing 1105 = 90 deg

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

        int leftSidePosition = leftEncoder.get_value();
        int rightSidePosition = rightEncoder.get_value();
        int headingPosition = inertial.get_heading();


        int averagePosition = (leftSidePosition + rightSidePosition)/2;

        //Potential
        error = desiredValue - averagePosition;
        //Integral
        totalError = totalError + error;
        //Derivative
        derivative = error - prevError;
        


        int turnDiff = (leftSidePosition - rightSidePosition);

        //Potential
        turnError = desiredTurnValue - turnDiff; 
        //Integral
        turnTotalError += turnError;
        //Derivative
        turnDerivative = turnError - turnPrevError;



        prevError = error;
        turnPrevError = turnError;

        int lateralMotorPower =  error * kP + totalError * kI + derivative * kD;
        int turnMotorPower =  turnError * turnkP + turnTotalError * turnkI + turnDerivative * turnkD;

        setDrive(lateralMotorPower + turnMotorPower, lateralMotorPower - turnMotorPower);


        std::string str = std::to_string(headingPosition);
        pros::lcd::set_text(0, "headingPos");
        pros::lcd::set_text(1, str);

        std::string str1 = std::to_string(turnError);
        pros::lcd::set_text(2, "error");
        pros::lcd::set_text(3, str1);
        
        std::string str2 = std::to_string(turnTotalError);
        pros::lcd::set_text(4, "turnTotalError");
        pros::lcd::set_text(5, str2);

        std::string str3 = std::to_string(turnMotorPower);
        pros::lcd::set_text(6, "turnMotorPower");
        pros::lcd::set_text(7, str3);

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