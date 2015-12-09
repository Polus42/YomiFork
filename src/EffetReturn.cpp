#include"EffetReturn.hpp"
#include "Jeu.hpp"
#include "Joueur.hpp"

void EffetReturn::actionEffet(Jeu *jeu,int x){

	if (x==1){
	
		if ((jeu->getGagnantCombat()==0)||(jeu->getGagnantCombat()==1)){
			jeu->getRcarteJ1().push_back(jeu->getLastCarte(1));
		}
		
	}else{
		if ((jeu->getGagnantCombat()==0)||(jeu->getGagnantCombat()==2)){
			jeu->getRcarteJ2().push_back(jeu->getLastCarte(2));
		}
	}
}

void EffetReturn::afficher(){

	std::cout<<" Return :La carte retournera dans la main de son propriétère à la fin du tour"<<std::endl;
}
std::string EffetReturn::getNom()
{
	return "Return";
}
