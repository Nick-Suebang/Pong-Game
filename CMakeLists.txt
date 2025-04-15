cmake_minimum_required(VERSION 3.15)
project(sfml1)

set(CMAKE_CXX_STANDARD 14)


add_executable(sfml1 main.cpp Raquette.cpp Raquette.h Balle.cpp Balle.h Jouet.cpp Jouet.h Affichage.cpp Affichage.h Son.cpp Son.h Utilitaires/Chronometre.cpp Utilitaires/Chronometre.h Utilitaires/Configuration.h Utilitaires/Configuration.cpp
        Brique.cpp)
# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system graphics window network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
endif()

