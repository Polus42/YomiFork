#include <iostream>
#include "Etat.hpp"



#ifndef ETATCALCDMG_HPP
#define ETATCALCDMG_HPP


class EtatCalcDmg : public Etat {

	private : 

	Jeu *jeu_;/*!< pointeur vers le jeu*/
	
	
	
	public : 

	/*!
	*  \brief Constructeur
	*
	*  Constructeur de la classe EtatCalcDmg
	*
	*  \param jeu : pointeur vers le jeu
	*/
	EtatCalcDmg ( Jeu *jeu) {
		jeu_=jeu;
	}
	/*!
		*  \brief  EtatCalcDmg : procédè à toutes les vérification nécessaire et inflige les dégât qu'il faut au deux joueur et passe à l'état clean up.
		*/
	void verification();

	/*!
		*  \brief  EtatCalcDmg : aucun effet
		*/
	void InfoCarte();

	/*!
		*  \brief  EtatCalcDmg : aucun effet
		*/
	void retournerCarte();

	/*!
		*  \brief  EtatCalcDmg : aucun effet
		*/
		
	void jouerCarte();

	/*!
		*  \brief  EtatCalcDmg : aucun effet
		*/
	void confirmation();

	/*!
		*  \brief  EtatCalcDmg : aucun effet
		*/
	void annulerAction();

};

#endif
