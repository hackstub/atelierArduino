Attention : le contenu est succeptible d'être modifié dans les prochains jours. Revenez plus tard pour une version plus finalisée.

Ce répertoire Github est destiné à regrouper les documents et lister le matériel utilisé pour l'atelier Arduino. Vous pouvez retrouver les slides/transparents [ici](https://github.com/alexAubin/atelierArduino/raw/master/slides.pdf) et le code utilisé pour contrôler le robot [ici](https://github.com/alexAubin/atelierArduino/blob/master/codeRobot.ino). Ci-dessous se trouve la liste des composants nécessaire pour faire un robot ainsi que quelques liens pour télécharger le logiciel Arduino et de la documentation pour programmer.

(Quelques) distributeurs d'électronique en France/Europe
=============================================

Arduino / Raspberry Pi / do-it-yourself
- [Semageek](http://boutique.semageek.com/)
- [Robotshop](http://www.robotshop.com/eu/en/)

Electronique générale
- Farnell
- Radiospares
- Mouser electronics
- ...

Distributeurs hors Europe (attention aux frais de douanes)
- [Seeedstudio](http://www.seeedstudio.com/)
- [Adafruit](http://www.adafruit.com/)
- [Sparkfun](https://www.sparkfun.com/)

Liste des composants
====================

- Arduino UNO (rev. 3) (par exemple [ici](http://www.robotshop.com/eu/en/arduino-uno-usb-microcontroller-rev-3.html))
- Cable USB A-B pour connecter l'Arduino (par exemple [ici](http://www.robotshop.com/en/15m-usb-cable-type-a-to-b.html))
- 2 x Servomoteur à rotation continue (par exemple [ici](www.robotshop.com/eu/en/parallax-futaba-continuous-rotation-servo.html))
- 2 x Roue pour servomoteur (par exemple [ici](http://www.robotshop.com/eu/en/parallax-boe-bot-sumobot-wheel-tire.html))
- Une bille folle (par exemple [ici](http://www.robotshop.com/eu/en/pololu-ball-caster-3-4-in-metal-ball.html), existe en plusieurs tailles)
- Pile 9V + un boitier ou un clip (par exemple [ici](http://www.robotshop.com/eu/en/adafruit-9v-battery-case-switch-barrel-connector.html))
- Un breadboard (voir [ici](http://www.robotshop.com/eu/en/catalogsearch/result/index/?cat=234&dir=asc&mode=list&order=price&q=solderless+breadboard) )
- Des fils (jumpers) male/male : (voir [ici](http://www.robotshop.com/eu/en/catalogsearch/result/index/?dir=desc&mode=list&order=stats_sales_order_count&q=jumper))
- Un chassis, par exemple en bois, de la même largeur que les deux servomoteurs.
- Des elastiques pour fixer le tout

Installation et utilisation du logiciel Arduino
===============================================


- Télécharger le logicie Arduino [ici](http://arduino.cc/en/Main/Software)

- La traduction française de la documentation n'est pas très complète ni optimisée pour le moment, mais vous pouvez la trouver [ici](http://playground.arduino.cc/French/Reference). Il existe cette présentation un peu plus complète que ce que j'ai fait : [ici](http://www.craslab.org/arduino/LivretArduinoFr06.pdf), surtout slide 10, 16, 17 et 34. (Pour ceux qui maîtrisent l'anglais, la [référence anglaise](http://arduino.cc/en/Reference/HomePage) en plutôt bien faite.)

Pour aller plus loin
====================

- Kit cool pour démarrer (un breadboard, résistances, condensateurs, fils, un servomoteur et quelques capteurs) : voir [ici](http://boutique.semageek.com/fr/32-sidekick-basic-kit.html).
- Capteur [ultrason](http://boutique.semageek.com/fr/372-capteur-de-distance-ultrason-hc-sr04.html) pour obtenir une distance face à des obstacles
- S'affranchir de la carte Arduino en mettant le microcontrolleur sur un breadboard : [ici](https://gist.github.com/alexAubin/018eb7c4200e0df6ed50)
- Pour ceux qui souhaitent apprendre de façon complète la programmation en C/C++ : [openClassRooms](http://openclassrooms.com/courses/programmez-avec-le-langage-c)

