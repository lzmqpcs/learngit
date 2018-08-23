.text
.globl _start
_start:

	/*初始化c语言的运行环境*/
	ldr sp,=0x7ffffff0
	b  main
	
	
halt_loop:
    b halt_loop
