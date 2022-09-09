//*******************************************************************
//        Name:		Rylan Anderson
//
//	  Date:		6/5/2022
//
//	  Description: Simple Driver for using the UART communication
//			protocol on STM32F4. UART GPIO pin initialized,
//			baudrate is configured, and a basic write
//			function can be used for debugging.
//
//*******************************************************************



// NOTE: Install RealTerm to see data being transfered

#include "stm32f4xx.h"
#include <stdint.h>



#define GPIOAEN						(1U<<0)
#define UART2EN						(1U<<17)
#define CR1_TE						(1U<<3)
#define CR1_UE						(1U<<13)

#define SR_TXE						(1U<<7)

#define SYS_FREQ					16000000
#define APB1_CLK					SYS_FREQ
#define UART_BAUDRATE				115200

//*******************************************************************

static void uart_set_baudrate(USART_TypeDef* USARTx, uint32_t periphClk,uint32_t baudRate);
static uint16_t compute_uart_bd(uint32_t periphClk, uint32_t baudRate);
void uart2_tx_init(void);
void uart2_write(int ch);

//*******************************************************************


int main(void)
{
	uart2_tx_init();

	while(1)
	{
		uart2_write('Y');

	}


}

//*******************************************************************

void uart2_tx_init(void)
{
	/******Configure UART GPIO pin******/
	// Enable clock access to GPIOA
	RCC->AHB1ENR |= GPIOAEN;

	// Set PA2 mode to alternate function mode
	// Reference manual p.157
	GPIOA->MODER &=~ (1U<<4);
	GPIOA->MODER |= (1U<<5);

	// Set PA2 alternate function type to UART_TX (AF07)
	// Reference manual p.161
	GPIOA->AFR[0] |= (1U<<8); // set pin 8 to 1
	GPIOA->AFR[0] |= (1U<<9); // set pin 9 to 1
	GPIOA->AFR[0] |= (1U<<10); // set pin 10 to 1
	GPIOA->AFR[0] &=~ (1U<<11); //set pin 11 to 0

	// NOTE: &=~ used for disabling


	/******Configure USART Module******/
	// Enable clock access to UART2
	// Connected to the APB1 Bus, Data sheet p. 15
	RCC->APB1ENR |= UART2EN;

	// Configure UART BAUDRATE
	uart_set_baudrate(USART2,APB1_CLK,UART_BAUDRATE);

	// Configure the transfer direction
	// Reference manual p. 550 set bit number 3 to 1 to enable transmitter
	USART2->CR1 = CR1_TE; // cleans out the register when use =


	// Enable the UART Module
	USART2->CR1 |= CR1_UE; // do not want to clean out register this time

}

//*******************************************************************

void uart2_write(int ch)
{
	// Make sure transmit data register is empty
	while(!(USART2->SR & SR_TXE)){}

	// Write to transmit data register
	USART2->DR = (ch & 0xFF);

}

//*******************************************************************

static void uart_set_baudrate(USART_TypeDef* USARTx, uint32_t periphClk,uint32_t baudRate)
{
	USARTx->BRR = compute_uart_bd(periphClk, baudRate);

}

//*******************************************************************

static uint16_t compute_uart_bd(uint32_t periphClk, uint32_t baudRate)
{
	return (periphClk + (baudRate/2U)/baudRate);
}



