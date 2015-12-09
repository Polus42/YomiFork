#include <iostream>
#include "Etat.hpp"



#ifndef ETATCHOIXPERSO_HPP
#define ETATCHOIXPERSO_HPP


class EtatChoixPerso : public Etat {

	private : 

	Jeu *jeu_;/*!< pointeur vers le jeu*/
	
	
	
	public : 

	EtatChoixPerso ( Jeu *jeu) {
		jeu_=jeu;
	}
	
	void verification();
	void InfoCarte();
	void retournerCarte();
	void jouerCarte();
	void confirmation();
	void annulerAction();

};

#endif
