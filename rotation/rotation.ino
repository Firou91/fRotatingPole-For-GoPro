
// ░██████╗░░█████╗░██████╗░██████╗░░█████╗░  ██████╗░░█████╗░████████╗░█████╗░████████╗██╗░█████╗░███╗░░██╗
// ██╔════╝░██╔══██╗██╔══██╗██╔══██╗██╔══██╗  ██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗╚══██╔══╝██║██╔══██╗████╗░██║
// ██║░░██╗░██║░░██║██████╔╝██████╔╝██║░░██║  ██████╔╝██║░░██║░░░██║░░░███████║░░░██║░░░██║██║░░██║██╔██╗██║
// ██║░░╚██╗██║░░██║██╔═══╝░██╔══██╗██║░░██║  ██╔══██╗██║░░██║░░░██║░░░██╔══██║░░░██║░░░██║██║░░██║██║╚████║
// ╚██████╔╝╚█████╔╝██║░░░░░██║░░██║╚█████╔╝  ██║░░██║╚█████╔╝░░░██║░░░██║░░██║░░░██║░░░██║╚█████╔╝██║░╚███║
// ░╚═════╝░░╚════╝░╚═╝░░░░░╚═╝░░╚═╝░╚════╝░  ╚═╝░░╚═╝░╚════╝░░░░╚═╝░░░╚═╝░░╚═╝░░░╚═╝░░░╚═╝░╚════╝░╚═╝░░╚══╝
// https://arduinogetstarted.com/tutorials/arduino-joystick?utm_content=cmp-true
// https://www.aranacorp.com/fr/utilisation-dun-joystick-avec-arduino/

// █▄▄ █▀█ █░█ ▀█▀ █▀█ █▄░█ █▀   █▀█ █▀█ █░█ █▀ █▀ █▀█ █ █▀█ █▀
// █▄█ █▄█ █▄█ ░█░ █▄█ █░▀█ ▄█   █▀▀ █▄█ █▄█ ▄█ ▄█ █▄█ █ █▀▄ ▄█

#include "config.h"

