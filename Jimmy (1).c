char UART5_Read(){
	while((UART5_FR_R & 0x0010) != 0){}
	return (char)(UART5_DR_R & 0xFF);

}
