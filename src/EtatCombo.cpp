#include "EtatCombo.hpp"
#include "Jeu.hpp"
#include "Carte.hpp"
#include "Joueur.hpp"
#include "Champion.hpp"

void EtatCombo::jouerCarte(){
	std::string conf;
	Carte *c;
	int p=-1; // l'indice de la carte à jouer dans la main
	bool toutPermis=false;// indique si on est dans un combo ou tout est permis ou non.
	int gagnant=jeu_->getGagnantCombat();// Le gagnant du combat.
	std::cout<<"Voulez vous combo oui/non"<<std::endl;
	std::cin>>conf;
	if (jeu_->getGoodComboType(gagnant)==1){
			toutPermis=1;
	}
	
	if (conf=="oui"){
	
		if (jeu_->getGagnantCombat()==2){// on regard le gagnant pour voir qui doit combo
			while ((p<0)||(p>=jeu_->getJ2()->getMain()->size())){
		
			std::cout<<"Choisir une carte valide à jouer"<<std::endl;
			std::cin >>p;
			--p; // on "convertie" car quand le joueur dit qu'il veut jouer la carte 1 il veut jouer la carte à l'indice 0
			}
	
			c=jeu_->getJ2()->jouerCarte(p);
			jeu_->addCarteJ2((jeu_->getJ2()->jouerCarte(p)));
			if((c->getGoodType()==0)||(c->getGoodType()==1)){// On ne joue en combo que des coup ou des choppes
				if (toutPermis){
					std::cout<<"Confirmer oui/non"<<std::endl;
					std::cin>>conf;
	
					if (conf=="oui"){
						jeu_->getEtatCourant()->confirmation();
		
					}else{
						jeu_->getEtatCourant()->annulerAction();
					}
			}else {
				if (c->getNum()==(1+(jeu_->getLastCarte(1)->getNum()))){
					std::cout<<"Confirmer oui/non"<<std::endl;
					std::cin>>conf;
	
					if (conf=="oui"){
						jeu_->getEtatCourant()->confirmation();
		
					}else{
						jeu_->getEtatCourant()->annulerAction();
					}
					
				}else{
					std::cout<<"Le numéro de carte n'est pas valide ( voir règle) il faudra rerentré la commande"<<std::endl;
					jeu_->getEtatCourant()->annulerAction();
				}
			}
			}else{
				std::cout<<"Le type de carte n'est pas valide il faudra rerentré la commande"<<std::endl;
				jeu_->getEtatCourant()->annulerAction();
			}
		}
		else
		{
			while ((p<0)||(p>=jeu_->getJ1()->getMain()->size())){
		
			std::cout<<"Chosir une carte valide à jouer"<<std::endl;
			std::cin >>p;
			--p; // on "convertie" car quand le joueur dit qu'il veut jouer la carte 1 il veut jouer la carte à l'indice 0
			}
	
			c=jeu_->getJ1()->jouerCarte(p);
			jeu_->addCarteJ1((jeu_->getJ1()->jouerCarte(p)));
			if((c->getGoodType()==0)||(c->getGoodType()==1)){// On ne joue en combo que des coup ou des choppes
				if (toutPermis){
					std::cout<<"Confirmer oui/non"<<std::endl;
					std::cin>>conf;
	
					if (conf=="oui"){
						jeu_->getEtatCourant()->confirmation();
		
					}else{
						jeu_->getEtatCourant()->annulerAction();
					}
				}else{
						if (c->getNum()==(1+(jeu_->getLastCarte(2)->getNum()))){
						std::cout<<"Confirmer oui/non"<<std::endl;
						std::cin>>conf;
	
						if (conf=="oui"){
							jeu_->getEtatCourant()->confirmation();
		
						}else{
							jeu_->getEtatCourant()->annulerAction();
						}
					
					}else{
						std::cout<<"Le numéro de carte n'est pas valide ( voir règle) il faudra rerentré la commande"<<std::endl;
						jeu_->getEtatCourant()->annulerAction();
					}
				}
			}else{
				std::cout<<"Le type de carte n'est pas valide il faudra rerentré la commande"<<std::endl;
				jeu_->getEtatCourant()->annulerAction();
				
			}
		}
	}else{
		jeu_->setEtatCourant(jeu_->getEtatCalcDmg());
		std::cout<<"Fin du combo"<<std::endl;
		jeu_->getEtatCourant()->verification();
	}
}


void EtatCombo::annulerAction(){
	if (jeu_->getGagnantCombat()==2){// on regard le gagnant pour voir qui doit combo
		jeu_->retournerToMain(2);
	}else{
		jeu_->retournerToMain(1);
		
	}
	std::cout<<"choisisser une nouvelle carte"<<std::endl;
}


void EtatCombo::verification() {
	
	
	if (jeu_->getGagnantCombat()==2){// on regard le gagnant pour voir qui doit combo
		jeu_->actionEffet(2);
	}else{
		jeu_->actionEffet(1);
	}
	
}

void EtatCombo::confirmation(){
	int gagnant=jeu_->getGagnantCombat();
	int comboMaxG;// le combo max du gagnat
	
	this->verification();
	
	
	if (gagnant==2){// on regard le gagnant pour voir qui doit bluff
		comboMaxG=jeu_->getJ1()->getChamp()->getComboMax();
	}else{
		comboMaxG=jeu_->getJ2()->getChamp()->getComboMax();		
	}
	
	if ((comboMaxG>jeu_->getCombo())&&(jeu_->getGoodComboType(gagnant)!=2)){ // 2 veut dire qu'on a joué un finisher et qu'on peut pas partir en combo
		
		
		std::cout<<"On peut continuer le combo"<<std::endl;
		
	}else {
		jeu_->setEtatCourant(jeu_->getEtatCalcDmg());
		std::cout<<"Fin du combo"<<std::endl;
		jeu_->getEtatCourant()->verification();// action automatique
	}
}

void EtatCombo::retournerCarte() {


	int p;

	std::cout<<"Choisir la carte à retourner"<<std::endl;

	std::cin>>p;
	--p;
	if (jeu_->getGagnantCombat()==2){// on regard le gagnant pour voir qui doit bluff
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


void EtatCombo::InfoCarte(){


	int p;
	
	
	std::cout<<"Choisir la carte d'on vous voulez les infos'"<<std::endl;

	std::cin>>p;
	--p;// convertion comme dans jouerCarte
	if (jeu_->getGagnantCombat()==2){// on regard le gagnant pour voir qui doit bluff
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
