#include <stdio.h>
#include <time.h>
#include "E101.h"
#include "move.h"


int adc_reading;
	int speed = 0;
	while(true){
    	adc_reading = read_analog(0);
    	speed = adc_reading/4;
    	set_motor(1, speed);
	}
