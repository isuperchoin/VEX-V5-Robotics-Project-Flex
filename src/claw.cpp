#include "claw.hpp"

pros::Motor claw(10);

short claw_state = 0; // 0 = closed, 1 = open

void claw_init(){
    claw.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    claw.set_encoder_units(pros::E_MOTOR_ENCODER_DEGREES);
    // claw.move_absolute(0, 100);
    claw.tare_position();
}

void claw_opcontrol() {
    if (master.get_digital(DIGITAL_R1)) {
        if (claw_state == 1) {
            claw.move_absolute(0, 100); // Tune how much I will colse the claw
            claw_state = 0;
        } else if (claw_state == 0) {
            claw.move_absolute(90, 100);
            claw_state = 1;
        }
    }  
}

