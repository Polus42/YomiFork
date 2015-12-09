#include<iostream>
#include<vector>
#include "Sujet.hpp"

#ifndef JEU_HPP
#define JEU_HPP
class Joueur;
class Etat;
class Carte;
class EtatPioche;
class Jeu : Sujet{

	private :

	Joueur *j1_;/*!< pointeur vers Joueur 1 */
	Joueur *j2_;/*!< pointeur vers Joueur 2 */
	int joue_;/*!< int qui indique quel joueur est entrain de jouer ( qui "a la main") */
	// indique le joueur que est entrain de jouer
	
	Etat *etatPioche_;/*!< pointeur vers un EtatPioche */
	Etat *etatChoixJ1_;/*!< pointeur vers un EtatChoixJ1 */
	Etat *etatChoixJ2_;/*!< pointeur vers un EtatChoixJ2 */
	Etat *etatChoixWin_;/*!< pointeur vers un EtatChoixWin */
	Etat *etatChoixPerso_;/*!< pointeur vers un EtatChoixPerso */
	Etat *etatCalcDmg_;/*!< pointeur vers un EtatCalcDmg */
	Etat *etatBluff_;/*!< pointeur vers un EtatBluff */
	Etat *etatCombo_;/*!< pointeur vers un EtatCombo */
	Etat *etatCleanUp_;/*!< pointeur vers un EtatCleanUp */
	Etat *etatFin_;/*!< pointeur vers un EtatFin */
	
	Etat *etatCourant_;/*!< pointeur vers l'état dans le quel ce trouve le jeu' */
	int gagnantCombat_;/*!< int qui indique qui à gagner le combat ce tour ci */
	 // 0 = match nul, 1 = J1 gagne, 2 = J2 gagne
	std::vector<Carte*> carteJ1_;/*!< vector<Carte*> carte jouer par J1 ce tour-ci */
	// carte jouer ce tour par J1
	std::vector<Carte*> carteJ2_;/*!< vector<Carte*> carte jouer par J2 ce tour-ci */
	// pareil pour J2
	std::vector<Carte*> RcarteJ1_; /*!< vector<Carte*> carte qui doivent revenir dans la main de J1 à la fin du tour */
	// carte qui doivent retourner dans la main du joueur 1 à la fin du tour
	std::vector<Carte*> RcarteJ2_;/*!< vector<Carte*> carte qui doivent revenir dans la main de J2 à la fin du tour */
	// Pareil pour J2
	
	

	int combo_; /*! int qui indique le compteur du combo ce tour-ci */
	// compteur de combo remis à 9 à chaque début de tour
	int comboTypeJ1_;/*! int qui indique le type de combo de J1 ce tour-ci */
	// indique quel type de combo on peut faire ( quel carte on peut jouer pour continuer le combo). C'est affecter par les effet style link ou finisher.
	// 0= combo classique; 1=on peut n'importe quel carte, 2= on arrête quoi qu'il arrive.
	int comboTypeJ2_;/*! int qui indique le type de combo de J2 ce tour-ci */
	bool bluff_; /*! bool qui indique si on a bluff avec un joker ce tour-ci */
	//indique si un joueur a bluffé (avec un jocker)ce tour ci 
	bool fini_; /*! bool qui indique si la partie est fini*/
	// flase= partie non finie ; true= partie finie
	
	// ----------------------------------------------------------------------------------
	// Implementation de la classe sujet
	std::vector<Observeur*> listeObs_;/*! les des observeurs */
	
	public :

	/*!
	*  \brief Constructeur
	*
	*  Constructeur de la classe Jeu
	*
	*/
		Jeu();
	//set et get--------------------------------- 

	//tout les get des etat de la liste des état à rajouter plustard

	Joueur* getJ1(){return j1_;}

	void setJ1(Joueur* j){j1_=j; }

	Joueur* getJ2(){return j2_;}

	void setJ2(Joueur* j){j2_=j; }

	//Etat *getEtatCourant(){return etatCourant_;}
	//void setEtatCourant(Etat et){ etatCourant_=&et;}	il faut defnir les etats conrets avant

	std::vector<Carte*> getCarteJ1(){return carteJ1_;}
	std::vector<Carte*> getCarteJ2(){return carteJ2_;}
	std::vector<Carte*> getRcarteJ1(){return RcarteJ1_;}
	std::vector<Carte*> getRcarteJ2(){return RcarteJ1_;}
	
	int getJoue(){return joue_;}
	void setJoue(int x){joue_=x;}

	int getGagnantCombat(){return gagnantCombat_;}
	void setGagnantCombat(int x){gagnantCombat_=x;}

