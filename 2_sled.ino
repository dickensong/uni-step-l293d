#include <DVD_Sled.h>

// Create Sled object called "XSled"
// 
// The Sled is controlled by an L293d Darlington bridge IC.
// It's a chip that's usually used to control a pair of DC 
// motors, but the bipolar coils in the DVD steppers can be
// thought of as individual DC motor coils themselves. If 
// you're scratching your noggin, don't worry. Here's how you
// wire it up.
//
// The L293d Darlington bridge is two identical circuits that
// run down each side of the chip. So the top right pin is the
// Top Enable pin, and the bottom left pin is the Bottom Enable
// pin. The "DC Motor" example in the Elegoo manuals explained 
// it real well; that's where I picked it up.
//
// The Top Negative and Positive go to the wires on the right-
// hand side of the DVD stepper. The Bottom Negative and Positive
// go to the Bottom Neg and Pos pins on the IC. 
// 
// I've only driven the steppers with 5V, but they may be able 
// to handle more. They're not particularly powerful, but teensy
// and cheap!
//
// Sled::Sled(int TopEnable, int BotEnable, int TopPos, int TopNeg, int BotPos, int BotNeg)
//
//

Sled XSled(11, 10, 13, 12, 8, 7);

// Define minimum and maximum step for XSled
int XMinPos = 0;
int XMaxPos = 980;
// Create tracker variables for XSled's position from 0 - 980 steps
int XPosition = 0;

// Also track XSled's speed and direction
int XDir = 1;
int XSpeed = 1;

// Delay between cycles (ms)
int StepDelay = 1;

void setup()
{
}

void loop()
{

//                                    Move back and forth based on Max and YMax
//                        Increase or decrease position tracker based on direction
XPosition = XPosition + (XDir * XSpeed);

//                                    If XSled's position is outside the defined boundaries, 
//                        change direction by multiplying by -1
if (XPosition > XMaxPos) {XDir = -1 * XDir;};
if (XPosition < XMinPos) {XDir = -1 * XDir;};

//                        Send number of steps (direction * speed) to XSled
XSled.Step(XDir * XSpeed);

delay(StepDelay);

}
