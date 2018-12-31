#include "doctest.h"
#include<sstream>
#include<iostream>
#include "CaseVide.h"
#include "Echiquier.h"
#include "Game.h"
#include "Bouton.h"

/** Les fonctions de dessins ne sont pas prises en compte dans ces tests */

/** Les classes suivantes ont déja des tests unitaires : - BlocLaser              l.29
                                                         - Case                   l.84
                                                         - CaseVide               l.112
                                                         - Cible                  l.138
                                                         - CibleHorizontale       l.157
                                                         - CibleVerticale         l.201
                                                         - Laser                  l.245
                                                         - MiroirGaucheVersBas    l.273
                                                         - MiroirGaucheVersHaut   l.389
                                                         - Monstre                l.505
                                                         - Mur                    l.532
                                                         - Echiquier              l.541
                                                         - Viewer                 l.767
                                                         - Bouton                 l.793
                                                         - TableauDeScore         l.802
                                                         - Game                   l.813
*/

TEST_CASE("Les methodes de Bloclaser sont correctes"){
    int x=6, y=7,cote=20;
    ecran::BlocLaser bloc{x,y,cote};

    SUBCASE("La methode direction() est correcte"){
        REQUIRE_EQ(bloc.direction(),ecran::Gauche);
    }

    SUBCASE("La methode setDirection() est correcte"){
        ecran::TDirection direc{ecran::Droite};
        bloc.setDirection(direc);
        REQUIRE_EQ(bloc.direction(),direc);
    }

    SUBCASE("La methode shoot() est correcte"){
        int x1=1,y1=1;
        int nbLigne=20,nbColonne=20;
        ecran::Game Jeu{nbLigne,nbColonne,cote};
        ecran::BlocLaser* bloc1 = new ecran::BlocLaser{x1,y1,cote};
        Jeu.plateau().setCase(bloc1);

        SUBCASE("La methode shoot() creer un Laser avec la bonne direction(Gauche)"){
            ecran::TDirection direc{ecran::Gauche};
            bloc1->setDirection(direc);
            ecran::Laser* las=bloc1->shoot();
            REQUIRE_EQ(direc,las->direction());
        }

        SUBCASE("La methode shoot() creer un Laser avec la bonne direction(Droite)"){
            ecran::TDirection direc{ecran::Droite};
            bloc1->setDirection(direc);
            ecran::Laser* las=bloc1->shoot();
            REQUIRE_EQ(direc,las->direction());
        }

        SUBCASE("La methode shoot() creer un Laser avec la bonne direction(Haut)"){
            ecran::TDirection direc{ecran::Haut};
            bloc1->setDirection(direc);
            ecran::Laser* las=bloc1->shoot();
            REQUIRE_EQ(direc,las->direction());
        }

        SUBCASE("La methode shoot() creer un Laser avec la bonne direction(Bas)"){
            ecran::TDirection direc{ecran::Bas};
            bloc1->setDirection(direc);
            ecran::Laser* las=bloc1->shoot();
            REQUIRE_EQ(direc,las->direction());
        }
    }

    SUBCASE("La metode typeObjet() est correcte"){
        REQUIRE_EQ("Ceci est un BlocLaser",bloc.typeObjet());
    }
}

TEST_CASE("Les methodes de Case sont correctes"){

    int x=6, y=7,cote=20;
    ecran::CaseVide cas{x,y,cote};

    SUBCASE("La methode centre() est correcte"){
        ecran::Point centre{x,y};
        REQUIRE_EQ(cas.centre().x(),centre.x());
        REQUIRE_EQ(cas.centre().y(),centre.y());
    }

    SUBCASE("La methode cote() est correcte"){
        REQUIRE_EQ(cote,cas.cote());
    }

    SUBCASE("La methode posNextMoveLaser() est correcte"){
        int nbLigne=20,nbColonne=20;
        ecran::Game Jeu{nbLigne,nbColonne,cote};
        ecran::Case* cas1=(ecran::Case*) Jeu.plateau().emplacementCase(x,y);
        REQUIRE_EQ(cas1->posNextMoveLaser(Jeu,0).x,x);
        REQUIRE_EQ(cas1->posNextMoveLaser(Jeu,0).y,y);
    }

    /*SUBCASE("La metode typeObjet() est correcte"){
        REQUIRE_EQ("Ceci est une Case",cas.typeObjet());
    }*/ /** Ne marche plus ce qui est normal*/
}

TEST_CASE("Les methodes de CaseVide sont correctes"){
    int x=6, y=7,cote=20;
    ecran::CaseVide cas{x,y,cote};

    SUBCASE("La methode touch() est correcte"){
        int nbLigne=20,nbColonne=20,cote=20;
        ecran::Echiquier tabl{nbLigne,nbColonne,cote};
        ecran::Game Jeu{nbLigne,nbColonne,cote};
        REQUIRE_FALSE(!cas.touch(Jeu,0));
    }

    SUBCASE("La methode transformation() est correcte"){
        int nbLigne=20,nbColonne=20;
        ecran::Echiquier tabl{nbLigne,nbColonne,cote};
        ecran::Case* cas1=(ecran::Case*) tabl.emplacementCase(x,y);
        cas1->transformation(tabl);
        cas1=tabl.emplacementCase(x,y);
        REQUIRE_EQ("Ceci est un MiroirGaucheVersBas",cas1->typeObjet());
    }

    SUBCASE("La metode typeObjet() est correcte"){
        REQUIRE_EQ("Ceci est une CaseVide",cas.typeObjet());
    }

}

