.text
.globl _start
_start:

	/*gpx1_0  gpx1con  [3-0]   0x1     0x11000c20*/
	/*gpx1_0  gpx1dat  [0]     0x1/0x0 0x11000c24*/
ldr  r1,=0x11000c20
ldr  r0,[r1]
bic  r0,r0,#0x0000000f
orr  r0,r0,#0x00000001
str  r0,[r1]

ldr  r1,=0x114001e0
ldr  r0,[r1]
bic  r0,r0,#0xf0000
orr  r0,r0,#0x10000
str  r0,[r1]

ldr  r1,=0x114001e0
ldr  r0,[r1]
bic  r0,r0,#0xf00000
orr  r0,r0,#0x100000
str  r0,[r1]



loop:
ldr  r1,=0x11000c24
ldr  r0,[r1]
orr  r0,r0,#0x01
str  r0,[r1]
bl delay

ldr  r1,=0x11000c24
ldr  r0,[r1]
bic  r0,r0,#0x01
str  r0,[r1]
bl delay


ldr  r1,=0x114001e4
ldr  r0,[r1]
orr  r0,r0,#0x10 
str  r0,[r1]
bl delay

ldr  r1,=0x114001e4
ldr  r0,[r1]
bic  r0,r0,#0x10 
str  r0,[r1]
bl delay

ldr  r1,=0x114001e4
ldr  r0,[r1]
orr  r0,r0,#0x20
str  r0,[r1]
bl delay

ldr  r1,=0x114001e4
ldr  r0,[r1]
bic  r0,r0,#0x20
str  r0,[r1]
bl delay


b loop



delay:
	ldr r2,=0x6fffffff

jian:
	sub r2,r2,#1
    cmp r2,#0
	bne jian
	mov pc,lr
	


   
	
halt_loop:
    b halt_loop
