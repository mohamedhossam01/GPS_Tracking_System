#include "tm4c123gh6pm.h"	

void LCD1_Command(unsigned char com){
	GPIO_PORTA_DATA_R = 0; //change this when you connect gps
	GPIO_PORTB_DATA_R = com;
	GPIO_PORTA_DATA_R |= 0X10;
	delayus(0);
	GPIO_PORTA_DATA_R = 0;
	if(com < 4) delayms(2);
	else delayms(40);
}

void LCD1_Init(){
	delayms(20);
	LCD1_Command(0x30);
	delayms(5);
	LCD1_Command(0x30);
	delayus(100);
	LCD1_Command(0x30);
	
	LCD1_Command(0x38);
	LCD1_Command(0x06);
	LCD1_Command(0x01);
	LCD1_Command(0x0F);
}
