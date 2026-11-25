#include "data_collection.hpp"
curr = 360.0;

void _process_data(){
    prev = curr;
    curr = chassis.imu.get_rotation();
    error = std::abs(curr - prev -360.0);
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