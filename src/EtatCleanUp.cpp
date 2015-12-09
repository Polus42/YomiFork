#include "EtatCleanUp.hpp"
#include "Jeu.hpp"
#include "Carte.hpp"
#include "Joueur.hpp"
#include "Champion.hpp"
#include"Deck.hpp"

void EtatCleanUp::verification() {

	int gagnant=jeu_->getGagnantCombat();
	bool trouver=false;
	int p; //un compteur
	
	// Ce block s'occupe de voir si la partie est fini.
	int hpJ1=jeu_->getJ1()->getChamp()->getHp();// Les hp du champ de J1
	int hpJ2=jeu_->getJ2()->getChamp()->getHp();// ceux de celui de J2
	
	if ((hpJ1<=0)||(hpJ2<=0)){// Si un des 2 à ses hp<0
		// Note gagnant combat indiquera le gagnant de la partie
		if ((hpJ1<=0)&&(hpJ2<=0)){
			jeu_->setGagnantCombat(0);
		}else{
			if(hpJ1<=0){
				jeu_->setGagnantCombat(2);
			}else{
				jeu_->setGagnantCombat(1);
			}
		
		}
		jeu_->setEtatCourant(jeu_->getEtatFin());
		jeu_->getEtatCourant()->verification();
	}//fin du block qui s'occupe de voir si la partie est fini
		
	
	else // Si la partie est pas fini on s'occupe de tout remettre bien pour un nouveau tourne
		
	{
		
		if ((((jeu_->getJ1()->getDeck()->getListeCartes().size())==0)&&((jeu_->getJ1()->getCim()->getListeCartes().size())==0))||(((jeu_->getJ2()->getDeck()->getListeCartes().size())==0)&&((jeu_->getJ2()->getCim()->getListeCartes().size())==0))){ // Si jamais il n'y plus de carte dans le deck ET le cimitère d'un joueur en même temps ( il a tout en mains). Sa veut dire que les joueurs ont fait les con et on arrête tout.
			jeu_->setGagnantCombat(0);
			jeu_->setEtatCourant(jeu_->getEtatFin());
			std::cout<<"Vous m'avez soulé, j'arrête la partie"<<std::endl;
			jeu_->getEtatCourant()->verification();
			
			
		}else{ // La on est vraiment sur qu'on doit continuer la partie
		
			jeu_->setCombo(0);
			jeu_->setComboTypeJ1(0);
			jeu_->setComboTypeJ2(0);
			jeu_->setBluff(false);
			if((gagnant==0)||(gagnant==1)){ // On regarde si la joueur à le droit de reprendre en main les carte avec effet return
				for (auto &i : jeu_->getRcarteJ1()){// on remet en mains les carte qui doivent y retourner et on enlève celle-ci des carte jouer
				trouver=false;
				p=0;
				
				while (!(trouver)||(p>=jeu_->getCarteJ1().size())){
				
					if(i->equals(jeu_->getCarteJ1().at(p))){
						trouver=true;
					}		
				}
				if (trouver){// la carte doit bien retourner en main
					jeu_->getJ1()->addCarteMain(jeu_->getCarteJ1().at(p));
					jeu_->getCarteJ1().erase(jeu_->getCarteJ1().begin()+p-1);// on a besoin de begin() just p fait bug
					}
				}
			
				}
			
			
			if((gagnant==0)||(gagnant==2)){ // On regarde si la joueur à le droit de reprendre en main les carte avec effet return
				for (auto &i : jeu_->getRcarteJ2()){// on remet en mains les carte qui doivent y retourner et on enlève celle-ci des carte jouer
					trouver=false;
					p=0;
				
					while (!(trouver)||(p>=jeu_->getCarteJ2().size())){
				
						if(i->equals(jeu_->getCarteJ2().at(p))){
							trouver=true;
						}		
					}
					if (trouver){// la carte doit bien retourner en main
						jeu_->getJ2()->addCarteMain(jeu_->getCarteJ2().at(p));
						jeu_->getCarteJ2().erase(jeu_->getCarteJ2().begin()+p-1);// on a besoin de begin() just p fait bug
					}
			
				}
			}
			// Là les carte qui doivent aller au cimitère y vont
			for (auto &v : jeu_->getCarteJ1()){
			
				jeu_->getJ1()->addCarteCim(v);
			}
			
			for (auto &v : jeu_->getCarteJ2()){
			
				jeu_->getJ1()->addCarteCim(v);
			}
			
			
			// C'est bon on peut enfin viré les vector de carte
			// il ne faut pas appellé clear sur jeu_->getCarteJ1().clear() ( c'est une copie)
			jeu_->clearCarteJ1();
			jeu_->clearCarteJ2();
			jeu_->clearRCarteJ1();
			jeu_->clearRCarteJ2();
			
			
			
			jeu_->setGagnantCombat(0);
			jeu_->setEtatCourant(jeu_->getEtatPioche());
			std::cout<<"Clean up effectué, on va piocher"<<std::endl;
			jeu_->getEtatCourant()->verification();
		}	
	}
}
			
	
		
		
	

	
	





void EtatCleanUp::InfoCarte() {}
void EtatCleanUp::retournerCarte(){}
void EtatCleanUp::jouerCarte(){}
void EtatCleanUp::confirmation(){}
void EtatCleanUp::annulerAction(){}
