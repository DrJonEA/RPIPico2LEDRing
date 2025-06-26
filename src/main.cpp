/*
 * main.cpp
 * Drive 12 WB2812B on GP15
 * Produce a chaser pattern
 *
 *  Created on: 15 Jun 2021
 *      Author: jondurrant
 */


#include "pico/stdlib.h"
#include <stdexcept>

#include <PicoLed.hpp>
#include "RingAnimation.h"
#include "RingChaser.h"
#include "TriTurn.h"
#include "DialUpDown.h"

#define LEDS_PIN 18
#define LEDS_LENGTH 24




int main(){

	stdio_init_all();

    // Initialize LED strip
	auto ledStrip = PicoLed::addLeds<PicoLed::WS2812B>(pio0, 0, LEDS_PIN, LEDS_LENGTH, PicoLed::FORMAT_GRB);

	//Keep brightness down as we are running at 3.3v
	ledStrip.setBrightness(64);

	// Initialise the LED to all off
	ledStrip.fill( PicoLed::RGB(0x00, 0x00, 0x00 ));
	ledStrip.show();
	sleep_ms(2000);

	// Set the chaser colour
	PicoLed::Color c = PicoLed::RGB(0xFF, 0, 0);

	//Create demo list
	const uint8_t demoCount = 3;
	RingAnimation * demo[3];
	demo[0] =  new RingChaser(
			&ledStrip,
			LEDS_LENGTH,
			c,
			100);

	c = PicoLed::RGB(0x00, 0x00, 0xFF);
	demo[1] =  new TriTurn(
				&ledStrip,
				LEDS_LENGTH,
				c,
				100);

	c = PicoLed::RGB(0x00, 0xFF, 0x00);
		demo[2] =  new DialUpDown(
					&ledStrip,
					LEDS_LENGTH,
					c,
					100);


	// Forever loop calling poll
	uint8_t demoNum = 0;

	uint32_t demoStart = to_ms_since_boot (get_absolute_time ());
	while(true){
		uint32_t now = to_ms_since_boot (get_absolute_time ());
		if ((now - demoStart) > 5000){
			demoStart = now;
			demoNum ++;

			if (demoNum >= demoCount){
				demoNum = 0;
			}
			demo[demoNum]->reset();
		}
		demo[demoNum]->poll();
	}

}
