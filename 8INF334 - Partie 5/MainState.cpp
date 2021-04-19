#include "MainState.h"

int mainState()
{
	Commande* commande = new Commande(new EnCoursDeCommande);
	int choix;
	std::string poutine;
	while (true) {
		choix = demanderNum(choixAction());
		switch (choix)
		{
		case 1:
			poutine = demanderTexte("Quelle est la poutine � ajouter ? \n");
			std::cout << commande->CommanderAutrePoutine(poutine);
			break;
		case 2:
			std::cout << commande->PassagePaiement();
			break;
		case 3:
			std::cout << commande->Payer();
			break;
		case 4:
			std::cout << commande->Recapitulatif();
			break;
		case 5:
			std::cout << commande->Retour();
			break;
		case 6:
			std::cout << commande->StateActuel();
			break;
		case 7:
			return 0;
		default:
			break;
		}
	}
	return 0;
}

std::string choixAction()
{
	return "Que souhaitez-vous faire?\n1 - Ajouter une poutine � la commande\n2 - Passer au paiement\n3 - Payer\n4 -Afficher le r�capitulatif de la commande \n5 - Retour � l'�tape pr�cedente\n6 - Afficher l'�tat actuel de la commande\n7 - Quitter\n";;
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
	catch (std::exception e) {
		std::cout << "Caract�re invalide.\n";
		return -1;
	}
}