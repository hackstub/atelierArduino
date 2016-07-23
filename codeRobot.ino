//
// Hackteliers @ Lycée Le Corbusier             / Fevrier  2015
// Atelier arduino @ Mediathèque de Hautepierre / Octobre  2015
// Atelier arduino @ Mediathèque de Neudorf     / Novembre 2015
//
// Code pou-r controller le robot
//

#include <Servo.h>

// ###############################
// #  Configuration des roues    #
// ###############################

#define PIN_ROUE_GAUCHE 9
#define PIN_ROUE_DROITE 10

#define RAYON_ROUES      33
#define ECARTEMENT_ROUES 110

#define VITESSE_PAR_DEFAUT 150
#define TOUR_PAR_SECONDE 0.539

// ###############################
// # Gestion des moteurs / roues #
// ###############################

#define CENTRE_ROUE_GAUCHE 1500
#define CENTRE_ROUE_DROITE 1500

Servo servoRoueGauche;
Servo servoRoueDroite;

void initRoues()
{
    servoRoueGauche.attach(PIN_ROUE_GAUCHE);
    servoRoueDroite.attach(PIN_ROUE_DROITE);
}

void detachRoues()
{
    servoRoueGauche.detach();
    servoRoueDroite.detach();
}

void commandeRoues(int commandeGauche, int commandeDroite)
{
    servoRoueGauche.writeMicroseconds(CENTRE_ROUE_GAUCHE+commandeGauche);
    servoRoueDroite.writeMicroseconds(CENTRE_ROUE_DROITE+commandeDroite);
}

void stopRoues ()
{
    commandeRoues(0,0);
}

void stopRouesSlow(int comG, int comD)
{
    for (float f = 0.9 ; f >= 0.0 ; f -= 0.1)
    {
        commandeRoues(comG * f,comD * f);
        attendre(0);
    }
    commandeRoues(0,0);
    attendre(1000);
}

void attendre(unsigned long duree)
{
    delay(duree);
}

// ######################
// #  Fonction avancer  #
// ######################

// Correction pour la fonction avancer si légère asymétrie entre gauche et droite
#define CORRECTION_AVANCER_GAUCHE 0
#define CORRECTION_AVANCER_DROITE 0

#define DISTANCE_PAR_SECONDE ((float) (2 * 3.1415 * RAYON_ROUES * TOUR_PAR_SECONDE))

void avancer(int distance)
{
    short int sens = (distance > 0) ? 1 : -1;

    float duree = abs((float) distance) / DISTANCE_PAR_SECONDE;

    float comG = CORRECTION_AVANCER_GAUCHE + sens * VITESSE_PAR_DEFAUT;
    float comD = CORRECTION_AVANCER_DROITE - sens * VITESSE_PAR_DEFAUT;

    commandeRoues(comG, comD);
    attendre(duree * 1000);
    stopRouesSlow(comG,comD);
}

// ######################
// #  Fonction tourner  #
// ######################

void tourner(float fraction)
{
    short int sens = (fraction > 0) ? 1 : -1;

    float duree =  fraction * 3.1415 * (float) (ECARTEMENT_ROUES) / DISTANCE_PAR_SECONDE;

    int com = sens * VITESSE_PAR_DEFAUT;
    commandeRoues(com, com);
    attendre(duree * 1000);
    stopRouesSlow(com,com);
}

// ###################################
// #  Gestion du module ultrason     #
// ###################################

// Define pin mapping
#define SENTRY_TRIGGER_PIN 2
#define SENTRY_ECHO_PIN    3
#define DISTANCE_OBSTACLE  10

// Initialisation
void initUltrason()
{
    // Init ultrason module
    pinMode(SENTRY_TRIGGER_PIN, OUTPUT);
    digitalWrite(SENTRY_TRIGGER_PIN, LOW);
    pinMode(SENTRY_ECHO_PIN, INPUT);
}

// Returns the distance measured, in centimeters
bool presenceObstacle()
{
    attendre(100);

    // Trigger emition
    digitalWrite(SENTRY_TRIGGER_PIN, HIGH);
    delayMicroseconds(100);
    digitalWrite(SENTRY_TRIGGER_PIN, LOW);

    // Read value from sensor
    long echoValue = pulseIn(SENTRY_ECHO_PIN, HIGH);

    // Convert echo value to distance in centimeters
    long distance = echoValue / 58;
    if (distance == 5) distance = 3000;

    Serial.println("distance");
    Serial.println(distance);

    if (((int) distance) <= DISTANCE_OBSTACLE) return true;
    else                                       return false;
}

// ###############################
// #  Gestion du bras            #
// ###############################

Servo brasServo;
#define BRAS_PIN 11

void initBras()
{
    // Init sentry servomotor
    brasServo.attach(BRAS_PIN);
    brasServo.write(70);
}

void activerBras(int sens = 1)
{
    if (sens == 1)
    {
        // Descendre d'un coup
        brasServo.write(0);
        attendre(1000);
        // Remonter doucement
        for (int c = 0 ; c < 70 ; c++)
        {
            brasServo.write(c);
            attendre(10);
        }
    }
    else
    {
        // Descendre (de l'autre cote) d'un coup
        brasServo.write(170);
        attendre(1000);
        // Remonter doucement
        for (int c = 170 ; c > 70 ; c--)
        {
            brasServo.write(c);
            attendre(10);
        }
    }
}

// ###############################
// #  Le programme               #
// ###############################

void setup()
{
    initRoues();
    initUltrason();
    initBras();

    stopRoues();
}

void loop()
{

    avancer(1000);
    attendre(1000);
    tourner(0.25);
    attendre(1000);

}




