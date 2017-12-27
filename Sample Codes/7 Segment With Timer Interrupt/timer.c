#include <LPC21xx.h>
#include "seven_segment.h"

uint8_t display_num; 																									//Display unit number to which the timer interrupt writes
extern uint8_t counter_digits[4];

/* Timer Counter 0 Interrupt executes each 10ms @ 60 MHz CPU Clock */
__irq void tc0 (void) {

	if (display_num > 3)																								//Max number of 4 Display units present
		display_num = 0;
	
	seven_segment_put(display_num, counter_digits[display_num]);				//Put the digit into its corresponding display
	++display_num;																											//Increment display number for next iteration
                
  T0IR = 1;                                    												// Clear interrupt flag
  VICVectAddr = 0;                             												// Acknowledge Interrupt
}

/* Setup the Timer Counter 0 Interrupt */
void init_timer (void) {
  T0MR0 = 149999;                              // 10mSec = 150.000-1 counts
  T0MCR = 3;                                   // Interrupt and Reset on MR0
  T0TCR = 1;                                   // Timer0 Enable
  VICVectAddr0 = (unsigned long)tc0;           // set interrupt vector in 0
  VICVectCntl0 = 0x20 | 4;                     // use it for Timer 0 Interrupt
  VICIntEnable = 0x00000010;                   // Enable Timer0 Interrupt
}
