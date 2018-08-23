.text
.globl _start
_start:

	/*初始化c语言的运行环境*/
	ldr sp,=0x7ffffff0
	mrc  p15,0,r0,c1,c0,0
	bic  r0,r0,#0x1000
	mcr  p15,0,r0,c1,c0,0
	b  main
	
	
halt_loop:
    b halt_loop
