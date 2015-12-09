#include <iostream>
#include "Etat.hpp"



#ifndef ETATCOMBO_HPP
#define ETATCOMBO_HPP


class EtatCombo : public Etat {

	private : 

	Jeu *jeu_;/*!< pointeur vers le jeu*/
	
	
	
	public : 
	/*!
	*  \brief Constructeur
	*
	*  Constructeur de la classe EtatCombo
	*
	*  \param jeu : pointeur vers le jeu
	*/
	EtatCombo ( Jeu *jeu) {
		jeu_=jeu;
	}
	/*!
		*  \brief  EtatCombo : aplique les effets de la carte jouer
		*/
	void verification();

	/*!
		*  \brief  EtatCombo : demande un numéro et affiche les infos de la carte corespondante de la main du joueur qui combo.
		*/
	void InfoCarte();
		/*!
		*  \brief  EtatCombo : demande un numéro et retourne la carte corespondante de la main du joueur qui combo.
		*/
	void retournerCarte();
	/*!
		*  \brief  EtatCombo : demande un numéro  et joue la carte corespondante de la main du joueur qui combo.( demande confirmation)
		*/
	void jouerCarte();
	/*!
		*  \brief  EtatCombo : si le joueur décide de confirmer qu'il veut jouer la carte qu'il vient de posé appelle vérification et passe à EtatCalcDmg ou reste dans EtatCombo selon les cas.
		*/
	void confirmation();
		/*!
		*  \brief  EtatCombo : si le joueur décide de confirmer qu'il ne veut pas jouer la carte qu'il vient de posé la renvoie dans sa main.
		*/
	void annulerAction();

};

#endif
