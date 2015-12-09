/*!
 * \file BuilderDeckTxt.hpp
 * \brief Implementation de la classe BuilderDeckTxt
 * \author paul_figiel
 * \version 1.0
 */
 //------------------------------
#include <iostream>
#include <fstream>
#include "BuilderDeck.hpp"
#ifndef BUILDERDECKTXT_HPP
#define BUILDERDECKTXT_HPP
class Carte;
class Deck;
//------------------------------
/**
* \class BuilderDeckTxt
* \brief Classe BuilderDeckTxt qui permet de charger en memoire un deck composé de carte
* à partir de fichiers txt
* \date 15/11/2015
* \author paul_figiel
*/
//------------------------------
class BuilderDeckTxt : public BuilderDeck
{
	private :

	public :
		/*!
		*  \brief Constructeur
		*
		*  Constructeur de la classe BuilderDeckTxt
		*
		*  \param dossier : chemin relatif du dossier ou se trouvent les cartes en format txt
		*/
		BuilderDeckTxt(std::string dossier);
		/*!
		*  \brief Charge une carte à partir du chemin relatif de son fichier
		*
		*  \param fichier : fichier de la carte
		*  \return : un pointeur sur la carte créé
		*/
		Carte *creerCarte(std::string fichier);
		/*!
		*  \brief Charge un champion à partir du chemin relatif de son fichier
		*
		*  \param fichiercarte : chemin relatif de la carte champion
		*  \return : pointeur sur le champion créé
		*/
		Champion *creerChampion(std::string fichiercarte);
		/*!
		*  \brief Rempli le deck de toutes les cartes contenues dans dossier_
		*
		*/
		void creerCartes();
		/*!
		*  \brief Melange les cartes dans deck_ et le renvoie
		*
		*  \return: pointeur sur le deck cree
		*/
		Deck *creerDeck();
};
#endif
