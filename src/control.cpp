#include "control.hpp"

void opcontrol_custom() {
    int stick1 = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int stick2 = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

    if (abs(stick1) < 10) {
        stick1 = 0;
    }
    if (abs(stick2) < 10) {
        stick2 = 0;
    }

    if ((abs(stick1) >= 10 && abs(stick2) >= 10)|| (stick1 <= -10 && stick2 <= -10)){
        chassis.drive_set((stick1 + stick2)/2, (stick1 + stick2)/2);
    } else if (stick1 >= 10 || stick1 <= -10){
        chassis.drive_set(stick1, stick1 * -1);
    } else if (stick2 >= 10 || stick2 <= -10){
        chassis.drive_set(stick2 * -1, stick2);
    } else {
        chassis.drive_set(0, 0);
    }
}