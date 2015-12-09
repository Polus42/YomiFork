#include <iostream>
#include <vector>
//#include"Champion"
//#include "Deck.hpp"
#ifndef JOUEUR_HPP
#define JOUEUR_HPP

class Deck;
class Champion;
class Carte;
class Jeu;
class Joueur {

	private :

	Champion *champ_;/*!< Champion* le champion du joueur*/
	Deck *deck_;/*!< Deck* le deck du joueur*/
	Deck *cim_;/*!< Deck* le cimetière du joueur*/
	double multDmg_; /*!< double le multiplicateur de dommage du joueur*/
	std::vector<Carte*> *main_;/*!< main du joueur dans un vector<Carte*>*/
	std::string nom_;/*!< string nom du joueur */


	public :
	
	
	/*!
	*  \brief Constructeur
	*
	*  Constructeur de la classe Joueur
	*
	*  \param *edeck : deck du joueur
	*  \param nom : nom du joueur
	*/
	Joueur (Deck *deck,std::string nom);

		

	Champion *getChamp() { return champ_;}
	void setChamp(Champion *champ) { champ_=champ;}

	Deck *getDeck(){ return deck_;}
	void setDeck(Deck *d){deck_=d;}

	Deck *getCim(){return cim_;}
	void setCim(Deck *cim){cim_=cim;}

	double getMultDmg(){ return multDmg_;}
	void setMultDmg(double md){multDmg_=md;}

	std::vector<Carte*> *getMain(){return main_;}
	void setMain(std::vector<Carte*> *main){main_=main;}
	
	void setNom(std::string nom){nom_=nom;}
	std::string getNom(){return nom_;}

	//----------------
	/*!
		*  \brief multiplie les dommages du joueur ---> multDmg_=multDmg_*x sachant qu'on ne veut pas multDmg_>3 ( régle anti one shoot )
		*
		*  \param int x : de combien on veut multiplié 
		*
		*/
	void multDmg(int x); 
	// multiplie les dommages ---> multDmg_=multDmg_*x sachant qu'on ne veut pas multDmg_>3 ( régle anti one shoot )
	/*!
		*  \brief pioche une carte du deck et la rajoute à la main du joueur

		*/
	void piocher();
	/*!
		*  \brief applique l'effet du champion du joueur
		*
		*  \param Jeu *jeu : Le jeu 
		*  \param int j : un entier indiquant qu'elle est le joueur
		*
		*/
	void actionEffet(Jeu *jeu,int j); 
	// Effectue l'effet du champion du joueur
	/*!
		*  \brief ajoute une carte à la main du joueur
		*
		*  \param Carte *c : carte à rajouter
		*
		*/
	void addCarteMain(Carte *c);
		/*!
		*  \brief ajoute une carte au cimetière du joueur
		*
		*  \param Carte *c : carte à rajouter
		*
		*/
	void addCarteCim(Carte* c);
		/*!
		*  \brief ajoute une au deck du joueur
		*
		*  \param Carte *c : carte à rajouter
		*
		*/
	void addCarteDeck(Carte *c);

	// précondition : x est un indice valide ( sera vérifié dans les classe Etat )
		/*!
		*  \brief renvoie la carte d'indice x de la main du joueur et la suprime de sa main
		*
		*  \param int x : l'indice de la carte
		*
		*/
	Carte* jouerCarte(int x);

	
};

#endif
