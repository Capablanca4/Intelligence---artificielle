#include "doctest.h"
#include<sstream>
#include<iostream>
#include "CaseVide.h"
#include "Echiquier.h"
#include"GameStatut.h"


/** Les fonctions de dessins ne sont pas prises en compte dans ces tests */

/** Les classes suivantes ont déja des tests unitaires : - BlocLaser              l.25
                                                         - Case                   l.81
                                                         - CaseVide               l.115
                                                         - Cible                  l.141
                                                         - CibleHorizontale       l.161
                                                         - CibleVerticale         l.206
                                                         - Laser                  l.251
                                                         - MiroirGaucheVersBas    l.324
                                                         - MiroirGaucheVersHaut   l.440
                                                         - Monstre                l.556
                                                         - Mur                    l.585
                                                         - Echiquier              l.594
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
        ecran::Echiquier tabl{nbLigne,nbColonne,cote};
        ecran::BlocLaser* bloc1 = new ecran::BlocLaser{x1,y1,cote};
        tabl.setCase(bloc1);

        SUBCASE("La methode shoot() creer un Laser avec la bonne direction(Gauche)"){
            ecran::TDirection direc{ecran::Gauche};
            bloc1->setDirection(direc);
            ecran::Laser* las=bloc1->shoot();
            REQUIRE_EQ(ecran::Gauche,bloc.direction());
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

    SUBCASE("La methode changerCote() est correcte"){
        const int newCote=30;
        cas.changerCote(newCote);
        REQUIRE_EQ(newCote,cas.cote());
    }

    SUBCASE("La methode posNextMoveLaser() est correcte"){
        int nbLigne=20,nbColonne=20;
        ecran::Echiquier tabl{nbLigne,nbColonne,cote};/** Plateau remplie de caseVide*/
        ecran::Case* cas1=(ecran::Case*) tabl.emplacementCase(x,y);
        REQUIRE_EQ(cas1->posNextMoveLaser(tabl).x,x);
        REQUIRE_EQ(cas1->posNextMoveLaser(tabl).y,y);
    }

    /*SUBCASE("La metode typeObjet() est correcte"){
        REQUIRE_EQ("Ceci est une Case",cas.typeObjet());
    }*/ /** Ne marche plus ce qui est normal*/
}

