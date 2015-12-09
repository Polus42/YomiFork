#include "Affichage.hpp"
#include "Jeu.hpp"
#include "Carte.hpp"
#include "Observeur.hpp"
#include "Effet.hpp"
#include "Joueur.hpp"
#include "Deck.hpp"
#include "Champion.hpp"

void Affichage::updateWindow(){
	window_->clear();
	window_->draw(spritefont_);
	dessinerCartes();
	dessinerInfos();
	window_->display();
}
void Affichage::setJeu(Jeu j){
	jeu_ = &j;
}
void Affichage::actualiser(){
	updateWindow();
}
void Affichage::fermer(){
	window_->close();
}
bool Affichage::estOuvert(){
	return window_->isOpen();
}
void Affichage::dessinerCartes(){
int nbcartes1 = jeu_->getJ1()->getMain()->size();
int nbcartes2= jeu_->getJ2()->getMain()->size();
if (jeu_->getJoue()==1)
{
	for (int k =0;k<nbcartes1;++k)
	{
		dessinerCarte(jeu_->getJ1()->getMain()->at(k),k*((RESX-largeurcarte_)/nbcartes1),RESY-hauteurcarte_);
	}
}
else
{
	for (int k =0;k<nbcartes2;++k)
	{
		dessinerCarte(jeu_->getJ2()->getMain()->at(k),k*((RESX-largeurcarte_)/nbcartes2),RESY-hauteurcarte_);
	}
}

}

void Affichage::dessinerCarte(Carte* c,int posx,int posy)
{
	if (c->getGoodType()==2)	// carte bloque en bleu
	{
		spritecartebleue_.setPosition(sf::Vector2f(posx, posy));
		window_->draw(spritecartebleue_);
	}
	if (c->getGoodType()==0)	// carte coup en rouge
	{
		spritecarterouge_.setPosition(sf::Vector2f(posx, posy));
		window_->draw(spritecarterouge_);
	}
	if (c->getGoodType()==1)	// carte choppe en vert
	{
		spritecarteverte_.setPosition(sf::Vector2f(posx, posy));
		window_->draw(spritecarteverte_);
	}
	if (c->getGoodType()==3)	// carte esquive en jaune
	{
		spritecartejaune_.setPosition(sf::Vector2f(posx, posy));
		window_->draw(spritecartejaune_);
	}
	if (c->getGoodType()==4)	// carte joker en violet
	{
		spritecarteviolette_.setPosition(sf::Vector2f(posx, posy));
		window_->draw(spritecarteviolette_);
	}
	// Affichage des textes de la carte
	// Dmg de la carte
	sf::Text text;
	text.setCharacterSize(15);
	text.setColor(sf::Color(0, 0, 0));
	text.setFont(font_);
	// Les effets
	std::string s;
	for (Effet *e : c->getGoodLeffet())
	{
		s+=e->getNom() + "\n";
	}
	// Affichage de tous les attributs de la carte
	text.setString(c->getNom()+"\n"+ "Dmg : "+std::to_string((int)c->getGoodDmg()) + "\n"+ "Effets :\n"+s + "Startup : "+std::to_string(c->getGoodFstartup())+"\n"+c->convertionNum()+" de "+c->convertionCouleur());
	text.setPosition(sf::Vector2f(posx+10, posy+10));
	window_->draw(text);

	if (c->getRetournable())
	{
		text.setString("Retournable");
		text.setPosition(sf::Vector2f(posx, posy+hauteurcarte_-15));
		window_->draw(text);
	}
}

void Affichage::dessinerInfos()
{
	// Affichage du combo
	sf::Text text;
	text.setColor(sf::Color(0, 0, 0));
	text.setFont(font_);
	std::string s =std::to_string(jeu_->getCombo());
	s = "Combo : " +s;
	// Affichage des joueurs
	s+="\n"+jeu_->getJ1()->getNom()+"  VS  "+jeu_->getJ2()->getNom();
	// Affichage du type de combo
	switch (jeu_->getGoodComboType(jeu_->getJoue())) { // on affiche qui le type du combo de la personne qui est entrain de joué ( dans l'état combo cela affichera le type du combo de la personne qui est entrain de combo)
	case 0:
	  	s+="\nCombo Classique";
	  break;
	case 1:
	  	s+="\nCombo : on peut n'importe quel carte";
	  break;
	case 2:
		s+="\nCombo : arret";
	default:
	  	s+="\nPas de combo";
	  break;
	}
	window_->draw(text);
	// Affichage des champions
	s+="\n"+jeu_->getJ1()->getChamp()->getNom() + " "+ std::to_string(jeu_->getJ1()->getChamp()->getHp())+ " PV  contre  " + jeu_->getJ2()->getChamp()->getNom() + std::to_string(jeu_->getJ2()->getChamp()->getHp()) + " PV";
	// Affichage du nom du joueur courant
	if (jeu_->getJoue()==1)
	{
		s+="\nTour de "+jeu_->getJ1()->getNom();
	}
	if (jeu_->getJoue()==2)
	{
		s+="\nTour de "+jeu_->getJ2()->getNom();
	}

	text.setString(s);
	text.setPosition(sf::Vector2f(0, 0));
	window_->draw(text);
}



