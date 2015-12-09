/*!
 * \file Director.hpp
 * \brief Gere les builder de carte
 * \author paul_figiel
 * \version 1.0
 */
 //------------------------------
#ifndef DIRECTOR_HPP
#define DIRECTOR_HPP
class Carte;
class Deck;
class BuilderDeck;
//------------------------------
/**
* \class Director
* \brief Classe Director qui sert à gerer les builder de carte
* \date 15/11/2015
* \author paul_figiel
*/
//------------------------------
class Director
{
	protected :
		BuilderDeck *builderdeck_;	/*!< Le builder qui créé les decks*/
	public :
	/*!
	*  \brief Permet de construire un deck à partir d'un fichier
	*
	*  \return : un pointeur sur le deck créé
	*/
		virtual Deck *faireDeck() = 0;
};
#endif
