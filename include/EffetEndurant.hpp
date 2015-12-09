#include <iostream>
#include "Effet.hpp"


#ifndef EFFETENDURANT_HPP
#define EFFETENDURANT_HPP

//Effet du champion Makunouchi

class EffetEndurant : public Effet {

public:
EffetEndurant(){}
void actionEffet(Jeu *jeu,int x); // x indique quel joueur apartient la carte.
void afficher();
std::string getNom();
};

#endif
