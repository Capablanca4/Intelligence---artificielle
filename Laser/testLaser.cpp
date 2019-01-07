#include "doctest.h"
#include<sstream>
#include<iostream>
#include "CaseVide.h"
#include "Echiquier.h"
#include "Game.h"
#include "Bouton.h"

/** Les fonctions de dessins ne sont pas prises en compte dans ces tests */

/** Les classes suivantes ont déja des tests unitaires : - Case                   l.29
                                                         - BlocLaser              l.84
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

TEST_CASE("Les methodes de Point sont correctes"){
    int x=6, y=7,cote=20;
    ecran::CaseVide cas{x,y,cote};

    SUBCASE("La methode x() est correcte"){
        REQUIRE_EQ(cas.x(),x);
    }

    SUBCASE("La methode y() est correcte"){
        REQUIRE_EQ(cas.y(),y);
    }

}

TEST_CASE("Les methodes de Case sont correctes"){

    int x=6, y=7,cote=20;
    ecran::CaseVide cas{x,y,cote};/// Car les Case sont des classes abstraites

    SUBCASE("La methode centre() est correcte"){
        ecran::Point centre{x,y};
        REQUIRE_EQ(cas.centre().x(),centre.x());
        REQUIRE_EQ(cas.centre().y(),centre.y());
    }

    SUBCASE("La methode cote() est correcte"){
        REQUIRE_EQ(cote,cas.cote());
    }

    SUBCASE("La methode nextLaser() est correcte"){
        int nbLigne=20,nbColonne=20;
        ecran::TDirection direc= ecran::Droite;
        ecran::Game Jeu{nbLigne,nbColonne,cote};
        ecran::Case* cas1=(ecran::Case*) Jeu.plateau().emplacementCase(x,y);
        std::vector<ecran::Laser*> nextLas{};
        cas1->nextLaser(Jeu,direc,nextLas);
        REQUIRE_EQ(nextLas[0]->x(),Jeu.plateau().coordVersPoint(x));
        REQUIRE_EQ(nextLas[0]->y(),Jeu.plateau().coordVersPoint(y));
        REQUIRE_EQ(nextLas[0]->direction(),direc);
    }

}

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

TEST_CASE("Les methodes de CaseVide sont correctes"){
    int x=6, y=7,cote=20;
    ecran::CaseVide cas{x,y,cote};

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
        ecran::Laser* las = new ecran::Laser{x,y,cote};
        Jeu.plateau().setCase(cible1);
        Jeu.addLaser(las);
        cible1->touch(Jeu,las);
        REQUIRE_FALSE(las->inMove());
        REQUIRE_EQ(Jeu.score(),1000);
    }

    SUBCASE("La methode typeObjet() est correcte"){
        REQUIRE_EQ("Ceci est une Cible",cible.typeObjet());
    }
}

TEST_CASE("Les methodes de CibleHorizontale sont correctes"){

    int nbLigne=20,nbColonne=20;
    int x=2,y=2,cote=20;
    ecran::Game Jeu{nbLigne,nbColonne,cote};
    ecran::CibleHorizontale* cible = new ecran::CibleHorizontale{Jeu.plateau().coordVersPoint(x),Jeu.plateau().coordVersPoint(y),cote};

    SUBCASE("La methode touch() est correcte "){
        Jeu.plateau().setCase(cible);
        ecran::Laser* las = new ecran::Laser{x,y,cote};
        Jeu.addLaser(las);
        cible->touch(Jeu,las);
        REQUIRE_FALSE(las->inMove());
        REQUIRE_EQ(Jeu.score(),1000);

    SUBCASE("La methode touch() met le bool in_move de Echiquier à faux si on vient de la Droite "){
        ecran::Laser* las = new ecran::Laser{x,y,cote,ecran::Droite};
        Jeu.addLaser(las);
        cible->touch(Jeu,las);
        REQUIRE_FALSE(Jeu.moving());
        }

    SUBCASE("La methode touch() met le bool in_move de Echiquier à faux si on vient de la Gauche "){
        ecran::Laser* las = new ecran::Laser{x,y,cote,ecran::Gauche};
        Jeu.addLaser(las);
        cible->touch(Jeu,las);
        REQUIRE_FALSE(Jeu.moving());
        }

   }

   SUBCASE("La methode typeObjet() est correcte"){
        REQUIRE_EQ("Ceci est une CibleHorizontale",cible->typeObjet());
   }

}

TEST_CASE("Les methodes de CibleVerticale sont correctes"){

    int nbLigne=20,nbColonne=20;
    int x=2,y=2,cote=20;
    ecran::Game Jeu{nbLigne,nbColonne,cote};
    ecran::CibleVerticale* cible = new ecran::CibleVerticale{Jeu.plateau().coordVersPoint(x),Jeu.plateau().coordVersPoint(y),cote};

    SUBCASE("La methode touch() est correcte "){
        Jeu.plateau().setCase(cible);
        ecran::Laser* las = new ecran::Laser{x,y,cote};
        Jeu.addLaser(las);
        cible->touch(Jeu,las);
        REQUIRE_FALSE(las->inMove());
        REQUIRE_EQ(Jeu.score(),1000);
    }

    SUBCASE("La methode touch() met le bool in_move de Echiquier à faux si on vient d'en Haut "){
        ecran::Laser* las = new ecran::Laser{x,y,cote,ecran::Haut};
        Jeu.addLaser(las);
        cible->touch(Jeu,las);
        REQUIRE_FALSE(Jeu.moving());
        }

    SUBCASE("La methode touch() met le bool in_move de Echiquier à faux si on vient d'en Bas "){
        ecran::Laser* las = new ecran::Laser{x,y,cote,ecran::Bas};
        Jeu.addLaser(las);
        cible->touch(Jeu,las);
        REQUIRE_FALSE(Jeu.moving());
        }

    SUBCASE("La methode typeObjet() est correcte"){
        REQUIRE_EQ("Ceci est une CibleVerticale",cible->typeObjet());
   }

}

TEST_CASE("Les methodes de Laser sont correctes"){

    int x1=2,y1=2,cote=20;
    ecran::Laser las{x1,y1,cote};
    ecran::TDirection direc{ecran::Gauche};

    SUBCASE("La methode direction() est correcte"){
        REQUIRE_EQ(las.direction(),ecran::Droite);
    }

    SUBCASE("La metode inMove() est correcte"){
        REQUIRE_FALSE(!las.inMove());
    }

    SUBCASE("la methode setDirection() est correcte"){
        las.setDirection(direc);
        REQUIRE_EQ(las.direction(),direc);
    }

    SUBCASE("la methode setMoveFalse() est correcte"){
        las.setMoveFalse();
        REQUIRE_FALSE(las.inMove());
    }

    SUBCASE("La methode typeObjet() est correcte"){
        REQUIRE_EQ(las.typeObjet(),"Ceci est un Laser");
    }
}

TEST_CASE("Les methodes de MiroirGaucheVersBas sont correctes"){

    int nbLigne=20,nbColonne=20;
    int x=2,y=2,cote=20;
    ecran::Game Jeu{nbLigne,nbColonne,cote};

    SUBCASE("La methode nextLaser est correcte quand on ne se situe pas au bord du tableau"){
        ecran::MiroirGaucheVersBas* mir= new ecran::MiroirGaucheVersBas{Jeu.plateau().coordVersPoint(x),Jeu.plateau().coordVersPoint(y),cote};
        Jeu.plateau().setCase(mir);
        std::vector<ecran::Laser*> nextLas{};

        SUBCASE("Cas ou le Laser vient de la Gauche "){

            mir->nextLaser(Jeu,ecran::Gauche,nextLas);
            REQUIRE_EQ(nextLas[0]->x(),Jeu.plateau().coordVersPoint(x));
            REQUIRE_EQ(nextLas[0]->y(),Jeu.plateau().coordVersPoint(y)-cote);
            REQUIRE_EQ(nextLas[0]->direction(),ecran::Bas);
        }

        SUBCASE("Cas ou le Laser vient de la Droite "){
            mir->nextLaser(Jeu,ecran::Droite,nextLas);
            REQUIRE_EQ(nextLas[0]->x(),Jeu.plateau().coordVersPoint(x));
            REQUIRE_EQ(nextLas[0]->y(),Jeu.plateau().coordVersPoint(y)+cote);
            REQUIRE_EQ(nextLas[0]->direction(),ecran::Haut);
        }

        SUBCASE("Cas ou le Laser vient d'en Haut "){
            mir->nextLaser(Jeu,ecran::Haut,nextLas);
            REQUIRE_EQ(nextLas[0]->x(),Jeu.plateau().coordVersPoint(x)+cote);
            REQUIRE_EQ(nextLas[0]->y(),Jeu.plateau().coordVersPoint(y));
            REQUIRE_EQ(nextLas[0]->direction(),ecran::Droite);
        }

        SUBCASE("Cas ou le Laser vient d'en Bas "){
            mir->nextLaser(Jeu,ecran::Bas,nextLas);
            REQUIRE_EQ(nextLas[0]->x(),Jeu.plateau().coordVersPoint(x)-cote);
            REQUIRE_EQ(nextLas[0]->y(),Jeu.plateau().coordVersPoint(y));
            REQUIRE_EQ(nextLas[0]->direction(),ecran::Gauche);
        }
    }

    SUBCASE("La methode nextLaser est correcte quand on se situe au bord du tableau"){
        std::vector<ecran::Laser*> nextLas{};

        SUBCASE("Cas ou le Laser vient de la Gauche "){
            ecran::MiroirGaucheVersBas* mir= new ecran::MiroirGaucheVersBas{Jeu.plateau().coordVersPoint(x),Jeu.plateau().coordVersPoint(0),cote};
            Jeu.plateau().setCase(mir);
            mir->nextLaser(Jeu,ecran::Gauche,nextLas);
            REQUIRE_EQ(nextLas[0]->x(),Jeu.plateau().coordVersPoint(x));
            REQUIRE_EQ(nextLas[0]->y(),Jeu.plateau().coordVersPoint(0));

        }

        SUBCASE("Cas ou le Laser vient de la Droite "){
            ecran::MiroirGaucheVersBas* mir= new ecran::MiroirGaucheVersBas{Jeu.plateau().coordVersPoint(x),Jeu.plateau().coordVersPoint(nbLigne-1),cote};
            Jeu.plateau().setCase(mir);
            mir->nextLaser(Jeu,ecran::Droite,nextLas);
            REQUIRE_EQ(nextLas[0]->x(),Jeu.plateau().coordVersPoint(x));
            REQUIRE_EQ(nextLas[0]->y(),Jeu.plateau().coordVersPoint(nbLigne-1));
        }

        SUBCASE("Cas ou le Laser vient d'en Bas "){
            ecran::MiroirGaucheVersBas* mir= new ecran::MiroirGaucheVersBas{Jeu.plateau().coordVersPoint(0),Jeu.plateau().coordVersPoint(y),cote};
            Jeu.plateau().setCase(mir);
            mir->nextLaser(Jeu,ecran::Bas,nextLas);
            REQUIRE_EQ(nextLas[0]->x(),Jeu.plateau().coordVersPoint(0));
            REQUIRE_EQ(nextLas[0]->y(),Jeu.plateau().coordVersPoint(y));
        }

    SUBCASE("Cas ou le Laser vient d'en Haut "){
            ecran::MiroirGaucheVersBas* mir= new ecran::MiroirGaucheVersBas{Jeu.plateau().coordVersPoint(nbColonne-1),Jeu.plateau().coordVersPoint(y),cote};
            Jeu.plateau().setCase(mir);
            mir->nextLaser(Jeu,ecran::Haut,nextLas);
            REQUIRE_EQ(nextLas[0]->x(),Jeu.plateau().coordVersPoint(nbColonne-1));
            REQUIRE_EQ(nextLas[0]->y(),Jeu.plateau().coordVersPoint(y));
        }
    }

    SUBCASE("la methode transformation() est correcte"){
        ecran::MiroirGaucheVersBas* mir= new ecran::MiroirGaucheVersBas{Jeu.plateau().coordVersPoint(x),Jeu.plateau().coordVersPoint(y),cote};
        Jeu.plateau().setCase(mir);
        mir->transformation(Jeu.plateau());
        ecran::MiroirGaucheVersHaut * mir2= (ecran::MiroirGaucheVersHaut *) Jeu.plateau().emplacementCase(x,y);
        REQUIRE_EQ(mir2->typeObjet(),"Ceci est un MiroirGaucheVersHaut");
    }

    SUBCASE("la methode typeObjet() est correcte"){
        ecran::MiroirGaucheVersBas mir{Jeu.plateau().coordVersPoint(x),Jeu.plateau().coordVersPoint(y),cote};
        REQUIRE_EQ(mir.typeObjet(),"Ceci est un MiroirGaucheVersBas");
    }
}

TEST_CASE("Les methodes de MiroirGaucheVersHaut sont correctes"){

    int nbLigne=20,nbColonne=20;
    int x=2,y=5,cote=20;
    ecran::Game Jeu{nbLigne,nbColonne,cote};

    SUBCASE("La methode nextLaser est correcte quand on ne se situe pas au bord du tableau"){
        ecran::MiroirGaucheVersHaut* mir= new ecran::MiroirGaucheVersHaut{Jeu.plateau().coordVersPoint(x),Jeu.plateau().coordVersPoint(y),cote};
        Jeu.plateau().setCase(mir);
        std::vector<ecran::Laser*> nextLas{};

        SUBCASE("Cas ou le Laser vient de la Gauche "){
            mir->nextLaser(Jeu,ecran::Gauche,nextLas);
            REQUIRE_EQ(nextLas[0]->x(),Jeu.plateau().coordVersPoint(x));
            REQUIRE_EQ(nextLas[0]->y(),Jeu.plateau().coordVersPoint(y)+cote);
        }

        SUBCASE("Cas ou le Laser vient de la Droite "){
            mir->nextLaser(Jeu,ecran::Droite,nextLas);
            REQUIRE_EQ(nextLas[0]->x(),Jeu.plateau().coordVersPoint(x));
            REQUIRE_EQ(nextLas[0]->y(),Jeu.plateau().coordVersPoint(y)-cote);
        }

        SUBCASE("Cas ou le Laser vient d'en Haut "){
            mir->nextLaser(Jeu,ecran::Haut,nextLas);
            REQUIRE_EQ(nextLas[0]->x(),Jeu.plateau().coordVersPoint(x)-cote);
            REQUIRE_EQ(nextLas[0]->y(),Jeu.plateau().coordVersPoint(y));
        }

        SUBCASE("Cas ou le Laser vient d'en Bas "){
            mir->nextLaser(Jeu,ecran::Bas,nextLas);
            REQUIRE_EQ(nextLas[0]->x(),Jeu.plateau().coordVersPoint(x)+cote);
            REQUIRE_EQ(nextLas[0]->y(),Jeu.plateau().coordVersPoint(y));
        }
    }

    SUBCASE("La methode nextLaser est correcte quand on se situe au bord du tableau"){
        std::vector<ecran::Laser*> nextLas{};

        SUBCASE("Cas ou le Laser vient de la Gauche "){
            ecran::MiroirGaucheVersHaut* mir= new ecran::MiroirGaucheVersHaut{Jeu.plateau().coordVersPoint(x),Jeu.plateau().coordVersPoint(nbLigne-1),cote};
            Jeu.plateau().setCase(mir);
            mir->nextLaser(Jeu,ecran::Gauche,nextLas);
            REQUIRE_EQ(nextLas[0]->x(),Jeu.plateau().coordVersPoint(x));
            REQUIRE_EQ(nextLas[0]->y(),Jeu.plateau().coordVersPoint(nbLigne-1));
        }

        SUBCASE("Cas ou le Laser vient de la Droite "){
            ecran::MiroirGaucheVersHaut* mir= new ecran::MiroirGaucheVersHaut{Jeu.plateau().coordVersPoint(x),Jeu.plateau().coordVersPoint(0),cote};
            Jeu.plateau().setCase(mir);
            mir->nextLaser(Jeu,ecran::Droite,nextLas);
            REQUIRE_EQ(nextLas[0]->x(),Jeu.plateau().coordVersPoint(x));
            REQUIRE_EQ(nextLas[0]->y(),Jeu.plateau().coordVersPoint(0));
        }

        SUBCASE("Cas ou le Laser vient d'en Bas "){
            ecran::MiroirGaucheVersHaut* mir= new ecran::MiroirGaucheVersHaut{Jeu.plateau().coordVersPoint(nbColonne-1),Jeu.plateau().coordVersPoint(y),cote};
            Jeu.plateau().setCase(mir);
            mir->nextLaser(Jeu,ecran::Bas,nextLas);
            REQUIRE_EQ(nextLas[0]->x(),Jeu.plateau().coordVersPoint(nbColonne-1));
            REQUIRE_EQ(nextLas[0]->y(),Jeu.plateau().coordVersPoint(y));
        }

        SUBCASE("Cas ou le Laser vient d'en Haut "){
            ecran::MiroirGaucheVersHaut* mir= new ecran::MiroirGaucheVersHaut{Jeu.plateau().coordVersPoint(0),Jeu.plateau().coordVersPoint(y),cote};
            Jeu.plateau().setCase(mir);
            mir->nextLaser(Jeu,ecran::Haut,nextLas);
            REQUIRE_EQ(nextLas[0]->x(),Jeu.plateau().coordVersPoint(0));
            REQUIRE_EQ(nextLas[0]->y(),Jeu.plateau().coordVersPoint(y));
        }
    }

    SUBCASE("la methode transformation() est correcte"){
        ecran::MiroirGaucheVersHaut* mir= new ecran::MiroirGaucheVersHaut{Jeu.plateau().coordVersPoint(x),Jeu.plateau().coordVersPoint(y),cote};
        Jeu.plateau().setCase(mir);
        mir->transformation(Jeu.plateau());
        ecran::CaseVide * mir2= (ecran::CaseVide *) Jeu.plateau().emplacementCase(x,y);
        REQUIRE_EQ(mir2->typeObjet(),"Ceci est une CaseVide");
    }

    SUBCASE("la methode typeObjet() est correcte"){
        ecran::MiroirGaucheVersHaut mir{Jeu.plateau().coordVersPoint(x),Jeu.plateau().coordVersPoint(y),cote};
        REQUIRE_EQ(mir.typeObjet(),"Ceci est un MiroirGaucheVersHaut");
    }
}

TEST_CASE("Les methodes de MiroirTransparentGaucheVersHaut sont correctes"){
    int nbLigne=20,nbColonne=20;
    int x=2,y=5,cote=20;
    ecran::Game Jeu{nbLigne,nbColonne,cote};

    SUBCASE("La methode nextLaser est correcte quand on ne se situe pas au bord du tableau"){
        ecran::MiroirTransparentGaucheVersHaut* mir= new ecran::MiroirTransparentGaucheVersHaut{Jeu.plateau().coordVersPoint(x),Jeu.plateau().coordVersPoint(y),cote};
        Jeu.plateau().setCase(mir);
        std::vector<ecran::Laser*> nextLas{};

        SUBCASE("Cas ou le Laser vient de la Gauche "){
            mir->nextLaser(Jeu,ecran::Gauche,nextLas);
            REQUIRE_EQ(nextLas[0]->x(),Jeu.plateau().coordVersPoint(x));
            REQUIRE_EQ(nextLas[0]->y(),Jeu.plateau().coordVersPoint(y)+cote);
            REQUIRE_EQ(nextLas[0]->direction(),ecran::Haut);
            REQUIRE_EQ(nextLas[1]->x(),Jeu.plateau().coordVersPoint(x)-cote);
            REQUIRE_EQ(nextLas[1]->y(),Jeu.plateau().coordVersPoint(y));
            REQUIRE_EQ(nextLas[1]->direction(),ecran::Gauche);
        }

        SUBCASE("Cas ou le Laser vient de la Droite "){
            mir->nextLaser(Jeu,ecran::Droite,nextLas);
            REQUIRE_EQ(nextLas[0]->x(),Jeu.plateau().coordVersPoint(x));
            REQUIRE_EQ(nextLas[0]->y(),Jeu.plateau().coordVersPoint(y)-cote);
            REQUIRE_EQ(nextLas[0]->direction(),ecran::Bas);
            REQUIRE_EQ(nextLas[1]->x(),Jeu.plateau().coordVersPoint(x)+cote);
            REQUIRE_EQ(nextLas[1]->y(),Jeu.plateau().coordVersPoint(y));
            REQUIRE_EQ(nextLas[1]->direction(),ecran::Droite);
        }

        SUBCASE("Cas ou le Laser vient d'en Haut "){
            mir->nextLaser(Jeu,ecran::Haut,nextLas);
            REQUIRE_EQ(nextLas[0]->x(),Jeu.plateau().coordVersPoint(x)-cote);
            REQUIRE_EQ(nextLas[0]->y(),Jeu.plateau().coordVersPoint(y));
            REQUIRE_EQ(nextLas[0]->direction(),ecran::Gauche);
            REQUIRE_EQ(nextLas[1]->x(),Jeu.plateau().coordVersPoint(x));
            REQUIRE_EQ(nextLas[1]->y(),Jeu.plateau().coordVersPoint(y)+cote);
            REQUIRE_EQ(nextLas[1]->direction(),ecran::Haut);
        }

        SUBCASE("Cas ou le Laser vient d'en Bas "){
            mir->nextLaser(Jeu,ecran::Bas,nextLas);
            REQUIRE_EQ(nextLas[0]->x(),Jeu.plateau().coordVersPoint(x)+cote);
            REQUIRE_EQ(nextLas[0]->y(),Jeu.plateau().coordVersPoint(y));
            REQUIRE_EQ(nextLas[0]->direction(),ecran::Droite);
            REQUIRE_EQ(nextLas[1]->x(),Jeu.plateau().coordVersPoint(x));
            REQUIRE_EQ(nextLas[1]->y(),Jeu.plateau().coordVersPoint(y)-cote);
            REQUIRE_EQ(nextLas[1]->direction(),ecran::Bas);
        }
    }

    SUBCASE("La methode nextLaser est correcte quand on se situe au bord du tableau"){
        std::vector<ecran::Laser*> nextLas{};

        SUBCASE("Cas ou le Laser vient de la Gauche "){

            SUBCASE("Cas ou le bord du plateau est en haut"){
                ecran::MiroirTransparentGaucheVersHaut* mir= new ecran::MiroirTransparentGaucheVersHaut{Jeu.plateau().coordVersPoint(x),Jeu.plateau().coordVersPoint(nbLigne-1),cote};
                Jeu.plateau().setCase(mir);
                mir->nextLaser(Jeu,ecran::Gauche,nextLas);
                REQUIRE_EQ(nextLas[0]->x(),Jeu.plateau().coordVersPoint(x));
                REQUIRE_EQ(nextLas[0]->y(),Jeu.plateau().coordVersPoint(nbLigne-1));
            }
            SUBCASE("Cas ou le bord du plateau est a gauche"){
                ecran::MiroirTransparentGaucheVersHaut* mir= new ecran::MiroirTransparentGaucheVersHaut{Jeu.plateau().coordVersPoint(0),Jeu.plateau().coordVersPoint(y),cote};
                Jeu.plateau().setCase(mir);
                mir->nextLaser(Jeu,ecran::Gauche,nextLas);
                REQUIRE_EQ(nextLas[0]->x(),Jeu.plateau().coordVersPoint(0));
                REQUIRE_EQ(nextLas[0]->y(),Jeu.plateau().coordVersPoint(y));
            }
        }

        SUBCASE("Cas ou le Laser vient de la Droite "){

            SUBCASE("Cas ou le bord du plateau est en bas"){
                ecran::MiroirTransparentGaucheVersHaut* mir= new ecran::MiroirTransparentGaucheVersHaut{Jeu.plateau().coordVersPoint(x),Jeu.plateau().coordVersPoint(0),cote};
                Jeu.plateau().setCase(mir);
                mir->nextLaser(Jeu,ecran::Droite,nextLas);
                REQUIRE_EQ(nextLas[0]->x(),Jeu.plateau().coordVersPoint(x));
                REQUIRE_EQ(nextLas[0]->y(),Jeu.plateau().coordVersPoint(0));
            }

            SUBCASE("Cas ou le bord du plateau est en droite"){
                ecran::MiroirTransparentGaucheVersHaut* mir= new ecran::MiroirTransparentGaucheVersHaut{Jeu.plateau().coordVersPoint(nbColonne-1),Jeu.plateau().coordVersPoint(y),cote};
                Jeu.plateau().setCase(mir);
                mir->nextLaser(Jeu,ecran::Droite,nextLas);
                REQUIRE_EQ(nextLas[0]->x(),Jeu.plateau().coordVersPoint(nbColonne-1));
                REQUIRE_EQ(nextLas[0]->y(),Jeu.plateau().coordVersPoint(y));
            }
        }

        SUBCASE("Cas ou le Laser vient d'en Bas "){

            SUBCASE("Cas ou le bord du plateau est en droite"){
                ecran::MiroirTransparentGaucheVersHaut* mir= new ecran::MiroirTransparentGaucheVersHaut{Jeu.plateau().coordVersPoint(nbColonne-1),Jeu.plateau().coordVersPoint(y),cote};
                Jeu.plateau().setCase(mir);
                mir->nextLaser(Jeu,ecran::Bas,nextLas);
                REQUIRE_EQ(nextLas[0]->x(),Jeu.plateau().coordVersPoint(nbColonne-1));
                REQUIRE_EQ(nextLas[0]->y(),Jeu.plateau().coordVersPoint(y));
            }

            SUBCASE("Cas ou le bord du plateau est en bas"){
                ecran::MiroirTransparentGaucheVersHaut* mir= new ecran::MiroirTransparentGaucheVersHaut{Jeu.plateau().coordVersPoint(x),Jeu.plateau().coordVersPoint(0),cote};
                Jeu.plateau().setCase(mir);
                mir->nextLaser(Jeu,ecran::Bas,nextLas);
                REQUIRE_EQ(nextLas[0]->x(),Jeu.plateau().coordVersPoint(x));
                REQUIRE_EQ(nextLas[0]->y(),Jeu.plateau().coordVersPoint(0));
            }

        }

        SUBCASE("Cas ou le Laser vient d'en Haut "){

            SUBCASE("Cas ou le bord du plateau est a gauche"){
                ecran::MiroirTransparentGaucheVersHaut* mir= new ecran::MiroirTransparentGaucheVersHaut{Jeu.plateau().coordVersPoint(0),Jeu.plateau().coordVersPoint(y),cote};
                Jeu.plateau().setCase(mir);
                mir->nextLaser(Jeu,ecran::Haut,nextLas);
                REQUIRE_EQ(nextLas[0]->x(),Jeu.plateau().coordVersPoint(0));
                REQUIRE_EQ(nextLas[0]->y(),Jeu.plateau().coordVersPoint(y));
            }

            SUBCASE("Cas ou le bord du plateau est en haut"){
                ecran::MiroirTransparentGaucheVersHaut* mir= new ecran::MiroirTransparentGaucheVersHaut{Jeu.plateau().coordVersPoint(x),Jeu.plateau().coordVersPoint(nbLigne-1),cote};
                Jeu.plateau().setCase(mir);
                mir->nextLaser(Jeu,ecran::Haut,nextLas);
                REQUIRE_EQ(nextLas[0]->x(),Jeu.plateau().coordVersPoint(x));
                REQUIRE_EQ(nextLas[0]->y(),Jeu.plateau().coordVersPoint(nbLigne-1));
            }
        }
    }

    SUBCASE("la methode typeObjet() est correcte"){
        ecran::MiroirTransparentGaucheVersHaut mir{Jeu.plateau().coordVersPoint(x),Jeu.plateau().coordVersPoint(y),cote};
        REQUIRE_EQ(mir.typeObjet(),"Ceci est un MiroirTransparentGaucheVersHaut");
    }
}

TEST_CASE("Les methodes de MiroirTransparentGaucheVersBas sont correctes"){
    int nbLigne=20,nbColonne=20;
    int x=2,y=5,cote=20;
    ecran::Game Jeu{nbLigne,nbColonne,cote};

        SUBCASE("La methode nextLaser est correcte quand on ne se situe pas au bord du tableau"){
        ecran::MiroirTransparentGaucheVersBas* mir= new ecran::MiroirTransparentGaucheVersBas{Jeu.plateau().coordVersPoint(x),Jeu.plateau().coordVersPoint(y),cote};
        Jeu.plateau().setCase(mir);
        std::vector<ecran::Laser*> nextLas{};

        SUBCASE("Cas ou le Laser vient de la Gauche "){

            mir->nextLaser(Jeu,ecran::Gauche,nextLas);
            REQUIRE_EQ(nextLas[0]->x(),Jeu.plateau().coordVersPoint(x));
            REQUIRE_EQ(nextLas[0]->y(),Jeu.plateau().coordVersPoint(y)-cote);
            REQUIRE_EQ(nextLas[0]->direction(),ecran::Bas);
            REQUIRE_EQ(nextLas[1]->x(),Jeu.plateau().coordVersPoint(x)-cote);
            REQUIRE_EQ(nextLas[1]->y(),Jeu.plateau().coordVersPoint(y));
            REQUIRE_EQ(nextLas[1]->direction(),ecran::Gauche);
        }

        SUBCASE("Cas ou le Laser vient de la Droite "){
            mir->nextLaser(Jeu,ecran::Droite,nextLas);
            REQUIRE_EQ(nextLas[0]->x(),Jeu.plateau().coordVersPoint(x));
            REQUIRE_EQ(nextLas[0]->y(),Jeu.plateau().coordVersPoint(y)+cote);
            REQUIRE_EQ(nextLas[0]->direction(),ecran::Haut);
            REQUIRE_EQ(nextLas[1]->x(),Jeu.plateau().coordVersPoint(x)+cote);
            REQUIRE_EQ(nextLas[1]->y(),Jeu.plateau().coordVersPoint(y));
            REQUIRE_EQ(nextLas[1]->direction(),ecran::Droite);
        }

        SUBCASE("Cas ou le Laser vient d'en Haut "){
            mir->nextLaser(Jeu,ecran::Haut,nextLas);
            REQUIRE_EQ(nextLas[0]->x(),Jeu.plateau().coordVersPoint(x)+cote);
            REQUIRE_EQ(nextLas[0]->y(),Jeu.plateau().coordVersPoint(y));
            REQUIRE_EQ(nextLas[0]->direction(),ecran::Droite);
            REQUIRE_EQ(nextLas[1]->x(),Jeu.plateau().coordVersPoint(x));
            REQUIRE_EQ(nextLas[1]->y(),Jeu.plateau().coordVersPoint(y)+cote);
            REQUIRE_EQ(nextLas[1]->direction(),ecran::Haut);
        }

        SUBCASE("Cas ou le Laser vient d'en Bas "){
            mir->nextLaser(Jeu,ecran::Bas,nextLas);
            REQUIRE_EQ(nextLas[0]->x(),Jeu.plateau().coordVersPoint(x)-cote);
            REQUIRE_EQ(nextLas[0]->y(),Jeu.plateau().coordVersPoint(y));
            REQUIRE_EQ(nextLas[0]->direction(),ecran::Gauche);
            REQUIRE_EQ(nextLas[1]->x(),Jeu.plateau().coordVersPoint(x));
            REQUIRE_EQ(nextLas[1]->y(),Jeu.plateau().coordVersPoint(y)-cote);
            REQUIRE_EQ(nextLas[1]->direction(),ecran::Bas);
        }
    }

    SUBCASE("La methode nextLaser est correcte quand on se situe au bord du tableau"){
        std::vector<ecran::Laser*> nextLas{};

        SUBCASE("Cas ou le Laser vient de la Gauche "){
            ecran::MiroirTransparentGaucheVersBas* mir= new ecran::MiroirTransparentGaucheVersBas{Jeu.plateau().coordVersPoint(x),Jeu.plateau().coordVersPoint(0),cote};
            Jeu.plateau().setCase(mir);
            mir->nextLaser(Jeu,ecran::Gauche,nextLas);
            REQUIRE_EQ(nextLas[0]->x(),Jeu.plateau().coordVersPoint(x));
            REQUIRE_EQ(nextLas[0]->y(),Jeu.plateau().coordVersPoint(0));

        }

        SUBCASE("Cas ou le Laser vient de la Droite "){
            ecran::MiroirTransparentGaucheVersBas* mir= new ecran::MiroirTransparentGaucheVersBas{Jeu.plateau().coordVersPoint(x),Jeu.plateau().coordVersPoint(nbLigne-1),cote};
            Jeu.plateau().setCase(mir);
            mir->nextLaser(Jeu,ecran::Droite,nextLas);
            REQUIRE_EQ(nextLas[0]->x(),Jeu.plateau().coordVersPoint(x));
            REQUIRE_EQ(nextLas[0]->y(),Jeu.plateau().coordVersPoint(nbLigne-1));
        }

        SUBCASE("Cas ou le Laser vient d'en Bas "){
            ecran::MiroirTransparentGaucheVersBas* mir= new ecran::MiroirTransparentGaucheVersBas{Jeu.plateau().coordVersPoint(0),Jeu.plateau().coordVersPoint(y),cote};
            Jeu.plateau().setCase(mir);
            mir->nextLaser(Jeu,ecran::Bas,nextLas);
            REQUIRE_EQ(nextLas[0]->x(),Jeu.plateau().coordVersPoint(0));
            REQUIRE_EQ(nextLas[0]->y(),Jeu.plateau().coordVersPoint(y));
        }

    SUBCASE("Cas ou le Laser vient d'en Haut "){
            ecran::MiroirTransparentGaucheVersBas* mir= new ecran::MiroirTransparentGaucheVersBas{Jeu.plateau().coordVersPoint(nbColonne-1),Jeu.plateau().coordVersPoint(y),cote};
            Jeu.plateau().setCase(mir);
            mir->nextLaser(Jeu,ecran::Haut,nextLas);
            REQUIRE_EQ(nextLas[0]->x(),Jeu.plateau().coordVersPoint(nbColonne-1));
            REQUIRE_EQ(nextLas[0]->y(),Jeu.plateau().coordVersPoint(y));
        }
    }

    SUBCASE("la methode typeObjet() est correcte"){
        ecran::MiroirTransparentGaucheVersBas mir{Jeu.plateau().coordVersPoint(x),Jeu.plateau().coordVersPoint(y),cote};
        REQUIRE_EQ(mir.typeObjet(),"Ceci est un MiroirTransparentGaucheVersBas");
    }
}

TEST_CASE("Les methodes de Monstre sont correctes"){

    int nbLigne=20,nbColonne=20,cote=20;
    int x=1,y=1;
    int x1=5,y1=7;
    ecran::Game Jeu{nbLigne,nbColonne,cote};

    SUBCASE("La methode touch() est correcte"){
        ecran::Monstre mons {x,y,cote};
        ecran::Laser* las = new ecran::Laser{x1,y1,cote};
        mons.touch(Jeu,las);
        REQUIRE_EQ(Jeu.plateau().emplacementCase(x,y)->typeObjet(),"Ceci est une CaseVide");
        REQUIRE_EQ(Jeu.score(),100);
    }

    SUBCASE("La methode changement() est correcte"){
        ecran::Monstre* mons= new ecran::Monstre{Jeu.plateau().coordVersPoint(x),Jeu.plateau().coordVersPoint(y),cote};
        Jeu.plateau().setCase(mons);
        mons->changement(Jeu.plateau());
        REQUIRE_EQ(Jeu.plateau().emplacementCase(x,y)->typeObjet(),"Ceci est une CaseVide");
    }

    SUBCASE("La methode typeObjet() est correcte"){
        ecran::Monstre mons {x,y,cote};
        REQUIRE_EQ(mons.typeObjet(),"Ceci est un Monstre");
    }
}

TEST_CASE("Les methodes de Mur sont correctes"){

    int x=1,y=1,cote=20;
    ecran::Mur mur {x,y,cote};

    SUBCASE("La methode typeObjet() est correcte"){
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

        SUBCASE("emplacementCase(Case* cas) est correcte"){
            ecran::Case* cas1=(ecran::Case*) bloc;
            REQUIRE_EQ(Jeu.plateau().emplacementCase(cas1),bloc);
        }
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

        SUBCASE("La methode pointVersCoord(const Point& centre) est correcte"){
            ecran::CaseVide* cas= new ecran::CaseVide{x1,y1,cote};
            ecran::coord coordTest=Jeu.plateau().pointVersCoord(cas->centre());
            REQUIRE_EQ(((x1-cote/2)/cote),coordTest.x);
            REQUIRE_EQ(((y1-cote/2)/cote),coordTest.y);
        }
    }

    SUBCASE("Les methodes coordVersPoint() sont correctes"){

        SUBCASE("La methode coordVersPoint(int coor) est correcte"){
            REQUIRE_EQ(Jeu.plateau().coordVersPoint(x),x*cote+cote/2);
        }

        SUBCASE("La methode coordVersPoint(coord coor) est correcte"){
            REQUIRE_EQ(Jeu.plateau().coordVersPoint(ecran::coord{x,y}).x(),x*cote+cote/2);
            REQUIRE_EQ(Jeu.plateau().coordVersPoint(ecran::coord{x,y}).y(),y*cote+cote/2);
        }
    }

    SUBCASE("La methode nbLigne() est correcte"){
        REQUIRE_EQ(Jeu.plateau().nbLigne(),nbLigne);
    }

    SUBCASE("La methode nbColonne() est correcte"){
        REQUIRE_EQ(Jeu.plateau().nbColonne(),nbColonne);
    }

    SUBCASE("La methode taille() est correcte"){
        REQUIRE_EQ(Jeu.plateau().taille(),cote);
    }

    SUBCASE("La methode destinationMove() est correcte "){
        std::vector<ecran::Laser*> nextLas{};

        SUBCASE("Quand le Laser va vers la Gauche "){

            SUBCASE("Dans le cas ou on ne se situe pas au bord du tableau"){ /** Test non fonctionnel*/
                ecran::Laser* las= new ecran::Laser{Jeu.plateau().coordVersPoint(x),Jeu.plateau().coordVersPoint(y),cote};
                Jeu.plateau().setCase(las);
                Jeu.addLaser(las);
                las->setDirection(ecran::Gauche);
                Jeu.plateau().destinationMove(Jeu,0,nextLas);
                Jeu.plateau().emplacementCase(x-1,y)->nextLaser(Jeu,las->direction(),nextLas);
                //ecran::Case* cas =nextLas[1] ;
                std::cout << nextLas[0]->x()<<","<<nextLas[0]->y()<<std::endl;
                /*REQUIRE_EQ(nextLas[0]->x(),cas->x());
                REQUIRE_EQ(nextLas[0]->y(),cas->y());*/
            }

            SUBCASE("Dans le cas ou on se situe au bord du tableau "){
                ecran::Laser* las= new ecran::Laser{Jeu.plateau().coordVersPoint(0),Jeu.plateau().coordVersPoint(y),cote};
                Jeu.plateau().setCase(las);
                Jeu.addLaser(las);
                las->setDirection(ecran::Gauche);
                Jeu.plateau().destinationMove(Jeu,0,nextLas);
                REQUIRE_FALSE(Jeu.moving());

            }
        }

        SUBCASE("Quand le Laser va vers la Droite "){

            SUBCASE("Dans le cas ou on ne se situe pas au bord du tableau"){
                ecran::Laser* las= new ecran::Laser{Jeu.plateau().coordVersPoint(x),Jeu.plateau().coordVersPoint(y),cote};
                Jeu.plateau().setCase(las);
                Jeu.addLaser(las);
                las->setDirection(ecran::Droite);
                Jeu.plateau().destinationMove(Jeu,0,nextLas);
                Jeu.plateau().emplacementCase(x+1,y)->nextLaser(Jeu,las->direction(),nextLas);
                //ecran::Case* cas =nextLas[1] ;
                std::cout << nextLas[0]->x()<<","<<nextLas[0]->y()<<std::endl;
                /*REQUIRE_EQ(nextLas[0]->x(),cas->x());
                REQUIRE_EQ(nextLas[0]->y(),cas->y());*/
            }

            SUBCASE("Dans le cas ou on se situe au bord du tableau "){
                ecran::Laser* las= new ecran::Laser{Jeu.plateau().coordVersPoint(nbColonne-1),Jeu.plateau().coordVersPoint(y),cote};
                Jeu.plateau().setCase(las);
                Jeu.addLaser(las);
                las->setDirection(ecran::Droite);
                Jeu.plateau().destinationMove(Jeu,0,nextLas);
                REQUIRE_FALSE(Jeu.moving());
            }
        }

        SUBCASE("Quand le Laser va vers le Haut "){

            SUBCASE("Dans le cas ou on ne se situe pas au bord du tableau"){
                ecran::Laser* las= new ecran::Laser{Jeu.plateau().coordVersPoint(x),Jeu.plateau().coordVersPoint(y),cote};
                Jeu.plateau().setCase(las);
                Jeu.addLaser(las);
                las->setDirection(ecran::Haut);
                Jeu.plateau().destinationMove(Jeu,0,nextLas);
                Jeu.plateau().emplacementCase(x,y+1)->nextLaser(Jeu,las->direction(),nextLas);
                //ecran::Case* cas =nextLas[1] ;
                std::cout << nextLas[0]->x()<<","<<nextLas[0]->y()<<std::endl;
                /*REQUIRE_EQ(nextLas[0]->x(),cas->x());
                REQUIRE_EQ(nextLas[0]->y(),cas->y());*/
            }

            SUBCASE("Dans le cas ou on se situe au bord du tableau "){
                ecran::Laser* las= new ecran::Laser{Jeu.plateau().coordVersPoint(x),Jeu.plateau().coordVersPoint(nbLigne-1),cote};
                Jeu.plateau().setCase(las);
                Jeu.addLaser(las);
                las->setDirection(ecran::Haut);
                Jeu.plateau().destinationMove(Jeu,0,nextLas);
                REQUIRE_FALSE(Jeu.moving());
            }
        }

        SUBCASE("Quand le Laser va vers le Bas "){

            SUBCASE("Dans le cas on ne se situe pas au bord du tableau"){
                ecran::Laser* las= new ecran::Laser{Jeu.plateau().coordVersPoint(x),Jeu.plateau().coordVersPoint(y),cote};
                Jeu.plateau().setCase(las);
                Jeu.addLaser(las);
                las->setDirection(ecran::Bas);
                Jeu.plateau().destinationMove(Jeu,0,nextLas);
                Jeu.plateau().emplacementCase(x,y+1)->nextLaser(Jeu,las->direction(),nextLas);
                //ecran::Case* cas =nextLas[1] ;
                std::cout << nextLas[0]->x()<<","<<nextLas[0]->y()<<std::endl;
                /*REQUIRE_EQ(nextLas[0]->x(),cas->x());
                REQUIRE_EQ(nextLas[0]->y(),cas->y());*/;
            }

            SUBCASE("Dans le cas ou on se situe au bord du tableau "){
                ecran::Laser* las= new ecran::Laser{Jeu.plateau().coordVersPoint(x),Jeu.plateau().coordVersPoint(0),cote};
                Jeu.plateau().setCase(las);
                Jeu.addLaser(las);
                las->setDirection(ecran::Bas);
                Jeu.plateau().destinationMove(Jeu,0,nextLas);
                REQUIRE_FALSE(Jeu.moving());
            }
        }
    }

    SUBCASE("La methode movable() est correcte "){
        SUBCASE(" Dans le cas ou les lasers n'ont touches que des Casevide"){

        }

        SUBCASE(" Dans le cas ou les lasers ont touches des Casevide et des cibles"){

        }

        SUBCASE(" Dans le cas ou les lasers ont touches un objet intouchable"){

        }
    }
}

TEST_CASE("Les methodes de Viewer sont correctes"){
    int largeur=500,hauteur=600;
    int decalageX=30,decalageY=80;
    ecran::Viewer fenetre{largeur,hauteur,decalageX,decalageY};

    SUBCASE("La methode pixelX() est correcte"){
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

TEST_CASE("Les methodes de Bouton sont correctes"){

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
/*
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
}*/
