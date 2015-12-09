#include <iostream>
#include "Etat.hpp"



#ifndef ETATCHOIXWIN_HPP
#define ETATCHOIXWIN_HPP


class EtatChoixWin : public Etat {

	private : 

	Jeu* jeu_;/*!< pointeur vers le jeu*/
	
	
	
	public : 
		/*!
	*  \brief Constructeur
	*
	*  Constructeur de la classe EtatChoixWin
	*
	*  \param jeu : pointeur vers le jeu
	*/
	EtatChoixWin ( Jeu *jeu) {
		jeu_=jeu;
	}
		/*!
		*  \brief  EtatChoixWin : procédè à toutes les vérification nécessaire et décide du gagnant du combat. Envoie vers EtatBluff, EtatCalcDmg, EtatCleanUp selpn les cas.
		*/
	void verification();

		/*!
		*  \brief  EtatChoixWin:pas d'effet
		*/
	void InfoCarte();
	/*!
		*  \brief  EtatChoixWin:pas d'effet
		*/
	void retournerCarte();
	/*!
		*  \brief  EtatChoixWin:pas d'effet
		*/
	void jouerCarte();
	/*!
		*  \brief  EtatChoixWin:pas d'effet
		*/
	void confirmation();
	/*!
		*  \brief  EtatChoixWin:pas d'effet
		*/
	void annulerAction();

};

#endif
