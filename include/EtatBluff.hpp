#include <iostream>
#include "Etat.hpp"



#ifndef ETATBLUFF_HPP
#define ETATBLUFF_HPP


class EtatBluff : public Etat {

	private : 

	Jeu* jeu_;/*!< pointeur vers le jeu*/
	
	
	
	public : 

	/*!
	*  \brief Constructeur
	*
	*  Constructeur de la classe EtatBluff
	*
	*  \param jeu : pointeur vers le jeu
	*/

	EtatBluff ( Jeu *jeu) {
		jeu_=jeu;
	}
	/*!
		*  \brief  EtatBluff : vérifie l'effet de la carte jouer en bluff et si c'est un joker.
		*/
	void verification();

	/*!
		*  \brief  EtatBluff : demande un numéro et affiche les infos de la carte corespondante dans la main du joueur qui bluff.
		*/
	void InfoCarte();

	/*!
		*  \brief  EtatBluff : demande un numéro et retourne la carte corespondante de la main du joueur qui bluff.
		*/
	void retournerCarte();

	/*!
		*  \brief  EtatBluff : demande un numéro et joue la carte corespondante de la main du joueur qui bluff (demande confirmation).
		*/
	void jouerCarte();

		/*!
		*  \brief  EtatBluff : si le joueur décide de confirmer qu'il veut jouer la carte qu'il vient de posé apelle vérification et passe au prochain état.
		*/
	void confirmation();

	/*!
		*  \brief  EtatBluff : si le joueur décide  qu'il ne veut pas jouer la carte qu'il vient de posé la renvoie dans sa main.
		*/
	void annulerAction();

};

#endif