TEST_CASE("Les methodes de Cible sont correctes"){
    int x=6, y=7,cote=20;
    int nbLigne=20,nbColonne=20;
    ecran::Cible cible{x,y,cote};
    ecran::Game Jeu{nbLigne,nbColonne,cote};

    SUBCASE("La methode touch() est correcte"){
        ecran::Cible* cible1 = new ecran::Cible{x,y,cote};
        Jeu.plateau().setCase(cible1);
        Jeu.addLaser(ecran::coord{0,0});
        REQUIRE_FALSE(cible1->touch(Jeu,0));/** Cas avec 1 Laser */
        REQUIRE_FALSE(!Jeu.touch(0));
    }

    SUBCASE("La methode typeObjet() est correcte"){
        REQUIRE_EQ("Ceci est une Cible",cible.typeObjet());
    }
}

TEST_CASE("Les methodes de CibleHorizontale sont correctes"){

    int nbLigne=20,nbColonne=20;
    int x=2,y=2,cote=20;
    ecran::Game Jeu{nbLigne,nbColonne,cote};

    SUBCASE("La methode touch() est correcte "){
        ecran::CibleHorizontale* cible = new ecran::CibleHorizontale{Jeu.plateau().coordVersPoint(x),Jeu.plateau().coordVersPoint(y),cote};
        Jeu.plateau().setCase(cible);
        ecran::Laser* las= new ecran::Laser{Jeu.plateau().coordVersPoint(x),Jeu.plateau().coordVersPoint(y-1),cote};
        Jeu.plateau().setCase(las);
        Jeu.addLaser(ecran::coord{x,y-1});

        SUBCASE("La methode touch() renvoie faux"){
            REQUIRE_FALSE(Jeu.plateau().emplacementCase(x,y)->touch(Jeu,0));}

        SUBCASE("La methode touch() modifie le Game selon le direction du Laser(Haut)"){
            las->setDirection(ecran::Haut);
            if(!cible->touch(Jeu,0))REQUIRE_FALSE(!Jeu.touch(0));
       }

       SUBCASE("La methode touch() modifie le Game selon le direction du Laser(Bas)"){
            las->setDirection(ecran::Bas);
            if(!cible->touch(Jeu,0))REQUIRE_FALSE(!Jeu.touch(0));
       }

       SUBCASE("La methode touch() modifie le Game selon le direction du Laser(Droite)"){
            las->setDirection(ecran::Droite);
            if(!cible->touch(Jeu,0))REQUIRE_FALSE(Jeu.touch(0));
       }

       SUBCASE("La methode touch() modifie le Game selon le direction du Laser(Gauche)"){
            las->setDirection(ecran::Gauche);
            if(!cible->touch(Jeu,0))REQUIRE_FALSE(Jeu.touch(0));
       }
   }

   SUBCASE("La methode typeObjet() est correcte"){
        ecran::CibleHorizontale cible{x,y,cote};
        REQUIRE_EQ("Ceci est une CibleHorizontale",cible.typeObjet());
   }

}

TEST_CASE("Les methodes de CibleVerticale sont correctes"){

    int nbLigne=20,nbColonne=20;
    int x1=2,y1=2,cote=20;
    ecran::Game Jeu{nbLigne,nbColonne,cote};

    SUBCASE("La methode touch() est correcte"){
        ecran::CibleVerticale* cible = new ecran::CibleVerticale{Jeu.plateau().coordVersPoint(x1),Jeu.plateau().coordVersPoint(y1),cote};
        Jeu.plateau().setCase(cible);
        ecran::Laser* las= new ecran::Laser{Jeu.plateau().coordVersPoint(x1),Jeu.plateau().coordVersPoint(y1-1),cote};
        Jeu.plateau().setCase(las);
        Jeu.addLaser(ecran::coord{x1,y1-1});

        SUBCASE("La methode touch() renvoie faux"){
            REQUIRE_FALSE(Jeu.plateau().emplacementCase(x1,y1)->touch(Jeu,0));}

        SUBCASE("La methode touch() modifie le Game selon le direction du Laser(Haut)"){
            las->setDirection(ecran::Haut);
            if(!cible->touch(Jeu,0))REQUIRE_FALSE(Jeu.touch(0));
       }

       SUBCASE("La methode touch() modifie le Game selon le direction du Laser(Bas)"){
            las->setDirection(ecran::Bas);
            if(!cible->touch(Jeu,0))REQUIRE_FALSE(Jeu.touch(0));
       }

       SUBCASE("La methode touch() modifie le Game selon le direction du Laser(Droite)"){
            las->setDirection(ecran::Droite);
            if(!cible->touch(Jeu,0))REQUIRE_FALSE(!Jeu.touch(0));
       }

       SUBCASE("La methode touch() modifie le Game selon le direction du Laser(Gauche)"){
            las->setDirection(ecran::Gauche);
            if(!cible->touch(Jeu,0))REQUIRE_FALSE(!Jeu.touch(0));
       }
    }

    SUBCASE("La methode typeObjet() est correcte"){
        ecran::CibleVerticale cible{x1,y1,cote};
        REQUIRE_EQ("Ceci est une CibleVerticale",cible.typeObjet());
   }

}

TEST_CASE("Les methodes de Laser sont correctes"){

    int x1=2,y1=2,cote=20;

    SUBCASE("Le constructeur par defaut est correcte"){
        ecran::Laser las{x1,y1,cote};
        REQUIRE_EQ(las.direction(),ecran::Droite);
    }

    SUBCASE("La methode direction() est correcte"){
        ecran::TDirection direc{ecran::Gauche};
        ecran::Laser las{x1,y1,cote,direc};
        REQUIRE_EQ(las.direction(),direc);
    }

    SUBCASE("la methode setDirection() est correcte"){
        ecran::TDirection direc{ecran::Droite};
        ecran::Laser las{x1,y1,cote};
        las.setDirection(direc);
        REQUIRE_EQ(las.direction(),direc);
    }

    SUBCASE("La methode typeObjet() est correcte"){
        ecran::Laser las{x1,y1,cote};
        REQUIRE_EQ(las.typeObjet(),"Ceci est un Laser");
    }
}

