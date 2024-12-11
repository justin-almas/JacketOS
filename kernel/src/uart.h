#ifndef UART_H
#define UART_H

void serial_init(void);
int kputchar(int);
int kputs(const char *);

#define COM1 0x3f8


#endif
