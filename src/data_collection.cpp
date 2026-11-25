#include "data_collection.hpp"
curr = 360.0;

void _process_data(){
    prev = curr;
    curr = chassis.imu.get_rotation();
    return curr - prev;
}

void print_data(){
  if (master.get_digital_new_press(DIGITAL_A)){
    printf("%f\n", _process_data() - 360);
  }
}