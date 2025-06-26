/*
 * RingAnimation.h
 *
 * Ring animation abstract class
 *
 *  Created on: 15 Jun 2022
 *      Author: jondurrant
 */

#ifndef WS2812B_RINGANIMATION_SRC_RINGANIMATION_H_
#define WS2812B_RINGANIMATION_SRC_RINGANIMATION_H_

#include <PicoLed.hpp>

class RingAnimation {
public:
	/***
	 * Default constructor
	 * SetStrip must be called after this
	 */
	RingAnimation();

	/***
	 * Construct the Ring object
	 * @param strip - PicoLed strip object
	 * @param length - number of RGB LED in strip
	 * @param colour - colour to use for the animation
	 * @param stepMS - time in milliseconds between each step of animation
	 */
	RingAnimation(
			PicoLed::PicoLedController *strip,
			uint8_t length,
			PicoLed::Color colour,
			uint16_t stepMS = 200);

	/***
	 * Destructor
	 */
	virtual ~RingAnimation();

	/***
	 * Set the LED strip to use
	 * @param strip - PicoLed strip object
	 * @param length - number of RGB LED in strip
	 */
	virtual void setStrip(PicoLed::PicoLedController *strip, uint8_t length);

	/***
	 * Set the time in milliseconds between each step of the animation
	 * @param stepMS
	 */
	virtual void setStepMS(uint16_t stepMS);

	/***
	 * Set the base colour to use for the animation
	 * @param colour
	 */
	virtual void setColour(PicoLed::Color colour);

	/***
	 * Called to check if a step is required in the animation and to perform
	 * that step
	 */
	virtual void poll();

	/***
	 * Reset animation to start position
	 */
	virtual void reset();
protected:
	/***
	 * Perform a step in the animation
	 * Abstract function to be provided by child classes
	 */
	virtual void step()=0;

	// LED Strip
	PicoLed::PicoLedController *pStrip = NULL;

	// Base colour for the animation
	PicoLed::Color xColour = PicoLed::RGB(255,255, 255);

	// length of strip
	uint8_t xLength = 0;

	// Time for each step of animation
	uint16_t xStepMS = 200;

	// Time since boot of the last animation step performed
	uint32_t xLastStep = 0;
};

#endif /* WS2812B_RINGANIMATION_SRC_RINGANIMATION_H_ */
