#include <stdio.h>
#include <time.h>
#include "E101.h"
#include "move.h"

void move(double speed){
	init();
	set_motor(1, 255 * speed);
	sleep1(0,500000);
	set_motor(2, 255 * speed);
	sleep1(0, 500000);
}
