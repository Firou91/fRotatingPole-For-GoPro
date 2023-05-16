// ░█████╗░░█████╗░███╗░░██╗███████╗██╗░██████╗░██╗░░░██╗██████╗░░█████╗░████████╗██╗░█████╗░███╗░░██╗
// ██╔══██╗██╔══██╗████╗░██║██╔════╝██║██╔════╝░██║░░░██║██╔══██╗██╔══██╗╚══██╔══╝██║██╔══██╗████╗░██║
// ██║░░╚═╝██║░░██║██╔██╗██║█████╗░░██║██║░░██╗░██║░░░██║██████╔╝███████║░░░██║░░░██║██║░░██║██╔██╗██║
// ██║░░██╗██║░░██║██║╚████║██╔══╝░░██║██║░░╚██╗██║░░░██║██╔══██╗██╔══██║░░░██║░░░██║██║░░██║██║╚████║
// ╚█████╔╝╚█████╔╝██║░╚███║██║░░░░░██║╚██████╔╝╚██████╔╝██║░░██║██║░░██║░░░██║░░░██║╚█████╔╝██║░╚███║
// ░╚════╝░░╚════╝░╚═╝░░╚══╝╚═╝░░░░░╚═╝░╚═════╝░░╚═════╝░╚═╝░░╚═╝╚═╝░░╚═╝░░░╚═╝░░░╚═╝░╚════╝░╚═╝░░╚══╝
// Configuration des broches et des paramètres

// Nombre de boutons
#define NUM_BUTTONS 2

// Délai anti-rebond pour les boutons (en millisecondes)
#define BUTTON_DEBOUNCE_DELAY 50

// Valeur minimale et maximale des lectures des boutons analogiques
#define MIN_VAL 0
#define MAX_VAL 1023

// Broches des boutons
const int buttonPins[NUM_BUTTONS] = {A0, A1};

// Broche de la LED
const int ledPin = 13;

// États des boutons
int buttonState[NUM_BUTTONS] = {HIGH, HIGH};
int lastButtonState[NUM_BUTTONS] = {HIGH, HIGH};
unsigned long lastDebounceTime[NUM_BUTTONS] = {0, 0};

// Priorité de rotation (0 : axe X, 1 : axe Y)
int rotationPriority = 0;

// Broches de contrôle moteur pour les axes X et Y
const int motorXPin1 = 2;
const int motorXPin2 = 3;
const int motorYPin1 = 4;
const int motorYPin2 = 5;

// Variables de vitesse des moteurs
float speedX = 0;
float speedY = 0;

// Vitesse maximale de rotation (en rotations par minute)
const float maxSpeedX = 1.0;
const float maxSpeedY = 1.0;