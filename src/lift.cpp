#include "lift.hpp"

pros::MotorGroup arm({8,-9});

void lift_init() {
    arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    arm.set_encoder_units(pros::E_MOTOR_ENCODER_DEGREES);
    arm.tare_position();
}

void lift_opcontrol() {
    if (master.get_digital(DIGITAL_L1)) {
        arm.move_velocity(100);
    } else if (master.get_digital(DIGITAL_L2)) {
        arm.move_velocity(-100);
    } else {
        arm.move_velocity(0);
    }
}