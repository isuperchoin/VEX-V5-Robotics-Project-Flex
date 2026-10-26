#include "lift.hpp"

pros::MotorGroup arm({8,-20});

const double LIFT_GEAR_RATIO = 16.0;

void lift_init() {
    arm.set_brake_mode(pros::E_MOTOR_BRAKE_COAST); //Back to HOLD after solving lift problem
    arm.set_encoder_units(pros::E_MOTOR_ENCODER_DEGREES);
    arm.tare_position();
}

void lift_opcontrol() {
    if (master.get_digital(DIGITAL_L1)) {  //Restirct angle range
        arm.move_velocity(127);
    } else if (master.get_digital(DIGITAL_L2)) {
        arm.move_velocity(-127);
    } else {
        arm.move_velocity(0);
    }
}

double lift_angle() {
    return arm.get_position() / LIFT_GEAR_RATIO;
}