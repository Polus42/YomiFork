#include <iostream>
#include "Etat.hpp"



#ifndef ETATCHOIXJ2_HPP
#define ETATCHOIXJ2_HPP


class EtatChoixJ2 : public Etat {

	private : 

	Jeu *jeu_;/*!< pointeur vers le jeu*/
	
	
	
	public : 

	/*!
	*  \brief Constructeur
	*
	*  Constructeur de la classe EtatChoixJ2
	*
	*  \param jeu : pointeur vers le jeu
	*/

	EtatChoixJ2 (Jeu *jeu) {
		jeu_=jeu;
	}


	
	
	/*!
		*  \brief  EtatChoixJ2 : aplique les effet de la carte jouer par J2
	*/
	void verification();
	/*!
		*  \brief  EtatChoixJ2 : demande un numéro et affiche les infos de la carte corespondante dans la main du joueur 2
		*/
	void InfoCarte();
	/*!
		*  \brief  EtatChoixJ2 : demande un numéro et retourne la carte corespondante de la main du joueur 2
		*/
	void retournerCarte();

	/*!
		*  \brief  EtatChoixJ2 : demande un numéro et joue la carte corespondante de la main du joueur 2 ( demande confirmation)
		*/
	void jouerCarte();
	/*!
		*  \brief  EtatChoixJ2 : si le joueur 2 confirme appelle vérification et passe à EtatChoixWin.
		*/
	void confirmation();
	/*!
		*  \brief  EtatChoixJ2 : si le joueur 2 ne annule son action retourne la carte qu'il vient de joueur dans sa main.
		*/
	void annulerAction();


};

#endif
