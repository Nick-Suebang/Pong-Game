#include "Son.h"
#include <SFML/Audio.hpp>

using namespace sf;

//-----------------------------------------------------------------------------
void Son::beep(const std::string &fichier)
{
    if (!buffer.loadFromFile(fichier))
        return; // error
    sound.setBuffer(buffer);
    sound.play();
}

//-----------------------------------------------------------------------------
void Son::jouerSonRate()
{
    beep(SON_RATE);
}

//-----------------------------------------------------------------------------
void Son::jouerSonRebond()
{
    beep(SON_REBOND);
}

//-----------------------------------------------------------------------------
void Son::jouerSonReussi()
{
    beep(SON_REUSSI);
}

//-----------------------------------------------------------------------------