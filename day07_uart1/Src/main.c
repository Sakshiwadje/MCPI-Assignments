
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"
#include "uart.h"
#include "switch.h"
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

//Count number of switch press (using interrupt) and display the count on UART (polling)
int main(void)
{
	char str[32];
	uint8_t count = 0;
	SystemInit();
	SwitchInit(SWITCH);
	UartInit(BAUD_9600);

	while(1) {

		while(exti0_flag==0);
		sprintf(str,"count = %d\r\n ",count);
		count++;
		UartPuts(str);
		exti0_flag=0;
	}

	return 0;
}
