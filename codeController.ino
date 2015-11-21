
#include <Servo.h>

#define pinBouton1 2
#define pinBouton2 3
#define pinBouton3 4

#define pinPorte1 9
#define pinPorte2 10
#define pinPorte3 11

Servo porte1;
Servo porte2;
Servo porte3;

void setup()
{
   pinMode(pinBouton1,INPUT_PULLUP);
   pinMode(pinBouton2,INPUT_PULLUP);
   pinMode(pinBouton3,INPUT_PULLUP);
   
   porte1.attach(pinPorte1);
   porte2.attach(pinPorte2);
   porte3.attach(pinPorte3);
   
   Serial.begin(9600);
}

void ouvrirPorte(Servo* porte)
{
  // Remonter doucement
  for (int c = 70 ; c < 0 ; c--)
  {
    porte->write(c);
    delay(10);
  }
  delay(3000);
  // Descendre doucement
  for (int c = 0 ; c < 70 ; c++)
  {
    porte->write(c);
    delay(10);
  }
}

void loop()
{
   // Mettre a jout l'état des boutons
   bool etatBouton1 = digitalRead(pinBouton1);
   bool etatBouton2 = digitalRead(pinBouton2);
   bool etatBouton3 = digitalRead(pinBouton3);

   Serial.println("etat:");   
   Serial.println(etatBouton1);
   Serial.println(etatBouton2);
   Serial.println(etatBouton3);
   
   // Ouvrir les portes si l'un des boutons est enfoncé
   if (etatBouton1 == LOW) ouvrirPorte(&porte1);
   if (etatBouton2 == LOW) ouvrirPorte(&porte2);
   if (etatBouton3 == LOW) ouvrirPorte(&porte3);
   
   delay(100);
}




