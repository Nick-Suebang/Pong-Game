# Jeu de Pong avec SFML

Ce projet est une implémentation du célèbre jeu Pong utilisant la bibliothèque SFML (Simple and Fast Multimedia Library). Le jeu reprend les mécaniques classiques du Pong avec quelques fonctionnalités modernes.

## Table des matières

- [Prérequis](#prérequis)
- [Installation](#installation)
- [Utilisation](#utilisation)
- [Structure du projet](#structure-du-projet)
- [Classes principales](#classes-principales)
- [Contrôles](#contrôles)

## Prérequis

- CMake (version 3.15 ou supérieure)
- Compilateur C++ supportant C++14
- SFML 2.x
- Un système d'exploitation Linux ou Windows

## Installation

1. Clonez le dépôt :
```bash
git clone <url-du-repo>
```

2. Créez un dossier build et accédez-y :
```bash
cd 20241121103027_Nick_Hariel-2333658-Lab10
mkdir build
cd build
```

3. Générez les fichiers de build avec CMake :
```bash
cmake ..
```

4. Compilez le projet :
```bash
cmake --build .
```

## Utilisation

Pour lancer le jeu, exécutez le fichier généré `sfml1` depuis le dossier build :
```bash
./sfml1
```

## Structure du projet

```
.
├── CMakeLists.txt
├── main.cpp
├── Affichage.cpp/h
├── Balle.cpp/h
├── Brique.cpp
├── Jouet.cpp/h
├── Raquette.cpp/h
├── Son.cpp/h
└── Utilitaires/
    ├── Chronometre.cpp/h
    └── Configuration.cpp/h
```

## Classes principales

### Raquette
Gère le comportement et le rendu des raquettes des joueurs.
- Déplacement vertical
- Collision avec la balle
- Rendu graphique

### Balle
Implémente la logique de la balle.
- Mouvement et rebonds
- Collisions avec les raquettes et les murs
- Physique réaliste

### Affichage
Gère tout l'aspect graphique du jeu.
- Rendu des éléments
- Interface utilisateur
- Score et informations

### Son
Gère les effets sonores du jeu.
- Sons de collision
- Effets sonores divers
- Musique de fond (si présente)

### Utilitaires
#### Chronometre
- Gestion du temps de jeu
- Mesure des intervalles

#### Configuration
- Paramètres du jeu
- Options configurables

## Contrôles

### Joueur 1 (gauche)
- Haut : W
- Bas : S

### Joueur 2 (droite)
- Haut : Flèche haut
- Bas : Flèche bas

### Général
- ESC : Pause/Menu
- R : Réinitialiser la partie
- Q : Quitter le jeu

## Fonctionnalités

- Mode 2 joueurs
- Système de score
- Effets sonores
- Physique réaliste
- Interface utilisateur intuitive
- Possibilité de personnalisation via le fichier de configuration

## Développement

Le projet utilise CMake comme système de build et est structuré de manière modulaire pour faciliter la maintenance et les extensions futures.

### Compilation en mode Debug

```bash
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build .
```

### Compilation en mode Release

```bash
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build .
```

## Dépendances externes

Le projet utilise les composants suivants de SFML :
- sfml-system
- sfml-graphics
- sfml-window
- sfml-network
- sfml-audio

## Contribution

Pour contribuer au projet :
1. Forkez le dépôt
2. Créez une branche pour votre fonctionnalité
3. Committez vos changements
4. Poussez vers la branche
5. Ouvrez une Pull Request

## Licence

Ce projet est distribué sous licence MIT. Voir le fichier `LICENSE` pour plus de détails.

## Auteurs

- Nick Hariel

## Support

Pour toute question ou problème, veuillez ouvrir une issue dans le dépôt GitHub.
