#include "BuilderDeckTxt.hpp"
#include <stdio.h> 
#include <dirent.h>
#include "EffetBoost.hpp"
#include "EffetYolo.hpp"
#include "EffetEndurant.hpp"
#include "EffetTheAnswer.hpp"
#include "EffetLink.hpp"
#include "EffetFinisher.hpp"
#include "EffetReturn.hpp"
#include "Deck.hpp"
#include "Carte.hpp"
#include "Champion.hpp"

BuilderDeckTxt::BuilderDeckTxt(std::string dossier)
{
	dossier_ = dossier;
	deck_ = new Deck();
}
Carte *BuilderDeckTxt::creerCarte(std::string fichiercarte)
{
	std::cout << "Chargement de la carte : "+fichiercarte << std::endl;
	Carte *c = new Carte();
	std::ifstream fichier(fichiercarte);
	std::string str;
	std::string delimiter = "=";
	std::string token,token2;
	while (std::getline(fichier, str))	//parcours de toutes les lignes du fichier
	{
		token = str.substr(0, str.find(delimiter));	// partie avant le "="
		if (token=="id_"){
		str.erase(0,str.find(delimiter)+1);
			c->setID(std::stoi(str));	// partie après le "="
			}
		if (token=="nom_"){
		str.erase(0,str.find(delimiter)+1);
			c->setNom(str);
			}
		if (token=="num_"){
		str.erase(0,str.find(delimiter)+1);
			c->setNum(std::stoi(str));
			}
		if (token=="retournable_"){
		str.erase(0,str.find(delimiter)+1);
			c->setRetournable(std::stoi(str));
			}
		if (token=="type_"){
		str.erase(0,str.find(delimiter)+1);
			c->setType(std::stoi(str));
			}
		if (token=="type2_"){
		str.erase(0,str.find(delimiter)+1);
			c->setType2(std::stoi(str));
			}
		if (token=="couleur_"){
		str.erase(0,str.find(delimiter)+1);
			c->setCouleur(std::stoi(str));
			}
		if (token=="Fstartup_"){
		str.erase(0,str.find(delimiter)+1);
			c->setFstartup(std::stod(str));
			}
		if (token=="Fstartup2_"){
		str.erase(0,str.find(delimiter)+1);
			c->setFstartup2(std::stod(str));
			}
		if (token=="dmg_"){
		str.erase(0,str.find(delimiter)+1);
			c->setDmg(std::stod(str));
			}
		if (token=="dmg2_"){
		str.erase(0,str.find(delimiter)+1);
			c->setDmg2(std::stod(str));
			}
		if (token=="Leffet_")
		{
			str.erase(0,str.find(delimiter)+1);
			token2 = str;
			token2.erase(token2.length()-1);
			if (token2=="EffetReturn"){
				c->addEffet(new EffetReturn());
				}
			if (token2=="EffetBoost"){
				c->addEffet(new EffetBoost());
				}
			if (token2=="EffetYolo"){
				c->addEffet(new EffetYolo());
				}
			if (token2=="EffetTheAnswer"){
				c->addEffet(new EffetTheAnswer());
				}
			if (token2=="EffetFinisher"){
				c->addEffet(new EffetFinisher());
				}
			if (token2=="EffetLink"){
				c->addEffet(new EffetLink());
				}
			if (token2=="EffetEndurant"){
				c->addEffet(new EffetEndurant());
				}
			}

		if (token=="Leffet2_") {
			str.erase(0,str.find(delimiter)+1);
			token2 = str;
			token2.erase(token2.length()-1);
			if (token2=="EffetReturn"){
				c->addEffet2(new EffetReturn());
				}
			if (token2=="EffetBoost"){
				c->addEffet2(new EffetBoost());
				}
			if (token2=="EffetYolo"){
				c->addEffet2(new EffetYolo());
				}
			if (token2=="EffetTheAnswer"){
				c->addEffet2(new EffetTheAnswer());
				}
			if (token2=="EffetFinisher"){
				c->addEffet2(new EffetFinisher());
				}
			if (token2=="EffetLink"){
				c->addEffet2(new EffetLink());
				}
			if (token2=="EffetEndurant"){
				c->addEffet2(new EffetEndurant());
				}
			}
		}
	return c;
}
void BuilderDeckTxt::creerCartes()
{

    DIR * rep = opendir(dossier_.c_str()); 
  
    if (rep != NULL)
    {
        struct dirent * ent;
  
        while ((ent = readdir(rep)) != NULL)	// On parcours tous les fichiers du dossier
        {
            std::string s(ent->d_name);
            if ((s!=".")&&(s!=".."))
            {
		    if (s=="Champion.txt")
		    {
		    	deck_->addChampion(creerChampion(dossier_+s));
		    }
		    else{
		    	for (int i =0; i<4; i++)
		    	{
		    		Carte * c= creerCarte(dossier_+s);
		    		c->setCouleur(i);
		    		deck_->addCarte(c);
		    	}
		    }
            }
        }
        closedir(rep);
    }
}
Champion *BuilderDeckTxt::creerChampion(std::string fichiercarte)
{
	std::cout << "Chargement du champion : "+fichiercarte << std::endl;
	Champion *c = new Champion();
	std::ifstream fichier(fichiercarte);
	std::string str;
	std::string delimiter = "=";
	std::string token,token2;
	while (std::getline(fichier, str))	//parcours de toutes les lignes du fichier
	{
		token = str.substr(0, str.find(delimiter));	// partie avant le "="
		if (token=="id_"){
		str.erase(0,str.find(delimiter)+1);
			c->setID(std::stoi(str));	// partie après le "="
			}
		if (token=="nom_"){
		str.erase(0,str.find(delimiter)+1);
			c->setNom(str);
			}
		if (token=="hpMax_"){
		str.erase(0,str.find(delimiter)+1);
			c->setHpMax(std::stoi(str));
			}
		if (token=="comboMax_"){
		str.erase(0,str.find(delimiter)+1);
			c->SetComboMax(std::stoi(str));
			}
		if (token=="effet_")
		{
			str.erase(0,str.find(delimiter)+1);
			token2 = str;
			token2.erase(token2.length()-1);
			if (token2=="EffetReturn"){
				c->setEffet(new EffetReturn());
				}
			if (token2=="EffetBoost"){
				c->setEffet(new EffetBoost());
				}
			if (token2=="EffetYolo"){
				c->setEffet(new EffetYolo());
				}
			if (token2=="EffetTheAnswer"){
				c->setEffet(new EffetTheAnswer());
				}
			if (token2=="EffetFinisher"){
				c->setEffet(new EffetFinisher());
				}
			if (token2=="EffetLink"){
				c->setEffet(new EffetLink());
				}
			if (token2=="EffetEndurant"){
				c->setEffet(new EffetEndurant());
				}
		}	
	}
	c->setHp(c->getHpMax());
	return c;
}
Deck * BuilderDeckTxt::creerDeck()
{
	deck_->shuffle();
	return deck_;
}



