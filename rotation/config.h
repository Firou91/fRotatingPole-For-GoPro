// Creator: Eliès Fali
// Date: 2023-05-30
// Version: 1.1.0
// Description: Fichier de configuration du programme

const int PIN_VITESSE_MOTOR_X = 11; // Constante pour la broche vitesse D3
const int PIN_SENS_MOTOR_X = 13; // Constante pour la direction / sens broche D12
const int PIN_VITESSE_MOTOR_Y = 3; // Constante pour la broche vitesse moteur 2 ()
const int PIN_SENS_MOTOR_Y = 12; // Constante pour la broche sens moteur 2 ()

const int PIN_BOUTON_SENS_1_MOTOR_X = 7; // Broche pour le bouton de sens 1 du Grove Dual Button
const int PIN_BOUTON_SENS_2_MOTOR_X = 8; // Broche pour le bouton de sens 2 du Grove Dual Button
const int PIN_BOUTON_SENS_1_MOTOR_Y = 5; // Broche pour le bouton de sens 1 du Grove Dual Button
const int PIN_BOUTON_SENS_2_MOTOR_Y = 6; // Broche pour le bouton de sens 2 du Grove Dual Button


// Vitesse maximale de rotation (en rotations par minute)
const float maxSpeedX = 1.0; // Vitesse maximale de rotation axe X (You can change this value)
const float maxSpeedY = 1.0; // Vitesse maximale de rotation axe Y (You can change this value)

// Variables de vitesse des moteurs
int speedMotors = 300; // Vitesse des moteurs (c.f fiche technique moteur)
int RPM_MOTOR_X = (speedMotors / 255) * maxSpeedX; // Constante pour la vitesse moteur 1 (DO NOT TOUCH)
int RPM_MOTOR_Y = (speedMotors / 255) * maxSpeedY; // Constante pour la vitesse moteur 2 (DO NOT TOUCH)
