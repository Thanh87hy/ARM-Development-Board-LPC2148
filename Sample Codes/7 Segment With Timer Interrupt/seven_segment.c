#include <LPC21xx.h>
#include "seven_segment.h"


uint32_t buffer_32bit;																								//To store 32 bit register values temporarily

/*	Function to display given segment_value on the display unit channel_no; other display units get DISABLED	*/
void seven_segment_put(uint8_t channel_no, uint8_t segment_value) {
	switch(channel_no) {
		case 0:
			IO0PIN |= ((0xFF)<<CONTROL_LINES);																			//Off All Displays
			buffer_32bit = IO0PIN;																									//Stored in buffer for future calculation
			IO0PIN &= ((0xFFFFFFFE)<<CONTROL_LINES);																//Selecting Display 0
			buffer_32bit &= ((ALL_BITS_HIGH)>>(PORT_ZERO_WIDTH-CONTROL_LINES));			//To cancel the side effects of AND op on other bits
			IO0PIN |= (buffer_32bit);																								//To cancel the side effects of AND op on other bits
			break;
		case 1:
			IO0PIN |= ((0xFF)<<CONTROL_LINES);																			//Off All Displays
			buffer_32bit = IO0PIN;																									//Stored in buffer for future calculation
			IO0PIN &= ((0xFFFFFFFD)<<CONTROL_LINES);																//Selecting Display 2
			buffer_32bit &= ((ALL_BITS_HIGH)>>(PORT_ZERO_WIDTH-CONTROL_LINES));			//To cancel the side effects of AND op on other bits
			IO0PIN |= (buffer_32bit);																								//To cancel the side effects of AND op on other bits
			break;
		case 2:
			IO0PIN |= ((0xFF)<<CONTROL_LINES);																			//Off All Displays
			buffer_32bit = IO0PIN;																									//Stored in buffer for future calculation
			IO0PIN &= ((0xFFFFFFFB)<<CONTROL_LINES);																//Selecting Display 3
			buffer_32bit &= ((ALL_BITS_HIGH)>>(PORT_ZERO_WIDTH-CONTROL_LINES));			//To cancel the side effects of AND op on other bits
			IO0PIN |= (buffer_32bit);																								//To cancel the side effects of AND op on other bits
			break;
		case 3:
			IO0PIN |= ((0xFF)<<CONTROL_LINES);																			//Off All Displays
			buffer_32bit = IO0PIN;																									//Stored in buffer for future calculation
			IO0PIN &= ((0xFFFFFFF7)<<CONTROL_LINES);																//Selecting Display 4
			buffer_32bit &= ((ALL_BITS_HIGH)>>(PORT_ZERO_WIDTH-CONTROL_LINES));			//To cancel the side effects of AND op on other bits
			IO0PIN |= (buffer_32bit);																								//To cancel the side effects of AND op on other bits
			break;		
	}
	switch(segment_value) {
		case 0:
			IO0PIN |= ((0xFF)<<DATA_LINES);																					//Off All segments
			buffer_32bit = IO0PIN;
			IO0PIN &= ((0xFFFFFF40)<<DATA_LINES);						             						//Write '0'
			buffer_32bit &= ((ALL_BITS_HIGH)>>(PORT_ZERO_WIDTH-DATA_LINES));				//To cancel the side effects of AND op on other bits
			IO0PIN |= (buffer_32bit);																								//To cancel the side effects of AND op on other bits
			break;
		case 1:
			IO0PIN |= ((0xFF)<<DATA_LINES);																					//Off All segments
			buffer_32bit = IO0PIN;
			IO0PIN &= ((0xFFFFFF79)<<DATA_LINES);						             						//Write '1'
			buffer_32bit &= ((ALL_BITS_HIGH)>>(PORT_ZERO_WIDTH-DATA_LINES));				//To cancel the side effects of AND op on other bits
			IO0PIN |= (buffer_32bit);																								//To cancel the side effects of AND op on other bits
			break;
		case 2:
			IO0PIN |= ((0xFF)<<DATA_LINES);																					//Off All segments
			buffer_32bit = IO0PIN;
			IO0PIN &= ((0xFFFFFF24)<<DATA_LINES);						             						//Write '2'
			buffer_32bit &= ((ALL_BITS_HIGH)>>(PORT_ZERO_WIDTH-DATA_LINES));				//To cancel the side effects of AND op on other bits
			IO0PIN |= (buffer_32bit);																								//To cancel the side effects of AND op on other bits
			break;
		case 3:
			IO0PIN |= ((0xFF)<<DATA_LINES);																					//Off All segments
			buffer_32bit = IO0PIN;
			IO0PIN &= ((0xFFFFFF30)<<DATA_LINES);						             						//Write '3'
			buffer_32bit &= ((ALL_BITS_HIGH)>>(PORT_ZERO_WIDTH-DATA_LINES));				//To cancel the side effects of AND op on other bits
			IO0PIN |= (buffer_32bit);																								//To cancel the side effects of AND op on other bits
			break;
		case 4:
			IO0PIN |= ((0xFF)<<DATA_LINES);																					//Off All segments
			buffer_32bit = IO0PIN;
			IO0PIN &= ((0xFFFFFF19)<<DATA_LINES);						             						//Write '4'
			buffer_32bit &= ((ALL_BITS_HIGH)>>(PORT_ZERO_WIDTH-DATA_LINES));				//To cancel the side effects of AND op on other bits
			IO0PIN |= (buffer_32bit);																								//To cancel the side effects of AND op on other bits
			break;
		case 5:
			IO0PIN |= ((0xFF)<<DATA_LINES);																					//Off All segments
			buffer_32bit = IO0PIN;
			IO0PIN &= ((0xFFFFFF12)<<DATA_LINES);						             						//Write '5'
			buffer_32bit &= ((ALL_BITS_HIGH)>>(PORT_ZERO_WIDTH-DATA_LINES));				//To cancel the side effects of AND op on other bits
			IO0PIN |= (buffer_32bit);																								//To cancel the side effects of AND op on other bits
			break;
		case 6:
			IO0PIN |= ((0xFF)<<DATA_LINES);																					//Off All segments
			buffer_32bit = IO0PIN;
			IO0PIN &= ((0xFFFFFF02)<<DATA_LINES);						             						//Write '6'
			buffer_32bit &= ((ALL_BITS_HIGH)>>(PORT_ZERO_WIDTH-DATA_LINES));				//To cancel the side effects of AND op on other bits
			IO0PIN |= (buffer_32bit);																								//To cancel the side effects of AND op on other bits
			break;
		case 7:
			IO0PIN |= ((0xFF)<<DATA_LINES);																					//Off All segments
			buffer_32bit = IO0PIN;
			IO0PIN &= ((0xFFFFFF78)<<DATA_LINES);						             						//Write '7'
			buffer_32bit &= ((ALL_BITS_HIGH)>>(PORT_ZERO_WIDTH-DATA_LINES));				//To cancel the side effects of AND op on other bits
			IO0PIN |= (buffer_32bit);																								//To cancel the side effects of AND op on other bits
			break;
		case 8:
			IO0PIN |= ((0xFF)<<DATA_LINES);																					//Off All segments
			buffer_32bit = IO0PIN;
			IO0PIN &= ((0xFFFFFF00)<<DATA_LINES);						             						//Write '8'
			buffer_32bit &= ((ALL_BITS_HIGH)>>(PORT_ZERO_WIDTH-DATA_LINES));				//To cancel the side effects of AND op on other bits
			IO0PIN |= (buffer_32bit);																								//To cancel the side effects of AND op on other bits
			break;
		case 9:
			IO0PIN |= ((0xFF)<<DATA_LINES);																					//Off All segments
			buffer_32bit = IO0PIN;
			IO0PIN &= ((0xFFFFFF18)<<DATA_LINES);						             						//Write '9'
			buffer_32bit &= ((ALL_BITS_HIGH)>>(PORT_ZERO_WIDTH-DATA_LINES));				//To cancel the side effects of AND op on other bits
			IO0PIN |= (buffer_32bit);																								//To cancel the side effects of AND op on other bits
			break;
	}
}

