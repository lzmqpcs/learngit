  
#define  GPD0CON   (*((volatile unsigned int *)0x114000A0))
#define  TCFG0     (*((volatile unsigned int *)0x139D0000))
#define  TCFG1     (*((volatile unsigned int *)0x139D0004))
#define  TCON      (*((volatile unsigned int *)0x139D0008))
#efine  TCNTB0    (*((volatile unsigned int *)0x139D000C))
#define  TCMPB0    (*((volatile unsigned int *)0x139D0010))

int main(int argc, const char *argv[])
{
	unsigned int temp=GPD0CON;
	temp &=~(0xf);
	temp |=(0x2);
	GPD0CON= temp;

    temp=TCFG0;
	temp &=~(0xff);
	temp |=(0xdd);
	TCFG0 = temp;
	
    temp=TCFG1;
	temp &=~(0xf);
	temp |=(0x8);
	TCFG1 = temp;

	 temp=TCNTB0;
	temp |=(0x500);
	TCNTB0 = temp;

	
	 temp=TCMPB0;
	temp |=(0x200);
	TCMPB0 = temp;

	 temp=TCON;
	temp &=~(0x1f);
	temp |=(0x1a);
	TCON = temp;
	temp &=~(0x1f);
	temp |=(0x19);








		
	return 0;
}
