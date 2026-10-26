#pragma once
#include "main.h"

inline ez::PID lift_pid(2.0, 0.0, 10.0, 0.0, "Lift_PID");

enum class LiftState {
    Down,
    Mid,
    Up
};

void lift_init();
// void lift_set_state(LiftState s);
// void lift_task_fn();
void lift_opcontrol();
double lift_angle();