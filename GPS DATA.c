void GPS_DATA(){
	double temp;
	uint8_t input;
	uint8_t i = 0;
	input = UART5_Read();
	while(input!='$')
	{
		input = UART5_Read();
			if (input == '$')
		{
			
			input = UART5_Read();
			if (input == 'G')
			{
			
				input = UART5_Read();
				if (input == 'P')
				{
			
					input = UART5_Read();
					if (input == 'G')
					{
						input = UART5_Read();
						if (input == 'L')
						{
							input = UART5_Read();
							if (input == 'L')
							{
									for(i = 0;i < 4;i++)
									{
											input = UART5_Read();
									}
									i = 0;
									while(input != ',')
									{
											xpos[i] = input;
											input = UART5_Read();
											i++;
									}
									xpos[i] = '\0';
									temp = strtod(xpos, &tempit);
									temp = temp / 60.0;
									temp = temp + 30;
									latnew = temp;
									sprintf(xpos, "%.8f", temp);
									input = UART5_Read();
									input = UART5_Read();
									input = UART5_Read();
									while(input == '0')
									{
										input = UART5_Read();
									}
									input = UART5_Read();
									input = UART5_Read();
									i = 0;
									while(input != ',')
									{
											ypos[i] = input;
											input = UART5_Read();
											i++;
									}
									ypos[i] = '\0';
									temp = strtod(ypos, &tempit);
									temp = temp / 60.0;
									temp = temp + 30;
									longnew = temp;
									input = UART5_Read();
									sprintf(ypos, "%.8f", temp);
									return;
							}
						}
					}
				}
			}
		}
	}
}