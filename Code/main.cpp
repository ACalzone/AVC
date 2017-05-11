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
        
    }
    return 0;
}
