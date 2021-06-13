#include "tm4c123gh6pm.h"	
#include <math.h>
#include "tm4c123.h"
float fdistance = 0;
void distance_update(float startX, float startY, float endX, float endY)
{
	fdistance += sqrt((startX - endX) * (startX - endX) + (startY - endY) * (startY - endY));
}
void LED_Init(){
	SYSCTL_RCGCGPIO_R |= 0x20;
	while ((SYSCTL_PRGPIO_R & 0x20)==0);
	GPIO_PORTF_LOCK_R = 0x4C4F434B;
	GPIO_PORTF_CR_R |= 0x0E;
	GPIO_PORTF_DIR_R |= 0x0E;
	GPIO_PORTF_DEN_R |= 0x0E;
	GPIO_PORTF_AMSEL_R &= ~0x0E;
	GPIO_PORTF_AFSEL_R &= ~0x0E;
	GPIO_PORTF_PCTL_R &= ~0x0000FFF0;
	GPIO_PORTF_DATA_R &= ~0x0E;
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
void LCD1_Command(unsigned char com){
	GPIO_PORTA_DATA_R = 0; //change this when you connect gps
	GPIO_PORTB_DATA_R = com;
	GPIO_PORTA_DATA_R |= 0X10;
	delayus(0);
	GPIO_PORTA_DATA_R = 0;
	if(com < 4) delayms(2);
	else delayms(40);
}
void LCD1_Data(unsigned char data){
	GPIO_PORTA_DATA_R = 0X04;//change this when you connect gps
	GPIO_PORTB_DATA_R = data;
	GPIO_PORTA_DATA_R = 0X14;
	delayus(0);
	GPIO_PORTA_DATA_R = 0;
	delayus(40);
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
void PORTA_Init(){
	SYSCTL_RCGCGPIO_R |= 0x01;
	while ((SYSCTL_PRGPIO_R & 0x01)==0);
	GPIO_PORTA_LOCK_R = 0x4C4F434B;
	GPIO_PORTA_CR_R |= 0xFF;
	GPIO_PORTA_DIR_R = 0xFF;
	GPIO_PORTA_DEN_R = 0xFF;
	GPIO_PORTA_AMSEL_R = 0;
	GPIO_PORTA_AFSEL_R = 0;
	GPIO_PORTA_PCTL_R = 0;
	GPIO_PORTA_DATA_R = 0;
}
void PORTB_Init(){
	SYSCTL_RCGCGPIO_R |= 0x02;
	while ((SYSCTL_PRGPIO_R & 0x02)==0);
	GPIO_PORTB_LOCK_R = 0x4C4F434B;
	GPIO_PORTB_CR_R |= 0xFF;
	GPIO_PORTB_DIR_R = 0xFF;
	GPIO_PORTB_DEN_R = 0xFF;
	GPIO_PORTB_AMSEL_R = 0;
	GPIO_PORTB_AFSEL_R = 0;
	GPIO_PORTB_PCTL_R = 0;
	GPIO_PORTB_DATA_R = 0;
}
void RGB_OUT (int distance){
	if (distance>=100)
		GPIO_PORTF_DATA_R |= 0x0E;
}
void LCD1_Print_int(int num){
	while(num > 9)
	{
		LCD1_Print_int(num/10);
		num = num % 10;
	}
	LCD1_Data('0'+num);
}
//int n;
void LCD1_Print_String(char word[]){
	char* it = word;
	while(*it!='\0')
	{
		LCD1_Data(*it);
		it++;
	}
}
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
