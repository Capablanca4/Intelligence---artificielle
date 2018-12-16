#include "doctest.h"
#include<sstream>
#include "CaseVide.h"
#include "Echiquier.h"

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
        ecran::Case* cas1=(ecran::Case*) tabl.plateau()[x][y];
        REQUIRE_EQ(cas1->posNextMoveLaser(tabl).x,x);
        REQUIRE_EQ(cas1->posNextMoveLaser(tabl).y,y);
    }
}
