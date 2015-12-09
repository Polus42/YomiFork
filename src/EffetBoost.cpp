#include"EffetBoost.hpp"
#include "Jeu.hpp"
#include "Joueur.hpp"

void EffetBoost::actionEffet(Jeu *jeu, int x){

	if (x==1){
	
		jeu->getJ1()->setMultDmg(jeu->getJ1()->getMultDmg()+0.5);
	}else{
		jeu->getJ2()->setMultDmg(jeu->getJ2()->getMultDmg()+0.5);
	}
}

void EffetBoost::afficher(){
	std::cout<<"Boost :Augment le multiplicateur de dommage de 0.5 du joueur ayant jouer la carte"<<std::endl;
}
std::string EffetBoost::getNom()
{
	return "Boost";
}
