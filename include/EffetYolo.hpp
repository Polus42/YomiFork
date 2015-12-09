#include <iostream>
#include "Effet.hpp"


#ifndef EFFETYOLO_HPP
#define EFFETYOLO_HPP

class EffetYolo : public Effet {

public:
EffetYolo(){}
void actionEffet(Jeu *jeu,int x); // x indique quel joueur apartient la carte.
void afficher();
std::string getNom();
};

#endif
