#include "Panier.h"
#include "Produit.h"

Panier::Panier() 
{

}

void Panier::ajouterProduit(Produit produit)
{
	liste_produits.push_back(produit);
}

int Panier::getNombreProduits()
{
	return liste_produits.size();
}

Produit Panier::getProduit(int Produit)
{
	return liste_produits[Produit];
}

float Panier::getMontantTotal()
{
	float somme = 0;
	for (int i = 0; i < getNombreProduits(); ++i)
	{
		somme += getProduit(i).getPrix();
	}
	return somme;
}