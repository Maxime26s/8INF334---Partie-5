#include "Header.h"

Menu* Menu::Instance = nullptr;

int main() {
	setlocale(LC_CTYPE, "fr-FR");

	while (true) {
		int choix;
		std::string temp;
		do {
			choix = demanderNum("Quel compte souhaitez-vous utiliser?\n1 - Client\n2 - Admin\n");
		} while (choix < 1 || choix > 2);
		bool admin = choix == 2;
		while (choix != 6 && admin || choix != 2 && !admin) {
			std::cout << std::endl;
			if (admin) {
				choix = demanderNum(menuAdmin());
				int ans = -1;
				std::string temp2 = "Quelle manière souhaitez-vous utiliser?\n1 - Par nom de poutine\n2 - Par numéro de poutine\n";
				switch (choix) {
				case 1:
					std::cout << Menu::getInstance()->obtenirMenu();
					break;
				case 2:
					std::cout << Menu::getInstance()->ajouterPoutine(
						demanderTexte("Quel est le nom de la poutine que vous souhaitez ajouter?") //nom
					);
					break;
				case 3:
					ans = demanderNum("Quelle manière souhaitez-vous utiliser?\n1 - Par nom de poutine\n2 - Par numéro de poutine\n");
					if (ans < 1 || ans > 2)
						break;
					if (ans == 1) {
						std::cout << Menu::getInstance()->modifierPoutine(
							demanderTexte("Quel est le nouveau nom de la poutine?"), //nouveau nom
							demanderTexte("Quel poutine souhaitez-vous modifier? (nom)") //nom
						);
					}
					else {			
						std::cout << Menu::getInstance()->modifierPoutine(
							demanderTexte("Quel est le nouveau nom de la poutine?"), //nouveau nom
							demanderNum("Quel poutine souhaitez-vous modifier? (numéro)") //num
						);
					}
					break;
				case 4:
					ans = demanderNum("Quelle manière souhaitez-vous utiliser?\n1 - Par nom de poutine\n2 - Par numéro de poutine\n");
					if (ans < 1 || ans > 2)
						break;
					if (ans == 1) {
						std::cout << Menu::getInstance()->deplacerPoutine(
							demanderNum("Quel est le nouveau numéro de la poutine?"), //nouveau num
							demanderTexte("Quel poutine souhaitez-vous déplacer? (nom)") //nom
						);
					}
					else {
						std::cout << Menu::getInstance()->deplacerPoutine(
							demanderNum("Quel est le nouveau numéro de la poutine?"), //nouveau num
							demanderNum("Quel poutine souhaitez-vous déplacer? (num)") //num
						);
					}
					break;
				case 5:
					ans = demanderNum("Quelle manière souhaitez-vous utiliser?\n1 - Par nom de poutine\n2 - Par numéro de poutine\n");
					if (ans < 1 || ans > 2)
						break;
					if (ans == 1) {
						std::cout << Menu::getInstance()->retirerPoutine(
							demanderTexte("Quel poutine souhaitez-vous supprimer? (nom)") //nom
						);
					}
					else {
						std::cout << Menu::getInstance()->retirerPoutine(
							demanderNum("Quel poutine souhaitez-vous supprimer? (num)") //num
						);
					}
					break;
				case 6:
					break;
				case 7:
					return 0;
				default:
					std::cout << "Entrée invalide." << std::endl;
				}
			}
			else {
				choix = demanderNum(menuClient());
				switch (choix)
				{
				case 1:
					std::cout << Menu::getInstance()->obtenirMenu();
					break;
				case 2:
					break;
				case 3:
					return 0;
					break;
				default:
					std::cout << "Entrée invalide." << std::endl;
					break;
				}
			}
		}
	}
	return 0;
}

std::string menuAdmin() {
	return "Que souhaitez-vous faire?\n1 - Afficher le menu\n2 - Ajouter une poutine\n3 - Modifier une poutine\n4 - Déplacer une poutine\n5 - Supprimer une poutine\n6 - Se deconnecter\n7 - Quitter\n";
	/*
		std::cout << "Que souhaitez-vous faire?" << std::endl <<
		"1 - Afficher le menu" << std::endl <<
		"2 - Ajouter une poutine" << std::endl <<
		"3 - Modifier une poutine" << std::endl <<
		"4 - Déplacer une poutine" << std::endl <<
		"5 - Supprimer une poutine" << std::endl <<
		"6 - Se deconnecter" << std::endl <<
		"7 - Quitter" << std::endl;
	*/
}

std::string menuClient() {
	return "Que souhaitez-vous faire?\n1 - Afficher le menu\n2 - Se deconnecter\n3 - Quitter\n";
	/*
		std::cout <<
		"Que souhaitez-vous faire?" << std::endl <<
		"1 - Afficher le menu" << std::endl <<
		"2 - Se deconnecter" << std::endl <<
		"3 - Quitter" << std::endl;
	*/
}

std::string demanderTexte(std::string question) {
	std::string temp;
	std::cout << question << std::endl;
	std::getline(std::cin, temp);
	return temp;
}

int demanderNum(std::string question) {
	try {
		std::string temp;
		std::cout << question << std::endl;
		std::getline(std::cin, temp);
		int num = std::stoi(temp);
		return num;
	}
	catch(std::exception e){
		std::cout << "Caractère invalide.\n";
		return -1;
	}
}