#include "DirectorConcret.hpp"
#include "BuilderDeckTxt.hpp"
#include "BuilderDeck.hpp"

Deck *DirectorConcret::faireDeck()
{
	builderdeck_->creerCartes();
	return builderdeck_->creerDeck();
}
