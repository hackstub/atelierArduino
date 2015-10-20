//
// Hackteliers @ Lycée Le Corbusier             / Fevrier 2015
// Atelier arduino @ Mediathèque de Hautepierre / Octobre 2015
//
// Code pour controller le robot
//

#include <Servo.h>  

// #########################
// #  Gestion des moteurs  #
// #########################

#define pinServoRoueGauche 9
#define pinServoRoueDroite 10

#define centerGauche 90
#define centerDroite 90

Servo servoRoueGauche;  // create servo object to control a servo 
Servo servoRoueDroite;  // create servo object to control a servo 

void initServos()
{
  servoRoueGauche.attach(pinServoRoueGauche);
  servoRoueDroite.attach(pinServoRoueDroite);
}
 
void stopServos()
{
  servoRoueGauche.write(centerGauche);
  servoRoueDroite.write(centerDroite);
  servoRoueGauche.detach();
  servoRoueDroite.detach();
}

// ######################
// #  Fonction avancer  #
// ######################

void avancer(int vitesse, int duree)
{
  initServos();
  servoRoueGauche.write(centerGauche+vitesse);
  servoRoueDroite.write(centerDroite-vitesse);
  delay(duree);
  stopServos();
}

// ######################
// #  Fonction tourner  #
// ######################

#define rotationEtalon 8870 // time to do 360° 

void tourner(float fraction)
{
  int vitesse = 2.5 * fraction / abs(fraction); 
  int duree = (int) (rotationEtalon * abs(fraction));
  
  initServos();
  servoRoueGauche.write(centerGauche+vitesse);
  servoRoueDroite.write(centerDroite+vitesse);
  delay(duree);
  stopServos();
}

// #########################
// #  Pour la calibration  #
// #########################

void calibrationRepos()    { avancer(0,10000); }
void calibrationRotation() { tourner(4); delay(10000); }
  
// ##################
// #  Le programme  #
// ##################

void setup() 
{ 
}
 
void loop() 
{ 
  
  avancer(5,2000);
  delay(1000);
  tourner(0.25);
  delay(1000);
  
  //calibrationRepos();
  //calibrationRotation();
}
