#include "Brique.h"

Brique::Brique(float departX, float departY, int largeur, int epaisseur): Jouet(departX, departY, largeur, epaisseur)
{
    forme.setFillColor(COULEURS[rand()%5]);
}
