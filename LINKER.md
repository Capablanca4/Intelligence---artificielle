Option de l'éditeur de liens (linker settings)  à utiliser en remplacement de 
SDL2 et SDL_bgi (implantation de winbgi en SDL pour linux et mac osX)
à mettre dans la colonne "link libraries" :

bgi
gdi32
comdlg32 
uuid 
oleaut32 
ole32

sinon il est possible de mettre -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 dans "Other linker options" 

(Options à mettre dans "Buid Options" du projet)
