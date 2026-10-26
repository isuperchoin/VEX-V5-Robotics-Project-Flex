#include "claw.hpp"

pros::Motor claw(10);

short claw_state = 0; // 0 = closed, 1 = open

void claw_init(){
    claw.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD); 
    claw.set_encoder_units(pros::E_MOTOR_ENCODER_DEGREES);
    claw.tare_position();
}

const double CLAW_CLOSED = 30;
const double CLAW_OPEN = -540; 

void claw_opcontrol() {
    if (master.get_digital_new_press(DIGITAL_R1)) {
        if (claw_state == 1) {
            claw.move_absolute(CLAW_CLOSED, 100);
            claw_state = 0;
        } else {
            claw.move_absolute(CLAW_OPEN, 100);
            claw_state = 1;
        }
    }
}

double claw_angle() {
    return claw.get_position();
}