TEST_CASE("Les methodes de MiroirGaucheVersBas sont correctes"){

    int nbLigne=20,nbColonne=20;
    int x1=2,y1=2,cote=20;
    ecran::Game Jeu{nbLigne,nbColonne,cote};

    SUBCASE("La methode posNextMoveLaser est correcte quand on ne se situe pas au bord du tableau"){
        ecran::MiroirGaucheVersBas* mir= new ecran::MiroirGaucheVersBas{Jeu.plateau().coordVersPoint(x1),Jeu.plateau().coordVersPoint(y1),cote};
        Jeu.plateau().setCase(mir);

        SUBCASE("Cas ou le Laser vient de la Gauche "){
            ecran::Laser* las= new ecran::Laser{Jeu.plateau().coordVersPoint(x1+1),Jeu.plateau().coordVersPoint(y1),cote};
            Jeu.plateau().setCase(las);
            Jeu.addLaser(ecran::coord{x1+1,y1});
            las->setDirection(ecran::Gauche);
            ecran::coord test= mir->posNextMoveLaser(Jeu,0);
            REQUIRE_EQ(test.x,x1);
            REQUIRE_EQ(test.y,y1-1);
        }

        SUBCASE("Cas ou le Laser vient de la Droite "){
            ecran::Laser* las= new ecran::Laser{Jeu.plateau().coordVersPoint(x1-1),Jeu.plateau().coordVersPoint(y1),cote};
            Jeu.plateau().setCase(las);
            Jeu.addLaser(ecran::coord{x1-1,y1});
            las->setDirection(ecran::Droite);
            ecran::coord test= mir->posNextMoveLaser(Jeu,0);
            REQUIRE_EQ(test.x,x1);
            REQUIRE_EQ(test.y,y1+1);
        }

        SUBCASE("Cas ou le Laser vient d'en Haut "){
            ecran::Laser* las= new ecran::Laser{Jeu.plateau().coordVersPoint(x1),Jeu.plateau().coordVersPoint(y1+1),cote};
            Jeu.plateau().setCase(las);
            Jeu.addLaser(ecran::coord{x1,y1+1});
            las->setDirection(ecran::Haut);
            ecran::coord test= mir->posNextMoveLaser(Jeu,0);
            REQUIRE_EQ(test.x,x1+1);
            REQUIRE_EQ(test.y,y1);
        }

        SUBCASE("Cas ou le Laser vient d'en Bas "){
            ecran::Laser* las= new ecran::Laser{Jeu.plateau().coordVersPoint(x1),Jeu.plateau().coordVersPoint(y1-1),cote};
            Jeu.plateau().setCase(las);
            Jeu.addLaser(ecran::coord{x1,y1-1});
            las->setDirection(ecran::Bas);
            ecran::coord test= mir->posNextMoveLaser(Jeu,0);
            REQUIRE_EQ(test.x,x1-1);
            REQUIRE_EQ(test.y,y1);
        }
    }

    SUBCASE("La methode posNextMoveLaser est correcte quand on se situe au bord du tableau"){

        SUBCASE("Cas ou le Laser vient de la Gauche "){
            ecran::MiroirGaucheVersBas* mir= new ecran::MiroirGaucheVersBas{Jeu.plateau().coordVersPoint(x1),Jeu.plateau().coordVersPoint(0),cote};
            Jeu.plateau().setCase(mir);
            ecran::Laser* las = new ecran::Laser{Jeu.plateau().coordVersPoint(x1),Jeu.plateau().coordVersPoint(1),cote};
            Jeu.plateau().setCase(las);
            Jeu.addLaser(ecran::coord{x1,1});
            las->setDirection(ecran::Gauche);
            ecran::coord test= mir->posNextMoveLaser(Jeu,0);
            REQUIRE_EQ(test.x,x1);
            REQUIRE_EQ(test.y,0);
        }

        SUBCASE("Cas ou le Laser vient de la Droite "){
            ecran::MiroirGaucheVersBas* mir= new ecran::MiroirGaucheVersBas{Jeu.plateau().coordVersPoint(x1),Jeu.plateau().coordVersPoint(nbLigne-1),cote};
            Jeu.plateau().setCase(mir);
            ecran::Laser* las = new ecran::Laser{Jeu.plateau().coordVersPoint(x1),Jeu.plateau().coordVersPoint(nbLigne-2),cote};
            Jeu.plateau().setCase(las);
            Jeu.addLaser(ecran::coord{x1,nbLigne-2});
            las->setDirection(ecran::Droite);
            ecran::coord test= mir->posNextMoveLaser(Jeu,0);
            REQUIRE_EQ(test.x,x1);
            REQUIRE_EQ(test.y,nbLigne-1);
        }

        SUBCASE("Cas ou le Laser vient d'en Bas "){
            ecran::MiroirGaucheVersBas* mir= new ecran::MiroirGaucheVersBas{Jeu.plateau().coordVersPoint(0),Jeu.plateau().coordVersPoint(y1),cote};
            Jeu.plateau().setCase(mir);
            ecran::Laser* las = new ecran::Laser{Jeu.plateau().coordVersPoint(1),Jeu.plateau().coordVersPoint(y1),cote};
            Jeu.plateau().setCase(las);
            Jeu.addLaser(ecran::coord{1,y1});
            las->setDirection(ecran::Bas);
            ecran::coord test= mir->posNextMoveLaser(Jeu,0);
            REQUIRE_EQ(test.x,0);
            REQUIRE_EQ(test.y,y1);
        }

    SUBCASE("Cas ou le Laser vient d'en Haut "){
            ecran::MiroirGaucheVersBas* mir= new ecran::MiroirGaucheVersBas{Jeu.plateau().coordVersPoint(nbColonne-1),Jeu.plateau().coordVersPoint(y1),cote};
            Jeu.plateau().setCase(mir);
            ecran::Laser* las = new ecran::Laser{Jeu.plateau().coordVersPoint(nbColonne-2),Jeu.plateau().coordVersPoint(y1),cote};
            Jeu.plateau().setCase(las);
            Jeu.addLaser(ecran::coord{nbColonne-2,y1});
            las->setDirection(ecran::Haut);
            ecran::coord test= mir->posNextMoveLaser(Jeu,0);
            REQUIRE_EQ(test.x,nbColonne-1);
            REQUIRE_EQ(test.y,y1);
        }
    }

    SUBCASE("la methode transformation() est correcte"){
        ecran::MiroirGaucheVersBas* mir= new ecran::MiroirGaucheVersBas{Jeu.plateau().coordVersPoint(x1),Jeu.plateau().coordVersPoint(y1),cote};
        Jeu.plateau().setCase(mir);
        mir->transformation(Jeu.plateau());
        ecran::MiroirGaucheVersHaut * mir2= (ecran::MiroirGaucheVersHaut *) Jeu.plateau().emplacementCase(x1,y1);
        REQUIRE_EQ(mir2->typeObjet(),"Ceci est un MiroirGaucheVersHaut");
    }

    SUBCASE("la methode typeObjet() est correcte"){
        ecran::MiroirGaucheVersBas* mir= new ecran::MiroirGaucheVersBas{Jeu.plateau().coordVersPoint(x1),Jeu.plateau().coordVersPoint(y1),cote};
        REQUIRE_EQ(mir->typeObjet(),"Ceci est un MiroirGaucheVersBas");
    }
}