/*	Function to Configure hardware pins to be used by seven segment display	*/
void configurePins_7seg(void) {
	IO0DIR = ALL_BITS_LOW;											//All pins of PORT0 as INPUT
	IO0DIR = ((0xFF))<<DATA_LINES;							//0.16-0.23 OUTPUT; DATA LINES
	IO0DIR |= ((0x0F))<<CONTROL_LINES;					//0.4-0.7		OUTPUT; CONTROL LINES

	IO0PIN = ALL_BITS_HIGH;											//OFF All displays
	IO0PIN = 0XFFFFFFFF;
}

/*	Optional Function; can be used to test the functionality of the 7 segment display units	*/
void check_functionality(void) {
	  buffer_32bit = IO0PIN;																									//Stored in buffer for future calculation
		IO0PIN &= ((0xFFFFFFFE)<<CONTROL_LINES);																//Selecting Display 1
		buffer_32bit &= ((ALL_BITS_HIGH)>>(PORT_ZERO_WIDTH-CONTROL_LINES));			//To cancel the side effects of AND op on other bits
		IO0PIN |= (buffer_32bit);																								//To cancel the side effects of AND op on other bits

		IO0PIN |= ((0xFF)<<DATA_LINES);																					//Off All segments
		buffer_32bit = IO0PIN;
		IO0PIN &= ((0xFFFFFF79)<<DATA_LINES);						             						//Write '1'
		buffer_32bit &= ((ALL_BITS_HIGH)>>(PORT_ZERO_WIDTH-DATA_LINES));				//To cancel the side effects of AND op on other bits
		IO0PIN |= (buffer_32bit);
		delay1(1000);
		
		
		
		buffer_32bit = IO0PIN;																									//Stored in buffer for future calculation
		IO0PIN &= ((0xFFFFFFFD)<<CONTROL_LINES);																//Selecting Display 2
		buffer_32bit &= ((ALL_BITS_HIGH)>>(PORT_ZERO_WIDTH-CONTROL_LINES));			//To cancel the side effects of AND op on other bits
		IO0PIN |= (buffer_32bit);																								//To cancel the side effects of AND op on other bits

		IO0PIN |= ((0xFF)<<DATA_LINES);																					//Off All segments
		buffer_32bit = IO0PIN;
		IO0PIN &= ((0xFFFFFF24)<<DATA_LINES);						             						//Write '2'
		buffer_32bit &= ((ALL_BITS_HIGH)>>(PORT_ZERO_WIDTH-DATA_LINES));				//To cancel the side effects of AND op on other bits
		IO0PIN |= (buffer_32bit);
		delay1(1000);
		
		
		buffer_32bit = IO0PIN;																									//Stored in buffer for future calculation
		IO0PIN &= ((0xFFFFFFFB)<<CONTROL_LINES);																//Selecting Display 3
		buffer_32bit &= ((ALL_BITS_HIGH)>>(PORT_ZERO_WIDTH-CONTROL_LINES));			//To cancel the side effects of AND op on other bits
		IO0PIN |= (buffer_32bit);																								//To cancel the side effects of AND op on other bits

		IO0PIN |= ((0xFF)<<DATA_LINES);																					//Off All segments
		buffer_32bit = IO0PIN;
		IO0PIN &= ((0xFFFFFF30)<<DATA_LINES);						             						//Write '3'
		buffer_32bit &= ((ALL_BITS_HIGH)>>(PORT_ZERO_WIDTH-DATA_LINES));				//To cancel the side effects of AND op on other bits
		IO0PIN |= (buffer_32bit);
		delay1(1000);
		
		
		buffer_32bit = IO0PIN;																									//Stored in buffer for future calculation
		IO0PIN &= ((0xFFFFFFF7)<<CONTROL_LINES);																//Selecting Display 4
		buffer_32bit &= ((ALL_BITS_HIGH)>>(PORT_ZERO_WIDTH-CONTROL_LINES));			//To cancel the side effects of AND op on other bits
		IO0PIN |= (buffer_32bit);																								//To cancel the side effects of AND op on other bits

		IO0PIN |= ((0xFF)<<DATA_LINES);																					//Off All segments
		buffer_32bit = IO0PIN;
		IO0PIN &= ((0xFFFFFF19)<<DATA_LINES);						             						//Write '4'
		buffer_32bit &= ((ALL_BITS_HIGH)>>(PORT_ZERO_WIDTH-DATA_LINES));				//To cancel the side effects of AND op on other bits
		IO0PIN |= (buffer_32bit);
		delay1(1000);
}
