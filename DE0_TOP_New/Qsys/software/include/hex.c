int he0(int x);

int he0(int x)
{
	int hex=0;
	switch(x)
	{
		case 0:
			hex=0x3F;
			break;
		case 1:
			hex=0x06;
			break;
		case 2:
			hex=0x5B;
			break;
		case 3:
			hex=0x4F;
			break;
		case 4:
			hex=0x66;
			break;
		case 5:
			hex=0x6D;
			break;
		case 6:
			hex=0x7D;
			break;
		case 7:
			hex=0x07;
			break;
		case 8:
			hex=0x7F;
			break;
		case 9:
			hex=0x6F;
			break;
		case 10:
			hex=0x77;
			break;
	}
	return ~hex;
}
