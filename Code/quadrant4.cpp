#include <stdio.h>
#include <time.h>
#include "E101.h"

int main {
    init();
    int sensor = 0; //variable for holding the sensor values
    int sensor_right = 0; //variable for the right sensor
    int red = 1; //variable to determine if the robot has reached that red part so that the first while loop will break
    int threshold_wall = 0;
    int threshold_turn = 0;
    while(red == 1){
         sensor = read_analog(0);
         if(sensor > threshold_wall) { //threshold is a placeholder for when we learn what the sensor values
           set_motor(1, 30); //should test out different speeds
           set_motor(2, 30);
         }
        else {
           set_motor(1, 0);
           set_motor(2, 0);
           sleep1(3, 0); //so it can wait for the gate to open
           sensor = read_analog(0);
           if(sensor > threshold_wall) {
             set_motor(1, 30);
             set_motor(2, 30);   
           }
           else {
             sensor_right = read_analog(3);
             while(sensor_right < threshold_turn) {
                  set_motor(1, 30);
                  sensor_right = read_analog(3);
             }
             while(sensor < threshold_turn) {
                  set_motor(2, 30);
                  sensor = read_analog(0);
             }
           }
        }
    }
    return 0;
}
