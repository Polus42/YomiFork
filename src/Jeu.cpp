#include "Jeu.hpp"
#include "Joueur.hpp"
#include "Carte.hpp"
#include "Deck.hpp"
#include "Etat.hpp"
#include "EtatPioche.hpp"
#include "EtatChoixJ1.hpp"
#include "EtatBluff.hpp"
#include "EtatChoixJ2.hpp"
#include "EtatCombo.hpp"
#include "EtatCleanUp.hpp"
#include "EtatFin.hpp"
#include"EtatChoixPerso.hpp"
#include "Observeur.hpp"
#include "EtatChoixWin.hpp"
#include "EtatCalcDmg.hpp"


Jeu::Jeu () { // les joueur seront rajouter à Jeu dans l'état "etatChoixPerso"
		joue_=1;
		etatPioche_= new EtatPioche(this);
		etatBluff_= new EtatBluff(this);
		etatChoixJ1_=new EtatChoixJ1(this);
		etatChoixJ2_=new EtatChoixJ2(this);
		etatCombo_=new EtatCombo(this);
		etatCleanUp_= new EtatCleanUp(this);
		etatFin_= new EtatFin(this);
		etatChoixWin_ = new EtatChoixWin(this);
		etatCalcDmg_ = new EtatCalcDmg(this);
		etatCourant_= etatPioche_;
		gagnantCombat_=0;
		combo_=0;
		comboTypeJ1_=0;
		comboTypeJ2_=0;
		bluff_=false;
		fini_=false;
		
}
void Jeu::retournerToMain(int i) {

	if (i==1){
		j1_->addCarteMain(this->getLastCarte(1));
		carteJ1_.pop_back();
		 
	}else {
		j2_->addCarteMain(this->getLastCarte(2));
		carteJ2_.pop_back();
	}

}

void Jeu::addRcarteJ1(Carte *c){RcarteJ1_.push_back(c);}
void Jeu::addRcarteJ2(Carte *c){RcarteJ2_.push_back(c);}

void Jeu::addCarteJ1(Carte* c){carteJ1_.push_back(c);}	
void Jeu::addCarteJ2(Carte *c){carteJ2_.push_back(c);}

void Jeu::actionEffet(int i){
	Carte *c;
	if(i==1){
		c=carteJ1_.at(carteJ1_.size()-1);
	}else{
		c=carteJ2_.at(carteJ2_.size()-1);
	}
	
	c->actionEffet(this,i);
	
}

void Jeu::plusCombo(){++combo_;}

Carte* Jeu::getLastCarte(int i){

	if (i==1){
	
		return (this->getCarteJ1().at(this->getCarteJ1().size()-1));
	}
	else{
		return (this->getCarteJ2().at(this->getCarteJ2().size()-1));
	}
}

int Jeu::getGoodComboType(int x){
	if (x==1){
		return this->getComboTypeJ1();
	}else{
		return this->getComboTypeJ2();
	}
}



void Jeu::clearCarteJ1(){

	carteJ1_.clear();
}

void Jeu::clearCarteJ2(){

	carteJ2_.clear();
}

void Jeu::clearRCarteJ1(){

	RcarteJ1_.clear();
}

void Jeu::clearRCarteJ2(){

	RcarteJ2_.clear();
}
// --------------------------------------------------------------------------------
// Implementation de la classe sujet
void Jeu::ajouterObs(Observeur *o)
{
	listeObs_.push_back(o);
}
void Jeu::supprimerObs(int i)
{
	listeObs_.erase(listeObs_.begin()+i);
}
void Jeu::notifierObs()
{
	for (Observeur *o : listeObs_)
	{
		o->actualiser();
	}
}
void Jeu::notifierObs(Observeur *o)
{
	o->actualiser();
}


