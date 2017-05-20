#include <stdio.h>
#include <time.h>
#include "E101.h"

int main(){
    init();
    char pix[32], pix_two[32]; //arrays for storing pixel values, two arrays so the robot can check two rows of pixels incase there is a problem with one
    int nwp = 0; //counts white pixels from picture
    int nwp2 = 0;
    int vLeft = 70, vRight = 70; //speed variables
    int error = 0; //error value
    int prev_error = 0; //previous error value
    double error_diff = 0; //difference in errors
    int error_total = 0; //sum of all error values
    double prop_signal = 0; //proportional signal
    double int_signal = 0; //integral signal
    double deriv_signal = 0; //derivative signal
    int error2 = 0;
    int prev_error2 = 0;
    double error_diff2 = 0;
    int error_total2 = 0;
    double prop_signal2 = 0;
    double int_signal2 = 0;
    double deriv_signal2 = 0;
    int s, x; 
    float kp = 0.05;
    float ki = 0.05;
    float kd = 0.05; //values that determine the strength of the PID
    while(true){
        take_picture();
        nwp = 0;
        for(int i=0; i<32; i++){
            pix[i] = get_pixel(120, i*10, 3);
            pix_two[i] = get_pixel(115, i*10, 3);
            if(pix[i]>127){ 
                s = 1;
                nwp++;
            } else {
                s = 0;
            }
            if(pix_two[i]>127) {
				x = 1;
				nwp2++;
			}
			else {
				x =0;
			}
            error = error + (i - 16) * s;
            error_diff = error - prev_error;
            error_total = error_total + error;
            prev_error = error;
            prop_signal = error * kp;
            deriv_signal = error_diff * kd;
            int_signal = error_total * ki;
            error2 = error2 + (i - 16) * x;
            error_diff2 = error2 - prev_error2;
            error_total2 = error_total2 + error2;
            prev_error2 = error2;
            prop_signal2 = error2 * kp;
            deriv_signal2 = error_diff2 * kd;
            int_signal2 = error_total2 * ki;
        }

        
        
        if(nwp>0 || nwp2>0){
            vLeft = 35 + prop_signal + int_signal + deriv_signal;
            vRight = 35 + prop_signal + int_signal + deriv_signal; 
            if(nwp < nwp2) {
				vLeft = 35 +  prop_signal1 + int_signal1 + deriv_signal1;
				vRight = 35 + prop_signal1 + int_signal1 + deriv_signal1;
			}         
			if(vLeft >= 255) {
				vLeft = 254;
			} 
			else if(vLeft <= -255){
			vLeft = -254;
			}
			 if(vRight <= -255) {
			vRight = -254;
			} 
			else if(vRight >= 255){
			vRight = 254;
			} 
            set_motor(1, vRight);
            set_motor(2, vLeft);
        }
        else {
            vLeft = -70;
            vRight = -70;
            set_motor(1, vRight);
            set_motor(2, vLeft);
        }
        /*while(true) {
            int adc_reading = read_analog(0);
            int threshold; placeholder variable, should remove once we know how much the value for the sensor will be when the robot is too close to the wall
            if(adc_reading <= threshold) {
                stop(0);
                Add the stuff to check/open the gate
                if(no gate) {
                    set_motor(1, Speed to be determined after testing);
                    sleep1(time to be determined after testing);
                    stop(0);
                }
                set_motor(1, vRight);
                sleep1(0, 25000);
                set_motor(2, vLeft);
                sleep1(0, 25000);
            }
        } This has been commented because it is not yet functional*/
    }
    return 0; //And additional thing to note is that the camera may be oriented incorrectly making the error calculations unusable and could be the reason why it only moves in a circle
}

