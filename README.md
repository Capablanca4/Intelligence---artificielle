# Prog quality
Projet L3 Prog quality

bonjour ceci est un notre projet de l3 de qualité de programmation ayant pour sujet :
  -Jeu de destructions de cible par laser

ceci est la branche contenant la version 2.0 du projet

j'ai choisi de changer l'UML selon le modèle suivant :

                              Point
                                |
                                V
                               Case
                                |
                                V
   BlocLaser    CaseVide    Cible    MiroirGaucheVersHaut    MiroirGaucheVersBas    Mur
                              |
                              V
               CibleHorizontale    CibleVerticale

Code block option compile :
mingw32-g++.exe  -o bin\Debug\Laser.exe obj\Debug\main.o obj\Debug\src\BlocLaser.o obj\Debug\src\Bouton.o obj\Debug\src\Case.o obj\Debug\src\CaseVide.o obj\Debug\src\Cible.o obj\Debug\src\CibleHorirontale.o obj\Debug\src\CibleVerticale.o obj\Debug\src\Echiquier.o obj\Debug\src\Game.o obj\Debug\src\Laser.o obj\Debug\src\MiroirGaucheVersBas.o obj\Debug\src\MiroirGaucheVersHaut.o obj\Debug\src\Mur.o obj\Debug\src\Point.o obj\Debug\src\Viewer.o obj\Debug\src\viewPort.o  -lgdi32 -lcomdlg32 -luser32 -luuid -loleaut32 -lole32 -lgdi32 -lcomdlg32 -luser32 -luuid -loleaut32 -lole32 -lgdi32 -lcomdlg32 -luser32 -luuid -loleaut32 -lole32  lib\libbgi.a lib\libbgi.a lib\libbgi.a
