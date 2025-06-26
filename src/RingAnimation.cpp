/*
 * RingAnimation.cpp
 *
 *  Created on: 15 Jun 2022
 *      Author: jondurrant
 */

#include "RingAnimation.h"
#include <stdlib.h>
#include "pico/stdlib.h"

#include <stdio.h>

/***
 * Default constructor
 * SetStrip must be called after this
 */
RingAnimation::RingAnimation() {
	xLastStep = to_ms_since_boot (get_absolute_time ());
}

/***
 * Construct the Ring object
 * @param strip - PicoLed strip object
 * @param length - number of RGB LED in strip
 * @param colour - colour to use for the animation
 * @param stepMS - time in milliseconds between each step of animation
 */
RingAnimation::RingAnimation(
		PicoLed::PicoLedController *strip,
		uint8_t length,
		PicoLed::Color colour,
		uint16_t stepMS) {
	setStrip(strip, length);
	setStepMS(stepMS);
	setColour(colour);
	xLastStep = to_ms_since_boot (get_absolute_time ());
}

/***
 * Destructor
 */
RingAnimation::~RingAnimation() {
	// NOP
}


/***
 * Set the LED strip to use
 * @param strip - PicoLed strip object
 * @param length - number of RGB LED in strip
 */
void RingAnimation::setStrip(PicoLed::PicoLedController *strip, uint8_t length){
	pStrip  = strip;
	xLength = length;
}

/***
 * Set the time in milliseconds between each step of the animation
 * @param stepMS
 */
void RingAnimation::setStepMS(uint16_t stepMS){
	xStepMS = stepMS;
}

/***
 * Called to check if a step is required in the animation and to perform
 * that step
 */
void RingAnimation::poll(){
	uint32_t now = to_ms_since_boot (get_absolute_time ());
	uint32_t sinceStep = now - xLastStep;
	uint32_t stepsDue = sinceStep / xStepMS;

	if (stepsDue > 0){
		for (uint32_t i = 0; i < stepsDue; i++){
			step();
		}
		xLastStep = now;
	}
}

/***
 * Set the base colour to use for the animation
 * @param colour
 */
void RingAnimation::setColour(PicoLed::Color colour){
	xColour = colour;
}

/***
 * Reset animation to start position
 */
void RingAnimation::reset(){
	xLastStep = to_ms_since_boot (get_absolute_time ());
}
