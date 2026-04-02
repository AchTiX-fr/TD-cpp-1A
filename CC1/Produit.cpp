#include "Produit.h"

Produit::Produit(std::string n, float p)
{
	nom = n;
	prix = p;
}

std::string Produit::getNom()
{
	return nom;
}

float Produit::getPrix()
{
	return prix;
}
