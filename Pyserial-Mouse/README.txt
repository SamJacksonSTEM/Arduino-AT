This is my first attempt at building a gyroscope controlled mouse using an Arduino Uno. This is inspired by a similar piece of assistive technology.

Arduino has an existing Mouse.h library, but it only works for other Arduino models (and we have an abundance of Unos).

I am adapting Prabeen Raj's work: https://github.com/Prabeen-Raj/Arduino-UNO-Mouse/tree/main

Right now I've set up the protocol for controlling the computer mouse using arduino uno and combined this with the Adafruit 10-DOF sensor's gyroscope.

Next steps:

    Improving the python serial read algorithm to read data faster
    Tune the gyroscope mouse control to be more precise/faster. Also make right/left control even (right now it's harder to move the mouse right, something to do with the sensor)
    Adding error handling
    Resolution adaptation
    .exe file / easy install

