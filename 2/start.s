.text
.globl _start
_start:

  ldr sp,=0x7ffffff0
  b main
	


   
	
halt_loop:
    b halt_loop
