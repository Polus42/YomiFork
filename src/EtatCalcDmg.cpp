#include "EtatCalcDmg.hpp"
#include "Jeu.hpp"
#include "Carte.hpp"
#include "Joueur.hpp"
#include "Champion.hpp"

void EtatCalcDmg::verification() {

	int gagnant=jeu_->getGagnantCombat();
	double dmg1=0;
	double dmg2=0;
	if ( jeu_->getBluff()){ //regarde si un joker a été jouer en bluff si oui -> pas de dmg
	 	std::cout<<"Joker jouer en bluff pas de do"<<std::endl;
	}else{
	if ((gagnant==0)||(gagnant==1)){
		for (auto &i : jeu_->getCarteJ1()){
			dmg1+=i->getGoodDmg();
		}
	}
	
	if ((gagnant==0)||(gagnant==2)){
		for (auto &j : jeu_->getCarteJ2()){
			dmg2+=j->getGoodDmg();
		}
	}
	dmg1=dmg1*jeu_->getJ1()->getMultDmg(); // on fait intervenir le multiplicateur de dégât
	dmg2=dmg2*jeu_->getJ2()->getMultDmg();// l'autre joueur
	
	// On enlève inflige les dommage aux hp des 2 champion
	jeu_->getJ1()->getChamp()->dmgTaken(dmg2);
	jeu_->getJ2()->getChamp()->dmgTaken(dmg1);
	}
	std::cout<<"Le joueur 1 a pris "<<dmg2<<" point de dégât"<<std::endl;
	std::cout<<"Le joueur 2 a pris "<<dmg1<<" point de dégât"<<std::endl;
	
	jeu_->setEtatCourant(jeu_->getEtatCleanUp());
	jeu_->getEtatCourant()->verification();
	
}



void EtatCalcDmg::InfoCarte() {}
void EtatCalcDmg::retournerCarte(){}
void EtatCalcDmg::jouerCarte(){}
void EtatCalcDmg::confirmation(){}
void EtatCalcDmg::annulerAction(){}
