/*!
 * \file Affichage.hpp
 * \brief Affichage graphique du jeu
 * \author paul_figiel
 * \version 1.0
 */
 //------------------------------
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Observeur.hpp"
#ifndef AFFICHAGE_HPP
#define AFFICHAGE_HPP
extern int RESX;
extern int RESY;
extern std::string NOM_JEU;
class Carte;
class Jeu;
//------------------------------
/**
* \class Affichage
* \brief Classe Affichage qui sert à interpreter graphiquement l'état d'un objet Jeu
* \date 15/11/2015
* \author paul_figiel
*/
//------------------------------
class Affichage : public Observeur {
	private :
	const int largeurcarte_ = 140;	/*!< largeur des cartes en pixels*/
	const int hauteurcarte_ = 190;	/*!< Hauteur des cartes en pixels*/
	const float hauteurtapis_ = 1026;	/*!< Hauteur du tapis en pixels*/
	const float largeurtapis_ = 1486;	/*!< Largeur du tapis en pixels*/
	Jeu *jeu_;	/*!< Jeu observé*/
	sf::RenderWindow *window_;	/*!< Fenetre d'affichage SFML*/
	
	sf::Texture texturefont_;	/*!< Texture de font */
	sf::Sprite spritefont_;		/*!< Sprite de font*/
	
	sf::Texture texturecarteverte_;	/*!< Texture de la carte verte*/
	sf::Texture texturecarterouge_;	/*!< Texture de la carte rouge*/
	sf::Texture texturecartebleue_;	/*!< Texture de la carte bleue*/
	sf::Texture texturecartejaune_;	/*!< Texture de la carte jaune*/
	sf::Texture texturecarteviolette_;	/*!< Texture de la carte violette*/
	
	sf::Sprite spritecarteverte_;	/*!< Sprite de la carte verte*/
	sf::Sprite spritecarterouge_;	/*!< Sprite de la carte rouge*/
	sf::Sprite spritecartebleue_;	/*!< Sprite de la carte bleue*/
	sf::Sprite spritecartejaune_;	/*!< Sprite de la carte jaune*/
	sf::Sprite spritecarteviolette_;	/*!< Sprite de la carte violette*/
	
	sf::Font font_;	/*!< Police d'ecriture utilisée'*/
	
	/*!
	*  \brief Dessine les cartes à l'ecran
	*
	*/
	void dessinerCartes();
	/*!
	*  \brief Dessine une carte à l'ecran
	*
	*
	*  \param c : carte à dessiner
	*  \param posx : position en x
	*  \param posy : position en y
	*/
	void dessinerCarte(Carte* c,int posx,int posy);
	
	public :
	/*!
	*  \brief Constructeur
	*
	*  Constructeur de la classe Affichage
	*
	*  \param resX : resolution en x de la fenetre
	*  \param resY : resolution en y de la fenetre
	*  \param nom_fenetre : nom de la fenetre
	*  \param j : pointeur sur un jeu
	*/
	Affichage(int resX,int resY,std::string nom_fenetre,Jeu *j)
	{
		window_ = new sf::RenderWindow(sf::VideoMode(resX, resY), nom_fenetre);
		jeu_ = j;
		// Chargement du font --------------------------------------------------------
		if (!texturefont_.loadFromFile("assets/tapis.png"))
		{
		    std::cout<<"Erreur de chargement d'image"<<std::endl;
		}
		spritefont_.setTexture(texturefont_);
		// Largeur et hauteur de tapis.png -------------------------------------------
		float scalex = RESX/largeurtapis_;
		float scaley = RESY/hauteurtapis_;

		spritefont_.scale(sf::Vector2f(scalex, scaley));
		// Chargement de la police ---------------------------------------------------
		if (!font_.loadFromFile("assets/arial.ttf"))
		{
		    std::cout<<"Erreur de chargement de la police d'écriture'"<<std::endl;
		}
		// Chargement des images des cartes ------------------------------------------
		if (!texturecarteverte_.loadFromFile("assets/carteverte.png"))
		{
		    std::cout<<"Erreur de chargement d'image"<<std::endl;
		}
		spritecarteverte_.setTexture(texturecarteverte_);
		
		if (!texturecarterouge_.loadFromFile("assets/carterouge.png"))
		{
		    std::cout<<"Erreur de chargement d'image"<<std::endl;
		}
		spritecarterouge_.setTexture(texturecarterouge_);
		
		if (!texturecartebleue_.loadFromFile("assets/cartebleue.png"))
		{
		    std::cout<<"Erreur de chargement d'image"<<std::endl;
		}
		spritecartebleue_.setTexture(texturecartebleue_);
		
		if (!texturecartejaune_.loadFromFile("assets/cartejaune.png"))
		{
		    std::cout<<"Erreur de chargement d'image"<<std::endl;
		}
		spritecartejaune_.setTexture(texturecartejaune_);
		
		if (!texturecarteviolette_.loadFromFile("assets/carteviolette.png"))
		{
		    std::cout<<"Erreur de chargement d'image"<<std::endl;
		}
		spritecarteviolette_.setTexture(texturecarteviolette_);
	}
	/*!
	*  \brief Setter
	*
	*  \param j : le jeu que l'affichage doit observer
	*/
	void setJeu(Jeu j);
	/*!
	*  \brief Fait la mise à jour graphique de l'affichage, va regarder dans le jeu observé
	* toutes les valeurs à mettre à jour
	*/
	void updateWindow();
	/*!
	*  \brief Getter
	*
	*  \return window_ : la fenetre d'affichage SFML utilisée
	*/
	sf::RenderWindow *getWindow(){return this->window_;};
	/*!
	*  \brief Implémente l'actualisation de la classe observeur
	*
	*/
	void actualiser();
	/*!
	*  \brief Ferme la fenetre d'affichage SFML
	*
	*/
	void fermer();
	/*!
	*  \brief Sert à savoir si la fenetre SFML est ouverte
	*
	*  \return true si la fenetre SFML est ouverte
	*/
	bool estOuvert();
	/*!
	*  \brief Dessine à l'ecran toutes les infos relatives au jeu, ( à la partie )
	*
	*/
	void dessinerInfos();
	
};

#endif
