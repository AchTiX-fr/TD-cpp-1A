#pragma once
#include <string>

class Produit
{
private :
	std::string nom;
	float prix;

public :
	Produit(std::string n, float p);
	std::string getNom();
	float getPrix();
};

