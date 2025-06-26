/*
 * TriTurn.h
 *
 * A WS2812B LEd ring animation of three pixels rotating clockwise at third itervals
 *
 *  Created on: 15 Jun 2022
 *      Author: jondurrant
 */

#ifndef WS2812B_ANIMATIONS_SRC_TRITURN_H_
#define WS2812B_ANIMATIONS_SRC_TRITURN_H_

#include "RingAnimation.h"

class TriTurn : public RingAnimation{
public:
	/***
	 * Default constructor
	 * SetStrip must be called after this
	 */
	TriTurn();

	/***
	 * Construct the object
	 * @param strip - PicoLed strip object
	 * @param length - number of RGB LED in strip
	 * @param colour - colour to use for the animation
	 * @param stepMS - time in milliseconds between each step of animation
	 */
	TriTurn(
			PicoLed::PicoLedController *strip,
			uint8_t length,
			PicoLed::Color colour,
			uint16_t stepMS);

	/***
	 * Destructor
	 */
	virtual ~TriTurn();

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
};

#endif /* WS2812B_ANIMATIONS_SRC_TRITURN_H_ */
