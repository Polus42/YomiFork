#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Carte.hpp"
#include "Jeu.hpp"
#include "Affichage.hpp"
#include "Effet.hpp"
#include "EffetBoost.hpp"
#include "BuilderDeck.hpp"
#include "BuilderDeckTxt.hpp"
#include "Joueur.hpp"
#include "Etat.hpp"
#include "Deck.hpp"
#include "Champion.hpp"
#include "DirectorConcret.hpp"

int RESX = 1500;
int RESY = 600;
std::string NOM_JEU = "ProjetPoo";
    
int main()
{
    // Chargement des cartes -------------------------------------------
    BuilderDeckTxt *bd = new BuilderDeckTxt("assets/DeckFlorianR/");
    DirectorConcret *director = new DirectorConcret(bd);
    BuilderDeckTxt *bd2 = new BuilderDeckTxt("assets/DeckMakunouchi/");
    DirectorConcret *director2 = new DirectorConcret(bd2);
    
    // Creation des joueurs ---------------------------------------------
    std::cout << "Quel est le nom du joueur 1 ?" << std::endl;
    std::string nomj1;
    std::string nomj2;
    std::cin>>nomj1;
    std::cout << "Quel est le nom du joueur 2 ?" << std::endl;
    std::cin>>nomj2;
    
    Joueur * j1 = new Joueur(director->faireDeck(),nomj1);
    Joueur * j2 = new Joueur(director2->faireDeck(),nomj2);

    // Creation de la partie --------------------------------------------
    Jeu *jeu_ = new Jeu();
    jeu_->setJ1(j1);
    jeu_->setJ2(j2);
    // On pioche 7 cartes chacun ----------------------------------------
	for (int i = 0;i<7;i++)
	{
		jeu_->getJ1()->piocher();
		jeu_->getJ2()->piocher();
	}

    // Creation de l'affichage graphique, observeur du jeu ---------------
    Affichage *af = new Affichage(RESX,RESY,NOM_JEU,jeu_);
    jeu_->ajouterObs(af);
    jeu_->notifierObs();
    int choix;
     // Lancement du jeu -------------------------------------------------
    jeu_->getEtatCourant()->verification();
    while (!(jeu_->getFini()))
    {	jeu_->notifierObs();
    	std::cout << "Voulez vous :\n1 -Jouer une carte\n2- Avoir des infos sur une carte\n3- Retourner une carte ?" <<std::endl;
    	std::cin>>choix;
    	switch (choix)
    	{
    		case 1:
    		jeu_->getEtatCourant()->jouerCarte();
    		break;
    		case 2:
    		jeu_->getEtatCourant()->InfoCarte();
    		break;
    		case 3:
    		jeu_->getEtatCourant()->retournerCarte();
    		break;
    	}
    }

    return 0;
}
