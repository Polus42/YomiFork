#include "Deck.hpp"
#include "Carte.hpp"
#include "Champion.hpp"
#include <ctime>
#include <algorithm>
#include <cstdlib>

Deck::Deck()
{
	champion_ = new Champion();
}

Carte* Deck::piocher(){

	Carte *c;
	
	c=listecartes_.at(listecartes_.size()-1);
	listecartes_.pop_back(); //suprime le dernier élément du vecteurs

	return c;
}

void Deck::addCarte(Carte *c){ listecartes_.push_back(c);}

void Deck::clear(){

	listecartes_.clear();
	
}
void Deck::addChampion(Champion *ch)
{
	champion_ = ch;
}
void Deck::shuffle()
{
	// On melange les cartes
	std::srand(unsigned (std::time(0)));
	std::random_shuffle(listecartes_.begin(),listecartes_.end());
}
