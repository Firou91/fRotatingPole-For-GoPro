<div align='center'><img style="height: 220px; margin: 0 auto" src='https://media.discordapp.net/attachments/1083813324422135859/1108096402019602463/IMG_0424_2.jpg?width=605&height=605'/></div>

# Config

Refer to the 'config.h' setting your config.
Content:
```h
// Number of buttons
#define NUM_BUTTONS 2

// Anti-bounce delay for buttons (in milliseconds)Délai anti-rebond pour les boutons (en millisecondes)
#define BUTTON_DEBOUNCE_DELAY 50

// Minimum and maximum value of the readings of the analog buttons
#define MIN_VAL 0
#define MAX_VAL 1023

// Button pins
const int buttonPins[NUM_BUTTONS] = {A0, A1};

// LED pin
const int ledPin = 13;

// Button states
int buttonState[NUM_BUTTONS] = {HIGH, HIGH};
int lastButtonState[NUM_BUTTONS] = {HIGH, HIGH};
unsigned long lastDebounceTime[NUM_BUTTONS] = {0, 0};

// Rotation priority (0: X axis, 1: Y axis)
int rotationPriority = 0;

// Motor control spindles for X and Y axes
const int motorXPin1 = 2;
const int motorXPin2 = 3;
const int motorYPin1 = 4;
const int motorYPin2 = 5;

// Motor speed variables
float speedX = 0;
float speedY = 0;

// Maximum rotation speed (in rotations per minute)
const float maxSpeedX = 1.0;
const float maxSpeedY = 1.0;
```

# Features

### Configurable file

- 
- 

### Real-time information in the Arduino IDE terminal

- 
- 

# Flowchart

Here is the flowchart at the following link: [Click here](https://lucid.app/lucidchart/89dfd381-6f20-4bba-bf32-a55033619b30/edit?viewport_loc=-11%2C-11%2C2219%2C1065%2C0_0&invitationId=inv_87d8bdc8-cb0e-48af-9632-bbdfbf632f1d)

<table><tr><td><h3 align='center'>Legal Notices</h2></tr></td>
<tr><td>
MIT License
Copyright (c) 2023 Firou91

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
</td></tr></table>
