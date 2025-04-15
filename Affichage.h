#ifndef SFML1_AFFICHAGE_H
#define SFML1_AFFICHAGE_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Affichage
{
private:
    Font police;
    Text text;
public:
    Affichage();

    [[nodiscard]] Text getText();

    void setMessage(const std::string &message);
};


#endif //SFML1_AFFICHAGE_H
