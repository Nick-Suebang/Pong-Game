// Adapté de https://gist.github.com/mcleary/b0bf4fa88830ff7c882d


#ifndef SFML1_CHRONOMETRE_H
#define SFML1_CHRONOMETRE_H
#pragma once

#include <iostream>
#include <chrono>
#include <ctime>
#include <cmath>

#include <unistd.h>

#include "Configuration.h"


class Chronometre
{
private:
    Configuration *configuration = Configuration::getInstance();
    std::chrono::time_point<std::chrono::system_clock> m_StartTime;
    std::chrono::time_point<std::chrono::system_clock> m_EndTime;
    double lapse{0};
    bool m_bRunning{false};

public:
    Chronometre();

    void start();

    void stop();

    void ajusterVitesse();

    double elapsedMilliseconds();

    double elapsedSeconds();

};


#endif //SFML1_CHRONOMETRE_H
