/*
 * DialUpDown.h
 * WS2812B Ring animation to dial up the number of lit LED to max and then
 * dial back down to one.
 *
 *  Created on: 15 Jun 2022
 *      Author: jondurrant
 */

#ifndef WS2812B_ANIMATIONS_SRC_DIALUPDOWN_H_
#define WS2812B_ANIMATIONS_SRC_DIALUPDOWN_H_

#include "RingAnimation.h"

class DialUpDown : public RingAnimation{
public:
	/***
	 * Default constructor
	 * SetStrip must be called after this
	 */
	DialUpDown();

	/***
	 * Construct the object
	 * @param strip - PicoLed strip object
	 * @param length - number of RGB LED in strip
	 * @param colour - colour to use for the animation
	 * @param stepMS - time in milliseconds between each step of animation
	 */
	DialUpDown(
			PicoLed::PicoLedController *strip,
			uint8_t length,
			PicoLed::Color colour,
			uint16_t stepMS);

	/***
	 * Destructor
	 */
	virtual ~DialUpDown();

	/***
	 * Reset animation to start position
	 */
	virtual void reset();

protected:
	/***
	 * Perform step of animation
	 */
	virtual void step();

private:

	//Step count
	uint8_t xStep = 0;

	//Direction
	bool xUp = true;
};

#endif /* WS2812B_ANIMATIONS_SRC_DIALUPDOWN_H_ */
