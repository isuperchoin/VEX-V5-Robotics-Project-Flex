#include "claw.hpp"

pros::Motor claw(10);

void claw_init(){
    claw.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    claw.set_encoder_units(pros::E_MOTOR_ENCODER_DEGREES);
    // claw.move_absolute(0, 100);
    claw.tare_position();
}

void claw_opcontrol() {
    if (master.get_digital(DIGITAL_R1)) {
        claw.move_absolute(90, 100);
    } 
    else if (master.get_digital(DIGITAL_R2)) {
        claw.move_absolute(0, 100);
    } 
}

