// Rectangle pour construction d'un algorigramme
// #####################
// #                   #
// #                   #
// #                   #
// #####################

// Losange pour construction d'un algorigramme
//          #
//    #            #
// #                  #
//    #            #
//          # 

// Ovale pour construction d'un algorigramme
//       #  #  #  #
//    #             #
//   #               #
//    #             #
//       #  #  #  #

// Flèche pour construction d'un algorigramme
//          #
//          #
//          #
//        # # #
//          #

// Parallélépipède pour construction d'un algorigramme
//        #####################
//      #                   #
//    #                   #
//  #                   #
// #####################



// Début
//     // Configuration des broches et des paramètres
//     Constante NUM_BUTTONS = 2
//     Constante BUTTON_DEBOUNCE_DELAY = 50
//     Constante MIN_VAL = 0
//     Constante MAX_VAL = 1023

//     Tableau buttonPins[NUM_BUTTONS] = {A0, A1}
//     Constante ledPin = 13

//     Tableau buttonState[NUM_BUTTONS] = {HIGH, HIGH}
//     Tableau lastButtonState[NUM_BUTTONS] = {HIGH, HIGH}
//     Tableau lastDebounceTime[NUM_BUTTONS] = {0, 0}

//     Constante rotationPriority = 0
//     Constante motorXPin1 = 2
//     Constante motorXPin2 = 3
//     Constante motorYPin1 = 4
//     Constante motorYPin2 = 5

//     Variable speedX = 0
//     Variable speedY = 0

//     Constante maxSpeedX = 1.0
//     Constante maxSpeedY = 1.0

//     // Initialisation
//     Subroutine setup()
//     Début
//         // Initialize Serial USB
//         Initialiser Serial à 9600 bauds
//         Afficher "Initialize System"

//         // Initialiser les boutons
//         Pour i de 0 à NUM_BUTTONS-1 Faire
//             Définir la broche buttonPins[i] en tant qu'entrée avec résistance de rappel
//         Fin Pour

//         // Initialiser les broches de contrôle moteur
//         Définir la broche motorXPin1 en tant que sortie
//         Définir la broche motorXPin2 en tant que sortie
//         Définir la broche motorYPin1 en tant que sortie
//         Définir la broche motorYPin2 en tant que sortie

//         // Initialiser la LED
//         Définir la broche ledPin en tant que sortie
//         Éteindre la LED
//     Fin Subroutine

//     // Boucle principale
//     Boucle loop()
//     Début
//         Lire les boutons
//         Contrôler la caméra
//         Afficher l'état
//         Attendre 50 millisecondes
//     Fin Boucle

//     // Affichage de l'état
//     Subroutine displayStatus()
//     Début
//         // Affichage de la priorité de rotation
//         Afficher "Rotation Priority: "
//         Si rotationPriority = 0 Alors
//             Afficher "X-axis"
//         Sinon
//             Afficher "Y-axis"
//         Fin Si

//         // Affichage de la direction des angles de moteur
//         Afficher "Angle Direction: "
//         Si buttonState[0] = LOW Alors
//             angleX = 180
//         Sinon
//             angleX = 0
//         Fin Si
//         Si buttonState[1] = LOW Alors
//             angleY = 360
//         Sinon
//             angleY = 0
//         Fin Si
//         Afficher "X: ", angleX, ", Y: ", angleY

//         // Affichage de la vitesse de rotation en temps réel
//         Afficher "Rotation Speed: "
//         Afficher "X: ", speedX, " RPM, Y: ", speedY, " RPM"
//         Afficher ""

//     Fin Subroutine

//     // Lecture des boutons
//     Subroutine readButtons()
//     Début
//         Pour i de 0 à NUM_BUTTONS-1 Faire
//             Lecture de la broche buttonPins[i]
//             Si la lecture est différente de lastButtonState[i] Alors
//                 lastDebounceTime[i] = millis()
//             Fin Si

//             Si (millis() - lastDebounceTime[i]) > BUTTON_DEBOUNCE_DELAY Alors
//                 Si la lecture est différente de buttonState[i] Alors
//                     buttonState[i] = lecture

    //                 Si buttonState[i] = LOW Alors
    //                     // Bouton enfoncé
    //                     Si i = 0 ET rotationPriority = 0 Alors
    //                         // Double-clic sur le premier bouton pour changer la priorité de rotation
    //                         Si (millis() - lastDebounceTime[1]) <= BUTTON_DEBOUNCE_DELAY Alors
    //                             rotationPriority = 1  // Changer la priorité de rotation vers l'axe Y
    //                             Allumer la LED pour indiquer la priorité de rotation de l'axe Y
    //                         Fin Si
    //                     Sinon Si i = 1 ET rotationPriority = 1 Alors
    //                         // Double-clic sur le second bouton pour changer la priorité de rotation
    //                         Si (millis() - lastDebounceTime[0]) <= BUTTON_DEBOUNCE_DELAY Alors
    //                             rotationPriority = 0  // Changer la priorité de rotation vers l'axe X
    //                             Éteindre la LED pour indiquer la priorité de rotation de l'axe X
    //                         Fin Si
    //                     Fin Si
    //                 Fin Si
    //             Fin Si
    //         Fin Si

//             lastButtonState[i] = lecture
//          Fin Pour
//      Fin Subroutine

        // Conversion de la valeur brute du joystick en valeur physique
    // Fonction joyRawToPhys(int raw)
    // Début
    //     Si rotationPriority = 0 Alors
    //         phys = map(raw, MIN_VAL, MAX_VAL, -100, 100)  // Conversion de la valeur brute en valeur physique pour l'axe X
    //     Sinon
    //         phys = map(raw, MIN_VAL, MAX_VAL, 100, -100)  // Conversion de la valeur brute en valeur physique pour l'axe Y
    //     Fin Si
    //     Retourner phys
    // Fin Fonction

    // // Contrôle de la caméra
    // Subroutine controlCamera()
    // Début
    //     // Lecture des états des boutons
    //     buttonXState = buttonState[0]
    //     buttonYState = buttonState[1]

    //     // Calcul des angles de rotation en fonction des états des boutons
    //     Si buttonXState = LOW Alors
    //         angleX = 180
    //     Sinon
    //         angleX = 0
    //     Fin Si
    //     Si buttonYState = LOW Alors
    //         angleY = 360
    //     Sinon
    //         angleY = 0
    //     Fin Si

    //     // Contrôle du moteur pour l'axe X
    //     Si angleX > 0 Alors
    //         Activer le sens horaire pour le moteurXPin1
    //         Désactiver le sens anti-horaire pour le moteurXPin2
    //         Régler la vitesse du moteurXPin2 en fonction de l'angleX
    //     Sinon
    //         Désactiver le sens horaire pour le moteurXPin1
    //         Désactiver le sens anti-horaire pour le moteurXPin2
    //     Fin Si

    //     // Contrôle du moteur pour l'axe Y
    //     Si angleY > 0 Alors
    //         Activer le sens horaire pour le moteurYPin1
    //         Désactiver le sens anti-horaire pour le moteurYPin2
    //         Régler la vitesse du moteurYPin2 en fonction de l'angleY
//          Sinon
//             Désactiver le sens horaire pour le moteurYPin1
//             Désactiver le sens anti-horaire pour le moteurYPin2
//          Fin Si
//      Fin Subroutine

//  Fin