TEST_CASE("Les methodes de MiroirGaucheVersHaut sont correctes"){

    int nbLigne=20,nbColonne=20;
    int x1=2,y1=2,cote=20;
    ecran::Game Jeu{nbLigne,nbColonne,cote};

    SUBCASE("La methode posNextMoveLaser est correcte quand on ne se situe pas au bord du tableau"){
        ecran::MiroirGaucheVersHaut* mir= new ecran::MiroirGaucheVersHaut{Jeu.plateau().coordVersPoint(x1),Jeu.plateau().coordVersPoint(y1),cote};
        Jeu.plateau().setCase(mir);

        SUBCASE("Cas ou le Laser vient de la Gauche "){
            ecran::Laser* las= new ecran::Laser{Jeu.plateau().coordVersPoint(x1-1),Jeu.plateau().coordVersPoint(y1),cote};
            Jeu.plateau().setCase(las);
            Jeu.addLaser(ecran::coord{x1-1,y1});
            las->setDirection(ecran::Gauche);
            ecran::coord test= mir->posNextMoveLaser(Jeu,0);
            REQUIRE_EQ(test.x,x1);
            REQUIRE_EQ(test.y,y1+1);
        }

        SUBCASE("Cas ou le Laser vient de la Droite "){
            ecran::Laser* las= new ecran::Laser{Jeu.plateau().coordVersPoint(x1+1),Jeu.plateau().coordVersPoint(y1),cote};
            Jeu.plateau().setCase(las);
            Jeu.addLaser(ecran::coord{x1+1,y1});
            las->setDirection(ecran::Droite);
            ecran::coord test= mir->posNextMoveLaser(Jeu,0);
            REQUIRE_EQ(test.x,x1);
            REQUIRE_EQ(test.y,y1-1);
        }

        SUBCASE("Cas ou le Laser vient d'en Haut "){
            ecran::Laser* las= new ecran::Laser{Jeu.plateau().coordVersPoint(x1),Jeu.plateau().coordVersPoint(y1-1),cote};
            Jeu.plateau().setCase(las);
            Jeu.addLaser(ecran::coord{x1,y1-1});
            las->setDirection(ecran::Haut);
            ecran::coord test= mir->posNextMoveLaser(Jeu,0);
            REQUIRE_EQ(test.x,x1-1);
            REQUIRE_EQ(test.y,y1);
        }

        SUBCASE("Cas ou le Laser vient d'en Bas "){
            ecran::Laser* las= new ecran::Laser{Jeu.plateau().coordVersPoint(x1),Jeu.plateau().coordVersPoint(y1+1),cote};
            Jeu.plateau().setCase(las);
            Jeu.addLaser(ecran::coord{x1,y1+1});
            las->setDirection(ecran::Bas);
            ecran::coord test= mir->posNextMoveLaser(Jeu,0);
            REQUIRE_EQ(test.x,x1+1);
            REQUIRE_EQ(test.y,y1);
        }
    }

    SUBCASE("La methode posNextMoveLaser est correcte quand on se situe au bord du tableau"){

        SUBCASE("Cas ou le Laser vient de la Gauche "){
            ecran::MiroirGaucheVersHaut* mir= new ecran::MiroirGaucheVersHaut{Jeu.plateau().coordVersPoint(x1),Jeu.plateau().coordVersPoint(nbLigne-1),cote};
            Jeu.plateau().setCase(mir);
            ecran::Laser* las = new ecran::Laser{Jeu.plateau().coordVersPoint(x1),Jeu.plateau().coordVersPoint(nbLigne-2),cote};
            Jeu.plateau().setCase(las);
            Jeu.addLaser(ecran::coord{x1,nbLigne-2});
            las->setDirection(ecran::Gauche);
            ecran::coord test= mir->posNextMoveLaser(Jeu,0);
            REQUIRE_EQ(test.x,x1);
            REQUIRE_EQ(test.y,nbLigne-1);
        }

        SUBCASE("Cas ou le Laser vient de la Droite "){
            ecran::MiroirGaucheVersHaut* mir= new ecran::MiroirGaucheVersHaut{Jeu.plateau().coordVersPoint(x1),Jeu.plateau().coordVersPoint(0),cote};
            Jeu.plateau().setCase(mir);
            ecran::Laser* las = new ecran::Laser{Jeu.plateau().coordVersPoint(x1),Jeu.plateau().coordVersPoint(1),cote};
            Jeu.plateau().setCase(las);
            Jeu.addLaser(ecran::coord{x1,1});
            las->setDirection(ecran::Droite);
            ecran::coord test= mir->posNextMoveLaser(Jeu,0);
            REQUIRE_EQ(test.x,x1);
            REQUIRE_EQ(test.y,0);
        }

        SUBCASE("Cas ou le Laser vient d'en Bas "){
            ecran::MiroirGaucheVersHaut* mir= new ecran::MiroirGaucheVersHaut{Jeu.plateau().coordVersPoint(nbColonne-1),Jeu.plateau().coordVersPoint(y1),cote};
            Jeu.plateau().setCase(mir);
            ecran::Laser* las = new ecran::Laser{Jeu.plateau().coordVersPoint(nbColonne-2),Jeu.plateau().coordVersPoint(y1),cote};
            Jeu.plateau().setCase(las);
            Jeu.addLaser(ecran::coord{nbColonne-2,y1});
            las->setDirection(ecran::Bas);
            ecran::coord test= mir->posNextMoveLaser(Jeu,0);
            REQUIRE_EQ(test.x,nbColonne-1);
            REQUIRE_EQ(test.y,y1);
        }

        SUBCASE("Cas ou le Laser vient d'en Haut "){
            ecran::MiroirGaucheVersHaut* mir= new ecran::MiroirGaucheVersHaut{Jeu.plateau().coordVersPoint(0),Jeu.plateau().coordVersPoint(y1),cote};
            Jeu.plateau().setCase(mir);
            ecran::Laser* las = new ecran::Laser{Jeu.plateau().coordVersPoint(1),Jeu.plateau().coordVersPoint(y1),cote};
            Jeu.plateau().setCase(las);
            Jeu.addLaser(ecran::coord{1,y1});
            las->setDirection(ecran::Haut);
            ecran::coord test= mir->posNextMoveLaser(Jeu,0);
            REQUIRE_EQ(test.x,0);
            REQUIRE_EQ(test.y,y1);
        }
    }

    SUBCASE("la methode transformation() est correcte"){
        ecran::MiroirGaucheVersHaut* mir= new ecran::MiroirGaucheVersHaut{Jeu.plateau().coordVersPoint(x1),Jeu.plateau().coordVersPoint(y1),cote};
        Jeu.plateau().setCase(mir);
        mir->transformation(Jeu.plateau());
        ecran::CaseVide * mir2= (ecran::CaseVide *) Jeu.plateau().emplacementCase(x1,y1);
        REQUIRE_EQ(mir2->typeObjet(),"Ceci est une CaseVide");
    }

    SUBCASE("la methode typeObjet() est correcte"){
        ecran::MiroirGaucheVersHaut* mir= new ecran::MiroirGaucheVersHaut{Jeu.plateau().coordVersPoint(x1),Jeu.plateau().coordVersPoint(y1),cote};
        REQUIRE_EQ(mir->typeObjet(),"Ceci est un MiroirGaucheVersHaut");
    }
}

