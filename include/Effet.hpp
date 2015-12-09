#include <iostream>
#include<cstdlib>
#include<ctime>

#ifndef EFFET_HPP
#define EFFET_HPP
class Joueur;
class Jeu;
class Effet 
{
	public :

	/*!
	*  \brief Constructeur vide
	*
	*  Constructeur de la classe Effet
	*
	*/
	Effet(){}
	 /*!
		*  \brief applique l'effet
		*  \param Jeu *jeu : le jeu 
		*  \param int x : le joueur qui joue l'effet
		*/
	virtual void actionEffet(Jeu *jeu, int x){} // x indique quel joueur a joué la carte

	/*!
		*  \brief affiche le nom de l'effet et ce qu'il fait
		*/
	virtual void afficher()=0;

	/*!
		*  \brief va chercher le nom de l'effet
		*  \return : une string qui corespond au nom de l'effet'
		*/
	virtual std::string getNom()=0;
};

#endif

