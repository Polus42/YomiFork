#include <iostream>
#include "Effet.hpp"


#ifndef EFFETTHEANSWER_HPP
#define EFFETTHEANSWER_HPP

//Effet du champion FlorienR

class EffetTheAnswer : public Effet {

public:
EffetTheAnswer(){}
void actionEffet(Jeu *jeu,int x); // x indique quel joueur apartient la carte.
void afficher();
std::string getNom();
};

#endif
