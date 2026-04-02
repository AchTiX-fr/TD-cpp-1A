#include <iostream>
#include "Produit.h"
#include "Panier.h"

int main()
{
	
	/*
	Question 1 :
	
	std::cout << "Bienvenue à Polytech Dijon" << std::endl;
	*/
	
	// Questions 2 et 3
	Produit cafe("Cafe", 2.5);

	// std::cout << cafe.getNom() << "( " << cafe.getPrix() << " € )" << std::endl;

	Produit croissant("Croissant", 1.20);
	Produit Beurre("Beurre", 0.80);
	Produit Baguette("Baguette", 1);

	Panier panier;

	panier.ajouterProduit(cafe);
	panier.ajouterProduit(croissant);
	panier.ajouterProduit(Beurre);
	panier.ajouterProduit(Baguette);

	// Affichage du contenu
	int ligne_fin = 0;

	for (int i = 0; i < panier.getNombreProduits(); ++i)
	{
		Produit p = panier.getProduit(i);

		std::cout << p.getNom() << "\033[" << i+1 << ";" << "40H" << std::flush << p.getPrix() << std::endl;

		ligne_fin = i;
	}
	std::cout << "---------------------------------------------------" << std::endl;
	std::cout << "Total" << "\033[" << ligne_fin + 3 << ";" << "40H" << std::flush << panier.getMontantTotal() << " €" << std::endl;

	return 0;
}