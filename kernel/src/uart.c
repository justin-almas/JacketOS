#include "uart.h"
#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>


static void outb(unsigned short port, unsigned char value) {
    __asm__ volatile ("outb %0, %1" : : "a"(value), "Nd"(port));
}

void serial_init(void) {
  	outb(COM1 + 1, 0x01); // Enable all interrupts
	outb(COM1 + 3, 0x03); // 8 bits, no parity, one stop bit
    	outb(COM1 + 2, 0xC7); // Enable FIFO, clear them, with 14-byte threshold
}


int kputchar(int c) {
	outb(COM1, (unsigned char) c);
	return c;
}


static void kprint(const char * str) {
	while(*str) {
		kputchar((int)*str);
		str++;
	}
}

int kputs(const char * str) {
	kprint(str);
	kputchar((int)'\n');
	return 0;
}
