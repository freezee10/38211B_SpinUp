#include "main.h"


void flywheel()
{
    while(true)
    {
    flywheelMotor1.move(127);
    flywheelMotor2.move(127);

    pros::delay(10);
    }
}