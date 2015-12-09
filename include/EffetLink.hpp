#include <iostream>
#include "Effet.hpp"


#ifndef EFFETLINK_HPP
#define EFFETLINK_HPP

class EffetLink : public Effet {

public:
EffetLink(){}
void actionEffet(Jeu *jeu,int x); // x indique quel joueur apartient la carte.
void afficher();
std::string getNom();
};

#endif
