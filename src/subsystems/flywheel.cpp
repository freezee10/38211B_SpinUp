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

void indexerOn()
{   
    while(true)
    {
        if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_A))
        {
            indexer.move_voltage(60);
            pros::delay(2000);
            indexer.brake();
        }
    pros::delay(10);
    }
}