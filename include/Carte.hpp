#include <iostream>
#include <vector>
//#include "Effet.hpp"
#include<Jeu.hpp>
#ifndef CARTE_HPP
#define CARTE_HPP

class Effet;
class Carte
{

    private:
   	int id_;/*!< int id de la carte*/
	std::string nom_;/*!< nom de la carte*/
	int type_; /*!< int type de la carte coté recto*/ 
	//0=coup, 1=choppe, 2=block , 3 = esquive, 4=jocker
	int type2_;/*!< int type de la carte coté verso*/
	//0=coup, 1=choppe, 2=block , 3 = esquive, 4=jocker
	std::vector<Effet*> Leffet_;/*!< vector<Effet*> effet de la carte coté recto*/
	std::vector<Effet*> Leffet2_;/*!< vector<Effet*> effet de la carte coté verso*/
	int num_; /*!< int numéro de la carte*/ 
	// numéro ex: 2 de trèfle , 3 de carreaux ( note : le numero pour les jocker est 0)
	int couleur_; /*!< int couleur de la carte*/
	//0=trèfle , 1 = pique, 2=carreaux, 3=coeur
	
	bool retournable_;/*!< bool indique si la carte a 2 coté*/
	int face_; /*!< int face de la carte*/
	// O = face rector et 1 = face verso --> utile pour les cartes retournable
	double Fstartup_;/*!< double frame de startup de la carte coté recto*/ 
	// frame de startup
	double Fstartup2_;/*!< double frame de startup de la carte coté verso*/ 
	double dmg_;/*!< double dommage de la carte coté recto*/ 
	double dmg2_;/*!< double dommage de la carte coté verso*/ 


    public:

    //Constructeur------------------------------------------------------------
	/*!
	*  \brief Constructeur vide
	*
	*  Constructeur de la classe Carte
	*
	*/

	Carte()
	{
	
	}

	// Constructeur pour carte qui n'ont' qu'un coté.

	/*!
	*  \brief Constructeur de carte à 1 coté.
	*
	*  Constructeur de la classe Carte
	*
	*  \param id : id de la carte
	*  \param nom : nom de la carte
	*  \param Leffet : liste des effets de la carte
	*  \param : type : type de la carte
	*  \param num : numéro de la carte
	*  \param couleur : couleur de la carte
	*  \param FS : framed de startup de la carte
	*  \param dmg : dommage de la carte
	*/
        Carte ( int id, std::string nom, int type, std::vector<Effet*> Leffet, int num, int couleur, double FS,double dmg) {
        
		id_=id;

		nom_=nom;

		type_=type;

		Leffet_=Leffet;

		num_=num;

		couleur_=couleur;

		retournable_=false;

		Fstartup_=FS;

		face_=0;

		dmg_=dmg;

        };

        // Constructeur pour carte qui ont 2 coté.

        	/*!
	*  \brief Constructeur de carte à 1 coté.
	*
	*  Constructeur de la classe Carte
	*
	*  \param id : id de la carte
	*  \param nom : nom de la carte
	*  \param Leffet : liste des effets de la carte coté recto
	*  \param Leffet2 : liste des effets de la carte coté verso
	*  \param : type : type de la carte coté recto
	*  \param : type2 : type de la carte coté verso
	*  \param num : numéro de la carte
	*  \param couleur : couleur de la carte
	*  \param FS : framed de startup de la carte coté recto
	*  \param FS2 : framed de startup de la carte coté verso
	*  \param dmg : dommage de la carte coté recto
	*  \param dmg2 : dommage de la carte coté verso
	*/

        Carte ( int id, std::string nom, int type, int type2, std::vector<Effet*> Leffet, std::vector<Effet*> Leffet2, int num, int couleur, double FS, double FS2,double dmg, double dmg2) {

       		id_=id;

		nom_=nom;

		type_=type;

		type2_=type2;

		Leffet_=Leffet;

		Leffet2_=Leffet2;

		num_=num;

		couleur_=couleur;

		retournable_=true;

		Fstartup_=FS;

		Fstartup2_=FS2;

		face_=0;

		dmg_=dmg;

		dmg2_=dmg2;
        }


    ~Carte();


	// get et set ------------------------------------------------------------------

	
    int getId(){ return id_ ;}

    void setID(int id) { id_=id;}
    
    std::string getNom() { return nom_;}
    
    void setNom(std::string nom) { nom_=nom;}
    
    int getType() {return type_;}

    int getType2() { return type2_;}
    
    void setType( int type) { type_=type;}

     void setType2( int type) { type2_=type;}

    std::vector<Effet*> getLeffet(){ return Leffet_;}

    std::vector<Effet*> getLeffet2(){ return Leffet2_;}

