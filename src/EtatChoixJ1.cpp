#include "EtatChoixJ1.hpp"
#include "Jeu.hpp"
#include "Carte.hpp"
#include "Joueur.hpp"



void EtatChoixJ1::jouerCarte(){
	
	int p=-1; // l'indice de la carte à jouer dans la main
	std::string conf;
	while ((p<0)||(p>=jeu_->getJ1()->getMain()->size())){
		std::cout<<"Choisir une carte valide à jouer"<<std::endl;
		std::cin >>p;
		--p; // on "convertit" car quand le joueur dit qu'il veut jouer la carte 1 il veut jouer la carte à l'indice 0
	}
	jeu_->addCarteJ1((jeu_->getJ1()->jouerCarte(p)));
	std::cout<<"Confirmer oui/non"<<std::endl;
	std::cin>>conf;
	
	if (conf=="oui"){
		jeu_->getEtatCourant()->confirmation();
		
	}else{
		jeu_->getEtatCourant()->annulerAction();
	}
}


void EtatChoixJ1::annulerAction(){

	jeu_->retournerToMain(1);
	std::cout<<"Choisissez une nouvelle carte"<<std::endl;
}


void EtatChoixJ1::verification() {

	jeu_->actionEffet(1);
}

void EtatChoixJ1::confirmation(){

	this->verification();
	std::cout<<"C'est au joueur 2 de choisir une carte"<<std::endl;
	jeu_->setJoue(2);
	jeu_->setEtatCourant(jeu_->getEtatChoixJ2());
	// Notifier l'affichage du changement -----------------------------
	jeu_->notifierObs();
}


void EtatChoixJ1::retournerCarte() {


	int p;

	std::cout<<"Choisir la carte à retourner"<<std::endl;

	std::cin>>p;
	--p;// convertion comme dans jouerCarte
	if ( (p>=0) &&(p<jeu_->getJ1()->getMain()->size())) {

		jeu_->getJ1()->getMain()->at(p)->changerFace();
		jeu_->notifierObs();
	}else{
		std::cout<<"La carte n'est pas retournalbe, fonction sans effet"<<std::endl;
	}
	// Notifier l'affichage du changement -----------------------------
	jeu_->notifierObs();
	
}

void EtatChoixJ1::InfoCarte(){

	int p;
	
	
	std::cout<<"Choisir la carte dont vous voulez les infos'"<<std::endl;

	std::cin>>p;
	--p;// convertion comme dans jouerCarte
	if ( (p>=0) &&(p<jeu_->getJ1()->getMain()->size())) {

		jeu_->getJ1()->getMain()->at(p)->afficher();
	}else{
		std::cout<<"Rentrez un numero de carte valide"<<std::endl;
	}
}
