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
		case 11:
			hex=0xF7;
			break;
		case 12:
			hex=0xFC;
			break;
		case 13:
			hex=0xB9;
			break;
		case 14:
			hex=0xDE;
			break;
		case 15:
			hex=0xF9;
			break;
		case 16:
			hex=0xF1;
			break;
		case 17:
			hex=0xEF;
			break;
		case 18:
			hex=0xF6;
			break;
		case 19:
			hex=0x86;
			break;
		case 20:
			hex=0x8D;
			break;
		case 21:
			hex=0xB8;
			break;
	}
	return ~hex;
}
