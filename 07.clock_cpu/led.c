#define  GPX2CON   (*((volatile unsigned  int  *)0x11000c40))
#define  GPX1CON   (*((volatile unsigned  int  *)0x11000c20))
#define  GPF3CON   (*((volatile unsigned  int  *)0x114001E0)) 
#define  GPX2DAT   (*((volatile unsigned  int  *)0x11000c44))
#define  GPX1DAT   (*((volatile unsigned  int  *)0x11000c24))
#define  GPF3DAT   (*((volatile unsigned  int  *)0x114001E4)) 
#define  CLK_SRC_CPU   (*((volatile unsigned  int  *)0x10044200)) 



int main()
{
#if 1 
	unsigned  int  temp  = 0;

	CLK_SRC_CPU  = 0x0; // cpu的工作时钟 24M 

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
	
		temp  = GPX1DAT;
		temp  |=(0x1 << 0);
		GPX1DAT  = temp;

		temp  = GPF3DAT;
		temp  |= (0x3 << 4);
		GPF3DAT  = temp;

		my_delay(1000000);

		temp  = GPX1DAT;
		temp  &=~(0x1 << 0);
		GPX1DAT  = temp;

		temp  = GPF3DAT;
		temp  &= ~(0x3 << 4);
		GPF3DAT  = temp;
		my_delay(1000000);
	
	}
	return;
#endif
}
void  my_delay(int ms)
{

	while(ms  --);

}

