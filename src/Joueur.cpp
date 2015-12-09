#include "Joueur.hpp"
#include"Champion.hpp"
#include"Carte.hpp"
#include"Deck.hpp"
#include"Jeu.hpp"
#include "Effet.hpp"

Joueur::Joueur (Deck *deck,std::string nom) {

		nom_ =nom;
		deck_=deck;
		champ_=deck_->getChampion();
		cim_ = new Deck();//il faut initialiser le cimetière ici
		multDmg_=1;
		main_ = new std::vector<Carte*>();
}

void Joueur::piocher(){
	if(deck_->getListeCartes().size()!=0) {
		this->addCarteMain(deck_->piocher());
	}else{// Si jamais il n'y a plus de carte à piocher on remet le cimetière dans le deck
		for( auto i : deck_->getListeCartes()){
			this->addCarteDeck(i);
		}
		cim_->clear();
		this->addCarteMain(deck_->piocher());
	}
	
}


void Joueur::actionEffet(Jeu *jeu,int j){
	champ_->actionEffet(jeu,j);
}


Carte* Joueur::jouerCarte(int p ) {

	//--p;
	if ((p>=0)&&(p<main_->size())){
	Carte *c=main_->at(p);

	main_->erase(main_->begin()+p); 
	
	return c;
	}
	
	return main_->at(0); // à modifier là je suis presser

}

void Joueur::multDmg(int x){

	if (!(multDmg_>=3)){ // le supérieur devrait pas arriver mais au cas où
	
		if ((multDmg_*x)>=3){
			multDmg_=3;
		}else{
			multDmg_=multDmg_*x;
		}
	}
}

void Joueur::addCarteMain(Carte *c){

	main_->push_back(c);
}

void Joueur::addCarteCim(Carte *c){
	cim_->addCarte(c);	
}

void Joueur::addCarteDeck(Carte *c){
	deck_->addCarte(c);
}