void setup() {
  // Initialize Serial USB
  Serial.begin(9600);
  Serial.println(F("Initialize System"));

  // Initialize Buttons
  for (int i = 0; i < NUM_BUTTONS; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }

  // Initialize Motor Control Pins
  pinMode(motorXPin1, OUTPUT);
  pinMode(motorXPin2, OUTPUT);
  pinMode(motorYPin1, OUTPUT);
  pinMode(motorYPin2, OUTPUT);

  // Initialize LED
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

void loop() {
  readButtons();
  controlCamera();
  displayStatus();
  delay(50);
}

void displayStatus() {
  // Display of the rotation priority
  Serial.print(F("Rotation Priority: "));
  if (rotationPriority == 0) {
    Serial.println(F("X-axis"));
  } else {
    Serial.println(F("Y-axis"));
  }

  // Display of the direction of the motor angles
  Serial.print(F("Angle Direction: "));
  int angleX = buttonState[0] == LOW ? 180 : 0;
  int angleY = buttonState[1] == LOW ? 360 : 0;
  Serial.print(F("X: "));
  Serial.print(angleX);
  Serial.print(F(", Y: "));
  Serial.println(angleY);

  // Display of the speed of rotation in real time of use
  Serial.print(F("Rotation Speed: "));
  Serial.print(F("X: "));
  Serial.print(speedX);
  Serial.print(F(" RPM, Y: "));
  Serial.print(speedY);
  Serial.println(F(" RPM"));

  Serial.println(F(""));
}

void readButtons() {
  for (int i = 0; i < NUM_BUTTONS; i++) {
    int reading = digitalRead(buttonPins[i]);

    if (reading != lastButtonState[i]) {
      lastDebounceTime[i] = millis();
    }

    if ((millis() - lastDebounceTime[i]) > BUTTON_DEBOUNCE_DELAY) {
      if (reading != buttonState[i]) {
        buttonState[i] = reading;

        if (buttonState[i] == LOW) {
          // Button pressed
          if (i == 0 && rotationPriority == 0) {
            // Double-click on first button to change rotation priority
            if ((millis() - lastDebounceTime[1]) <= BUTTON_DEBOUNCE_DELAY) {
              rotationPriority = 1; // Change to Y-axis rotation priority
              digitalWrite(ledPin, HIGH); // Turn on LED to indicate Y-axis priority
            }
          } else if (i == 1 && rotationPriority == 1) {
            // Double-click on second button to change rotation priority
            if ((millis() - lastDebounceTime[0]) <= BUTTON_DEBOUNCE_DELAY) {
              rotationPriority = 0; // Change to X-axis rotation priority
              digitalWrite(ledPin, LOW); // Turn off LED to indicate X-axis priority
            }
          }
        }
      }
    }

    lastButtonState[i] = reading;
  }
}

float joyRawToPhys(int raw) {
  float phys = map(raw, MIN_VAL, MAX_VAL, -100, 100);
  if (rotationPriority == 0) {
    // Convert raw joystick value to physical value for X-axis
    float phys = map(raw, MIN_VAL, MAX_VAL, -100, 100);
    return phys;
  } else {
    // Convert raw joystick value to physical value for Y-axis
    float phys = map(raw, MIN_VAL, MAX_VAL, 100, -100);
    return phys;
  }
}

void controlCamera() {
  // Read button states
  int buttonXState = buttonState[0];
  int buttonYState = buttonState[1];

  // Calculate rotation angles based on button states
  int angleX = buttonXState == LOW ? 180 : 0;
  int angleY = buttonYState == LOW ? 360 : 0;

  // Control X-axis motor
  if (angleX > 0) {
    digitalWrite(motorXPin1, HIGH);
    digitalWrite(motorXPin2, LOW);
    analogWrite(motorXPin2, map(angleX, 0, 180, 0, 255));
  } else {
    digitalWrite(motorXPin1, LOW);
    digitalWrite(motorXPin2, LOW);
  }

  // Control Y-axis motor
  if (angleY > 0) {
    digitalWrite(motorYPin1, HIGH);
    digitalWrite(motorYPin2, LOW);
    analogWrite(motorYPin2, map(angleY, 0, 360, 0, 255));
  } else {
    digitalWrite(motorYPin1, LOW);
    digitalWrite(motorYPin2, LOW);
  }
}


// ░░█ █▀█ █▄█ █▀ ▀█▀ █ █▀▀ █▄▀
// █▄█ █▄█ ░█░ ▄█ ░█░ █ █▄▄ █░█

// Les vitesses des moteurs sont converties en angles de rotation par seconde, puis 
// les limites de rotation sont appliquées.
// Les angles de rotation sont convertis en signaux de contrôle des moteurs en utilisant la 
// fonction map() pour les ajuster dans la plage appropriée (0-255) pour les signaux de PWM 
// (modulation de largeur d'impulsion) envoyés aux moteurs.

// Les signaux de contrôle sont envoyés aux broches de sortie correspondantes pour contrôler 
// les moteurs.
// Le code en boucle répète ensuite ces étapes en continu, ce qui permet de lire les valeurs 
// du joystick, de calculer les vitesses des moteurs et de contrôler les moteurs.

// // Constants
// #define NUM_JOY 2
// #define MIN_VAL 0
// #define MAX_VAL 1023

// // Parameters
// const int joyPin[NUM_JOY] = {A0, A1};
// const int joyBtn = 2;
// const int joyOffset = 0;

// // Motor control pins
// const int motorPinX = 3; // Connect the motor for X-axis control to digital pin 3
// const int motorPinY = 5; // Connect the motor for Y-axis control to digital pin 5

// // Motor speed limits
// const float maxSpeedX = 1.0; // Maximum speed (in rotations per minute) for X-axis
// const float maxSpeedY = 1.0; // Maximum speed (in rotations per minute) for Y-axis

// // Variables
// int joyVal[NUM_JOY] = {0, 0};
// float joyPhys[NUM_JOY] = {0.0, 0.0};
// bool isJoyButtonPressed = false;


// // Dans la fonction setup(), nous effectuons les initialisations nécessaires, comme l'ouverture 
// // de la communication série et la configuration des broches pour le joystick et les moteurs.
// void setup() {
//   // Initialize Serial communication
//   Serial.begin(9600);
//   Serial.println(F("Initialize System"));

//   // Initialize joystick
//   for (int i = 0; i < NUM_JOY; i++) {
//     pinMode(joyPin[i], INPUT);
//   }
//   pinMode(joyBtn, INPUT_PULLUP);

//   // Initialize motor control pins
//   pinMode(motorPinX, OUTPUT);
//   pinMode(motorPinY, OUTPUT);
// }

// // La boucle principale loop() est exécutée en continu. À l'intérieur de cette boucle, nous 
// // appelons les deux fonctions principales : readJoystick() et controlCamera().
// void loop() {
//   readJoystick();
//   controlCamera();
//   delay(500);
// }

// // La fonction readJoystick() lit les valeurs des axes du joystick et les convertit en valeurs 
// // physiques. Elle lit également l'état du bouton du joystick. Ces valeurs sont ensuite imprimées 
// // sur la communication série à des fins de test.
// void readJoystick() {
//   // Read joystick values
//   for (int i = 0; i < NUM_JOY; i++) {
//     joyVal[i] = analogRead(joyPin[i]);
//     joyPhys[i] = joyRawToPhys(joyVal[i]);
//   }

//   // Read joystick button state
//   isJoyButtonPressed = !digitalRead(joyBtn);

//   // Print joystick values (for testing)
//   for (int i = 0; i < NUM_JOY; i++) {
//     Serial.print(F("joy"));
//     Serial.print(i);
//     Serial.print(F(": "));
//     Serial.println(joyVal[i]);
//   }

//   // Print converted joystick values (for testing)
//   for (int i = 0; i < NUM_JOY; i++) {
//     Serial.print(F("Conv"));
//     Serial.print(i);
//     Serial.print(F(": "));
//     Serial.println(joyPhys[i]);
//   }

//   if (isJoyButtonPressed) {
//     Serial.println(F("Joy Button pressed"));
//   }
// }

// // La fonction joyRawToPhys() convertit les valeurs brutes des axes du joystick en valeurs 
// // physiques basées sur la plage de 0 à 100, avec une compensation de décalage si nécessaire.
// float joyRawToPhys(int raw) {
//   // Joystick conversion rule
//   float phys = map(raw, MIN_VAL, MAX_VAL, -100 + joyOffset, 100 + joyOffset) - joyOffset;
//   return phys;
// }

// // La fonction controlCamera() calcule les vitesses des moteurs (en rotations par minute) en 
// // fonction des valeurs physiques des axes du joystick. Elle applique ensuite les limites de 
// // vitesse définies.
// void controlCamera() {
//   // Calculate motor speeds based on joystick input
//   float speedX = joyPhys[0] * maxSpeedX / 100.0; // Calculate X-axis speed
//   float speedY = joyPhys[1] * maxSpeedY / 100.0; // Calculate Y-axis speed

//   // Apply speed limits
//   speedX = constrain(speedX, -maxSpeedX, maxSpeedX);
//   speedY = constrain(speedY, -maxSpeedY, maxSpeedY);

//   // Calculate rotation angles based on motor speeds
//   float angleX = speedX * 360.0 / 60.0; // Convert speed to degrees per second
//   float angleY = speedY * 360.0 / 60.0; // Convert speed to degrees per second

//   // Apply rotation limits
//   angleX = constrain(angleX, -180.0, 180.0);
//   angleY = constrain(angleY, -360.0, 360.0);

//   // Convert rotation angles to motor control signals
//   int motorSpeedX = map(angleX, -180.0, 180.0, 0, 255);
//   int motorSpeedY = map(angleY, -360.0, 360.0, 0, 255);

//   // Control the motors
//   analogWrite(motorPinX, motorSpeedX);
//   analogWrite(motorPinY, motorSpeedY);
// }

///////////////////////////////////////////////////////////////////////////////////////

// //Constants
// #define NUM_JOY 2
// #define MIN_VAL 0
// #define MAX_VAL 1023

// //Parameters
// const int joyPin[NUM_JOY] = {A0, A1};
// const int joyBtn = 2;
// const int joyOffset = 0;

// //Variables
// int joyVal[NUM_JOY] = {0, 0};

// // Motor control pins for X and Y axes
// const int motorXPin1 = 2;
// const int motorXPin2 = 3;
// const int motorYPin1 = 4;
// const int motorYPin2 = 5;

// // Motor speed variables
// float speedX = 0;
// float speedY = 0;

// // Maximum speed of rotation (in rotations per minute)
// const float maxSpeedX = 1.0;
// const float maxSpeedY = 1.0;

// void setup() {
//   // Initialize Serial USB
//   Serial.begin(9600);
//   Serial.println(F("Initialize System"));

//   // Initialize Joystick
//   for (int i = 0; i < NUM_JOY; i++) {
//     pinMode(joyPin[i], INPUT);
//   }
//   pinMode(joyBtn, INPUT_PULLUP);

//   // Initialize Motor Control Pins
//   pinMode(motorXPin1, OUTPUT);
//   pinMode(motorXPin2, OUTPUT);
//   pinMode(motorYPin1, OUTPUT);
//   pinMode(motorYPin2, OUTPUT);
// }

// void loop() {
//   readJoystick();
//   controlCamera();
//   delay(500);
// }

// void readJoystick() {
//   for (int i = 0; i < NUM_JOY; i++) {
//     joyVal[i] = analogRead(joyPin[i]);
//     Serial.print(F("joy"));
//     Serial.print(i);
//     Serial.print(F(" : "));
//     Serial.println(joyVal[i]);
//   }
//   for (int i = 0; i < NUM_JOY; i++) {
//     Serial.print(F("Conv"));
//     Serial.print(i);
//     Serial.print(F(" : "));
//     Serial.println(joyRawToPhys(joyVal[i]));
//   }
//   if (!digitalRead(joyBtn)) {
//     Serial.println(F("Joy Button pressed"));
//   }
// }

// float joyRawToPhys(int raw) {
//   float phys = map(raw, MIN_VAL, MAX_VAL, -100 + joyOffset, 100 + joyOffset) - joyOffset;
//   return phys;
// }

// void controlCamera() {
//   float joyX = joyRawToPhys(joyVal[0]);
//   float joyY = joyRawToPhys(joyVal[1]);

//   speedX = map(joyX, -100, 100, -maxSpeedX, maxSpeedX);
//   speedY = map(joyY, -100, 100, -maxSpeedY, maxSpeedY);

//   speedX = constrain(speedX, -maxSpeedX, maxSpeedX);
//   speedY = constrain(speedY, -maxSpeedY, maxSpeedY);

//   float angleX = speedX * 6.0; // Convert speed to angle (360 degrees per minute)
//   float angleY = speedY * 6.0;

//   // Apply rotation limits
//   angleX = constrain(angleX, -180.0, 180.0);
//   angleY = constrain(angleY, -360.0, 360.0);

//   int motorXSpeed = map(angleX, -180, 180, 0, 255);
//   int motorYSpeed = map(angleY, -360, 360, 0, 255);

//   // Control X-axis motor
//   if (angleX > 0) {
//     digitalWrite(motorXPin1, HIGH);
//     digitalWrite(motorXPin2, LOW);
//     analogWrite(motorXSpeed, motorXPin2);
//   } else if (angleX < 0) {
//     digitalWrite(motorXPin1, LOW);
//     digitalWrite(motorXPin2, HIGH);
//     analogWrite(-motorXSpeed, motorXPin2);
//   } else {
//     digitalWrite(motorXPin1, LOW);
//     digitalWrite(motorXPin2, LOW);
//   }

//   // Control Y-axis motor
//   if (angleY > 0) {
//     digitalWrite(motorYPin1, HIGH);
//     digitalWrite(motorYPin2, LOW);
//     analogWrite(motorYSpeed, motorYPin2);
//   } else if (angleY < 0) {
//     digitalWrite(motorYPin1, LOW);
//     digitalWrite(motorYPin2, HIGH);
//     analogWrite(-motorYSpeed, motorYPin2);
//   } else {
//     digitalWrite(motorYPin1, LOW);
//     digitalWrite(motorYPin2, LOW);
//   }
// }

