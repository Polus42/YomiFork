#include"EffetYolo.hpp"
#include "Jeu.hpp"
#include "Joueur.hpp"

void EffetYolo::actionEffet(Jeu *jeu, int x){
	
	jeu->getJ1()->multDmg(2);
	jeu->getJ2()->multDmg(2);
}

void EffetYolo::afficher(){
	std::cout<<"Yolo :Multiplie par 2 le multiplicateur de dommage des 2 joueurs"<<std::endl;
}
std::string EffetYolo::getNom()
{
	return "Yolo";
}
