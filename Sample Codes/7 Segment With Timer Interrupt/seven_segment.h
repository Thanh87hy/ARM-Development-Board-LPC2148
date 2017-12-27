#ifndef SEVEN_SEGMENT_H
#define SEVEN_SEGMENT_H

#include <stdint.h>

#define DATA_LINES 16
#define DATA_WIDTH 8
#define CONTROL_LINES 4
#define CONTROL_WIDTH 4
#define PORT_ZERO_WIDTH 32
#define ALL_BITS_HIGH 0xFFFFFFFF
#define ALL_BITS_LOW 0x00000000

/*	Function Declarations	*/
void configurePins_7seg(void);
void delay1(int d);
void check_functionality(void);
void seven_segment_put(uint8_t channel_no, uint8_t segment_value);

#endif //SEVEN_SEGMENT_H
