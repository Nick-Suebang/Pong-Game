#include <SFML/Graphics.hpp>
#include "Raquette.h"
#include "Balle.h"
#include "Affichage.h"
#include "Brique.h"
#include "Son.h"
#include "Utilitaires/Chronometre.h"
using namespace sf;

//-----------------------------------------------------------------------------
int main()
{
    Configuration *configuration = Configuration::getInstance();


    int pointage {0};
    int vies{3};

    RenderWindow maFenetre(VideoMode(configuration->LARGEUR_FENETRE, configuration->HAUTEUR_FENETRE), "Pong");
    Raquette raquette(configuration->LARGEUR_FENETRE / 2, configuration->HAUTEUR_FENETRE - 20);
    Balle balle(configuration->LARGEUR_FENETRE / 2, configuration->NBR_LIGNES_BRIQUE * (configuration->EPAISSEUR_BRIQUE + configuration->ESPACEMENT) + 100);

    Affichage affichage;
    Son son;

    Chronometre leChronometre;

    bool tenirRaquette = false;

    Brique*lesBriques [configuration->NBR_RANGEES_BRIQUE][configuration->NBR_LIGNES_BRIQUE];
    for (unsigned int x = 0; x < configuration->NBR_RANGEES_BRIQUE; x++)
    {
        for (unsigned int y = 0; y < configuration->NBR_LIGNES_BRIQUE; y++)
        {
            lesBriques[x][y] = new Brique(x * (configuration->LARGEUR_BRIQUE + configuration->ESPACEMENT) + configuration->ESPACEMENT,y * (configuration->EPAISSEUR_BRIQUE + 10) + 90, configuration->LARGEUR_BRIQUE, configuration->EPAISSEUR_BRIQUE);
        }
    }

    while (maFenetre.isOpen())
    {
        Event evenement;
        while (maFenetre.pollEvent(evenement))
        {
            if (evenement.type == Event::Closed)
                maFenetre.close();
        }

        // Pour déplacer la raquette à gauche ou à droite
        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            raquette.bougerAGauche();
        }
        else if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            raquette.bougerADroite();
        }

        if (Mouse::isButtonPressed(Mouse::Left))
        {
            if (tenirRaquette == true)
            {
                raquette.setPositionX(Mouse::getPosition(maFenetre).x);
            }
            else if (raquette.getHitBox().contains(Mouse::getPosition(maFenetre).x, Mouse::getPosition(maFenetre).y))
            {
                tenirRaquette = true;
            }
        }
        else
        {
            tenirRaquette = false;
        }

        // Gestion des collisions
        // toucher le plancher
        if (balle.getHitBox().top > configuration->HAUTEUR_FENETRE)
        {
            son.jouerSonRate();
            balle.toucherPlancher();
            vies--;
        }

        // toucher le plafond
        if (balle.getHitBox().top < 0)
        {
            son.jouerSonRebond();
            balle.rebondirRaquetteOuPlafond();
        }

        // toucher un mur
        if (balle.getHitBox().left < 0 || balle.getHitBox().left + 10 > configuration->LARGEUR_FENETRE)
        {
            son.jouerSonRebond();
            balle.rebondirMurs();
        }
        // toucher la raquette
        if (balle.getHitBox().intersects(raquette.getHitBox()))
        {
            son.jouerSonReussi();
            balle.rebondirRaquetteOuPlafond();
            pointage++;
        }

        // Pour l'affichage
        maFenetre.clear();

        if (vies == 0)
        {
            affichage.setMessage("Game Over");
        } else
        {
            affichage.setMessage("Vies : " + std::to_string(vies) + " Pointage : " + std::to_string(pointage));
        }

        maFenetre.draw(raquette.getForme());
        maFenetre.draw(balle.getForme());
        maFenetre.draw(affichage.getText());

        for (unsigned int x = 0; x < configuration->NBR_RANGEES_BRIQUE; x++)
        {
            for (unsigned int y = 0; y < configuration->NBR_LIGNES_BRIQUE; y++)
            {
                if (lesBriques[x][y] != nullptr)
                {
                    maFenetre.draw(lesBriques[x][y]->getForme());
                }
            }
        }

        for (unsigned int x = 0; x < configuration->NBR_RANGEES_BRIQUE; x++)
        {
            for (unsigned int y = 0; y < configuration->NBR_LIGNES_BRIQUE; y++)
            {
                if (lesBriques[x][y] != nullptr)
                {
                    if (lesBriques[x][y]->getHitBox().intersects(balle.getHitBox()))
                    {
                        son.jouerSonReussi();
                        balle.rebondirRaquetteOuPlafond();
                        delete lesBriques[x][y];
                        lesBriques[x][y] = nullptr;
                        pointage++;
                    }
                }
            }
        }
        maFenetre.display();

        // Game over : pause 5 secondes et on sort de la boucle
        if (vies == 0)
        {
            sleep(seconds(5));
            maFenetre.close();
        }

        balle.bouger();
        leChronometre.ajusterVitesse();

    }
    for (unsigned int x = 0; x < configuration->NBR_RANGEES_BRIQUE; x++)
    {
        for (unsigned int y = 0; y < configuration->NBR_LIGNES_BRIQUE; y++)
        {
            if (lesBriques[x][y] != nullptr)
            {
                delete lesBriques[x][y];
                lesBriques[x][y] = nullptr;
            }
        }
    }
    return 0;
}

