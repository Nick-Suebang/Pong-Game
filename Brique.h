#ifndef BRIQUE_H
#define BRIQUE_H

#include <SFML/Graphics/Color.hpp>
#include "Jouet.h"


class Brique : public Jouet {
private:
    sf::Color COULEURS[5] = {Color::Cyan, Color::Blue, Color::Green, Color::Red, Color::Yellow};
public:
    Brique (float departX, float departY, int largeur, int epaisseur);
};



#endif //BRIQUE_H
