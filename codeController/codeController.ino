
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

bool statusPorte1 = false;
bool statusPorte2 = false;
bool statusPorte3 = false;

void setup()
{
   pinMode(pinBouton1,INPUT_PULLUP);
   pinMode(pinBouton2,INPUT_PULLUP);
   pinMode(pinBouton3,INPUT_PULLUP);
   
   porte1.attach(pinPorte1);
   porte2.attach(pinPorte2);
   porte3.attach(pinPorte3);
 
   porte1.write(70);
   porte2.write(70);
   porte3.write(70);
   
   Serial.begin(9600);
}

void ouvrirPorte(Servo* porte)
{
  // Remonter doucement
  for (int c = 70 ; c > 0 ; c--)
  {
    porte->write(c);
    delay(30);
  }
  delay(5000);
}

void fermerPorte(Servo* porte)
{

  // Descendre doucement
  for (int c = 0 ; c < 70 ; c++)
  {
    porte->write(c);
    delay(30);
  }
}

void loop()
{
   // Mettre a jout l'état des boutons
   bool etatBouton1 = digitalRead(pinBouton1);
   bool etatBouton2 = digitalRead(pinBouton2);
   bool etatBouton3 = digitalRead(pinBouton3);
   
   // Everything opened mode
   etatBouton1 = LOW;
   etatBouton2 = LOW;
   etatBouton3 = LOW;

   Serial.println("etat:");   
   Serial.println(etatBouton1);
   Serial.println(etatBouton2);
   Serial.println(etatBouton3);
   
   // Ouvrir les portes si l'un des boutons est enfoncé
   if ((etatBouton1 == LOW)  && (statusPorte1 == false)) { ouvrirPorte(&porte1); statusPorte1 = true;  }
   if ((etatBouton1 == HIGH) && (statusPorte1 == true )) { fermerPorte(&porte1); statusPorte1 = false; }

   if ((etatBouton2 == LOW)  && (statusPorte2 == false)) { ouvrirPorte(&porte2); statusPorte2 = true;  }
   if ((etatBouton2 == HIGH) && (statusPorte2 == true )) { fermerPorte(&porte2); statusPorte2 = false; }
   
   if ((etatBouton3 == LOW)  && (statusPorte3 == false)) { ouvrirPorte(&porte3); statusPorte3 = true;  }
   if ((etatBouton3 == HIGH) && (statusPorte3 == true )) { fermerPorte(&porte3); statusPorte3 = false; }
 
     
   delay(100);
}




