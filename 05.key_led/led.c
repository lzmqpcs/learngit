#define  GPX2CON   (*((volatile unsigned  int  *)0x11000c40))
#define  GPX1CON   (*((volatile unsigned  int  *)0x11000c20))
#define  GPF3CON   (*((volatile unsigned  int  *)0x114001E0)) 
#define  GPX2DAT   (*((volatile unsigned  int  *)0x11000c44))
#define  GPX1DAT   (*((volatile unsigned  int  *)0x11000c24))
#define  GPF3DAT   (*((volatile unsigned  int  *)0x114001E4)) 



int main()
{
	unsigned  int  temp  = 0;
	unsigned  int val  =0;

	temp  = GPX1CON;
	temp  &=~(0xf << 4);
	temp  |=(0x0  <<  4);
	GPX1CON  = temp;

	temp = GPX2CON;
	temp  &=~(0xf << 28);
	temp  |=(0x1 << 28);
	GPX2CON  = temp;
	temp = GPX1CON;
	temp  &=~(0xf << 0);
	temp  |=(0x1 << 0);
	GPX1CON  = temp;
	temp = GPF3CON;
	temp  &=~(0xff << 16);
	temp  |=(0x11 << 16);
	GPF3CON  = temp;

	temp  = GPX2DAT;
	temp  |=(0x1 << 7);
	GPX2DAT  = temp;

	temp  = GPX1DAT;
	temp  |=(0x1 << 0);
	GPX1DAT  = temp;

	temp  = GPF3DAT;
	temp  |= (0x3 << 4);
	GPF3DAT  = temp;




	while(1)
	{
	

		val  = GPX1DAT;
		if(val  & (1 << 1))
		{
		
			GPF3DAT  &=~(0x1  << 4);

		
		}else{
		
			GPF3DAT |=(0x1 << 4);
		
		
		}
	
	}
	return;

}
