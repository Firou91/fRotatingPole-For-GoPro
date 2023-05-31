<div align='center'><img src='https://media.discordapp.net/attachments/1083813324422135859/1108130221867139072/Colors3.jpg'/></div>

# Config

Refer to the 'config.h' setting your config.
Content:
```h
// Broches A et B
const int PIN_VITESSE_MOTOR_X = 11;
const int PIN_SENS_MOTOR_X = 13;
const int PIN_VITESSE_MOTOR_Y = 3;
const int PIN_SENS_MOTOR_Y = 12;
// Boutons
const int PIN_BOUTON_SENS_1_MOTOR_X = 8; // Broche pour le bouton de sens 1 du Grove Dual Button
const int PIN_BOUTON_SENS_2_MOTOR_X = 7; // Broche pour le bouton de sens 2 du Grove Dual Button
const int PIN_BOUTON_SENS_1_MOTOR_Y = 5; // Broche pour le bouton de sens 1 du Grove Dual Button
const int PIN_BOUTON_SENS_2_MOTOR_Y = 6; // Broche pour le bouton de sens 2 du Grove Dual Button


// EN TEST

// Vitesse maximale de rotation (en rotations par minute)
const float maxSpeedX = 1.0; // Vitesse maximale de rotation axe X (You can change this value)
const float maxSpeedY = 1.0; // Vitesse maximale de rotation axe Y (You can change this value)
// Variables de vitesse des moteurs
int speedMotors = 300; // Vitesse des moteurs (c.f fiche technique moteur)
int RPM_MOTOR_X = (speedMotors / 255) * maxSpeedX; // Constante pour la vitesse moteur 1 (DO NOT TOUCH)
int RPM_MOTOR_Y = (speedMotors / 255) * maxSpeedY; // Constante pour la vitesse moteur 2 (DO NOT TOUCH)

// Angles de rotation
const float DEFAULT_ANGLE_X = 0.0; // Angle par défaut pour le moteur X
const float MIN_ANGLE_X = -90.0; // Angle minimal pour le moteur X
const float MAX_ANGLE_X = 90.0; // Angle maximal pour le moteur X
 // Angle par défaut pour le moteur Y
const float DEFAULT_ANGLE_Y = 0.0;
// Angle min/max pour le moteur Y
const float MIN_ANGLE_Y = -90.0; 
const float MAX_ANGLE_Y = 90.0;
// Angles actuels
float currentAngleX = DEFAULT_ANGLE_X;
float currentAngleY = DEFAULT_ANGLE_Y;

// Délai maximal (en ms) pour effectuer un double-clic
const int DOUBLE_CLIC_DELAY = 500; 
// Temps du dernier clic
unsigned long lastButtonClickTime = 0; 
bool isFirstButtonClick = true;
int rotaPriority = 1;
```

# Features

### Configurable file

- Steering angles
- Engine speed
- Double click motor selection

### Real-time information in the Arduino IDE terminal

If you don't have all the necessary equipment but at least have the Grove Dual Buttons, you can consult the information on your actions in real time in the standard monitor.

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
