void UART5_INIT(){//khaled
	SYSCTL_RCGCUART_R |= 0x20;
	SYSCTL_RCGCGPIO_R |= 0x10;
	
	UART5_CTL_R = 0;
	UART5_IBRD_R = 104;
	UART5_FBRD_R = 11;
	UART5_LCRH_R = 0x0070;
	UART5_CTL_R |= 0x0301;
	GPIO_PORTE_CR_R |= 0x30;
	GPIO_PORTE_AFSEL_R|=0x30;
	GPIO_PORTE_PCTL_R=(GPIO_PORTE_PCTL_R&0xFF00FFFF)+0x00110000;
	GPIO_PORTE_DEN_R |= 0x30;
	GPIO_PORTE_AMSEL_R &=~0x30;
}