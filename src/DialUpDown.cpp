/*
 * DialUpDown.cpp
 *
 *  Created on: 15 Jun 2022
 *      Author: jondurrant
 */

#include "DialUpDown.h"

/***
 * Default constructor
 * SetStrip must be called after this
 */
DialUpDown::DialUpDown() : RingAnimation() {
	// NOP

}

/***
 * Construct the object
 * @param strip - PicoLed strip object
 * @param length - number of RGB LED in strip
 * @param colour - colour to use for the animation
 * @param stepMS - time in milliseconds between each step of animation
 */
DialUpDown::DialUpDown(
	PicoLed::PicoLedController *strip,
	uint8_t length,
	PicoLed::Color colour,
	uint16_t stepMS):
	RingAnimation(strip, length, colour, stepMS){
	//NOP
}

/***
 * Destructor
 */
DialUpDown::~DialUpDown() {
	// NOP
}

/***
 * Perform step of animation
 */
void DialUpDown::step(){
	//If step has reached end restart
	if (xStep >= xLength){
		xUp = false;
		xStep = xLength -2;
	}
	if (xStep == 0){
		xUp = true;
	}

	//Only animate if we have a strip
	if (pStrip != NULL){
		pStrip->clear();
		for (uint8_t i =0; i <= xStep; i++){
			pStrip->setPixelColor(i, xColour);
		}
		pStrip->show();
	}
	if (xUp){
		xStep++;
	} else {
		xStep--;
	}
}

/***
 * Reset animation to start position
 */
void DialUpDown::reset(){
	RingAnimation::reset();
	xStep = 0;
}