TEST_CASE("Les methodes de Monstre sont correctes"){

    int nbLigne=20,nbColonne=20,cote=20;
    int x=1,y=1;
    ecran::Game Jeu{nbLigne,nbColonne,cote};

    SUBCASE("La methode touch() est correcte"){

        ecran::Monstre mons {x,y,cote};
        REQUIRE_FALSE(!mons.touch(Jeu,0));
        REQUIRE_EQ(Jeu.score(),100);
    }

    SUBCASE("La methode changement() est correcte"){
        ecran::Monstre* mons= new ecran::Monstre{Jeu.plateau().coordVersPoint(x),Jeu.plateau().coordVersPoint(y),cote};
        Jeu.plateau().setCase(mons);
        mons->changement(Jeu.plateau());
        ecran::CaseVide * mir2= (ecran::CaseVide *) Jeu.plateau().emplacementCase(x,y);
        REQUIRE_EQ(mir2->typeObjet(),"Ceci est une CaseVide");
    }

    SUBCASE("La methode typeObjet() est correcte"){
        ecran::Monstre mons {x,y,cote};
        REQUIRE_EQ(mons.typeObjet(),"Ceci est un Monstre");
    }
}

TEST_CASE("Les methodes de Mur sont correctes"){

    SUBCASE("La methode typeObjet() est correcte"){
        int x=1,y=1,cote=20;
        ecran::Mur mur {x,y,cote};
        REQUIRE_EQ(mur.typeObjet(),"Ceci est un Mur");
    }
}

