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
  pinMode(PIN_VITESSE_MOTOR_X, OUTPUT); // Broche vitesseMotA configurée en sortie
  pinMode(PIN_SENS_MOTOR_X, OUTPUT); // Broche sensMotA configurée en sortie
  digitalWrite(PIN_SENS_MOTOR_X, LOW); // À l'arrêt
  analogWrite(PIN_VITESSE_MOTOR_X, 0);

  pinMode(PIN_VITESSE_MOTOR_Y, OUTPUT);
  pinMode(PIN_SENS_MOTOR_Y, OUTPUT);
  digitalWrite(PIN_SENS_MOTOR_Y, LOW); // Arrêt du moteur 2
  analogWrite(PIN_VITESSE_MOTOR_Y, 0);

  pinMode(PIN_BOUTON_SENS_1_MOTOR_X, INPUT_PULLUP); // Broche du bouton de sens 1 configurée en entrée avec une résistance de pull-up interne activée
  pinMode(PIN_BOUTON_SENS_2_MOTOR_X, INPUT_PULLUP); // Broche du bouton de sens 2 configurée en entrée avec une résistance de pull-up interne activée
  pinMode(PIN_BOUTON_SENS_1_MOTOR_Y, INPUT_PULLUP); // Broche du bouton de sens 1 configurée en entrée avec une résistance de pull-up interne activée
  pinMode(PIN_BOUTON_SENS_2_MOTOR_Y, INPUT_PULLUP); // Broche du bouton de sens 2 configurée en entrée avec une résistance de pull-up interne activée

  // Démarre la communication série
  Serial.begin(9600);
}

void loop() {
  int sensRotaMotorX = rotaDirectionMotorX();
  int sensRotaMotorY = rotaDirectionMotorY();

  controlMotorX(sensRotaMotorX);
  controlMotorY(sensRotaMotorY);
  // Autres actions à effectuer dans la boucle principale
}

int rotaDirectionMotorX() {
  int etatBoutonSens1 = digitalRead(PIN_BOUTON_SENS_1_MOTOR_X);
  int etatBoutonSens2 = digitalRead(PIN_BOUTON_SENS_2_MOTOR_X);

  if (etatBoutonSens1 == LOW) {
    return 1; // Sens 1
  } else if (etatBoutonSens2 == LOW) {
    return 2; // Sens 2
  }

  return 0; // Aucun sens sélectionné
}
int rotaDirectionMotorY() {
  int etatBoutonSens1 = digitalRead(PIN_BOUTON_SENS_1_MOTOR_Y);
  int etatBoutonSens2 = digitalRead(PIN_BOUTON_SENS_2_MOTOR_Y);

  if (etatBoutonSens1 == LOW) {
    return 1; // Sens 1
  } else if (etatBoutonSens2 == LOW) {
    return 2; // Sens 2
  }

  return 0; // Aucun sens sélectionné
}

void controlMotorX(int sensRotaMotorX) {
  switch (sensRotaMotorX) {
    case 1:
      Serial.println("Moteur X sens 1 ");
      digitalWrite(PIN_SENS_MOTOR_X, HIGH); // Sens 1
      analogWrite(PIN_VITESSE_MOTOR_X, 255); // Vitesse maximale à faire varier entre 0 et 255
      // Serial.println("Le moteur X tourne dans le sens 1");
      break;
    case 2:
      Serial.println("Moteur X sens 2 ");
      digitalWrite(PIN_SENS_MOTOR_X, LOW); // Sens 2
      analogWrite(PIN_VITESSE_MOTOR_X, 255); // Vitesse maximale
      // Serial.println("Le moteur X tourne dans le sens 2");
      break;
    default:
      analogWrite(PIN_VITESSE_MOTOR_X, 0); // Vitesse nulle
      //Serial.println("Le moteur X est à l'arrêt");
      break;
  }
}
void controlMotorY(int sensRotaMotorY) {
  switch (sensRotaMotorY) {
    case 1:
      Serial.println("Moteur Y sens 1 ");
      digitalWrite(PIN_SENS_MOTOR_Y, LOW); // Sens 1
      analogWrite(PIN_VITESSE_MOTOR_Y, 255); // Vitesse maximale à faire varier entre 0 et 255
      // Serial.println("Le moteur Y tourne dans le sens 1");
      break;
    case 2:
      Serial.println("Moteur Y sens 2 ");
      digitalWrite(PIN_SENS_MOTOR_Y, HIGH); // Sens 2
      analogWrite(PIN_VITESSE_MOTOR_Y, 255); // Vitesse maximale
      // Serial.println("Le moteur Y tourne dans le sens 2");
      break;
    default:
      analogWrite(PIN_VITESSE_MOTOR_Y, 0); // Vitesse nulle
      //Serial.println("Le moteur Y est à l'arrêt");
      break;
  }
}


