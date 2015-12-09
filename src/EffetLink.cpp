#include"EffetLink.hpp"
#include "Jeu.hpp"
#include "Joueur.hpp"
void EffetLink::actionEffet(Jeu *jeu,int x){

	if (x==1){
		jeu->setComboTypeJ1(1);
	}else{
		jeu->setComboTypeJ2(1);
	}
}

void EffetLink::afficher(){

	std::cout<<"Link :Permet de jouer n'importe quel coup en combo après celui-ci si le compteur de combo n'est pas trop élever"<<std::endl;
}
std::string EffetLink::getNom()
{
	return "Link";
}
