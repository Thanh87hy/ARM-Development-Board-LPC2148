#include <LPC21xx.h>
#include "seven_segment.h"
#include "timer.h"


/*	Function declaration	*/
void extract_digits(unsigned int number);

/*	Global variables	*/
uint8_t counter_digits[4];																			

/*	Main loop;execution starts here	*/
int main() {
	unsigned int count=0;																											// Counter variable to display on seven segment
	configurePins_7seg();																											//Configure hardware pins to be used by seven segment display
  init_timer();																															//Initialise timer settings, and interrupt
	
	//Infinite loop
	while(1) {
		extract_digits(count);																									//Extract digits of count variable
		count++;																																//Increment counter variable
		delay1(1000);																														//so that counter increments can be perceived
	}	
}

/*	Delay routine;gives an approximate delay in milliseconds	*/
void delay1(int d)           // delay routine
{  
	int i;
    while(d)                        
    {	
			for(i=0;i<7000;i++);	     
        d--;
    }
}

/*	Function to extract individual digits of number;thousand, hundreds, tens, ones	*/
void extract_digits(unsigned int number)
{
		uint8_t digit;																												// Buffer variable to do calculation
		digit = number / 1000u ;            																 // extract thousands digit
    counter_digits[3] = digit;        																	// and store it to  array
    digit = (number / 100u) % 10u;     																	 // extract hundreds digit
    counter_digits[2] = digit;        																	// and store it to  array
    digit = (number / 10u) % 10u;        																// extract tens digit
    counter_digits[1] = digit;       																	 // and store it to  array
    digit = number % 10u;                																// extract ones digit
    counter_digits[0] =digit;            															 // and store it to  array

}


