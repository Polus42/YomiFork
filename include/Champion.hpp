#include <iostream>
#include<math.h>
#ifndef CHAMPION_HPP
#define CHAMPION_HPP

class Effet;
class Jeu;
class Champion {

	private :

	int id_;/*!< int id du champion*/
	int hp_;/*!< int actuel  hp du champion*/
	int hpMax_;/*!< int hp max du champion*/
	int comboMax_;/*!< int combo max du champion*/
	Effet * effet_;/*!< int id du champion*/
	std::string nom_;/*!< nom du champion*/

	public :

	/*!
	*  \brief Constructeur  vide
	*
	*  Constructeur de la classe Champion
	*/
	
	Champion()
	{
	
	}

	/*!
	*  \brief Constructeur
	*
	*  Constructeur de la classe Affichage
	*
	*  \param id : id du champion
	*  \param hpmax: hp max du champion
	*  \param comboMax : combo max du champion
	*  \param *effet : effet du champion
	*  \param nom : nom du champion
	*/
	Champion ( int id, int hpMax, int comboMax, Effet *effet, std::string nom) {

		id_=id;
		hpMax_=hpMax;
		hp_=hpMax;
		comboMax_=comboMax;
		effet_=effet;
		nom_=nom;
	}


	int getId(){return id_;}

	int getHp(){return hp_;}

	int getHpMax(){return hpMax_;}

	int getComboMax(){return comboMax_;}

	Effet *getEffet(){return effet_;}

	std::string getNom(){return nom_;}

	void setID(int id) { id_=id;}

	void setHp(int HP) { hp_=HP;}

	void setHpMax(int HP) {hpMax_=HP;}

	void SetComboMax( int cb){ comboMax_=cb;}

	void setEffet(Effet *effet) { effet_=effet;}

	void setNom(std::string nom) { nom_=nom;}

   // FIN set et get---------------------------------------------------

     /*!
		*  \brief inflige des dégâts au champion. Les dommage sont convertie en entier ( floor)
		*  \param double dmg : les dommages subit
		*/
	void dmgTaken( double dmg);


     /*!
		*  \brief soigne le champion
		*  \param int heal : les hp soigner
		*/
	void heal ( int heal);


     /*!
		*  \brief aplique l'effet du champion
		*  \param Jeu* jeu : le jeu et 
		*  \param int j : indique à quel joueur appartient le champion
		*/
	void actionEffet(Jeu *jeu, int j);	
};

#endif
