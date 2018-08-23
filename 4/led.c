
#define  GPX2CON   (*((volatile unsigned int *)0x11000C40))
#define  GPX1CON   (*((volatile unsigned int *)0x11000C20))
#define  GPF3CON   (*((volatile unsigned int *)0x114001E0))
#define  GPX2DAT   (*((volatile unsigned int *)0x11000C44))
#define  GPX1DAT   (*((volatile unsigned int *)0x11000C24))
#define  GPF3DAT   (*((volatile unsigned int *)0x114001E4))


int main(int argc, const char *argv[])
{

	unsigned temp = GPX2CON;
	temp &=~(0xf<<28);
	temp |=(0x1<<28);
	GPX2CON = temp;
	

    temp = GPX1CON;
	temp &=~(0xf);
	temp |=(0x1);
	GPX1CON = temp;

    temp = GPF3CON;
	temp &=~(0xff<<16);
	temp |=(0x11<<16);
	GPF3CON = temp;

    temp = GPX1CON;
	temp &=~(0xff<<4);
	temp |=(0x00<<4);
	GPX1CON = temp;
while(1)
{ 
	if(GPX1DAT & 0x2)
	{
	temp = GPX2DAT;
	temp &=~(0x1<<7);
	GPX2DAT = temp;
	
	temp = GPX1DAT;
	temp &=~(0x1);
	GPX1DAT = temp;
	}
	else
	{
	temp = GPX2DAT;
	temp |=(0x1<<7);
	GPX2DAT = temp;
	
	temp = GPX1DAT;
	temp |=(0x1);
	GPX1DAT = temp;
	}
	if(GPX1DAT & 0x4)
	{

		temp = GPF3DAT;
		temp &=~(0x3<<4);
		GPF3DAT = temp;
	}
	else
	{
		temp = GPF3DAT;
		temp |=(0x3<<4);
		GPF3DAT = temp;

	}


	

}



	
	return 0;
}



