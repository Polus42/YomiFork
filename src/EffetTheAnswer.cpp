#include"EffetTheAnswer.hpp"
#include "Jeu.hpp"
#include "Joueur.hpp"
#include "Champion.hpp"

void EffetTheAnswer::actionEffet(Jeu *jeu,int x){
	
	std::srand (time(NULL));//intialise random seed
	int r=rand()%21+30;// Un nouveau entre 30 et 50
	Joueur* joueur;
	if (x==1){
		joueur=jeu->getJ1();
	}
	else{
		joueur=jeu->getJ2();
	}
	
	if (r<36){
		std::cout<<"Je me souvient plus de ce que fait ma capacite"<<std::endl;
	}
	
	if((r>=36)&&(r<42)){
		std::cout<<"Moi aussi je suis endurant"<<std::endl;
		joueur->getChamp()->heal(2);
	}
	
	if(r==42){
		std::cout<<"The answer to life, the universe and everything"<<std::endl;
		joueur->setMultDmg(3);
	}
	if((r>=43)&&(r<46)){
		std::cout<<"Non je triche pas c'est faux'"<<std::endl;
		joueur->piocher();
	}
	
	if(r>=46){
		std::cout<<"moi aussi je suis endurant ou pas..."<<std::endl;
		joueur->getChamp()->heal(-2);
	}
} 
void EffetTheAnswer::afficher(){
	std::cout<<"Une effet aléatoire parmis"<<std::endl;
	std::cout<<"Effectue un effet aléatoire parmis les suivant à chaque tour"<<std::endl;
	std::cout<<"Ne fait rien"<<std::endl;
	std::cout<<"Heal de 2 hp"<<std::endl;
	std::cout<<"Mais votre multiplicateur de dommage à sa valeur maximal (3)"<<std::endl;
	std::cout<<"Vous piocher une carte en plus"<<std::endl;
	std::cout<<"Vous perdez 2 hp(si vous tomber ko à cause de cette effet vous le serez à la fin du tour)"<<std::endl;
		
}
std::string EffetTheAnswer::getNom()
{
	return "TheAnswer";
}

