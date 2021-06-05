#include "tm4c123gh6pm.h"	

void LCD1_Print_int(int num){
	while(num > 9)
	{
		LCD1_Print_int(num/10);
		num = num % 10;
	}
	LCD1_Data('0'+num);
}
void LCD1_Print_String(char word[]){
	char* it = word;
	while(*it!='\0')
	{
		LCD1_Data(*it);
		it++;
	}
}