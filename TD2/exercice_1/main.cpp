// Exercice 1 - Erreurs de syntaxe
// Utilisez les informations fournies par le compilateur pour identifier 
// et corriger les erreurs de syntaxe du code suivant

#include <iostream>
#include <vector>

int main()
{
	std::vector<int> integers = { 1, 2, 3, 4, 5, 6, 7 };

	for (int i: integers)
	{
		std::cout << i << std::endl;
	}

	return 0;
}