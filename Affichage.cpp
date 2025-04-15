#include "Affichage.h"

//-----------------------------------------------------------------------------
Affichage::Affichage()
{
    // Pour choisir une police
    police.loadFromFile("DS-DIGIT.ttf");

    // Notre texte
    text.setFont(police);
    text.setCharacterSize(75);
    text.setFillColor(sf::Color::White);
}

//-----------------------------------------------------------------------------
void Affichage::setMessage(const std::string &message)
{
    text.setString(message);
}

//-----------------------------------------------------------------------------
Text Affichage::getText()
{
    return text;
}

//-----------------------------------------------------------------------------