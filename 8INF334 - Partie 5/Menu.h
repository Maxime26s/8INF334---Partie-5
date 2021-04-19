#pragma once
#include <vector>
#include <string>

class Menu
{
	static Menu* Instance;

	std::vector<std::string> poutines;

	Menu();

public:
	static Menu* getInstance() {
		if (Menu::Instance == nullptr)
			Menu::Instance = new Menu();

		return Menu::Instance;
	}

	std::string ajouterPoutine(std::string nom);
	std::string retirerPoutine(int index);
	std::string retirerPoutine(std::string nom);
	std::string modifierPoutine(std::string newNom, int index);
	std::string modifierPoutine(std::string newNom, std::string nom);
	std::string deplacerPoutine(int newNum, int index);
	std::string deplacerPoutine(int newNum, std::string nom);
	int chercherPoutine(std::string nom);
	std::string obtenirMenu();
};

