#include "data_collection.hpp"
double curr = 360.0;
double prev_angle;
double error;

double _process_data(){
    prev_angle = curr;
    curr = chassis.imu.get_rotation();
    error = curr - prev_angle -360.0;
    if (error > 180){
        return 360.0 - error;
    }
    else {
        return error;
    }
}

void print_data(){
  if (master.get_digital_new_press(DIGITAL_A)){
    printf("%f\n", std::abs(_process_data() - 360));
  }
}