TEST_CASE("Les methodes de CaseVide sont correctes"){
    int x=6, y=7,cote=20;
    ecran::CaseVide cas{x,y,cote};

    SUBCASE("La methode touch() est correcte"){
        int nbLigne=20,nbColonne=20;
        ecran::Echiquier tabl{nbLigne,nbColonne,cote};
        GameStatut StatutJeu{1,200};
        REQUIRE_FALSE(!cas.touch(tabl,StatutJeu,0));
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
    ecran::Cible cible{x,y,cote};

    SUBCASE("La methode touch() est correcte"){
        int nbLigne=20,nbColonne=20;
        int x1=1,y1=1;
        ecran::Echiquier tabl{nbLigne,nbColonne,cote};
        GameStatut StatutJeu{1,200};
        ecran::Cible* cible1 = new ecran::Cible{x1,y1,cote};
        tabl.setCase(cible1);
        REQUIRE_FALSE(cible1->touch(tabl,StatutJeu,0));
        REQUIRE_FALSE(!StatutJeu.touch(0));
    }

    SUBCASE("La methode typeObjet() est correcte"){
        REQUIRE_EQ("Ceci est une Cible",cible.typeObjet());
    }
}

TEST_CASE("Les methodes de CibleHorizontale sont correctes"){

    int nbLigne=20,nbColonne=20;
    int x1=2,y1=2,cote=20;

    SUBCASE("La methode touch() est correcte "){
        ecran::Echiquier tabl{nbLigne,nbColonne,cote};
        GameStatut StatutJeu{1,200};
        ecran::CibleHorizontale* cible = new ecran::CibleHorizontale{tabl.coordVersPoint(x1),tabl.coordVersPoint(y1),cote};
        tabl.setCase(cible);
        ecran::Laser* las= new ecran::Laser{tabl.coordVersPoint(x1),tabl.coordVersPoint(y1-1),cote};
        tabl.setCase(las);
        tabl.setCoordLaser(ecran::coord{x1,y1-1});

        SUBCASE("La methode touch() renvoie faux"){
            REQUIRE_FALSE(tabl.emplacementCase(x1,y1)->touch(tabl,StatutJeu,0));}

        SUBCASE("La methode touch() modifie le GameStatut selon le direction du Laser(Haut)"){
            las->setDirection(ecran::Haut);
            if(!cible->touch(tabl,StatutJeu,0))REQUIRE_FALSE(!StatutJeu.touch(0));
       }

       SUBCASE("La methode touch() modifie le GameStatut selon le direction du Laser(Bas)"){
            las->setDirection(ecran::Bas);
            if(!cible->touch(tabl,StatutJeu,0))REQUIRE_FALSE(!StatutJeu.touch(0));
       }

       SUBCASE("La methode touch() modifie le GameStatut selon le direction du Laser(Droite)"){
            las->setDirection(ecran::Droite);
            if(!cible->touch(tabl,StatutJeu,0))REQUIRE_FALSE(StatutJeu.touch(0));
       }

       SUBCASE("La methode touch() modifie le GameStatut selon le direction du Laser(Gauche)"){
            las->setDirection(ecran::Gauche);
            if(!cible->touch(tabl,StatutJeu,0))REQUIRE_FALSE(StatutJeu.touch(0));
       }
   }

   SUBCASE("La methode typeObjet() est correcte"){
        ecran::CibleHorizontale cible{x1,y1,cote};
        REQUIRE_EQ("Ceci est une CibleHorizontale",cible.typeObjet());
   }

}

TEST_CASE("Les methodes de CibleVerticale sont correctes"){

    int nbLigne=20,nbColonne=20;
    int x1=2,y1=2,cote=20;

    SUBCASE("La methode touch() est correcte"){
        ecran::Echiquier tabl{nbLigne,nbColonne,cote};
        GameStatut StatutJeu{1,200};
        ecran::CibleVerticale* cible = new ecran::CibleVerticale{tabl.coordVersPoint(x1),tabl.coordVersPoint(y1),cote};
        tabl.setCase(cible);
        ecran::Laser* las= new ecran::Laser{tabl.coordVersPoint(x1),tabl.coordVersPoint(y1-1),cote};
        tabl.setCase(las);
        tabl.setCoordLaser(ecran::coord{x1,y1-1});

        SUBCASE("La methode touch() renvoie faux"){
            REQUIRE_FALSE(tabl.emplacementCase(x1,y1)->touch(tabl,StatutJeu,0));}

        SUBCASE("La methode touch() modifie le GameStatut selon le direction du Laser(Haut)"){
            las->setDirection(ecran::Haut);
            if(!cible->touch(tabl,StatutJeu,0))REQUIRE_FALSE(StatutJeu.touch(0));
       }

       SUBCASE("La methode touch() modifie le GameStatut selon le direction du Laser(Bas)"){
            las->setDirection(ecran::Bas);
            if(!cible->touch(tabl,StatutJeu,0))REQUIRE_FALSE(StatutJeu.touch(0));
       }

       SUBCASE("La methode touch() modifie le GameStatut selon le direction du Laser(Droite)"){
            las->setDirection(ecran::Droite);
            if(!cible->touch(tabl,StatutJeu,0))REQUIRE_FALSE(!StatutJeu.touch(0));
       }

       SUBCASE("La methode touch() modifie le GameStatut selon le direction du Laser(Gauche)"){
            las->setDirection(ecran::Gauche);
            if(!cible->touch(tabl,StatutJeu,0))REQUIRE_FALSE(!StatutJeu.touch(0));
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

        SUBCASE("La methode direction() est correcte selon la direction du Laser(Gauche)"){
            ecran::TDirection direc{ecran::Gauche};
            ecran::Laser las{x1,y1,cote,direc};
            REQUIRE_EQ(las.direction(),direc);
        }

        SUBCASE("La methode direction() est correcte selon la direction du Laser(Droite)"){
            ecran::TDirection direc{ecran::Droite};
            ecran::Laser las{x1,y1,cote,direc};
            REQUIRE_EQ(las.direction(),direc);
        }

        SUBCASE("La methode direction() est correcte selon la direction du Laser(Haut)"){
            ecran::TDirection direc{ecran::Haut};
            ecran::Laser las{x1,y1,cote,direc};
            REQUIRE_EQ(las.direction(),direc);
        }

        SUBCASE("La methode direction() est correcte selon la direction du Laser(Bas)"){
            ecran::TDirection direc{ecran::Bas};
            ecran::Laser las{x1,y1,cote,direc};
            REQUIRE_EQ(las.direction(),direc);
        }
    }

    SUBCASE("la methode setDirection() est correcte"){

        SUBCASE("La methode direction() est correcte selon la direction du Laser(Gauche)"){
            ecran::TDirection direc{ecran::Gauche};
            ecran::Laser las{x1,y1,cote};
            las.setDirection(direc);
            REQUIRE_EQ(las.direction(),direc);
        }

        SUBCASE("La methode direction() est correcte selon la direction du Laser(Droite)"){
            ecran::TDirection direc{ecran::Droite};
            ecran::Laser las{x1,y1,cote};
            las.setDirection(direc);
            REQUIRE_EQ(las.direction(),direc);
        }

        SUBCASE("La methode direction() est correcte selon la direction du Laser(Haut)"){
            ecran::TDirection direc{ecran::Haut};
            ecran::Laser las{x1,y1,cote};
            las.setDirection(direc);
            REQUIRE_EQ(las.direction(),direc);
        }

        SUBCASE("La methode direction() est correcte selon la direction du Laser(Bas)"){
            ecran::TDirection direc{ecran::Bas};
            ecran::Laser las{x1,y1,cote};
            las.setDirection(direc);
            REQUIRE_EQ(las.direction(),direc);
        }

        SUBCASE("La methode typeObjet() est correcte"){
            ecran::Laser las{x1,y1,cote};
            REQUIRE_EQ(las.typeObjet(),"Ceci est un Laser");
        }
    }
}

TEST_CASE("Les methodes de MiroirGaucheVersBas sont correctes"){

    int nbLigne=20,nbColonne=20;
    int x1=2,y1=2,cote=20;
    ecran::Echiquier tabl{nbLigne,nbColonne,cote};

    SUBCASE("La methode posNextMoveLaser est correcte quand on ne se situe pas au bord du tableau"){
        ecran::MiroirGaucheVersBas* mir= new ecran::MiroirGaucheVersBas{tabl.coordVersPoint(x1),tabl.coordVersPoint(y1),cote};
        tabl.setCase(mir);

        SUBCASE("Cas ou le Laser vient de la Gauche "){
            ecran::Laser* las= new ecran::Laser{tabl.coordVersPoint(x1+1),tabl.coordVersPoint(y1),cote};
            tabl.setCase(las);
            tabl.setCoordLaser(ecran::coord{x1+1,y1});
            las->setDirection(ecran::Gauche);
            ecran::coord test= mir->posNextMoveLaser(tabl);
            REQUIRE_EQ(test.x,x1);
            REQUIRE_EQ(test.y,y1-1);
        }

        SUBCASE("Cas ou le Laser vient de la Droite "){
            ecran::Laser* las= new ecran::Laser{tabl.coordVersPoint(x1-1),tabl.coordVersPoint(y1),cote};
            tabl.setCase(las);
            tabl.setCoordLaser(ecran::coord{x1-1,y1});
            las->setDirection(ecran::Droite);
            ecran::coord test= mir->posNextMoveLaser(tabl);
            REQUIRE_EQ(test.x,x1);
            REQUIRE_EQ(test.y,y1+1);
        }

        SUBCASE("Cas ou le Laser vient d'en Haut "){
            ecran::Laser* las= new ecran::Laser{tabl.coordVersPoint(x1),tabl.coordVersPoint(y1+1),cote};
            tabl.setCase(las);
            tabl.setCoordLaser(ecran::coord{x1,y1+1});
            las->setDirection(ecran::Haut);
            ecran::coord test= mir->posNextMoveLaser(tabl);
            REQUIRE_EQ(test.x,x1+1);
            REQUIRE_EQ(test.y,y1);
        }

        SUBCASE("Cas ou le Laser vient d'en Bas "){
            ecran::Laser* las= new ecran::Laser{tabl.coordVersPoint(x1),tabl.coordVersPoint(y1-1),cote};
            tabl.setCase(las);
            tabl.setCoordLaser(ecran::coord{x1,y1-1});
            las->setDirection(ecran::Bas);
            ecran::coord test= mir->posNextMoveLaser(tabl);
            REQUIRE_EQ(test.x,x1-1);
            REQUIRE_EQ(test.y,y1);
        }
    }

    SUBCASE("La methode posNextMoveLaser est correcte quand on se situe au bord du tableau"){

        SUBCASE("Cas ou le Laser vient de la Gauche "){
            ecran::MiroirGaucheVersBas* mir= new ecran::MiroirGaucheVersBas{tabl.coordVersPoint(x1),tabl.coordVersPoint(0),cote};
            tabl.setCase(mir);
            ecran::Laser* las = new ecran::Laser{tabl.coordVersPoint(x1),tabl.coordVersPoint(1),cote};
            tabl.setCase(las);
            tabl.setCoordLaser(ecran::coord{x1,1});
            las->setDirection(ecran::Gauche);
            ecran::coord test= mir->posNextMoveLaser(tabl);
            REQUIRE_EQ(test.x,x1);
            REQUIRE_EQ(test.y,0);
        }

        SUBCASE("Cas ou le Laser vient de la Droite "){
            ecran::MiroirGaucheVersBas* mir= new ecran::MiroirGaucheVersBas{tabl.coordVersPoint(x1),tabl.coordVersPoint(nbLigne-1),cote};
            tabl.setCase(mir);
            ecran::Laser* las = new ecran::Laser{tabl.coordVersPoint(x1),tabl.coordVersPoint(nbLigne-2),cote};
            tabl.setCase(las);
            tabl.setCoordLaser(ecran::coord{x1,nbLigne-2});
            las->setDirection(ecran::Droite);
            ecran::coord test= mir->posNextMoveLaser(tabl);
            REQUIRE_EQ(test.x,x1);
            REQUIRE_EQ(test.y,nbLigne-1);
        }

        SUBCASE("Cas ou le Laser vient d'en Bas "){
            ecran::MiroirGaucheVersBas* mir= new ecran::MiroirGaucheVersBas{tabl.coordVersPoint(0),tabl.coordVersPoint(y1),cote};
            tabl.setCase(mir);
            ecran::Laser* las = new ecran::Laser{tabl.coordVersPoint(1),tabl.coordVersPoint(y1),cote};
            tabl.setCase(las);
            tabl.setCoordLaser(ecran::coord{1,y1});
            las->setDirection(ecran::Bas);
            ecran::coord test= mir->posNextMoveLaser(tabl);
            REQUIRE_EQ(test.x,0);
            REQUIRE_EQ(test.y,y1);
        }

    SUBCASE("Cas ou le Laser vient d'en Haut "){
            ecran::MiroirGaucheVersBas* mir= new ecran::MiroirGaucheVersBas{tabl.coordVersPoint(nbColonne-1),tabl.coordVersPoint(y1),cote};
            tabl.setCase(mir);
            ecran::Laser* las = new ecran::Laser{tabl.coordVersPoint(nbColonne-2),tabl.coordVersPoint(y1),cote};
            tabl.setCase(las);
            tabl.setCoordLaser(ecran::coord{nbColonne-2,y1});
            las->setDirection(ecran::Haut);
            ecran::coord test= mir->posNextMoveLaser(tabl);
            REQUIRE_EQ(test.x,nbColonne-1);
            REQUIRE_EQ(test.y,y1);
        }
    }

    SUBCASE("la methode transformation() est correcte"){
        ecran::MiroirGaucheVersBas* mir= new ecran::MiroirGaucheVersBas{tabl.coordVersPoint(x1),tabl.coordVersPoint(y1),cote};
        tabl.setCase(mir);
        mir->transformation(tabl);
        ecran::MiroirGaucheVersHaut * mir2= (ecran::MiroirGaucheVersHaut *) tabl.emplacementCase(x1,y1);
        REQUIRE_EQ(mir2->typeObjet(),"Ceci est un MiroirGaucheVersHaut");
    }

    SUBCASE("la methode typeObjet() est correcte"){
        ecran::MiroirGaucheVersBas* mir= new ecran::MiroirGaucheVersBas{tabl.coordVersPoint(x1),tabl.coordVersPoint(y1),cote};
        REQUIRE_EQ(mir->typeObjet(),"Ceci est un MiroirGaucheVersBas");
    }
}

TEST_CASE("Les methodes de MiroirGaucheVersHaut sont correctes"){

    int nbLigne=20,nbColonne=20;
    int x1=2,y1=2,cote=20;
    ecran::Echiquier tabl{nbLigne,nbColonne,cote};

    SUBCASE("La methode posNextMoveLaser est correcte quand on ne se situe pas au bord du tableau"){
        ecran::MiroirGaucheVersHaut* mir= new ecran::MiroirGaucheVersHaut{tabl.coordVersPoint(x1),tabl.coordVersPoint(y1),cote};
        tabl.setCase(mir);

        SUBCASE("Cas ou le Laser vient de la Gauche "){
            ecran::Laser* las= new ecran::Laser{tabl.coordVersPoint(x1-1),tabl.coordVersPoint(y1),cote};
            tabl.setCase(las);
            tabl.setCoordLaser(ecran::coord{x1-1,y1});
            las->setDirection(ecran::Gauche);
            ecran::coord test= mir->posNextMoveLaser(tabl);
            REQUIRE_EQ(test.x,x1);
            REQUIRE_EQ(test.y,y1+1);
        }

        SUBCASE("Cas ou le Laser vient de la Droite "){
            ecran::Laser* las= new ecran::Laser{tabl.coordVersPoint(x1+1),tabl.coordVersPoint(y1),cote};
            tabl.setCase(las);
            tabl.setCoordLaser(ecran::coord{x1+1,y1});
            las->setDirection(ecran::Droite);
            ecran::coord test= mir->posNextMoveLaser(tabl);
            REQUIRE_EQ(test.x,x1);
            REQUIRE_EQ(test.y,y1-1);
        }

        SUBCASE("Cas ou le Laser vient d'en Haut "){
            ecran::Laser* las= new ecran::Laser{tabl.coordVersPoint(x1),tabl.coordVersPoint(y1-1),cote};
            tabl.setCase(las);
            tabl.setCoordLaser(ecran::coord{x1,y1-1});
            las->setDirection(ecran::Haut);
            ecran::coord test= mir->posNextMoveLaser(tabl);
            REQUIRE_EQ(test.x,x1-1);
            REQUIRE_EQ(test.y,y1);
        }

        SUBCASE("Cas ou le Laser vient d'en Bas "){
            ecran::Laser* las= new ecran::Laser{tabl.coordVersPoint(x1),tabl.coordVersPoint(y1+1),cote};
            tabl.setCase(las);
            tabl.setCoordLaser(ecran::coord{x1,y1+1});
            las->setDirection(ecran::Bas);
            ecran::coord test= mir->posNextMoveLaser(tabl);
            REQUIRE_EQ(test.x,x1+1);
            REQUIRE_EQ(test.y,y1);
        }
    }

    SUBCASE("La methode posNextMoveLaser est correcte quand on se situe au bord du tableau"){

        SUBCASE("Cas ou le Laser vient de la Gauche "){
            ecran::MiroirGaucheVersHaut* mir= new ecran::MiroirGaucheVersHaut{tabl.coordVersPoint(x1),tabl.coordVersPoint(nbLigne-1),cote};
            tabl.setCase(mir);
            ecran::Laser* las = new ecran::Laser{tabl.coordVersPoint(x1),tabl.coordVersPoint(nbLigne-2),cote};
            tabl.setCase(las);
            tabl.setCoordLaser(ecran::coord{x1,nbLigne-2});
            las->setDirection(ecran::Gauche);
            ecran::coord test= mir->posNextMoveLaser(tabl);
            REQUIRE_EQ(test.x,x1);
            REQUIRE_EQ(test.y,nbLigne-1);
        }

        SUBCASE("Cas ou le Laser vient de la Droite "){
            ecran::MiroirGaucheVersHaut* mir= new ecran::MiroirGaucheVersHaut{tabl.coordVersPoint(x1),tabl.coordVersPoint(0),cote};
            tabl.setCase(mir);
            ecran::Laser* las = new ecran::Laser{tabl.coordVersPoint(x1),tabl.coordVersPoint(1),cote};
            tabl.setCase(las);
            tabl.setCoordLaser(ecran::coord{x1,1});
            las->setDirection(ecran::Droite);
            ecran::coord test= mir->posNextMoveLaser(tabl);
            REQUIRE_EQ(test.x,x1);
            REQUIRE_EQ(test.y,0);
        }

        SUBCASE("Cas ou le Laser vient d'en Bas "){
            ecran::MiroirGaucheVersHaut* mir= new ecran::MiroirGaucheVersHaut{tabl.coordVersPoint(nbColonne-1),tabl.coordVersPoint(y1),cote};
            tabl.setCase(mir);
            ecran::Laser* las = new ecran::Laser{tabl.coordVersPoint(nbColonne-2),tabl.coordVersPoint(y1),cote};
            tabl.setCase(las);
            tabl.setCoordLaser(ecran::coord{nbColonne-2,y1});
            las->setDirection(ecran::Bas);
            ecran::coord test= mir->posNextMoveLaser(tabl);
            REQUIRE_EQ(test.x,nbColonne-1);
            REQUIRE_EQ(test.y,y1);
        }

        SUBCASE("Cas ou le Laser vient d'en Haut "){
            ecran::MiroirGaucheVersHaut* mir= new ecran::MiroirGaucheVersHaut{tabl.coordVersPoint(0),tabl.coordVersPoint(y1),cote};
            tabl.setCase(mir);
            ecran::Laser* las = new ecran::Laser{tabl.coordVersPoint(1),tabl.coordVersPoint(y1),cote};
            tabl.setCase(las);
            tabl.setCoordLaser(ecran::coord{1,y1});
            las->setDirection(ecran::Haut);
            ecran::coord test= mir->posNextMoveLaser(tabl);
            REQUIRE_EQ(test.x,0);
            REQUIRE_EQ(test.y,y1);
        }
    }

    SUBCASE("la methode transformation() est correcte"){
        ecran::MiroirGaucheVersHaut* mir= new ecran::MiroirGaucheVersHaut{tabl.coordVersPoint(x1),tabl.coordVersPoint(y1),cote};
        tabl.setCase(mir);
        mir->transformation(tabl);
        ecran::CaseVide * mir2= (ecran::CaseVide *) tabl.emplacementCase(x1,y1);
        REQUIRE_EQ(mir2->typeObjet(),"Ceci est une CaseVide");
    }

    SUBCASE("la methode typeObjet() est correcte"){
        ecran::MiroirGaucheVersHaut* mir= new ecran::MiroirGaucheVersHaut{tabl.coordVersPoint(x1),tabl.coordVersPoint(y1),cote};
        REQUIRE_EQ(mir->typeObjet(),"Ceci est un MiroirGaucheVersHaut");
    }
}

TEST_CASE("Les methodes de Monstre sont correctes"){

    int nbLigne=20,nbColonne=20,cote=20;
    int x=1,y=1;

    SUBCASE("La methode touch() est correcte"){

        ecran::Echiquier tabl{nbLigne,nbColonne,cote};
        GameStatut StatutJeu{1,200};
        ecran::Monstre mons {x,y,cote};
        REQUIRE_FALSE(!mons.touch(tabl,StatutJeu,0));
        REQUIRE_EQ(StatutJeu.score(),100);
    }

    SUBCASE("La methode changement() est correcte"){
        ecran::Echiquier tabl{nbLigne,nbColonne,cote};
        ecran::Monstre* mons= new ecran::Monstre{tabl.coordVersPoint(x),tabl.coordVersPoint(y),cote};
        tabl.setCase(mons);
        mons->changement(tabl);
        ecran::CaseVide * mir2= (ecran::CaseVide *) tabl.emplacementCase(x,y);
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
    ecran::Echiquier tabl{nbLigne,nbColonne,cote};

    SUBCASE("Les methodes emplacementCase() sont correctes"){
        ecran::BlocLaser* bloc = new ecran::BlocLaser{tabl.coordVersPoint(x),tabl.coordVersPoint(y),cote};
        tabl.setCase(bloc);

        SUBCASE("emplacementCase(x,y) est correcte"){
            ecran::Case* cas=tabl.emplacementCase(x,y);
            REQUIRE_EQ(cas,bloc);}

        SUBCASE("emplacementCase(coord& coor) est correcte"){
            ecran::coord coor{x,y};
            ecran::Case* cas=tabl.emplacementCase(coor);
            REQUIRE_EQ(cas,bloc);}

        SUBCASE("emplacementCase(Point& emplacement) est correcte"){
            ecran::Point point{x,y};
            ecran::Case* cas=tabl.emplacementCase(point);
            REQUIRE_EQ(cas,bloc);}
    }

    SUBCASE("La methode setCase() est correcte"){/**Pas très utile car déjà testé au desus*/
        ecran::Mur* bloc = new ecran::Mur{tabl.coordVersPoint(x),tabl.coordVersPoint(y),cote};
        tabl.setCase(bloc);
        REQUIRE_EQ(bloc,tabl.emplacementCase(x,y));
    }

    SUBCASE("La methode pointVersCoord() est correcte"){
        int x1=30;
        REQUIRE_EQ(((x1-cote/2)/cote),tabl.pointVersCoord(x1));
    }

    SUBCASE("La methode coordVersPoint() est correcte"){
        REQUIRE_EQ(tabl.coordVersPoint(x),x*cote+cote/2);
    }
}
