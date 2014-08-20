#What is it?
It's a tiny Arduino program, specifically for the [MicroView](https://www.sparkfun.com/products/12923) (of [Kickstarter fame](https://www.kickstarter.com/projects/1516846343/microview-chip-sized-arduino-with-built-in-oled-di)). It displays all 12 input pins and the states read on them. Think of it as a poor man's multimeter. It's as if you had an LED hooked up to every input pin and saw the LED light up whenever there's a signal. You can wire up the pins to your project, say on a breadboard, and toggle the inputs and see the results on the MicroView.

The code is super simple and is both a way for me to get playing with the MicroView itself as well as warm up to the API. Feel free to fork and modify, just respect the License please! (see below)

#What does it look like?
I'm glad you asked! Behold:

![MicroView displaying all input pin states](https://raw.githubusercontent.com/galaktor/microview_pins/master/preview.jpg)

The boxes correspond roughly to the pin located at the position on the MicroView. A filled box means a signal above 0 was read on the pin. An empty box means signal of 0. All pins are read as digital pins, even the analog pins below (the row has an 'A' indicating that they are analog, i.e. "A0", "A1" etc). If I can think of an easy way to visualize analog signals on confined space I might upgrade the analog bit but for now, it's binary. 
Non-input pins are replaced with a character that matches the pin's purpose as per the [MicroView overview page](http://learn.microview.io/intro/general-overview-of-microview.html):

* 'V' = 'VIN' (MV pin 16)
* '+' = '+5V' (MV pin 15)
* '-' = 'GND' (MV pin  8)
* 'R' = 'RST' (MV pin  1)

(Note that in this picture, the pins are dangling so the values are random.)

The input signals are polled every 50 microseconds, which was not chosen with much thought and can be easily changed in the code (look for the delay() call in the loop() function).

#License
The source code is licensed under the GPL v3 license. See LICENSE and COPYRIGHT files.
