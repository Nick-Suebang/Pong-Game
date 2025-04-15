#ifndef SFML1_RAQUETTE_H
#define SFML1_RAQUETTE_H

#include "Jouet.h"

using namespace sf;

class Raquette : public Jouet
{
private:
    float vitesse{1.3f};
public:
    Raquette(float argDepartX, float argDepartY);

    void bougerAGauche();

    void bougerADroite();

    void setPositionX (int argPosition);
};


#endif //SFML1_RAQUETTE_H
