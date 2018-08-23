led.bin : led.s
	arm-none-linux-gnueabi-gcc -c -o led.o led.s
	arm-none-linux-gnueabi-ld -Tled.lds -N led.o -o led.elf
	arm-none-linux-gnueabi-objcopy -O binary -S led.elf led.bin
	arm-none-linux-gnueabi-objdump -D -m arm  led.elf > led.dis

clean:
	rm -f *.dis *.bin *.elf *.o

	

