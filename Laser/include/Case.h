#ifndef CASE_H
#define CASE_H
#include "Point.h"
#include "Viewer.h"
#include <vector>

namespace ecran{

struct coord {int x,y; };

enum TDirection{Droite,Gauche,Haut,Bas};

class Laser;

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

        /** Fonction gerant le deplacement du laser*/
        virtual void touch(Game& Jeu,Laser* las);
        virtual void nextLaser(Game& Jeu,const TDirection& direcLas,std::vector<Laser*>& nextLas) const;

        /**Fonction gerant le changement d'objet*/
        virtual void transformation(Echiquier& plateau);

        /** Fonctions de desssin*/
        virtual void draw(Viewer& fenetre)=0;
        void clearCase(Viewer& fenetre);

        virtual std::ostream& name(std::ostream& ost)const=0;
        std::ostream& write(std::ostream& ost)const;
        friend std::ostream& operator<< (std::ostream& ost,const Case& cas);

        /**Fonction de test*/
        virtual std::string typeObjet()const;
    private:
        int d_cote; /** largeur du carre definissant la case*/

};
}
#endif // CASE_H
