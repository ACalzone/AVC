#include <stdio.h>
#include <time.h>
#include "E101.h"
#include "movement.h"

int main {
    init();
    char pix[32], wh[32];
    int nwp = 0; vLeft = 70, vRight = 70;
    while(true){
        take_picture();
        display_picture(1, 0);
        double sum = 0;
        nwp = 0;
        for(int i=0; i<32; i++){
            pix[i] = get_pixel(120, i*10, 3);
            if(pix[i]>90){
                wh[i]=1;
                sum = sum + (i-16);
                nwp++;
            } else {
                wh[i] = 0;
            }
            printf("%d\n", wh[i]);
        }
        if(nwp>0){
            sum = sum/nwp;
            vLeft = 70 + sum;
            vRight = 70 - sum;
        }
        printf("sum = %f nwp = %d\n", sum, nwp);
        set_motor(1, vRight);
        sleep1(0, 25000);
        set_motor(2, vLeft);
        sleep1(0, 25000);
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
