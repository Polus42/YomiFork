#include <iostream>
#include "Etat.hpp"



#ifndef ETATFIN_HPP
#define ETATFIN_HPP


class EtatFin : public Etat {

	private : 

	Jeu *jeu_;/*!< pointeur vers le jeu*/
	
	
	
	public : 
/*!
	*  \brief Constructeur
	*
	*  Constructeur de la classe EtatFin
	*
	*  \param jeu : pointeur vers le jeu
	*/
	EtatFin ( Jeu *jeu) {
		jeu_=jeu;
	}

	/*!
		*  \brief  EtatFin : affiche le gagnant da la partie et fait que fini_ de classe jeu = true ( met fin à la partie)
		*/
	void verification();
	/*!
		*  \brief  EtatFin : aucun effet
		*/
	void InfoCarte();
	/*!
		*  \brief  EtatFin : aucun effet
		*/
	void retournerCarte();
	/*!
		*  \brief  EtatFin : aucun effet
		*/
	void jouerCarte();
	/*!
		*  \brief  EtatFin : aucun effet
		*/
	void confirmation();
	/*!
		*  \brief  EtatFin : aucun effet
		*/
	void annulerAction();

};

#endif
