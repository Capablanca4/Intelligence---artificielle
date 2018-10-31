#include <iostream>
#include "Viewer.h"

int main()
{
    ecran::Viewer fenetre{500,700};
    fenetre.openWindow();
    fenetre.waitUntilButton();
    fenetre.closeWindow();
    return 0;
}

