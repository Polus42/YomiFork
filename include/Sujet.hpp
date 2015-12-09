/*!
 * \file Sujet.hpp
 * \brief Interface pour un sujet
 * \author paul_figiel
 * \version 1.0
 */
 //------------------------------
#ifndef SUJET_HPP
#define SUJET_HPP
class Observeur;
//------------------------------
/**
* \class Sujet
* \brief Classe Sujet qui sert de base pour implementer des classes observées
* \date 15/11/2015
* \author paul_figiel
*/
//------------------------------
class Sujet {

	public :
	/*!
	*  \brief Permet d'ajouter un observeur au sujet
	*  \param o : observeur à ajouter
	*/
	virtual void ajouterObs(Observeur *o) = 0;
	/*!
	*  \brief Permet de supprimer un observeur au sujet
	*  \param o : indice de l'observateur à supprimer
	*/
	virtual void supprimerObs(int i) = 0;
	/*!
	*  \brief Permet de notifier tous les observateurs du changement du sujet
	*/
	virtual void notifierObs() = 0;
	/*!
	*  \brief Permet de notifier un observeur
	*  \param o : observeur à notifier
	*/
	virtual void notifierObs(Observeur *o) = 0;
	

};
#endif
