#include"EffetEndurant.hpp"
#include "Jeu.hpp"
#include "Joueur.hpp"
#include "Champion.hpp"

void EffetEndurant::actionEffet(Jeu *jeu,int x){
	
	std::srand (time(NULL));//intialise random seed
	if (x==1){
		jeu->getJ1()->getChamp()->heal(std::rand()%5+1); // heal entre 1 est 5
	}
	else{
		jeu->getJ2()->getChamp()->heal(std::rand()%5+1);
	}

} 
void EffetEndurant::afficher(){
	std::cout<<"Heal de 1 à 5 hp en début de tour"<<std::endl;	
}
std::string EffetEndurant::getNom()
{
	return "Endurant";
}