TEST_CASE("Les methodes de Echiquier sont correctes"){

    int nbLigne=20,nbColonne=20;
    int x=2,y=2,cote=20;
    ecran::Game Jeu{nbLigne,nbColonne,cote};

    SUBCASE("Les methodes emplacementCase() sont correctes"){
        ecran::BlocLaser* bloc = new ecran::BlocLaser{Jeu.plateau().coordVersPoint(x),Jeu.plateau().coordVersPoint(y),cote};
        Jeu.plateau().setCase(bloc);

        SUBCASE("emplacementCase(x,y) est correcte"){
            ecran::Case* cas=Jeu.plateau().emplacementCase(x,y);
            REQUIRE_EQ(cas,bloc);}

        SUBCASE("emplacementCase(coord& coor) est correcte"){
            ecran::coord coor{x,y};
            ecran::Case* cas=Jeu.plateau().emplacementCase(coor);
            REQUIRE_EQ(cas,bloc);}

        SUBCASE("emplacementCase(Point& emplacement) est correcte"){
            ecran::Point point{x,y};
            ecran::Case* cas=Jeu.plateau().emplacementCase(point);
            REQUIRE_EQ(cas,bloc);}

        /*SUBCASE("emplacementCase(Case*& cas) est correcte"){
            const ecran::Case*& cas1=(ecran::Case*)& bloc;
            ecran::Case* cas2=Jeu.plateau().emplacementCase(cas1);
            REQUIRE_EQ(cas2,bloc);}
        }*/
    }

    SUBCASE("La methode setCase() est correcte"){
        ecran::Mur* bloc = new ecran::Mur{Jeu.plateau().coordVersPoint(x),Jeu.plateau().coordVersPoint(y),cote};
        Jeu.plateau().setCase(bloc);
        REQUIRE_EQ(bloc,Jeu.plateau().emplacementCase(x,y));
    }

    SUBCASE("Les methodes pointVersCoord() sont correctes"){
        int x1=30,y1=50;

        SUBCASE("La methode pointVersCoord(int x) est correcte"){
            REQUIRE_EQ(((x1-cote/2)/cote),Jeu.plateau().pointVersCoord(x1));
            }

        SUBCASE("La methode pointVersCoord(int x,int y) est correcte"){
            ecran::coord coordTest=Jeu.plateau().pointVersCoord(x1,y1);
            REQUIRE_EQ(((x1-cote/2)/cote),coordTest.x);
            REQUIRE_EQ(((y1-cote/2)/cote),coordTest.y);
        }

        SUBCASE("La methode pointVersCoord(Case* cas) est correcte"){
            ecran::CaseVide* cas= new ecran::CaseVide{x1,y1,cote};
            ecran::coord coordTest=Jeu.plateau().pointVersCoord(cas);
            REQUIRE_EQ(((x1-cote/2)/cote),coordTest.x);
            REQUIRE_EQ(((y1-cote/2)/cote),coordTest.y);
        }
    }

    SUBCASE("La methode coordVersPoint() est correcte"){
        REQUIRE_EQ(Jeu.plateau().coordVersPoint(x),x*cote+cote/2);
    }

    SUBCASE("La methode move() est correcte "){

        SUBCASE("Quand le Laser va vers la Gauche "){

            SUBCASE("Dans le cas ou le Laser n'est pas bloque et on ne se situe pas au bord du tableau"){
                ecran::Laser* las= new ecran::Laser{Jeu.plateau().coordVersPoint(x),Jeu.plateau().coordVersPoint(y),cote};
                Jeu.plateau().setCase(las);
                Jeu.addLaser(ecran::coord{x,y});
                las->setDirection(ecran::Gauche);
                Jeu.plateau().move(Jeu,0);
                REQUIRE_EQ(Jeu.plateau().emplacementCase(x,y)->typeObjet(),"Ceci est une CaseVide");
                REQUIRE_EQ(Jeu.plateau().emplacementCase(Jeu.coordLas(0))->typeObjet(),"Ceci est un Laser");
            }

            SUBCASE("Dans le cas ou est correcte quand le Laser est bloque"){
                ecran::Laser* las= new ecran::Laser{Jeu.plateau().coordVersPoint(x),Jeu.plateau().coordVersPoint(y),cote};
                Jeu.plateau().setCase(las);
                Jeu.addLaser(ecran::coord{x,y});
                las->setDirection(ecran::Gauche);
                ecran::Mur* mur= new ecran::Mur{Jeu.plateau().coordVersPoint(x-1),Jeu.plateau().coordVersPoint(y),cote};
                Jeu.plateau().setCase(mur);
                Jeu.plateau().move(Jeu,0);
                REQUIRE_FALSE(Jeu.inMove(0));
            }

            SUBCASE("Dans le cas ou on se situe au bord du tableau "){
                ecran::Laser* las= new ecran::Laser{Jeu.plateau().coordVersPoint(0),Jeu.plateau().coordVersPoint(y),cote};
                Jeu.plateau().setCase(las);
                Jeu.addLaser(ecran::coord{0,y});
                las->setDirection(ecran::Gauche);
                Jeu.plateau().move(Jeu,0);
                REQUIRE_FALSE(Jeu.inMove(0));

            }
        }

        SUBCASE("Quand le Laser va vers la Droite "){

            SUBCASE("Dans le cas ou le Laser n'est pas bloque et on ne se situe pas au bord du tableau"){
                ecran::Laser* las= new ecran::Laser{Jeu.plateau().coordVersPoint(x),Jeu.plateau().coordVersPoint(y),cote};
                Jeu.plateau().setCase(las);
                Jeu.addLaser(ecran::coord{x,y});
                las->setDirection(ecran::Droite);
                Jeu.plateau().move(Jeu,0);
                REQUIRE_EQ(Jeu.plateau().emplacementCase(x,y)->typeObjet(),"Ceci est une CaseVide");
                REQUIRE_EQ(Jeu.plateau().emplacementCase(Jeu.coordLas(0))->typeObjet(),"Ceci est un Laser");
            }

            SUBCASE("Dans le cas ou le Laser est bloque"){
                ecran::Laser* las= new ecran::Laser{Jeu.plateau().coordVersPoint(x),Jeu.plateau().coordVersPoint(y),cote};
                Jeu.plateau().setCase(las);
                Jeu.addLaser(ecran::coord{x,y});
                las->setDirection(ecran::Droite);
                ecran::Mur* mur= new ecran::Mur{Jeu.plateau().coordVersPoint(x+1),Jeu.plateau().coordVersPoint(y),cote};
                Jeu.plateau().setCase(mur);
                Jeu.plateau().move(Jeu,0);
                REQUIRE_FALSE(Jeu.inMove(0));
            }

            SUBCASE("Dans le cas ou on se situe au bord du tableau "){
                ecran::Laser* las= new ecran::Laser{Jeu.plateau().coordVersPoint(nbColonne-1),Jeu.plateau().coordVersPoint(y),cote};
                Jeu.plateau().setCase(las);
                Jeu.addLaser(ecran::coord{nbColonne-1,y});
                las->setDirection(ecran::Droite);
                Jeu.plateau().move(Jeu,0);
                REQUIRE_FALSE(Jeu.inMove(0));
            }
        }

        SUBCASE("Quand le Laser va vers le Haut "){

            SUBCASE("Dans le cas ou le Laser n'est pas bloque et on ne se situe pas au bord du tableau"){
                ecran::Laser* las= new ecran::Laser{Jeu.plateau().coordVersPoint(x),Jeu.plateau().coordVersPoint(y),cote};
                Jeu.plateau().setCase(las);
                Jeu.addLaser(ecran::coord{x,y});
                las->setDirection(ecran::Haut);
                Jeu.plateau().move(Jeu,0);
                REQUIRE_EQ(Jeu.plateau().emplacementCase(x,y)->typeObjet(),"Ceci est une CaseVide");
                REQUIRE_EQ(Jeu.plateau().emplacementCase(Jeu.coordLas(0))->typeObjet(),"Ceci est un Laser");
            }

            SUBCASE("Dans le cas ou le Laser est bloque"){
                ecran::Laser* las= new ecran::Laser{Jeu.plateau().coordVersPoint(x),Jeu.plateau().coordVersPoint(y),cote};
                Jeu.plateau().setCase(las);
                Jeu.addLaser(ecran::coord{x,y});
                las->setDirection(ecran::Haut);
                ecran::Mur* mur= new ecran::Mur{Jeu.plateau().coordVersPoint(x),Jeu.plateau().coordVersPoint(y+1),cote};
                Jeu.plateau().setCase(mur);
                Jeu.plateau().move(Jeu,0);
                REQUIRE_FALSE(Jeu.inMove(0));
            }

            SUBCASE("Dans le cas ou on se situe au bord du tableau "){
                ecran::Laser* las= new ecran::Laser{Jeu.plateau().coordVersPoint(x),Jeu.plateau().coordVersPoint(nbLigne-1),cote};
                Jeu.plateau().setCase(las);
                Jeu.addLaser(ecran::coord{x,nbLigne-1});
                las->setDirection(ecran::Haut);
                Jeu.plateau().move(Jeu,0);
                REQUIRE_FALSE(Jeu.inMove(0));
            }
        }

        SUBCASE("Quand le Laser va vers le Bas "){

            SUBCASE("Dans le cas ou le Laser n'est pas bloque et on ne se situe pas au bord du tableau"){
                ecran::Laser* las= new ecran::Laser{Jeu.plateau().coordVersPoint(x),Jeu.plateau().coordVersPoint(y),cote};
                Jeu.plateau().setCase(las);
                Jeu.addLaser(ecran::coord{x,y});
                las->setDirection(ecran::Bas);
                Jeu.plateau().move(Jeu,0);
                REQUIRE_EQ(Jeu.plateau().emplacementCase(x,y)->typeObjet(),"Ceci est une CaseVide");
                REQUIRE_EQ(Jeu.plateau().emplacementCase(Jeu.coordLas(0))->typeObjet(),"Ceci est un Laser");
            }

            SUBCASE("Dans le cas ou le Laser est bloque"){
                ecran::Laser* las= new ecran::Laser{Jeu.plateau().coordVersPoint(x),Jeu.plateau().coordVersPoint(y),cote};
                Jeu.plateau().setCase(las);
                Jeu.addLaser(ecran::coord{x,y});
                las->setDirection(ecran::Bas);
                ecran::Mur* mur= new ecran::Mur{Jeu.plateau().coordVersPoint(x),Jeu.plateau().coordVersPoint(y-1),cote};
                Jeu.plateau().setCase(mur);
                Jeu.plateau().move(Jeu,0);
                REQUIRE_FALSE(Jeu.inMove(0));
            }

            SUBCASE("Dans le cas ou on se situe au bord du tableau "){
                ecran::Laser* las= new ecran::Laser{Jeu.plateau().coordVersPoint(x),Jeu.plateau().coordVersPoint(0),cote};
                Jeu.plateau().setCase(las);
                Jeu.addLaser(ecran::coord{x,0});
                las->setDirection(ecran::Bas);
                Jeu.plateau().move(Jeu,0);
                REQUIRE_FALSE(Jeu.inMove(0));
            }
        }
    }

    SUBCASE("La methode start() est correcte"){
        ecran::BlocLaser* bloc = new ecran::BlocLaser{Jeu.plateau().coordVersPoint(x),Jeu.plateau().coordVersPoint(y),cote};
        Jeu.addLaser(ecran::coord{x,y});
        Jeu.plateau().setCase(bloc);

        SUBCASE("Dans le cas ou la direction du BlocLaser est Droite"){
            bloc->setDirection(ecran::Droite);
            Jeu.plateau().start(Jeu,0);
            REQUIRE_EQ(Jeu.plateau().emplacementCase(x+1,y)->typeObjet(),"Ceci est un Laser");}

        SUBCASE("Dans le cas ou la direction du BlocLaser est Gauche"){
            bloc->setDirection(ecran::Gauche);
            Jeu.plateau().start(Jeu,0);
            REQUIRE_EQ(Jeu.plateau().emplacementCase(x-1,y)->typeObjet(),"Ceci est un Laser");}

        SUBCASE("Dans le cas ou la direction du BlocLaser est Haut"){
            bloc->setDirection(ecran::Haut);
            Jeu.plateau().start(Jeu,0);
            REQUIRE_EQ(Jeu.plateau().emplacementCase(x,y+1)->typeObjet(),"Ceci est un Laser");}

        SUBCASE("Dans le cas ou la direction du BlocLaser est Bas"){
            bloc->setDirection(ecran::Bas);
            Jeu.plateau().start(Jeu,0);
            REQUIRE_EQ(Jeu.plateau().emplacementCase(x,y-1)->typeObjet(),"Ceci est un Laser");}
    }

}

