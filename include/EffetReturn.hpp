#include <iostream>
#include "Effet.hpp"


#ifndef EFFETRETURN_HPP
#define EFFETRETURN_HPP

class EffetReturn : public Effet {

public:
EffetReturn(){}
void actionEffet(Jeu *jeu,int x); // x indique quel joueur apartient la carte.
void afficher();
std::string getNom();
};

#endif
