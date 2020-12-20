#include<lpc17xx.h>

void uart_init(void);
void uart_send(char*);

int main()
{
	char *a = "hilll";
	while(1)
	{
			uart_init();
			uart_send(a);
	}

}

void uart_init()
{
	
	LPC_SC->PCONP |= (1<<3);
	LPC_SC->PCLKSEL0 |= (1<<6) | (0<<7);
	LPC_UART0->LCR |= (1<<7) | (1<<8);
	LPC_UART0->DLL = 36;
	LPC_UART0->DLM = 0;
	LPC_UART0->LCR |= (1<<0) | (1<<1) | (1<<2) | (1<<7);
	
	LPC_UART0->FDR = (2<<4) | 1;    
	LPC_UART0->FCR = (1<<0) | (1<<1) | (1<<2);
	
	LPC_PINCON->PINSEL0 = (1<<4) | (1<<6);  //pincon
	LPC_UART0->LCR &= ~(1<<7);
	
}
void uart_send(char* str)
{
	while(*str!= '\0')
	{
	while(!(LPC_UART0->LSR & (1<<5)));
		LPC_UART0->THR = *str;	
		str++;
	}
	
	
}