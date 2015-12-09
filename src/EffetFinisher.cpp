#include"EffetFinisher.hpp"
#include "Jeu.hpp"
#include "Joueur.hpp"

void EffetFinisher::actionEffet(Jeu *jeu,int x){
	if (x==1){
		jeu->setComboTypeJ1(2);
	}else{
		jeu->setComboTypeJ2(2);
	}
}

void EffetFinisher::afficher(){

	std::cout<<"Finisher :Impossible de jouer une carte en combo après celle-ci"<<std::endl;
}
std::string EffetFinisher::getNom()
{
	return "Finisher";
}