TEST_CASE("Les methodes de Viewer sont correctes"){
    int largeur=500,hauteur=600;
    int decalageX=30,decalageY=80;
    ecran::Viewer fenetre{largeur,hauteur,decalageX,decalageY};

    SUBCASE("La methode pixelX() est correcte"){/** Attention des fois il y a des problèmes dus aux arrondis de conversion */
        REQUIRE_EQ(fenetre.pixelX(0),decalageX);
        REQUIRE_EQ(fenetre.pixelX(hauteur),hauteur-decalageX);
    }

    SUBCASE("La methode pixelY() est correcte"){
        REQUIRE_EQ(fenetre.pixelY(0),largeur-decalageY);
        REQUIRE_EQ(abs(fenetre.pixelY(largeur)-decalageY),0);
    }

    SUBCASE("La methode reversePixelX() est correcte"){
        REQUIRE_EQ(fenetre.reversePixelX(decalageX),0);
        REQUIRE_EQ(fenetre.reversePixelX(hauteur-decalageX),hauteur);
    }

    SUBCASE("La methode reversePixelY() est correcte"){
        REQUIRE_EQ(fenetre.reversePixelY(largeur-decalageY),0);
        REQUIRE_EQ(abs(fenetre.reversePixelY(decalageY)-largeur),0);
    }
}

