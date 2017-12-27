//steppermotor interface to run in anticlockwise direction 

#include <LPC21xx.h>

int main(void)
{
	unsigned long int i;    
	PINSEL0 = 0x00000000;   // Pin select Register 0 Enable for GPIO Port 0
	PINSEL1 = 0x00000000;   // Pin select Register 1 Enable for GPIO Port 1
	IODIR0 = 0x00007400;    // Directing PORT 0 pin 14 to 11 as out                                                                      put
	IODIR1 = 0xFEFFFFFF;   // Directing PORT 1 pin 24 as input switch
	
	while(1)              // Condition is always true
	{
//	if(IOPIN1^0x01000000) //if switch Pressed anticlockwise direction
//	{
		for(i=0;i<100;i++)
		{
	IOSET0= 0x00002400;	 //Setting port 0 for the sequence of 0101 
	for(i=0;i<10000;i++);  // For Delay 
	IOCLR0= 0x00002400;
	IOSET0= 0x00004400;	 //Setting port 0 for the sequence of 1001
	for(i=0;i<10000;i++);
	IOCLR0= 0x00004400;
	IOSET0= 0x00005000;	 //Setting port 0 for the sequence of 1010
	for(i=0;i<10000;i++);
	IOCLR0= 0x00005000;
	IOSET0= 0x00003000;	 //Setting port 0 for the sequence of 0110
	for(i=0;i<10000;i++);
	IOCLR0= 0x00003000;
		}
//	else			 //clockwise direction
//	{
		for(i=0;i<100;i++)
		{
	IOSET0= 0x00002400;         //Setting port 0 for the sequence of 0101 
	for(i=0;i<10000;i++);
	IOCLR0= 0x00002400;    // Clearing the port 0 from the sequence
	IOSET0= 0x00003000;	    //Setting port 0 for the sequence of 0110
	for(i=0;i<10000;i++);
	IOCLR0= 0x00003000;    // Clearing the port 0 from the sequence
	IOSET0= 0x00005000;  	    //Setting port 0 for the sequence of 1010
	for(i=0;i<10000;i++);
	IOCLR0= 0x00005000;    // Clearing the port 0 from the sequence
	IOSET0= 0x00004400;	    //Setting port 0 for the sequence of 1001
	for(i=0;i<10000;i++);
	IOCLR0= 0x00004400;	// Clearing the port 0 from the sequence 
	}
	}
}








 
