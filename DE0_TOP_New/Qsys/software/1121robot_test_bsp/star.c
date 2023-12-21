void star_display(int i)
{
	 int num0,num1,num2,num3;

	 	usleep(200000);
		switch(i)
		{
		case 0:
			num3=0x73;
			num2=0x38;
			num1=0x77;
			num0=0x66;
			break;
		case 1:
			num3=0x38;
			num2=0x77;
			num1=0x66;
			num0=0x73;
			break;
		case 2:
			num3=0x77;
			num2=0x66;
			num1=0x73;
			num0=0x38;
			break;
		case 3:
			num3=0x66;
			num2=0x73;
			num1=0x38;
			num0=0x77;
			break;
		}
		IOWR(HEX0_BASE,0,~num0);
		IOWR(HEX1_BASE,0,~num1);
		IOWR(HEX2_BASE,0,~num2);
		IOWR(HEX3_BASE,0,~num3);

}
