dog.bin: dog.o 
	arm-linux-ld -Ttext 0x0 -o dog.elf $^
	arm-linux-objcopy -O binary dog.elf dog.bin
	arm-linux-objdump -D dog.elf > dog_elf.dis
	gcc mkv210_image.c -o mkx210
	./mkx210 dog.bin 210.bin
	
%.o : %.S
	arm-linux-gcc -o $@ $< -c

%.o : %.c
	arm-linux-gcc -o $@ $< -c 

clean:
	rm *.o *.elf *.bin *.dis mkx210 -f

	
	