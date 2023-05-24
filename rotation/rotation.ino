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
  pinMode(PIN_VITESSE_MOTEUR_1, OUTPUT); // Broche vitesseMotA configurée en sortie
  pinMode(PIN_SENS_MOTEUR_1, OUTPUT); // Broche sensMotA configurée en sortie
  digitalWrite(PIN_SENS_MOTEUR_1, LOW); // À l'arrêt
  analogWrite(PIN_VITESSE_MOTEUR_1, 0);

  pinMode(PIN_VITESSE_MOTEUR_2, OUTPUT);
  pinMode(PIN_SENS_MOTEUR_2, OUTPUT);
  digitalWrite(PIN_SENS_MOTEUR_2, LOW); // Arrêt du moteur 2
  analogWrite(PIN_VITESSE_MOTEUR_2, 0);

  pinMode(PIN_BOUTON_SENS_1_MOTOR_1, INPUT_PULLUP); // Broche du bouton de sens 1 configurée en entrée avec une résistance de pull-up interne activée
  pinMode(PIN_BOUTON_SENS_2_MOTOR_1, INPUT_PULLUP); // Broche du bouton de sens 2 configurée en entrée avec une résistance de pull-up interne activée
  pinMode(PIN_BOUTON_SENS_1_MOTOR_2, INPUT_PULLUP); // Broche du bouton de sens 1 configurée en entrée avec une résistance de pull-up interne activée
  pinMode(PIN_BOUTON_SENS_2_MOTOR_2, INPUT_PULLUP); // Broche du bouton de sens 2 configurée en entrée avec une résistance de pull-up interne activée

  // Démarre la communication série
  Serial.begin(9600);
}

void loop() {
  int sensRotaMotor1 = rotaDirectionMotor1();
  int sensRotaMotor2 = rotaDirectionMotor2();

  controlMotor1(sensRotaMotor1);
  controlMotor2(sensRotaMotor2);
  // Autres actions à effectuer dans la boucle principale
}

int rotaDirectionMotor1() {
  int etatBoutonSens1 = digitalRead(PIN_BOUTON_SENS_1_MOTOR_1);
  int etatBoutonSens2 = digitalRead(PIN_BOUTON_SENS_2_MOTOR_1);

  if (etatBoutonSens1 == LOW) {
    return 1; // Sens 1
  } else if (etatBoutonSens2 == LOW) {
    return 2; // Sens 2
  }

  return 0; // Aucun sens sélectionné
}
int rotaDirectionMotor2() {
  int etatBoutonSens1 = digitalRead(PIN_BOUTON_SENS_1_MOTOR_2);
  int etatBoutonSens2 = digitalRead(PIN_BOUTON_SENS_2_MOTOR_2);

  if (etatBoutonSens1 == LOW) {
    return 1; // Sens 1
  } else if (etatBoutonSens2 == LOW) {
    return 2; // Sens 2
  }

  return 0; // Aucun sens sélectionné
}

void controlMotor1(int sensRotaMotor1) {
  switch (sensRotaMotor1) {
    case 1:
      Serial.println("Moteur A sens 1 ");
      digitalWrite(PIN_SENS_MOTEUR_1, LOW); // Sens 1
      analogWrite(PIN_VITESSE_MOTEUR_1, 128); // Vitesse maximale à faire varier entre 0 et 255
      break;
    case 2:
      Serial.println("Moteur A sens 2 ");
      digitalWrite(PIN_SENS_MOTEUR_1, HIGH); // Sens 2
      analogWrite(PIN_VITESSE_MOTEUR_1, 255); // Vitesse maximale
      break;
    default:
      digitalWrite(PIN_SENS_MOTEUR_1, LOW); // Aucun sens sélectionné, arrêt du moteur
      analogWrite(PIN_VITESSE_MOTEUR_1, 0); // Vitesse nulle
      break;
  }
}

void controlMotor2(int sensRotaMotor2) {
  
  switch (sensRotaMotor2) {
    case 1:
      Serial.println("Moteur B sens 1 ");
      digitalWrite(PIN_SENS_MOTEUR_2, LOW); // Sens 1
      analogWrite(PIN_VITESSE_MOTEUR_2, 255); // Vitesse maximale à faire varier entre 0 et 255
      break;
    case 2:
      Serial.println("Moteur B sens 2 ");
      digitalWrite(PIN_SENS_MOTEUR_2, HIGH); // Sens 2
      analogWrite(PIN_VITESSE_MOTEUR_2, 255); // Vitesse maximale
      break;
    default:
      digitalWrite(PIN_SENS_MOTEUR_2, LOW); // Aucun sens sélectionné, arrêt du moteur
      analogWrite(PIN_VITESSE_MOTEUR_2, 0); // Vitesse nulle
      break;
  }
}






















// const int PIN_VITESSE_MOTEUR1 = 3; // Constante pour la broche vitesse moteur 1 (D3)
// const int PIN_SENS_MOTEUR1 = 12; // Constante pour la broche sens moteur 1 (D12)
// const int PIN_VITESSE_MOTEUR2 = 11; // Constante pour la broche vitesse moteur 2 ()
// const int PIN_SENS_MOTEUR2 = 13; // Constante pour la broche sens moteur 2 ()
// const int PIN_BOUTON_SENS_1 = 7; // Broche pour le bouton de sens 1 du Grove Dual Button
// const int PIN_BOUTON_SENS_2 = 8; // Broche pour le bouton de sens 2 du Grove Dual Button

// const int DOUBLE_CLIC_DELAY = 500; // Délai maximal (en millisecondes) pour effectuer un double-clic

// unsigned long lastButtonClickTime = 0; // Temps du dernier clic
// bool isFirstButtonClick = true; // Indique si le premier clic d'un double-clic a été effectué
// int rotaPriority = 1; // Variable pour contrôler le moteur actif (1: moteur 1, 2: moteur 2)

// void setup() {
//   pinMode(PIN_VITESSE_MOTEUR1, OUTPUT);
//   pinMode(PIN_SENS_MOTEUR1, OUTPUT);
//   digitalWrite(PIN_SENS_MOTEUR1, LOW); // Arrêt du moteur 1
//   analogWrite(PIN_VITESSE_MOTEUR1, 0);

//   pinMode(PIN_VITESSE_MOTEUR2, OUTPUT);
//   pinMode(PIN_SENS_MOTEUR2, OUTPUT);
//   digitalWrite(PIN_SENS_MOTEUR2, LOW); // Arrêt du moteur 2
//   analogWrite(PIN_VITESSE_MOTEUR2, 0);

//   pinMode(PIN_BOUTON_SENS_1, INPUT_PULLUP);
//   pinMode(PIN_BOUTON_SENS_2, INPUT_PULLUP);

//   Serial.begin(9600);
// }

// void loop() {
//   int sensRotation = rotaDirection();
//   controlMotor(sensRotation);
//   // Autres actions à effectuer dans la boucle principale
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
