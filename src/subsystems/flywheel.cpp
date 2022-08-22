#include "main.h"

pros::Motor Flywheel1(11, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_ROTATIONS);
pros::Motor Flywheel2(12, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_ROTATIONS);


void flywheel()
{
    while(true)
    {
    Flywheel1.move(127);
    Flywheel2.move(127);

    pros::delay(10);
    }
}