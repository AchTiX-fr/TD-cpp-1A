#pragma once
#include "Produit.h"
#include <vector>

class Panier
{
private :
	std::vector <Produit> liste_produits;
public :
	Panier();
	void ajouterProduit(Produit produit);
	int getNombreProduits();
	Produit getProduit(int Produit);
	float getMontantTotal();
};

