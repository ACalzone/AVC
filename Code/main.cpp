#include <stdio.h>
#include <time.h>
#include "E101.h"

int main {
    init();
    char pix[320], wh[320];
    int nwp = 0; //counts white pixels from picture
    int vLeft = 70, vRight = 70; //speed variables
    int error = 0; //error value
    int prev_error = 0; //previous error value
    double error_diff = 0; //difference in errors
    int error_total = 0; //sum of all error values
    double prop_signal = 0; //proportional signa
    double int_signal = 0; //integral signal
    double deriv_signal = 0; //derivative signal
    int w; //determines if specific pixel is white or not
    float kp = 0.5;
    float ki = 0.05;
    float kd = 0.5;
    while(true){
        take_picture();
        display_picture(1, 0);
        nwp = 0;
        for(int i=0; i<320; i++){
            pix[i] = get_pixel(120, i, 3);
            if(pix[i]>90){ //might want to change value that determines colour
                wh[i]=1;
                s = 1;
                nwp++;
            } else {
                wh[i] = 0;
                s = 0;
            }
            printf("%d\n", wh[i]);
            error = error + (i - 160) * s;
            error_diff = error - prev_error;
            error_total = error_total + error;
            prop_signal = error*kp;
            int_signal = error_total * ki;
            deriv_signal = error_diff * kd;
            prev_error = error;
        }
        
        if(nwp>0){
            vLeft = 70 + prop_signal + int_signal + deriv_signal;
            vRight = 70 - prop_signal - int_signal - deriv_signal;
            set_motor(1, vRight);
            sleep1(0, 250);
            set_motor(2, vLeft);
            sleep1(0, 250); 
        }
        else {
            vLeft = -70;
            vRight = 70;
            set_motor(1, vRight);
            set_motor(2, vLeft);
        }
        printf("sum = %f nwp = %d\n", sum, nwp);
        while(true) {
            int adc_reading = read_analog(0);
            int threshold; //placeholder variable, should remove once we know how much the value for the sensor will be when the robot is too close to the wall
            if(adc_reading <= threshold) {
                stop(0);
                /*Add the stuff to check/open the gate
                if(no gate) {
                    set_motor(1, Speed to be determined after testing);
                    sleep1(time to be determined after testing);
                    stop(0);
                }*/
                set_motor(1, vRight);
                sleep1(0, 25000);
                set_motor(2, vLeft);
                sleep1(0, 25000);
            }
        }
    }
    return 0;
}
