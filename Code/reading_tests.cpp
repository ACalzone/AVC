#include <stdio.h>
#include <time.h>
#include "E101.h"

int main {
    init();
    int adc_reading;
    while(true) {
         adc_reading = read_analog(0);
         printf("%d\n", adc_reading);
         sleep1(0, 500000);
    }
    return 0;
}
