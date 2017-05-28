#include <stdio.h>
#include <time.h>
#include "E101.h"

int main {
    init();
    int sensor = 0; //variable for holding the sensor values
    int red = 1; //variable to determine if the robot has reached that red part so that the first while loop will break
    while(red = 1){
         sensor = read_analog(0);
         if(sensor >threshold) { //threshold is a placeholder for when we learn what the sensor values
           set_motor(1, 30); //should test out different speeds
           set_motor(2, 30);
         }
        else {
           stop(0);
           sleep1(3, 0); //so it can wait for the gate to open
           set_motor(1, 30); //not sure which motor will make it turn right
        }
    }
    return 0;
}
