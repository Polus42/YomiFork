#include <iostream>
#include "Etat.hpp"



#ifndef ETATCLEANUP_HPP
#define ETATCLEANUP_HPP


class EtatCleanUp : public Etat {

	private : 

	Jeu *jeu_;/*!< pointeur vers le jeu*/
	
	
	
	public : 
			/*!
	*  \brief Constructeur
	*
	*  Constructeur de la classe EtatCleanUp
	*
	*  \param jeu : pointeur vers le jeu
	*/
	EtatCleanUp ( Jeu *jeu) {
		jeu_=jeu;
	}

	/*!
		*  \brief  EtatCleanUp : procédè à toutes les vérification nécessaire et soit envoie vers EtatFin, soit prépare le jeu pour un nouveau tour et envoie vers EtatPioche.
		*/
	void verification();

	/*!
		*  \brief  EtatCleanUp :aucun effet.
		*/
	void InfoCarte();
		/*!
		*  \brief  EtatCleanUp :aucun effet.
		*/
	void retournerCarte();
		/*!
		*  \brief  EtatCleanUp :aucun effet.
		*/
	void jouerCarte();
		/*!
		*  \brief  EtatCleanUp :aucun effet.
		*/
	void confirmation();
		/*!
		*  \brief  EtatCleanUp :aucun effet.
		*/
	void annulerAction();

};

#endif
