/*	Author: Mayur Ryali
 *  Partner(s) Name: 
 *	Lab Section: 21
 *	Assignment: Lab #5  Exercise #3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum States{Start, Initial, Off, Push1, Push2, Push3, Wait, Release} state;

unsigned char button;
unsigned char tempC = 0x00;
unsigned char count = 0x00;


void Tick () {
	switch(state) {
		case Start:
			state = Initial;
			break;
		case : Initial
			if (button) {
				state = wait;	
			}
			else {
				state = Off;
			}
			break;
		case Wait:	
			if (!button) {
				count++;
				state = Release;
			}
			else {
				state = wait;
			}
			break;
		case Release:
			if (button) {
				if (count == 1) {
					state = Push1;
				}
				else if (count == 2) {
					state = Push2;
				}
				else if (count == 3) {
					state = Push3;
				}
				else if (count == 4) {
					state = Push4;
				}
				else if (count == 5) {
					state = Off;
				}
				else {
					state = Initial;
				}
			}
			else {
				state = Release;
			}
			break;
		case Push1:
			if (button) {
				state = wait;
			}
			else {
				state = Push1;
			}
			break;
		case Push2:if (button) {
                                state = wait;
                        }
                        else {
                                state = Push2;
                        }
                        break;
		case Push3:
			if (button) {
                                state = wait;
                        }
                        else {
                                state = Push3;
                        }
                        break;
		case Push4:
			if (button) {
                                state = wait;
                        }
                        else {
                                state = Push4;
                        }
                        break;
		case Off:
			if (button) {
                                state = wait;
                        }
                        else {
                                state = Off;
                        }
                        break;
		default: 
			state = Start;
			break;

	}

	switch (state) {
		case Start:
			break;
		case Initial:
			tempC = 0x7F;
			break;
		case Wait:
			break;
		case Release:
			break;
		case Push1:
			tempC = 0x41;
			break;
		case Push2:
			tempC = 0x22;
			break;
		case Push3:
			tempC = 0x14;
			break;
		case Push4:
			tempC = 0x08;
			break;
		case Off:
			tempC = 0x00;
			break;
		default:
			break;
	}
}




int main(void) {
	DDRA = 0x00; PORTA = 0xFF; //input
    	DDRB = 0xFF; PORTB = 0x00; //output

    	count = 0x00;

    	while (1) {
	    	button = PINA & 0x01;
	    	Tick();
	    	PORTC = tempC;
    	}
    	return 1;
}
