#include "Balle.h"

//-----------------------------------------------------------------------------
Balle::Balle(float argDepartX, float argDepartY) : Jouet(argDepartX, argDepartY, 10, 10)
{
    departX=argDepartX;
    departY=argDepartY;
}

//-----------------------------------------------------------------------------
void Balle::rebondirMurs()
{
    vitesseHorizontale *= -1;
}

//-----------------------------------------------------------------------------
void Balle::rebondirRaquetteOuPlafond()
{
    vitesseVerticale *= -1;
}

//-----------------------------------------------------------------------------
void Balle::toucherPlancher()
{
    position.y = departY;
    position.x = departX;
}

//-----------------------------------------------------------------------------
void Balle::bouger()
{
    position.y += vitesseVerticale;
    position.x += vitesseHorizontale;

    forme.setPosition(position);
}
//-----------------------------------------------------------------------------