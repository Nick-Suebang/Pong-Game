#include "Chronometre.h"

//----------------------------------------------------------------------------------------------------------------------
Chronometre::Chronometre()
{
    start();
}

//----------------------------------------------------------------------------------------------------------------------
void Chronometre::start()
{
    m_StartTime = std::chrono::system_clock::now();
    lapse = elapsedMilliseconds();
    m_bRunning = true;
}

//----------------------------------------------------------------------------------------------------------------------
void Chronometre::stop()
{
    m_EndTime = std::chrono::system_clock::now();
    m_bRunning = false;
}

//----------------------------------------------------------------------------------------------------------------------
double Chronometre::elapsedMilliseconds()
{
    std::chrono::time_point<std::chrono::system_clock> endTime;

    if (m_bRunning)
    {
        endTime = std::chrono::system_clock::now();
    } else
    {
        endTime = m_EndTime;
    }

    return std::chrono::duration_cast<std::chrono::milliseconds>(endTime - m_StartTime).count();
}

//----------------------------------------------------------------------------------------------------------------------
double Chronometre::elapsedSeconds()
{
    return elapsedMilliseconds() / 1000.0;
}

//----------------------------------------------------------------------------------------------------------------------
void Chronometre::ajusterVitesse()
{
    double duree{1000.0 / (double) configuration->FPS};
    double interval = (double) elapsedMilliseconds() - lapse;

   /* while( interval < duree)
    {
        usleep(1000);
        interval = (double) elapsedMilliseconds() - lapse;
     //   std::cout << interval << " " << duree<< " " << elapsedMilliseconds() << std::endl;
    }
   */

    if (interval < duree)
    {
        usleep(((duree - interval)*1000));
    }
    lapse = (double) elapsedMilliseconds();
}

//----------------------------------------------------------------------------------------------------------------------
