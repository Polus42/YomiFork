#include <iostream>
#include "Etat.hpp"



#ifndef ETATPIOCHE_HPP
#define ETATPIOCHE_HPP



class EtatPioche : public Etat{

	private : 

	Jeu *jeu_;/*!< pointeur vers le jeu*/
	
	
	public : 

	/*!
	*  \brief Constructeur
	*
	*  Constructeur de la classe EtatPioche
	*
	*  \param jeu : pointeur vers le jeu
	*/
	EtatPioche ( Jeu *jeu) {
		jeu_=jeu;
	}
	
	/*!
		*  \brief  EtatPioche : Fait piocher les 2 joueurs et aplique les effets des deux champion
		*/
	void verification();
	/*!
		*  \brief  EtatPioche : aucun effet
		*/
	void InfoCarte();
		/*!
		*  \brief  EtatPioche : aucun effet
		*/
	void retournerCarte();
		/*!
		*  \brief  EtatPioche : aucun effet
		*/
	void jouerCarte();
	/*!
		*  \brief  EtatPioche : aucun effet
		*/
	void confirmation();
		/*!
		*  \brief  EtatPioche : aucun effet
		*/
	void annulerAction();

};

#endif