    void setLeffet (std::vector<Effet*> Leffet){ Leffet_=Leffet;}

    void setLeffet2 (std::vector<Effet*> Leffet){ Leffet2_=Leffet;}
    
    int getNum(){ return num_;}
    
    void setNum(int num){  num_=num;}

    int getCouleur(){ return couleur_;}
    
    void setCouleur(int coul){ couleur_=coul;}

    bool getRetournable(){ return retournable_;}
    
    void setRetournable(bool r){ retournable_=r;}

    double getFstartup(){ return Fstartup_;}

    double getFstartup2(){ return Fstartup2_;}

    double getFace(){ return face_;}
    void setFace(int x){face_=x;}
    
    

    void setFstartup(int FS) {Fstartup_=FS ;}

    void setFstartup2(int FS) {Fstartup2_=FS ;}

    double getDmg(){return dmg_;}
    double getDmg2(){return dmg2_;}

    void setDmg(double dmg){ dmg_ = dmg;}
    void setDmg2(double dmg2){dmg2_ = dmg2;}




    // FIN set et get---------------------------------------------------

   // C'est 4 get vont chercher la bonne valeur selon si la carte est face recto ou verso
   /*!
		*  \brief Retourne le type de la carte selon son coté ( type_ si recto type2_ pour verso)
		*
		*  \return : un int indiquant le type de la carte
		*/
   	int getGoodType();

   	 /*!
		*  \brief Retourne le type de les frame de startup de la carte selon son coté ( Fstartup_ si recto Fstartup2_ pour verso)
		*
		*  \return : un int indiquant les frame de startup de la carte
		*/
	int getGoodFstartup();

	 /*!
		*  \brief Retourne la bonne liste d'effet de la carte selon son coté ( Leffet_ si recto Leffet2_ pour verso)
		*
		*  \return : un vector<Effet*>
		*/
	std::vector<Effet*> getGoodLeffet();

	 /*!
		*  \brief Retourne les dommages de la carte selon son coté ( dmg_ si recto dmg2_ pour verso)
		*
		*  \return : un double indiquand les dommages de la carte
		*/
	double getGoodDmg();
	
	
     /*!
		*  \brief rajoute un effet à Leffet_ de la carte
		*   \param newEffet : l'effet à rajouté
		*/
    void addEffet(Effet* newEffet);

     /*!
		*  \brief rajoute un effet à Leffet2_ de la carte
		*  \param newEffet : l'effet à rajouté
		*/
    void addEffet2(Effet *newEffet);

     /*!
		*  \brief apelle actionEffet de Effet sur chaque effet de la carte en prennant en compte le coté ou est tourner la carte
		*
		*  \param Jeu *jeu : Le jeu 
		*  \param int j : un entier indiquant qu'elle joueur joue la carte
		*
		*/
    void actionEffet(Jeu* jeu, int j);// prend en compte le coté sur le quel la carte est tourné
     /*!
		*  \brief affiche les stats de la carte
		*
		*/
    void afficher(); // affiche les stats de la carte

         /*!
		*  \retourne la carte sur son autre coté si possible
		*
		*/
    bool changerFace(); // tourne la carte de sur son autre face si possible sinon ne fait rien et affiche un message d'erreur. Le résultat de la fonction est vrai si on peut la retourner et false sinon.


    // C'est 4 fonction vont renvoyer une string qui convient selon leur valeur ex: type_=0 renvoi "coup"

      /*!
		*  \brief convertie les entier 0, 1, ect... indiquant le type de la carte en string : coup,choppe ect... pour l'affichage'
		*
		*  \param entier x : indique de qe quel coté on veut indiqué le type
		*  \retourne un string indiquant le type de la carte
		*/
    std::string convertionType(int x); // Cele-ci prend un int pour savoir le type de quel face on veut afficher

        /*!
		*  \brief convertie les entier 0, 1, ect... indiquant le numéro de la carte en string : 2,3... valet,dame,roi, as
		*
		*  \retourne un string indiquant le numéro de la carte
		*/
    std::string convertionNum();

         /*!
		*  \brief convertie les entier 0, 1 indiquant le  coté de la carte en string : recto, verso
		*
		*  \retourne un string indiquant le coté de la carte ( recto / verso)
		*/
    std::string convertionFace();

         /*!
		*  \brief convertie les entier 0, 1, ect... indiquant la couleur de la carte en string : coeur,pique...
		*
		*  \retourne un string indiquant la couleurla carte
		*/
    std::string convertionCouleur();

    
     /*!
		*  \brief regarde si 2 carte sont les même  selon leur id
		*  \param c : pointeur vers la seconde carte
		*  \retourne true si l'id des deux cartes sont la même sinon retourne fasle
		*/
    bool equals(Carte *c);
    
   
};

#endif // CARTE_H

