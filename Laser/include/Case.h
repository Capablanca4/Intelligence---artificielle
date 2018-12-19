#ifndef CASE_H
#define CASE_H
#include "Point.h"
#include "Viewer.h"
#include "GameStatut.h"
#include <vector>

namespace ecran{

struct coord {
    int x,y; };

class Echiquier;

enum TDirection{Droite,Gauche,Haut,Bas};

class Case: public Point
{
    public:
        /** Constructeurs et destructeur*/
        Case(Point& centre,int cote);
        Case(int x,int y,int cote);
        virtual ~Case();

        /** Accesseur*/
        const Point centre()const;
        const int cote()const;

        /** Modificateur*/
        void changerCote(const int cote);
        void changerCentre(const Point& centre);

        /** Fonction gerant le deplacement du laser*/
        virtual bool touch(Echiquier& plateau,GameStatut& StatutJeu,int n);
        virtual coord posNextMoveLaser(Echiquier& plateau) const;

        /**Fonction gerant le changement d'objet*/
        virtual void transformation(Echiquier& plateau);

        /** Fonctions de desssin*/
        virtual void draw(Viewer& fenetre)=0;
        void clearCase(Viewer& fenetre);

        /**Fonction de test*/
        virtual std::string typeObjet()const;

    private:
        int d_cote; /** largeur du carre definissant la case*/

};
}
#endif // CASE_H
