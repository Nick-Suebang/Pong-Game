#ifndef SFML1_JOUET_H
#define SFML1_JOUET_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Jouet
{
protected:
    Vector2f position;
    RectangleShape forme;
public:
    Jouet(float argDepartX, float argDepartY, int argHauteur, int argLargeur);

    [[nodiscard]] FloatRect getHitBox() const;

    [[nodiscard]] RectangleShape getForme();
};


#endif //SFML1_JOUET_H
