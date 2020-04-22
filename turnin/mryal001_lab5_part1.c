/*	Author: Mayur Ryali
 *  Partner(s) Name: 
 *	Lab Section: 21
 *	Assignment: Lab #5  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif
_A
/*
unsigned char getBit(unsigned char val, unsigned char k) {
	return ((val & (0x01 << k)) != 0); //bit logic AND each bit and see if the bit is a 1 or 0 and return
}
*/


int main(void) {
	DDRA = 0x00; PORTA = 0xFF; //input
	DDRC = 0xFF; PORTC = 0x00; //output

	unsigned char tempA = 0x00; //temp val for A
	unsigned char tempC = 0x00; //temp val for C
    	
	while (1) {
		tempA = ~PINA & 0x0F; //only need bottom set of pins. Negated to account for pull-up mode

		if (tempA == 1 || tempA == 2) {
			tempC = 0x20; // PC5
			tempC = tempC | 0x40; //low fuel (PC6)
		}
		else if (tempA == 3 || tempA == 4) {
			tempC = 0x30; // PC5-PC4
			tempC = tempC | 0x40; //low fuel (PC6)
		}
		else if (tempA == 5 || tempA == 6) {
			tempC = 0x38; // PC5-PC3
		}
		else if (tempA >= 7 && tempA <= 9) {
			tempC = 0x3C; // PC5 - PC2
		}
		else if (tempA >= 10 && tempA <= 12) {
			tempC = 0x3E; // PC5 - PC1
		}
		else if (tempA >= 13 && tempA <= 15) {
			tempC = 0x3F; // PC5 - PC0
		}
		else {
			tempC = 0x00;
			tempC = tempC | 0x40; // low fuel
		}

		PORTC = tempC; //set PORTC to tempC
   	}
	return 1;
}
