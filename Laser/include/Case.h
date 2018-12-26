#ifndef CASE_H
#define CASE_H
#include "Point.h"
#include "Viewer.h"
#include <vector>

namespace ecran{

struct coord {int x,y; };

enum TDirection{Droite,Gauche,Haut,Bas};

class Echiquier;

class Game;

class Case: public Point
{
    public:
        /** Constructeurs et destructeur*/
        Case(Point& centre,int cote);
        Case(int x,int y,int cote);
        Case(Case& cas);
        virtual ~Case();

        /** Accesseur*/
        const Point centre()const;
        const int cote()const;

        /** Modificateur*/
        void changerCentre(const Point& centre);

        /**Fonction de test*/
        virtual std::string typeObjet()const;

        /** Fonction gerant le deplacement du laser*/
        virtual bool touch(Game& Jeu,int n);
        virtual coord posNextMoveLaser(Game& Jeu,int n) const;

        /**Fonction gerant le changement d'objet*/
        virtual void transformation(Echiquier& plateau);

        /** Fonctions de desssin*/
        virtual void draw(Viewer& fenetre)=0;
        void clearCase(Viewer& fenetre);

    private:
        int d_cote; /** largeur du carre definissant la case*/

};
}
#endif // CASE_H