// EN TEST

// █▀ █▀█ █▀▀ █▀▀ █▀▄   █░░ █ █▀▄▀█ █ ▀█▀
// ▄█ █▀▀ ██▄ ██▄ █▄▀   █▄▄ █ █░▀░█ █ ░█░

// void moveMotorX(float speedRPM) {
//   // Vérifie si la vitesse donnée dépasse la vitesse maximale autorisée
//   if (speedRPM > MAX_SPEED_X) {
//     speedRPM = MAX_SPEED_X;
//   }

//   // Convertit la vitesse en tours par minute en valeur de vitesse appropriée pour la fonction analogWrite()
//   int speedValue = map(speedRPM, 0, MAX_SPEED_X, 0, 255);

//   // Détermine le sens de rotation en fonction de la valeur de vitesse
//   if (speedValue > 0) {
//     digitalWrite(PIN_SENS_MOTOR_X, HIGH); // Sens 1
//   } else {
//     digitalWrite(PIN_SENS_MOTOR_X, LOW); // Sens 2
//   }

//   // Met à jour la vitesse du moteur
//   analogWrite(PIN_VITESSE_MOTOR_X, abs(speedValue));
// }

// void moveMotorY(float speedRPM) {
//   // Vérifie si la vitesse donnée dépasse la vitesse maximale autorisée
//   if (speedRPM > MAX_SPEED_Y) {
//     speedRPM = MAX_SPEED_Y;
//   }

//   // Convertit la vitesse en tours par minute en valeur de vitesse appropriée pour la fonction analogWrite()
//   int speedValue = map(speedRPM, 0, MAX_SPEED_Y, 0, 255);

//   // Détermine le sens de rotation en fonction de la valeur de vitesse
//   if (speedValue > 0) {
//     digitalWrite(PIN_SENS_MOTOR_Y, HIGH); // Sens 1
//   } else {
//     digitalWrite(PIN_SENS_MOTOR_Y, LOW); // Sens 2
//   }

//   // Met à jour la vitesse du moteur
//   analogWrite(PIN_VITESSE_MOTOR_Y, abs(speedValue));
// }


// █▀▄▀█ █▀█ ▀█▀ █▀█ █▀█   ▄▀█ █▄░█ █▀▀ █░░ █▀▀ █▀
// █░▀░█ █▄█ ░█░ █▄█ █▀▄   █▀█ █░▀█ █▄█ █▄▄ ██▄ ▄█

// void setup() {
//   // Positionne les moteurs à l'angle par défaut
//   angleMotorX(DEFAULT_ANGLE_X);
//   angleMotorY(DEFAULT_ANGLE_Y);
// }

// void angleMotorX(float angle) {
//   // Vérifie si l'angle donné est en dehors de la plage autorisée
//   if (angle < MIN_ANGLE_X || angle > MAX_ANGLE_X) {
//     // Gère l'erreur d'angle invalide
//     Serial.println("Angle invalide pour le moteur X");
//     return;
//   }

//   // Calcule la valeur de vitesse en fonction de l'angle (à adapter en fonction de votre configuration)
//   int speed = map(angle, MIN_ANGLE_X, MAX_ANGLE_X, 0, 255);

//   // Détermine le sens de rotation en fonction de l'angle (à adapter en fonction de votre configuration)
//   if (angle < currentAngleX) {
//     digitalWrite(PIN_SENS_MOTOR_X, HIGH); // Sens 1
//   } else {
//     digitalWrite(PIN_SENS_MOTOR_X, LOW); // Sens 2
//   }

//   // Met à jour la vitesse du moteur
//   analogWrite(PIN_VITESSE_MOTOR_X, speed);

