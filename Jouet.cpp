#include "Jouet.h"

//-----------------------------------------------------------------------------
Jouet::Jouet(float argDepartX, float departY, int hauteur, int argLargeur)
{


    // assigne ses arguments au x et y de position
    position.x = argDepartX;
    position.y = departY;

    // initialise forme en définissant sa taille et sa position
    forme.setSize(sf::Vector2f(hauteur, argLargeur));
    forme.setPosition(position);
}

//-----------------------------------------------------------------------------
FloatRect Jouet::getHitBox() const
{
    return forme.getGlobalBounds();
}

//-----------------------------------------------------------------------------
RectangleShape Jouet::getForme()
{
    return forme;
}

//-----------------------------------------------------------------------------