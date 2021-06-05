#include "tm4c123gh6pm.h"	
#include <math.h>
#include "tm4c123.h"
float fdistance = 0;
void distance_update(float startX, float startY, float endX, float endY){
	fdistance += sqrt((startX - endX) * (startX - endX) + (startY - endY) * (startY - endY));
}

int i,j;
void Systick_Init(int ms) {
	NVIC_ST_CTRL_R = 0;
	NVIC_ST_RELOAD_R = 16000 * ms - 1;
	NVIC_ST_CURRENT_R = 0;
	NVIC_ST_CTRL_R = 5;
}
void delayus(int us){
	i = 0;
	while(i<us)
	{
		j = 0;
		while(j<3)
		{
				j++;
		} 
		i++;
	}
		
}
void delayms(int ms){
	i = 0;
	while(i<ms)
	{
		j = 0;
		while(j<3180)
		{
				j++;
		} 
		i++;
	}
}






