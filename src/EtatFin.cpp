#include "EtatFin.hpp"
#include "Jeu.hpp"

void EtatFin::verification() {


	if (jeu_->getGagnantCombat()==0){
		std::cout<<"Ko simultaner"<<std::endl;
	}else{
		std::cout<<"Le gagnant est les joueur "<<jeu_->getGagnantCombat()<<std::endl;
	}
	
	jeu_->setFini(true);
}



void EtatFin::InfoCarte() {}
void EtatFin::retournerCarte(){}
void EtatFin::jouerCarte(){}
void EtatFin::confirmation(){}
void EtatFin::annulerAction(){}
