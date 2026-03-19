#include <iostream>
#include "compare.h"

int main()
{
	int entier_1 = 0, entier_2 = 0;
	int entier = 42;
	float flottant = 12.24f;
	bool bouleen = true;
	std::string chaine = "POLYTECH DIJON";

	std::cout << "Integer = " << entier << std::endl;
	std::cout << "Float = " << flottant << std::endl;
	std::cout << "Boolean = " << bouleen << std::endl;
	std::cout << "String = " << chaine << std::endl;

	std::cout << "Donnez deux valeurs pour savoir si elles sont égales" << std::endl;
	std::cin >> entier_1;
	std::cin >> entier_2;

	std::cout << areEqual(entier_1, entier_2);

	for (int index = 0; index < 10; ++index) 
	{
		std::cout << index << std::endl;
	}



	return 0;
}

