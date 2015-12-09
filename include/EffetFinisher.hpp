#include <iostream>
#include "Effet.hpp"


#ifndef EFFETFINISHER_HPP
#define EFFETFINISHER_HPP

class EffetFinisher : public Effet {

public:
EffetFinisher(){}
void actionEffet(Jeu *jeu,int x); // x indique quel joueur apartient la carte.
void afficher();
std::string getNom();
};

#endif
