#include <stdio.h>
#include <time.h>
#include "E101.h"
#include "movement.h"

void move(double speedRight, double speedLeft){
	init();
	set_motor(1, speedRight);
	sleep1(0,500000);
	set_motor(2, speedLeft);
	sleep1(0, 500000);
}
