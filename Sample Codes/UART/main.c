/*PIN CONNECTIONS:
*	RX of USB-UART converter	->	0.0
*	TX of USB-UART converter	->	0.1
*	GND of USB-UART converter	->	GND of LPC2148
*/



//#include "Serial.h"

#include <stdio.h>                /* prototype declarations for I/O functions */
#include <LPC214x.H>              /* LPC21xx definitions */                     
#include "Serial.h"

#define UART0_TEXT "\n\r Testing UART0  www.rdltech.in"
#define UART1_TEXT "\n\r Testing UART0  www.rdltech.in"

/**
**************************************************************************

****1111
  Function Name : delay()

  Description :This function suspends the tasks for specified ticks.	

  Input :  ticks:no of ticks in multiple of 1 usec
            task: task to be suspended

  Output : void

  Note :
*******************************************************************************
*/

void delay(int count)
{
  int j=0,i=0;

  for(j=0;j<count;j++)
  {
    /* At 60Mhz, the below loop introduces
    delay of 10 us */
    for(i=0;i<35;i++);
  }
}

/****************/
/* main program */
/****************/
int main (void)  {                /* execution starts here                    */

	int buffer_variable;				//To read input from the user
	
  uart1_init();					  // Initialize UART1
	uart0_init();						// Initialize UART0
	
	uart1_puts ("UART1");	  // Transffer data to PC through Serial
	uart0_puts ("UART0");	  // Transffer data to PC through Serial
  delay(100000);
	
	
	
  while (1) {                          /* An embedded program does not stop */
  //uart0_getkey();
		
		buffer_variable = uart1_getkey();			//Check for returnValue; negative indicates receive buffer NOT full condition
		if (buffer_variable >= 0)
			uart1_putc((char)buffer_variable);
  }                               
}
