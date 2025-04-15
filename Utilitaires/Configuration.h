#ifndef PROTOCONSOLE_CONFIG_H
#define PROTOCONSOLE_CONFIG_H

#include <string>

class Configuration
{

private:
    // "Patron Singleton"
    static Configuration *instance;
    Configuration(){} // Constructeur privé

public :
    static Configuration *getInstance();

    const int FPS{400};
    const int LARGEUR_FENETRE{1024};
    const int HAUTEUR_FENETRE{764};

    const int NBR_LIGNES_BRIQUE {5};
    const int NBR_RANGEES_BRIQUE {10};
    const float LARGEUR_BRIQUE = LARGEUR_FENETRE / (NBR_RANGEES_BRIQUE + 1);
    const float EPAISSEUR_BRIQUE {20};
    const float ESPACEMENT = LARGEUR_BRIQUE / (NBR_RANGEES_BRIQUE + 1);
};

#endif //PROTOCONSOLE_CONFIG_H
