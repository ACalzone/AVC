#include <stdio.h>
#include <time.h>
#include "E101.h"
int main(){
init();
char ip[15] = {'1','3','0','.','1','9','5','.','6','.','1','9','6'};
connect_to_server(ip, 1024);
char g[24] = {'P','l','e','a','s','e'};
send_to_server(g);
char fromserver[24];
receive_from_server(fromserver);
send_to_server(fromserver);

while (true){
	//int scale_int=0;
	int white=0;
	//float t =0;
	
take_picture();
//display_picture(1,0);
int sum = 0;
//float pre_error=0;
//float kd=0.1;
//float deriv_signal=0;
int i;
float kp = 0.01;
int prop_signal = 0;
int w;
int r,b,g;
int red = 0;
for(i=0; i<320; i++){
	w = get_pixel(120,i,3);
	r = get_pixel(120,i, 0);
 g = get_pixel(120,i, 1);
 b = get_pixel(120,i, 2);

	if(r > 191) {
	   red = 1;
	}
	if(w>110){
		sum = sum + (i-160)*1;
		white++;
		}
		else{
		sum = sum + (i-160)*0;
	}
		
		//double temp_sum= sum;
		//if(temp_sum<0){
			//temp_sum = temp_sum*-1;
			
			//}
			
			
			//double  scale = ((double) temp_sum*(70/12000));
			// scale_int = (int) scale;
	//printf("%d   %d\n", sum, scale_int);

	//pre_error=sum;
	}
	//eriv_signal=(sum-pre_error)*kd;
	prop_signal = (int)((float)sum * kp);
//float g = read_analog(	
//if((white==0)&&(read_analog(1)>20)){//&&(g<50)&&(b<50)){
//while(true){
//set_motor(1,-30);
//set_motor(2,-30);
//}
//}

//////////////////////////////////////////////////
	//if(40 - ((prop_signal))<0){
	 //t = 0;	
		//}
		//else {t = (40 - (prop_signal));}
	////////////////////////////////////////////
	 if(sum>0){  ////////////////for turning left
	set_motor(2,-50);
	set_motor(1,-(90 + (prop_signal)));
	//sleep1(1,0);
	//printf(" motor 1 %d\n",(int)(55+(prop_signal)) );
	}	
	else if(sum<0){ //////////////////for turning right
	set_motor(2, -(80 - (prop_signal)));
	set_motor(1,-20);
	//sleep1(1,0);
	//printf( "motor 2 %d\n",(int)(55-prop_signal) );
		
	
	
	}
	//////////////////////////////////////
	else if ((sum==0)&&(white==0)){
	set_motor(2, (50));
	set_motor(1, (30));
	sleep1(0,250000);
	}

	//sleep1(0,5);
		
 else if ((sum==0)&&(white!=0)){
	set_motor(2, -20);
 	set_motor(1, -(20));
}
else if((sum>2500)&&(sum<3400)){
set_motor(2, -(80 - (prop_signal)));
set_motor(1,-20);


}
// if((white==0)&&(r>90)){
//set_motor(1,30);
//set_motor(2,30);

//}
	//sleep1(0,5);
	//////////////////////////////////////////////////////
/*if(red == 1){
	while(true) {
	    int sensor = 0;
	    int sensor_right = 0;
	    int threshold_wall = 20;
	    int threshold_turn =40;
	    sensor = read_analog(0);
	    if(sensor > threshold_wall) {
		set_motor(1, 30);
		set_motor(2, 30);
	    }
	    else {
		set_motor(1, 0);
		set_motor(2, 0);
		sensor_right = read_analog(2);
		if(sensor_right <= threshold_wall) {
		 // sleep1(6, 50000);
		  sensor = read_analog(0);
		  if(sensor > threshold_wall) {
			set_motor(1, 30);
			set_motor(2, 30);
		  }
		  else {
			while(sensor <= threshold_wall && sensor_right > threshold_wall) {
			    set_motor(2, 30);
			    sensor = read_analog(0);
			}
			if(sensor <= threshold_wall && sensor_right <= threshold_wall){
			    while(sensor_right <= threshold_turn) {
				set_motor(1, 30);
				sensor_right = read_analog(2);
			    }
			}
		  }
		}
		printf("%d      %d\n", sensor, sensor_right);
	    }
	}
}*/
	//////////////////////////////////////////////////////////
		
	printf("%d   %d  %d\n", sum, prop_signal, white);	
	//sleep1(0,5000000);
	//stop(0);
	//stop(1);
	//set_motor(1,0);
	//set_motor(2,0);
 

	//stop(0);
	
	

	
}
	
	
	return 0;
	}
