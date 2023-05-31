// Creator: Eliès Fali
// Date: 2023-05-30
// Version: 1.1.0
// Description: Fichier de configuration du programme

const int PIN_VITESSE_MOTOR_X = 11; // Constante pour la broche vitesse D3
const int PIN_SENS_MOTOR_X = 13; // Constante pour la direction / sens broche D12
const int PIN_VITESSE_MOTOR_Y = 3; // Constante pour la broche vitesse moteur 2 ()
const int PIN_SENS_MOTOR_Y = 12; // Constante pour la broche sens moteur 2 ()

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
// 
const float DEFAULT_ANGLE_Y = 0.0; // Angle par défaut pour le moteur Y
const float MIN_ANGLE_Y = -90.0; // Angle minimal pour le moteur Y
const float MAX_ANGLE_Y = 90.0; // Angle maximal pour le moteur Y
// 
float currentAngleX = DEFAULT_ANGLE_X; // Angle actuel du moteur X
float currentAngleY = DEFAULT_ANGLE_Y; // Angle actuel du moteur Y

// Variables pour le double-clic
const int DOUBLE_CLIC_DELAY = 500; // Délai maximal (en millisecondes) pour effectuer un double-clic
// 
unsigned long lastButtonClickTime = 0; // Temps du dernier clic
bool isFirstButtonClick = true; // Indique si le premier clic d'un double-clic a été effectué
int rotaPriority = 1; // Variable pour contrôler le moteur actif (1: moteur 1, 2: moteur 2)
