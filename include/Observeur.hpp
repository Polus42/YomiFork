/*!
 * \file Observeur.hpp
 * \brief Interface pour un observeur
 * \author paul_figiel
 * \version 1.0
 */
 //------------------------------
#ifndef OBSERVEUR_HPP
#define OBSERVEUR_HPP
//------------------------------
/**
* \class Observeur
* \brief Classe Observeur qui sert de base pour implementer des classes qui observent un sujet
* \date 15/11/2015
* \author paul_figiel
*/
//------------------------------
class Observeur {

	public :
	/*!
	*  \brief Permet d'actualiser l'oserveur en fonction de son sujet
	*
	*/
	virtual void actualiser() = 0;

};
#endif
