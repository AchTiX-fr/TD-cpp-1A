#include <iostream>
#include <chrono>
#include <thread>
#include "Console.h"
#include "FlapModule.h"
#include "FlapDisplay.h"
void second(void);
void flapmodule(void);


int main()
{
	/*
	std::cout << "Chargement en cours ";
	std::cout << "\rChargement en cours .  ";
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	std::cout << "\rChargement en cours .. ";
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	std::cout << "\rChargement en cours ...";
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	std::cout << "\rChargement en cours .  ";
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	std::cout << "\rChargement en cours .. ";
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	std::cout << "\rChargement en cours ...";
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	std::cout << "\rChargement en cours .  ";


	std::cout << "Chargement terminé." << std::endl;
	*/

	//second();

	flapmodule();

	return 0;
}

void second()
{
	Console maConsole;

	//test d'effacer la console
	maConsole.clear();

	std::this_thread::sleep_for(std::chrono::milliseconds(500));

	//test du curseur
	std::cout << "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	maConsole.moveTo(0, 5);
	std::cout << "test";

	std::this_thread::sleep_for(std::chrono::milliseconds(500));

	maConsole.clear();

	//test d'écriture à un emplacement defini
	maConsole.textTo(13, 23, "Hello World");
}

void flapmodule()
{
	// effacage de la console
	Console maConsole;
	maConsole.clear();

	// test d'affichage d'un 'F'
	FlapModule mon_flap;
	mon_flap.display('T');
	while (mon_flap.update())
	{
		maConsole.clear();
		maConsole.moveTo(10, 15);
		std::cout << "[ " << mon_flap.currentSign() << " ]";
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(900));

	// test d'affichage de "HELLO WORLD"
	FlapDisplay mon_display(9);
	mon_display.Message("PARIS CDG");
	while (mon_display.update())
	{
		maConsole.clear();
		std::cout << mon_display.currentDisplay();
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(900));

	return;

	// test avec une horloge avec une classe hours
}