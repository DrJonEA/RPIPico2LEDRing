# RPIPico2LEDRing
Demo Project with a WS2812B LED Ring of 24 pixels.

![LED Ring](images/GreenDial.jpg "LED Ring")

This project is built to support my YouTube channel [DrJonEA](https://youtube.com/@drjonea) and is an extension of project tutorials provided in full on my Udemy course [Pico Micro Projects in C++](https://www.udemy.com/course/rpi-pico-microprojects-c1/?referralCode=2F48111FD8290C72D4C7).

This project is design for a Raspberry Pi Pico 2.

## Connection
A WS2812B LED Ring of 24 pixels is connected via a 470ohm resistor to GPIO 18 on the Pico.  I run my LED ring at 5Volts which means I also put this through a signal level shifter to go from the 3.3v to 5volts.

The LED ring I provide power and ground directly from the Pico VBUS and GND, VBUS being 5Volts from the USB cable. I also use a 1,000uF capacitor across the LED ring as the jump in current draw can brown out the Pico.

## Clone and build
Clone the repo using the command *git clone --recurse-submodules* as I have used submodule libraries for the management of the LED ring.

To build using the Raspberry Pi Pico SDK use the commands:
```
mkdir build
cd build
cmake ..
make 
```

On Windows you may wish to uswe ninja instead of make. Depends how your tool chain is setup.
