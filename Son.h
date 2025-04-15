#ifndef SFML1_SON_H
#define SFML1_SON_H

#include <SFML/Audio.hpp>

using namespace sf;

class Son
{
private:
    Sound sound;
    SoundBuffer buffer;
    const std::string SON_RATE{"rate.ogg"};
    const std::string SON_REBOND{"rebond.ogg"};
    const std::string SON_REUSSI{"reussi.ogg"};
public:
    void beep(const std::string &fichier);
    void jouerSonRate();
    void jouerSonRebond();
    void jouerSonReussi();
};


#endif //SFML1_SON_H
