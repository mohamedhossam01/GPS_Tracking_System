#include "tm4c123gh6pm.h"	

void LCD1_Data(unsigned char data){
	GPIO_PORTA_DATA_R = 0X04;//change this when you connect gps
	GPIO_PORTB_DATA_R = data;
	GPIO_PORTA_DATA_R = 0X14;
	delayus(0);
	GPIO_PORTA_DATA_R = 0;
	delayus(40);
}
float fdistance = 0;
int main(){
	char x[]={'H','e','l','l','o',' ','W','o','r','l','d','!','\0'};
	SCB->CPACR |= ((3UL << 10*2) | (3UL << 11*2) );
	PORTA_Init();
	PORTB_Init();
	LCD1_Init();
	LED_Init();
	RGB_OUT((int)fdistance);
	LCD1_Print_String(x);
	LCD1_Command(0xC0);
	LCD1_Print_int(12345);
}
