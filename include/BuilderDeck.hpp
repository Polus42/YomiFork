/*!
 * \file BuilderDeck.hpp
 * \brief Implementation de la classe BuilderDeck
 * \author paul_figiel
 * \version 1.0
 */
 //------------------------------
#include <iostream>
#include <fstream>
#ifndef BUILDERDECK_HPP
#define BUILDERDECK_HPP
class Carte;
class Deck;
class Champion;
//------------------------------
/**
* \class BuilderDeck
* \brief Classe BuilderDeck qui permet de charger en memoire un deck composé de carte
* à partir de fichiers txt
* \date 15/11/2015
* \author paul_figiel
*/
//------------------------------
class BuilderDeck
{
	protected :
		Deck *deck_;	/*!< Le deck cree par ce builder*/
		std::string dossier_;	/*!< Le dossier ou se trouvent les cartes*/
	public :
		/*!
		*  \brief Charge une carte à partir du chemin relatif de son fichier
		*
		*  \param fichier : fichier de la carte
		*  \return : un pointeur sur la carte créé
		*/
		virtual Carte *creerCarte(std::string fichier) = 0;
		/*!
		*  \brief Charge un champion à partir du chemin relatif de son fichier
		*
		*  \param fichiercarte : chemin relatif de la carte champion
		*  \return : pointeur sur le champion créé
		*/
		virtual Champion *creerChampion(std::string fichiercarte) = 0;
		/*!
		*  \brief Rempli le deck de toutes les cartes contenues dans dossier_
		*
		*/
		virtual void creerCartes() = 0;
		/*!
		*  \brief Melange les cartes dans deck_ et le renvoie
		*
		*  \return: pointeur sur le deck cree
		*/
		virtual Deck *creerDeck() = 0;
};
#endif
