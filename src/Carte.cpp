#include "Carte.hpp"
#include "Effet.hpp"

Carte::~Carte()
{

}

// Va chercher le bon type de la carte selon si la carte est recto ou verso
int Carte::getGoodType(){

	if (this->face_==0) {
		return this->getType();
	}else {
		
		return this->getType2();
	}
}

// Va chercher les bonnes frame de startup de la carte selon si la carte est recto ou verso
int Carte::getGoodFstartup(){

    	if (this->face_==0) {
    		return this->getFstartup();
    	}else {
		return this->getFstartup2();
    	}
}



// Va chercher les bon effets de la carte selon si la carte est recto ou verso
std::vector<Effet*> Carte::getGoodLeffet() {

	if (this->face_==0) {
		return this->getLeffet();
	}else{
		return this->getLeffet2();
	}
    
}



// Va chercher les bon dommage de la carte selon si la carte est recto ou verso

double Carte::getGoodDmg(){
	if (this->face_==0){
		return this->getDmg();
	}else{
		return this->getDmg2();
	}
	
}
    


// Rajoute un effet sur la carte
void Carte::addEffet(Effet *effet) {

	Leffet_.push_back(effet);
}
void Carte::addEffet2(Effet *newEffet) {
	Leffet2_.push_back(newEffet);
}

// Aplique tout les effets de la cartes selon si la carte est recto ou verso

void Carte::actionEffet(Jeu *jeu,int j){

	for (auto &i : this->getGoodLeffet()) { // demande C++11 c'est un for each
		i->actionEffet(jeu,j);
	}
}

// tourne la carte de sur son autre face si possible sinon ne fait rien et affiche un message d'erreur. Le résultat de la fonction est vrai si on peut la retourner et false sinon.



bool Carte::changerFace() {


	if ( retournable_) { // on regarge si la carte est retournable
		

		if ( face_==0) {// on regarde de quel coté est la carte ctuellement

			face_=1;
		}else{
			face_=0;
		}
	}

	return retournable_;
}




// Les 4 fonction de convertionCouleur

std::string Carte::convertionType(int x){
	int type; // le type qu'on veut
	
	if ((x==0)||(!(retournable_))) {  // le !retournable_ est là pour ne pas pouvoir cherche type2_ si celui ci n'est pas initialiser
		type=type_;
	}else {
		type=type2_;
	}

	switch (type) {

		case 0 :
		{
		return ("un coup");
		break; 
		}
		case 1 :
		{return ("une choppe");
		 break;
		}
		case 2 :
		{
		 return ("un block");
		 break;
		}
		case 3:
		{
		return("une esquive");
		break;
		}
		case 4:
		{
		return("un joker");
		}
	}
	return "";	
}


std::string Carte::convertionNum(){

	if (num_<=10) {

		return(std::to_string(num_));// demande c++11 ------------------------------------------------
	}
	else {

		switch (num_) {

			case 11 : 
			{
			return("valet");
			break;
			}
			case 12 :
			{
			return("dame");
			break;
			}
			case 13 :
			{
			return ("roi");
			}
		}
	}
	return "";
}



std::string Carte::convertionFace() {


	if (face_==0){
		return ("recto");
	}else{
		return("verso");
	}
	return "";
}



std::string Carte::convertionCouleur() {

	switch (couleur_) {

		case 0 :
		{
		return("trefle");
		break;
		}
		case 1 :
		{
		return("pique");
		break;
		}
		case 2 :
		{
		return("carreaux");
		break;
		}
		case 3 :
		{
		return ("coeur");
		break;
		}
	}
	return "";
}



//fin des 4 fonction de convertion -----------------------------------------






	void Carte::afficher(){

	std::cout<<"Le nom de la carte est "<<nom_<< std::endl;
	std::cout<<"Le numero de la carte est "<<this->convertionNum()<< std::endl;
	std::cout<<"La couleur de la carte est "<<this->convertionCouleur()<< std::endl;

	 if (retournable_){

	 	std::cout<<"la carte a 2 coté"<<std::endl;
	 }else {
	 	std::cout<<"la carte a 1 coté"<<std::endl;
	 }

	 std::cout<<"la carte coté recto est ";
	 std::cout<<this->convertionType(0)<<std::endl;

	 std::cout<<"ses frame de startup sont "<<Fstartup_<<" et ses dommage sont "<<dmg_<<std::endl;
	 std::cout<<" Ses effet sont ";

	 for (auto &i : this->getLeffet()) { // demande C++11 c'est un for each
		i->afficher();	//definir afficher dans effet
	}
	std::cout<<std::endl;
	// fin affichage coté recto 

	
	if ( retournable_) {

	 std::cout<<"la carte coté verso est ";
	 std::cout<<this->convertionType(1)<<std::endl;

	 std::cout<<"ses frame de startup sont "<<Fstartup2_<<" et ses dommage sont "<<dmg2_<<std::endl;
	 std::cout<<" Ses effet sont ";

	 for (auto &i : this->getLeffet2()) { // demande C++11 c'est un fort each
		i->afficher();	//definir afficher dans effet
	}
	std::cout<<std::endl;
	}
}


bool Carte::equals(Carte* c){

	return (id_==c->id_);
}








