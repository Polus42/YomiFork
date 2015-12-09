#include<iostream>
#include<vector>

//#include "Header.hpp"

#ifndef ETAT_HPP
#define ETAT_HPP
class Jeu;
class Carte;
class Joueur;
class Etat {
	protected :

	public :
/*!
		*  \brief procéde au diverse vérification (varie selon l'état).
		*/
	virtual void verification()=0;
	/*!
		*  \brief affiche l'info d'une carte (varie selon l'état).
		*/
	virtual void InfoCarte()=0;

	/*!
		*  \brief retourne la dérnière carte jouer dans la main de son propriétaire (varie selon l'état).
		*/
	virtual void retournerCarte()=0;

	/*!
		*  \brief joue une carte (varie selon l'état).
		*/
	virtual void jouerCarte()=0;

	/*!
		*  \brief confirme l'action (varie selon l'état).
		*/
	virtual void confirmation()=0;

	/*!
		*  \brief annule l'action (varie selon l'état).
		*/
	virtual void annulerAction()=0;

};
#endif
