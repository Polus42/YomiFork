#include"EtatChoixWin.hpp"
#include "Jeu.hpp"
#include "Carte.hpp"
#include "Joueur.hpp"

// Rapel important pour mieux comprendre : 0=coup, 1=choppe, 2=block , 3 = esquive, 4=jocker
void EtatChoixWin::verification(){

	Carte* c1;
	Carte *c2;
	int type1;
	int type2;
	bool astuceNul=false; // sert pour éviter que l'on se prenne les dégâts d'un coup quand on bloque

	c1=jeu_->getLastCarte(1);
	c2=jeu_->getLastCarte(2);
	
	type1=c1->getGoodType();
	type2=c2->getGoodType();

	
	
	//Ce block s'occupe du cas ou les cartes sont du même type.
	if ( ((type1==0) && ( type2==0))||((type1==1)&&(type2==1))){ //vérifie si les 2 joueur on joué 2 coup ou 2 choppe
	
		if ( c1->getGoodFstartup()<c2->getGoodFstartup()){
			jeu_->setGagnantCombat(1);
			jeu_->plusCombo();
		}else{
			if(c1->getGoodFstartup()>c2->getGoodFstartup()){
				jeu_->setGagnantCombat(2);
				jeu_->plusCombo();
			}else{
				jeu_->setGagnantCombat(0);
			}
		} 
	}else{
		if(type1==type2){ // même type mais pas des coups ou des choppes ou des joker
			jeu_->setGagnantCombat(0);
		}
	}
	// Block qui s'occupe quand les joueur ont jouer des type différents
	
	// coup vs choppe
	if (((type1==0) && ( type2==1))){
		jeu_->setGagnantCombat(1);
		jeu_->plusCombo();
	}

	if (((type1==1) && ( type2==0))){
		jeu_->setGagnantCombat(2);
		jeu_->plusCombo();
	}

	// coup vs block
	
	if((((type1==0) && ( type2==2)))||(((type1==2) && ( type2==0)))){
		jeu_->setGagnantCombat(0);
		astuceNul=true;
		std::cout<<"test"<<std::endl;
		
		
	}

	//coup vs esquive note : Quand le joueur gagne le combat sur une esquive le compteur de combo ne monte pas
	
	
	if((((type1==0) && ( type2==3)))){
		jeu_->setGagnantCombat(2);
	}

	if(((type1==3) && ( type2==0))){
		jeu_->setGagnantCombat(1);
	}

	//choppe vs esquive ou block
	if (((type1==1) && (( type2==2)||(type2==3)))) {
		jeu_->setGagnantCombat(1);
		jeu_->plusCombo();
	}

	if (((type2==1) && (( type1==2)||(type1==3)))) {
		jeu_->setGagnantCombat(2);
		jeu_->plusCombo();
	}

	// esquive vs block
	
	if((((type1==2) && ( type2==3))||((type1==3) && ( type2==2)))){ // cas traiter en même temps
	
		jeu_->setGagnantCombat(0);
	}

	
	// joker vs coup ou choppe
	if(((type1==4) && (( type2==0)||(type2==1)))){
		jeu_->setGagnantCombat(1);
		jeu_->plusCombo();
	}

	if(((type2==4) && (( type1==0)||(type1==1)))){
		jeu_->setGagnantCombat(2);
		jeu_->plusCombo();
	}

	// joker vs block
	
	if((((type1==2) && ( type2==4))||((type1==4) && ( type2==2)))){ // cas traiter en même temps
	
		jeu_->setGagnantCombat(0);
	}

	// jokler vs esquive ( rapelle : sur victoire par esquive le compteur de combo n'augmente pas)
	
	if((type1==4) && ( type2==3)) {
	
		jeu_->setGagnantCombat(2);
	}

	if((type2==4) && ( type1==3)) {
	
		jeu_->setGagnantCombat(1);
	}
	
	// A partir de là on sait qui est le gagnant
	if (jeu_->getGagnantCombat()==0){
		
		if ((astuceNul)){ // Si on a bloquer on veut pas ce prendre les dégats du coup qui se trouve dans la pile de carte jouer donc on saut comme un gros nul la phase de calcule de dommage
			std::cout<<"Coup bloquer pas de dégât"<<std::endl;
			jeu_->setEtatCourant(jeu_->getEtatCleanUp());
			jeu_->getEtatCourant()->verification();
		}else{
		
		
			jeu_->setEtatCourant(jeu_->getEtatCalcDmg());
			jeu_->getEtatCourant()->verification();
		}
	}
	if ( jeu_->getGoodComboType(jeu_->getGagnantCombat())!=2){
	
		if (jeu_->getGagnantCombat()==1){
		
			jeu_->setJoue(2);
			jeu_->setEtatCourant(jeu_->getEtatBluff());
			jeu_->notifierObs();
			std::cout<<"C'est au joueur 2 de choisir si il veut bluffé ou non"<<std::endl;
		}
	
	
		if (jeu_->getGagnantCombat()==2){
		
			jeu_->setJoue(1);
			jeu_->setEtatCourant(jeu_->getEtatBluff());
			jeu_->notifierObs();
			std::cout<<"C'est au joueur 1 de choisir si il veut bluffé ou non"<<std::endl;
		}
	}else{
		
		// Cas avec finisher
			jeu_->setEtatCourant(jeu_->getEtatCalcDmg());
			jeu_->getEtatCourant()->verification();
	}
	
}





void EtatChoixWin::InfoCarte() {}
void EtatChoixWin::retournerCarte(){}
void EtatChoixWin::jouerCarte(){}
void EtatChoixWin::confirmation(){}
void EtatChoixWin::annulerAction(){}
