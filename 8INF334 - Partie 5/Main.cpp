#include "Main.h"
int main() {
	setlocale(LC_CTYPE, "fr-FR");
	int choix = -1;
	do {
		std::cout <<
			"Quel patron souhaitez-vous tester?" << std::endl <<
			"1 - Singleton" << std::endl <<
			"2 - Decorator" << std::endl <<
			"3 - State" << std::endl << std::endl;
		try {
			std::string temp;
			std::getline(std::cin, temp);
			choix = std::stoi(temp);
		}
		catch (std::exception e) {
			std::cout << "Caractère invalide.\n";
			choix = -1;
		}
	} while (choix < 1 || choix > 3);
	std::cout << std::endl;
	switch (choix) {
	case 1:
		mainSingleton();
		break;
	case 2:
		//mainDecorator();
		break;
	case 3:
		//mainState();
		break;
	}
	return 0;
}