#include <iostream>
#include "Viewer.h"
#include "Cible.h"

int main()
{
    ecran::Viewer fenetre{500,700};
    fenetre.openWindow();
    ecran::Cible cible1{250,250,20};
    cible1.draw(fenetre);
    fenetre.waitUntilButton();
    fenetre.closeWindow();
    return 0;
}

