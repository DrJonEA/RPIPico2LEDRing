/*
 * RingChaser.cpp
 *
 *  Created on: 15 Jun 2022
 *      Author: jondurrant
 */

#include "RingChaser.h"

/***
 * Default constructor
 * SetStrip must be called after this
 */
RingChaser::RingChaser() : RingAnimation() {
	// NOP

}

/***
 * Construct the object
 * @param strip - PicoLed strip object
 * @param length - number of RGB LED in strip
 * @param colour - colour to use for the animation
 * @param stepMS - time in milliseconds between each step of animation
 */
RingChaser::RingChaser(
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
RingChaser::~RingChaser() {
	// NOP
}

/***
 * Perform step of animation
 */
void RingChaser::step(){
	//If step has reached end restart
	if (xStep >= xLength){
		xStep = 0;
	}

	//Only animate if we have a strip
	if (pStrip != NULL){
		pStrip->clear();
		pStrip->setPixelColor(xStep, xColour);
		pStrip->show();
	}
	xStep++;
}

/***
 * Reset animation to start position
 */
void RingChaser::reset(){
	RingAnimation::reset();
	xStep = 0;
}
