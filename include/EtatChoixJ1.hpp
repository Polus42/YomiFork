#include <iostream>
#include "Etat.hpp"



#ifndef ETATCHOIXJ1_HPP
#define ETATCHOIXJ1_HPP


class EtatChoixJ1 : public Etat {

	private : 

	Jeu *jeu_;/*!< pointeur vers le jeu*/
	
	
	
	public : 

	/*!
	*  \brief Constructeur
	*
	*  Constructeur de la classe EtatChoixJ1
	*
	*  \param jeu : pointeur vers le jeu
	*/

	EtatChoixJ1 (Jeu *jeu) {
		jeu_=jeu;
	}


	/*!
		*  \brief  EtatChoixJ1 : aplique les effet de la carte jouer par J1
	*/
	void verification();
	/*!
		*  \brief  EtatChoixJ1 : demande un numéro et affiche les infos de la carte corespondante dans la main du joueur 1
		*/
	void InfoCarte();
	/*!
		*  \brief  EtatChoixJ1 : demande un numéro et retourne la carte corespondante de la main du joueur 1
		*/
	void retournerCarte();

	/*!
		*  \brief  EtatChoixJ1 : demande un numéro et joue la carte corespondante de la main du joueur 1 ( demande confirmation)
		*/
	void jouerCarte();
	/*!
		*  \brief  EtatChoixJ1 : si le joueur 1 confirme appelle vérification et passe à l'état choix J2.
		*/
	void confirmation();
	/*!
		*  \brief  EtatChoixJ1 : si le joueur 1 ne annule son action retourne la carte qu'il vient de joueur dans sa main.
		*/
	void annulerAction();

};

#endif
