#include "EtatPioche.hpp"
#include "Jeu.hpp"
#include "Carte.hpp"
#include "Joueur.hpp"
//#include"Deck.hpp"

void EtatPioche::verification() {

	// -----------------------------------------------------------
	jeu_->getJ1()->piocher();
	jeu_->getJ2()->piocher();

	jeu_->getJ1()->actionEffet(jeu_,1);
	jeu_->getJ2()->actionEffet(jeu_,2);

	std::cout<<"C'est au joueur 1 de choisir une carte"<<std::endl;

	jeu_->setEtatCourant(jeu_->getEtatChoixJ1());
	jeu_->setJoue(1);
	
	jeu_->notifierObs();
}



void EtatPioche::InfoCarte() {}
void EtatPioche::retournerCarte(){}
void EtatPioche::jouerCarte(){}
void EtatPioche::confirmation(){}
void EtatPioche::annulerAction(){}

// Les autre action n'on pas lieu dans cette etat


