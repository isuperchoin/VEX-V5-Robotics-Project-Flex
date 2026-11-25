#include "control.hpp"

constexpr int DEADZONE = 10;
constexpr int MAX_SPEED = 127;

void opcontrol_turn_and_go() {
    /**
    Mechanism:
    Turning by holding joystick either alone or to the opposite side of the other joystick
    Driving by holding both joysticks in the same direction.

    Note:
    -When turning, it will apply both left and right motors --> It can be really fast and can be hard to control.  Use with caution.

    Upside:
    - Simple and intuitive logic

    Downside:
    - Can't perform curved driving
    - Rather slower and simple motion
    */

    int stick1 = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int stick2 = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

    if (abs(stick1) < DEADZONE) {
        stick1 = 0;
    }
    if (abs(stick2) < DEADZONE) {
        stick2 = 0;
    }

    if ((stick1 * stick2 > 0)){
        //Both sticks forward or backward
        chassis.drive_set((stick1 + stick2)/2, (stick1 + stick2)/2);

    } else if (stick1 != 0 || stick2 != 0) {
        //Either stick is forward and the other is backward or neutral
        int turning_power = std::clamp((stick1 - stick2), MAX_SPEED *-1, MAX_SPEED);
        chassis.drive_set(turning_power, turning_power * -1);

    } else {
        //Both sticks are neutral
        chassis.drive_set(0, 0);
    }
}