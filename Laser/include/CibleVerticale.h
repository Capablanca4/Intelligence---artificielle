#ifndef CIBLEVERTICALE_H
#define CIBLEVERTICALE_H
#include "Cible.h"

namespace ecran{
class CibleVerticale : public Cible
{
    public:
        CibleVerticale(const Cible& cib);
        CibleVerticale(const int x,const int y,const int cote);
        virtual ~CibleVerticale();
        void draw(Viewer& fenetre);
};
}
#endif // CIBLEVERTICALE_H