	int getCombo(){return combo_;}
	void setCombo(int x){combo_=x;}
	
	int getComboTypeJ1(){return comboTypeJ1_;}
	void setComboTypeJ1(int x){comboTypeJ1_=x;}
	
	int getComboTypeJ2(){return comboTypeJ2_;}
	void setComboTypeJ2(int x){comboTypeJ2_=x;}
	
	Etat *getEtatCourant(){return etatCourant_;}
	void setEtatCourant(Etat *et){etatCourant_=et;}
	
	Etat *getEtatPioche(){return etatPioche_;}
	Etat *getEtatChoixJ1(){return etatChoixJ1_;}
	Etat *getEtatChoixJ2(){return etatChoixJ2_;} 
	
	Etat *getEtatChoixWin(){return etatChoixWin_;}
	Etat *getEtatCalcDmg(){return etatCalcDmg_;}
	Etat *getEtatBluff(){return etatBluff_;}
	Etat *getEtatCombo(){return etatCombo_;}
	Etat *getEtatCleanUp(){return etatCleanUp_;}
	Etat *getEtatFin(){return etatFin_;}
	
	bool getFini(){return fini_;}
	void setFini(bool f){fini_=f;}
	
	bool getBluff(){return bluff_;}
	void setBluff(bool b){bluff_=b;}

	// Les autres fonction----------------------------------------------

	// C'est 2 fonction ajoute une carte dans les vector des cartes jouer par les joueur à la fin
	/*!
		*  \brief ajoute une carte à la liste des carte de J1
		*  \param Carte* c : carte à rajouter
		*/
	void addCarteJ1(Carte *c);
	/*!
		*  \brief ajoute une carte à la liste des carte de J2
		*  \param Carte* c : carte à rajouter
		*/
	void addCarteJ2(Carte *c);


	// Pareil mais pour les 2 autre vector
	/*!
		*  \brief ajoute une carte à la liste des carte à retourner de J1
		*  \param Carte* c : carte à rajouter
		*/
	void addRcarteJ1(Carte *c);
	/*!
		*  \brief ajoute une carte à la liste des carte à retourner de J2
		*  \param Carte* c : carte à rajouter
		*/
	void addRcarteJ2(Carte *c);


	void vidage(); // Vide tout les vector et remet les autres valeur comme il faut pour un nouveau tour

	/*!
		*  \brief Retourne la dérnière carte jouer par le joueur i
		*  \param int i : le joueur concerner
		*/
	void retournerToMain(int i); // retourne en main la carte du joueur corespondant au numéro choisi

	/*!
		*  \brief vide le vector<Carte*> carteJ1_
		*/
	void clearCarteJ1();
	/*!
		*  \brief vide le vector<Carte*> carteJ2_
		*/
	void clearCarteJ2();
	/*!
		*  \brief vide le vector<Carte*> RcarteJ1_
		*/
	void clearRCarteJ1();
	/*!
		*  \brief vide le vector<Carte*> RcarteJ2_
		*/
	void clearRCarteJ2();
	
	/*!
		*  \brief augmente de un le compteur de combo ( combo_)
		*/
	void plusCombo(); // Rajoute 1 au compteur de combo ex : combo_=1 ---> combo_=2


	/*!
		*  \brief applique l'effet de la derière carte jouer par le joueur i
		*  \param int i : le joueur concerner
		*/
	void actionEffet(int i);

	/*!
		*  \brief retourne la dérnière carte jouer par le joueur i
		*  \param int i : le joueur concerner
		*  \return Carte* : pointeur vers la carte
		*/
	Carte* getLastCarte(int j);
	/*!
		*  \brief retourne le type de combo du joueur i
		*  \param int i : le joueur concerner
		*  \return int : le type de combo du joueur i
		*/
	int getGoodComboType(int x);// Va cherche le combo type correspondant à l'entier x (1=J1 ...)
	
	// --------------------------------------------------------------------------------
	// Implementation de la classe sujet
	/*!
		*  \brief ajoute un observeur à jeu
		*  \param Oberserveur *o : l'observeur à rajouté
		*/
	void ajouterObs(Observeur *o);
	/*!
		*  \brief suprime un observeur du jeu
		*  \param i : l'indice de l'observeur'
		*/
	void supprimerObs(int i);
	/*!
		*  \brief notifie les observeur de jeu
		*/
	void notifierObs();
	/*!
		*  \brief ajoute un observeur de jeu
		*  \param Oberserveur *o : l'observeur concerner
		*/
	void notifierObs(Observeur *o);

};
#endif