//   // Met à jour l'angle actuel
//   currentAngleX = angle;
// }
// void angleMotorY(float angle) {
//   // Vérifie si l'angle donné est en dehors de la plage autorisée
//   if (angle < MIN_ANGLE_Y || angle > MAX_ANGLE_Y) {
//     // Gère l'erreur d'angle invalide
//     Serial.println("Angle invalide pour le moteur Y");
//     return;
//   }

//   // Calcule la valeur de vitesse en fonction de l'angle (à adapter en fonction de votre configuration)
//   int speed = map(angle, MIN_ANGLE_Y, MAX_ANGLE_Y, 0, 255);

//   // Détermine le sens de rotation en fonction de l'angle (à adapter en fonction de votre configuration)
//   if (angle < currentAngleY) {
//     digitalWrite(PIN_SENS_MOTOR_Y, LOW); // Sens 1
//   } else {
//     digitalWrite(PIN_SENS_MOTOR_Y, HIGH); // Sens 2
//   }

//   // Met à jour la vitesse du moteur
//   analogWrite(PIN_VITESSE_MOTOR_Y, speed);

//   // Met à jour l'angle actuel
//   currentAngleY = angle;
// }


// █▀▄ █▀█ █░█ █▄▄ █░░ █▀▀ ▄▄ █▀▀ █░░ █ █▀▀ █▄▀
// █▄▀ █▄█ █▄█ █▄█ █▄▄ ██▄ ░░ █▄▄ █▄▄ █ █▄▄ █░█

// void loop() {
//   int sensRotation = rotaDirection();
//   controlMotor(sensRotation);
// }

// int rotaDirection() {
//   int etatBoutonSens1 = digitalRead(PIN_BOUTON_SENS_1);
//   int etatBoutonSens2 = digitalRead(PIN_BOUTON_SENS_2);

//   if (etatBoutonSens1 == LOW) {
//     if (isDoubleClick(PIN_BOUTON_SENS_1)) {
//       return toggleRotaPriority(); // Changer la priorité de rotation
//     } else {
//       return rotaPriority;
//     }
//   } else if (etatBoutonSens2 == LOW) {
//     if (isDoubleClick(PIN_BOUTON_SENS_2)) {
//       return toggleRotaPriority(); // Changer la priorité de rotation
//     } else {
//       return rotaPriority;
//     }
//   }

//   return 0; // Aucun sens sélectionné
// }

// void controlMotor(int sensRotation) {
//   switch (sensRotation) {
//     case 1:
//       digitalWrite(PIN_SENS_MOTEUR1, LOW);
//       analogWrite(PIN_VITESSE_MOTEUR1, 128);
//       break;
//     case 2:
//       digitalWrite(PIN_SENS_MOTEUR1, HIGH);
//       analogWrite(PIN_VITESSE_MOTEUR1, 255);
//       break;
//     default:
//       digitalWrite(PIN_SENS_MOTEUR1, LOW);
//       analogWrite(PIN_VITESSE_MOTEUR1, 0);
//       break;
//   }
  
//   if (rotaPriority == 2) {
//     switch (sensRotation) {
//       case 1:
//         digitalWrite(PIN_SENS_MOTEUR2, LOW);
//         analogWrite(PIN_VITESSE_MOTEUR2, 128);
//         break;
//       case 2:
//         digitalWrite(PIN_SENS_MOTEUR2, HIGH);
//         analogWrite(PIN_VITESSE_MOTEUR2, 255);
//         break;
//       default:
//         digitalWrite(PIN_SENS_MOTEUR2, LOW);
//         analogWrite(PIN_VITESSE_MOTEUR2, 0);
//         break;
//     }
//   }
// }

// int toggleRotaPriority() {
//   if (rotaPriority == 1) {
//     rotaPriority = 2;
//     Serial.println("Rota Priority: Motor 2");
//   } else {
//     rotaPriority = 1;
//     Serial.println("Rota Priority: Motor 1");
//   }
//   return rotaPriority;
// }

// bool isDoubleClick(int buttonPin) {
//   unsigned long currentTime = millis();
//   int buttonState = digitalRead(buttonPin);

//   if (buttonState == LOW) {
//     if (currentTime - lastButtonClickTime <= DOUBLE_CLIC_DELAY) {
//       lastButtonClickTime = 0;
//       return true;
//     } else {
//       lastButtonClickTime = currentTime;
//     }
//   }

//   return false;
// }
