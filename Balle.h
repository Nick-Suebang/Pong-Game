#ifndef SFML1_BALLE_H
#define SFML1_BALLE_H

#include "Jouet.h"

using namespace sf;

class Balle : public Jouet
{
private:
    float departX;
    float departY;
    float vitesseHorizontale{1.2f};
    float vitesseVerticale{1.2f};

public:
    Balle(float argDepartX, float argDepartY);

    void rebondirMurs();

    void rebondirRaquetteOuPlafond();

    void toucherPlancher();

    void bouger();
};


#endif //SFML1_BALLE_H
