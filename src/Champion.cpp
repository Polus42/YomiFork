#include "Champion.hpp"
#include "Effet.hpp"



void Champion::dmgTaken( double dmg) {
	int dmgg=floor(dmg);// floor = partie entière
	hp_-=dmgg;
}


void Champion::heal(int heal) {

	if (heal+hp_<=hpMax_) {

		hp_+=heal;
	
	}else{

		hp_=hpMax_;
	}
}


void Champion::actionEffet(Jeu *jeu,int j){

	effet_->actionEffet(jeu,j);
}


