
int main(){
	convert = 3.14159265358979323846/180.0;
	PORTA_Init();
	PORTB_Init();
	UART5_INIT();
	LCD1_Init();
	LED_Init();
	GPS_DATA();
	xstart = latnew;
	ystart = longnew;
	while(1)
	{
		GPS_DATA();
		tempdist += distance(xstart,ystart,latnew,longnew);
		LCD1_Print_String(arr);
		LCD1_Data(' ');
		LCD1_Data(' ');
		LCD1_Print_int((int)dist);
		if(tempdist >= 25)
		{
				dist = dist + 25;
				xstart = latnew;
				ystart = longnew;
				tempdist = 0;
				RGB_OUT((int)dist);				
		}
		if(distance(latnew,longnew,xtar,ytar)<=15)
		{
				GPIO_PORTF_DATA_R = 0x08;
				break;
		}
		delayms(2000);
		LCD1_Command(0x01);
	}
}
