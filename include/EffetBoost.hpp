#include <iostream>
#include "Effet.hpp"


#ifndef EFFETBOOST_HPP
#define EFFETBOOST_HPP

class EffetBoost : public Effet {

public:
EffetBoost(){}


void actionEffet(Jeu *jeu,int x); // x indique quel joueur apartient la carte.
void afficher();
std::string getNom();
};

#endif
