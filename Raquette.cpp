#include "Raquette.h"

//-----------------------------------------------------------------------------
Raquette::Raquette(float argDepartX, float argDepartY) : Jouet(argDepartX, argDepartY, 50, 5)
{
}

//-----------------------------------------------------------------------------
void Raquette::bougerAGauche()
{
    position.x -= vitesse;
    forme.setPosition(position);
}

//-----------------------------------------------------------------------------
void Raquette::bougerADroite()
{
    position.x += vitesse;
    forme.setPosition(position);
}

void Raquette::setPositionX(int argPosition)
{
    position.x = argPosition;
    forme.setPosition(position);
}

//-----------------------------------------------------------------------------
