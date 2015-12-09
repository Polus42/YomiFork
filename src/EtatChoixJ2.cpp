#include "EtatChoixJ2.hpp"
#include "Jeu.hpp"
#include "Carte.hpp"
#include "Joueur.hpp"
#include <iostream>

void EtatChoixJ2::jouerCarte(){
	std::string conf;
	int p=-1; // l'indice de la carte à jouer dans la mai

	while ((p<0)||(p>=jeu_->getJ2()->getMain()->size())){
	std::cout<<"Choisir une carte valide à jouer"<<std::endl;
	std::cin >>p;
	--p; // on "convertie" car quand le joueur dit qu'il veut jouer la carte 1 il veut jouer la carte à l'indice 0
	}
	jeu_->addCarteJ2((jeu_->getJ2()->jouerCarte(p)));
	
	std::cout<<"Confirmer oui/non"<<std::endl;
	std::cin>>conf;
	
	if (conf=="oui"){
		jeu_->getEtatCourant()->confirmation();
		
	}else{
		jeu_->getEtatCourant()->annulerAction();
	}
}


void EtatChoixJ2::annulerAction(){

	jeu_->retournerToMain(2);
	std::cout<<"Choisissez une nouvelle carte"<<std::endl;
}


void EtatChoixJ2::verification() {

	jeu_->actionEffet(2);

}

void EtatChoixJ2::confirmation(){
	this->verification();
	jeu_->setEtatCourant(jeu_->getEtatChoixWin());
	jeu_->getEtatCourant()->verification();
	// Notifier l'affichage du changement -----------------------------
	jeu_->notifierObs();
}

void EtatChoixJ2::retournerCarte() {


	int p;

	std::cout<<"Choisir la carte à retourner"<<std::endl;

	std::cin>>p;
	--p;
	if ( (p>=0) &&(p<jeu_->getJ2()->getMain()->size())) {

		jeu_->getJ2()->getMain()->at(p)->changerFace();
		jeu_->notifierObs();
	}else{
		std::cout<<"La carte n'est pas retournable, fonction sans effet"<<std::endl;
	}
	// Notifier l'affichage du changement -----------------------------
	jeu_->notifierObs();
	
}


void EtatChoixJ2::InfoCarte(){


	int p;
	
	
	std::cout<<"Choisir la carte dont vous voulez les infos'"<<std::endl;

	std::cin>>p;
	--p;// convertion comme dans jouerCarte
	if ( (p>=0) &&(p<jeu_->getJ2()->getMain()->size())) {

		jeu_->getJ2()->getMain()->at(p)->afficher();
	}else{
		std::cout<<"Rentrez un numero de carte valide"<<std::endl;
	}
}
