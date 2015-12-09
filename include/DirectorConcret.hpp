/*!
 * \file DirectorConcret.hpp
 * \brief Gere les builder de carte
 * \author paul_figiel
 * \version 1.0
 */
 //------------------------------
#include "Director.hpp"
#ifndef DIRECTORCONCRET_HPP
#define DIRECTORCONCRET_HPP
class Carte;
class Deck;
class BuilderDeck;
//------------------------------
/**
* \class DirectorConcret
* \brief Classe DirectorConcret qui sert à gerer les builder de carte, implemente Director
* \date 15/11/2015
* \author paul_figiel
*/
//------------------------------
class DirectorConcret : public Director
{
	private :
	public :
	/*!
	*  \brief Constructeur
	*
	*  Constructeur de la classe DirectorConcret
	*
	*  \param bd : le builder que doit gerer le director
	*/
		DirectorConcret(BuilderDeck * bd)
		{
			builderdeck_ = bd;
		}
	/*!
	*  \brief Permet de construire un deck à partir d'un fichier
	*
	*  \return : un pointeur sur le deck créé
	*/
		Deck *faireDeck();
};
#endif