TEST_CASE("Les methodes de Bouton sont correctes"){ /** Pas grand chose a tester pour l'instant*/

    SUBCASE("La methode texte() est correcte"){
        std::string text{"Bonjour"};
        ecran::Bouton bout{50,50,50,30,text};
        REQUIRE_EQ(bout.texte(),"Bonjour");
    }
}

TEST_CASE("Les methodes de TableauDeScore sont correctes"){
    int x=20,y=20,largeur=70,hauteur=30,add=100;
    ecran::TableauDeScore tabl{x,y,largeur,hauteur};

    SUBCASE("La methode addScore() est correcte"){
        REQUIRE_EQ(tabl.score(),0);
        tabl.addScore(add);
        REQUIRE_EQ(tabl.score(),add);
    }
}

TEST_CASE("Les methodes de Game sont correctes"){
    int nbLigne=20,nbColonne=20,cote=20;
    ecran::Game Jeu{nbLigne,nbColonne,cote};

    SUBCASE("La methode setInMoveFalse() est correcte"){
        Jeu.addLaser({0,0});
        Jeu.setInMoveFalse(0);
        REQUIRE_FALSE(Jeu.inMove(0));
    }

    SUBCASE("La methode setTouchTrue() est correcte"){
        Jeu.addLaser({0,0});
        Jeu.setTouchTrue(0);
        REQUIRE_FALSE(!Jeu.touch(0));
    }

    SUBCASE("La methode addLaser() est correcte"){
        int x=5,y=14;
        Jeu.addLaser({x,y});
        REQUIRE_EQ(Jeu.coordLas(0).x,x);
        REQUIRE_EQ(Jeu.coordLas(0).y,y);
        REQUIRE_EQ(Jeu.nbLaser(),1);
        REQUIRE_FALSE(!Jeu.inMove(0));
        REQUIRE_FALSE(Jeu.touch(0));
    }

    SUBCASE("La methode setCoordLaser() est correcte"){
        int x=5,y=14;
        Jeu.addLaser({x,y});
        Jeu.setCoordLaser({y,x},0);
        REQUIRE_EQ(Jeu.coordLas(0).x,y);
        REQUIRE_EQ(Jeu.coordLas(0).y,x);
    }

    SUBCASE("La methode addScore() est correcte"){
        int score=1000;
        Jeu.addScore(score);
        REQUIRE_EQ(Jeu.score(),score);
    }

    SUBCASE("La methode increaseIter() est correcte"){
        Jeu.increaseIter();
        REQUIRE_EQ(Jeu.iteration(),1);
    }

    SUBCASE("La methode winning() est correcte"){
        Jeu.addLaser({0,0});
        REQUIRE_FALSE(Jeu.winning());
        Jeu.setTouchTrue(0);
        REQUIRE_FALSE(!Jeu.winning());
    }

    SUBCASE("La methode finish() est correcte"){

        SUBCASE("Le jeu doit continuer"){
            Jeu.addLaser({0,0});
            REQUIRE_FALSE(Jeu.finish());
        }

        SUBCASE("Le jeu est fini"){
            Jeu.addLaser({0,0});
            Jeu.setInMoveFalse(0);
            REQUIRE_FALSE(!Jeu.finish());
        }

        SUBCASE("Un Laser est arrete mais pas les autres"){
            Jeu.addLaser({0,0});
            Jeu.addLaser({1,1});
            Jeu.setInMoveFalse(0);
            REQUIRE_FALSE(!Jeu.finish());
        }

        SUBCASE("Un Laser a atteind la cible mais les autres sa deplace encore"){
            Jeu.addLaser({0,0});
            Jeu.addLaser({1,1});
            Jeu.setInMoveFalse(0);
            Jeu.setTouchTrue(0);
            REQUIRE_FALSE(Jeu.finish());
        }
    }
}
