#include <stdio.h>
#include <time.h>
#include "E101.h"

int main(){
	init();
    /*
   	set_motor(1, 60);
   	set_motor(2, 60);
   	sleep1(3,0);
   	set_motor(1, 0);
   	set_motor(2, 0);
   	return 0;
    */    
    int pix[320];                      //, pix_two[32];
    int nwp = 0;                       //counts white pixels from picture
    int vLeft = 70, vRight = 70;           //speed variables
    int error = 0;                         //error value
    int prev_error = 0;                    //previous error value
    double error_diff = 0;                 //difference in errors
    int error_total = 0;                   //sum of all error values
    double prop_signal = 0;                //proportional signal
    double int_signal = 0;                 //integral signal
    double deriv_signal = 0;              //derivative signal
    int s, x; 
    float kp = 0.01;
   	// float ki = 0.05;
    float kd = 0.05;
    while(true){
        take_picture();
        //display_picture(1,0);
        nwp = 0;
        error = 0;
        for(int i=0; i<320; i++){
            pix[i] = get_pixel(120, i, 3);
            if(pix[i]>127){ //might want to change value that determines colour
                s = 1;
                nwp++;
            } else {
                s = 0;
            }          
			x =0;			
            error = error + (i - 160) * s;
            //error_diff = error - prev_error;
            //error_total = error_total + error;
            //prev_error = error;
            prop_signal = error * kp;
            //deriv_signal = error_diff * kd;
           	// int_signal = error_total * ki;
        }        
       	//printf(" error=%d nwp=%d\n",error,nwp);
        if(nwp>0){
            vLeft = 35 - prop_signal;// + int_signal + deriv_signal;
            vRight = 35 + prop_signal;// - int_signal - deriv_signal; 			       
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
			stop(1);       
       	} 
		else {
            vLeft = -35;
            vRight = -35;
            set_motor(1, vRight);
            set_motor(2, vLeft);
			sleep1(0, 500000);
			stop(0);
        }
		/*while(true) {
            int adc_reading = read_analog(0);
            int threshold; //placeholder variable, should remove once we know how much the value for the sensor will be when the robot is too close to the wall
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
        }*/
    }
    return 0;
}
