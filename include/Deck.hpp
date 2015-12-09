#include <vector>

#ifndef DECK_HPP
#define DECK_HPP

class Carte;
class Champion;
class Deck {

	private :
	std::vector<Carte*> listecartes_;/*!< liste des cartes du deck dans un vector<Carte*>*/
	Champion *champion_;/*!< pointeur vers le champion du deck*/

	public :

	/*!
	*  \brief Constructeur vide
	*
	*  Constructeur de la classe Deck
	*
	*/
	Deck();

	std::vector<Carte*> getListeCartes(){ return listecartes_;}
	void setListeCartes(std::vector<Carte*> l){ listecartes_=l;}
	Champion *getChampion(){return champion_;};
   // FIN set et get---------------------------------------------------

    /*!
		*  \brief Pioche une carte et la suprime du deck
		*
		*  \return : un pointeur vers la carte piocher
		*/
	Carte *piocher();

	    /*!
		*  \brief rajoue une carte au deck
		*  \param Carte *c : pointeur vers la carte à rajouté
		*/
	void addCarte(Carte *c);
	 /*!
		*  \brief rajoue un champion au deck
		*  \param Champion *ch : pointeur vers le champion à rajouté
		*/
	void addChampion(Champion *ch);

	/*!
		*  \brief supprime toutes les carte du deck ( clear le vecteur<Carte*>)
		*/
	void clear();

	/*!
		*  \brief Mélange le deck
		*/
	void shuffle();

};

#endif
