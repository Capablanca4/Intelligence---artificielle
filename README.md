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
               
    Echiquier ( utilise Case )
    
    Viewer(utilisé par Case et Echiquier)
    ViewerPort(utilié par Viewer)


Site important pour le coté graphique : http://perso.iut-nimes.fr/wdesrat/faq06.html

Site important pour les gestions de la souris : https://www.cs.colorado.edu/~main/bgi/doc/getmouseclick.html
