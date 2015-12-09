#include "EtatBluff.hpp"
#include "Jeu.hpp"
#include "Carte.hpp"
#include "Joueur.hpp"
#include "Champion.hpp"


void EtatBluff::jouerCarte(){
	
	std::string conf;
	int p=-1; // l'indice de la carte à jouer dans la main
	int gagnant=jeu_->getGagnantCombat();

	
	
	if (jeu_->getGoodComboType(gagnant)!=2) {
	std::cout << gagnant << std::endl;
	std::cout<<"Voulez vous bluffer oui/non"<<std::endl;
	std::cin>>conf;
	if (conf=="oui"){
	
		if (jeu_->getGagnantCombat()==1){// on regard le gagnant pour voir qui doit bluff
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
		else
		{
			while ((p<0)||(p>=jeu_->getJ1()->getMain()->size())){
				std::cout<<"Choisir une carte valide à jouer"<<std::endl;
				std::cin >>p;
				--p; // on "convertie" car quand le joueur dit qu'il veut jouer la carte 1 il veut jouer la carte à l'indice 0
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
	}else{	
			
			std::cout<<"C'est au joueur "<<gagnant<<" de combo"<<std::endl;
			jeu_->setJoue(jeu_->getGagnantCombat());
			jeu_->setEtatCourant(jeu_->getEtatCombo());
			
		}
			
		}else{
			
			jeu_->setEtatCourant(jeu_->getEtatCalcDmg());
			jeu_->getEtatCourant()->verification();// action automatique
	}
}


void EtatBluff::annulerAction(){
	if (jeu_->getGagnantCombat()==1){// on regard le gagnant pour voir qui doit bluff
		jeu_->retournerToMain(2);
	}else{
		jeu_->retournerToMain(1);
		
	}
	std::cout<<"choisisser une nouvelle carte"<<std::endl;
}


void EtatBluff::verification() {
	Carte* c;
	
	if (jeu_->getGagnantCombat()==1){// on regard le gagnant pour voir qui doit bluff
		c=jeu_->getLastCarte(1);
	}else{
		c=jeu_->getLastCarte(2);
	}
	
	if (c->getGoodType()==4){ // vu que les jocker on qu'un seul coté ou aurait put utilise getType() mais sa revient au même;
		jeu_->setBluff(true);
	}else{
		jeu_->setBluff(false);
	}
}

void EtatBluff::confirmation(){
	int gagnant=jeu_->getGagnantCombat();
	std::cout<<"C'est au joueur "<<gagnant<<" de combo"<<std::endl;
	//int comboMaxG;// le combo max du gagnat
	jeu_->setJoue(gagnant);
	this->verification();
	
	
	
	/*if (gagnant==1){// on regard le gagnant pour voir qui doit bluff
		comboMaxG=jeu_->getJ1()->getChamp()->getComboMax();
	}else{
		comboMaxG=jeu_->getJ2()->getChamp()->getComboMax();		
	}
	*/
	//if ((comboMaxG>jeu_->getCombo())&&(jeu_->getGoodComboType(gagnant)!=2)){ // 2 veut dire qu'on a joué un finisher et qu'on peut pas partir en combo
		std::cout<<"C'est au joueur "<<gagnant<<" de partir en combo"<<std::endl;
		jeu_->notifierObs();
		jeu_->setEtatCourant(jeu_->getEtatCombo());
		
		
	/*}else {
		jeu_->setEtatCourant(jeu_->getEtatCalcDmg());
		jeu_->getEtatCourant()->verification();// action automatique
	}*/
}

void EtatBluff::retournerCarte() {


	int p;

	std::cout<<"Choisir la carte à retourner"<<std::endl;

	std::cin>>p;
	--p;
	if (jeu_->getGagnantCombat()==1){// on regard le gagnant pour voir qui doit bluff
		if ( (p>=0) &&(p<jeu_->getJ2()->getMain()->size())) { // On regarde si l'indice est valide

			jeu_->getJ2()->getMain()->at(p)->changerFace();
			jeu_->notifierObs();
		}else{
			std::cout<<" La carte n'est pas retournalbe fonction sans effet"<<std::endl;
		}
	}else{
		if ( (p>=0) &&(p<jeu_->getJ1()->getMain()->size())) {// On regarde si l'indice est valide

			jeu_->getJ1()->getMain()->at(p)->changerFace();
			jeu_->notifierObs();
		}else{
			std::cout<<" La carte n'est pas retournalbe fonction sans effet"<<std::endl;
		}
	}
}


void EtatBluff::InfoCarte(){


	int p;
	
	
	std::cout<<"Choisir la carte d'on vous voulez les infos'"<<std::endl;

	std::cin>>p;
	--p;// convertion comme dans jouerCarte
	if (jeu_->getGagnantCombat()==1){// on regard le gagnant pour voir qui doit bluff
		if ( (p>=0) &&(p<jeu_->getJ2()->getMain()->size())) {// On regarde si l'indice est valide

			jeu_->getJ2()->getMain()->at(p)->afficher();
		}else{
			std::cout<<" Rentrer un numero de carte valide"<<std::endl;
		}
	}if ( (p>=0) &&(p<jeu_->getJ1()->getMain()->size())) {// On regarde si l'indice est valide

			jeu_->getJ1()->getMain()->at(p)->afficher();
		}else{
			std::cout<<" Rentrer un numero de carte valide"<<std::endl;
		}
}
