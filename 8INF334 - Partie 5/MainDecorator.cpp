#include "MainDecorator.h"

void MainDecorator::Menu() {
	cout << "============== Bienvenue dans la commande de poutine ! ==============" << endl;
	cout << endl;
	cout << "1) Commander une poutine" << endl;
	cout << "2) Creer une poutine" << endl;
	cout << endl << "3) Quitter" << endl;
	cout << endl;
	cout << endl << "Entrez le num�ro de l'option d�sir�e: ";
}

void MainDecorator::mainDecorator() {
	int choix;
	Menu();
	cin >> choix;
	cin.ignore();
	while (true) 
	{
		switch (choix) 
		{
		case 1:
			PoutineClassique();
			break;
		case 2:
			PoutineCustom();
			break;
		case 3:
			return;
			break;
		default:
			cout << endl << "Choix invalide." << endl << endl;
			break;
		}
		Menu();
		cin >> choix;
		cin.ignore();
	}
}

void MainDecorator::PoutineClassique() {
	Poutine* classique = new ConcretePoutine;
	cout << "Votre poutine : " << classique->Creer() << endl << endl;
}

void MainDecorator::MenuIngredients() {
	cout << "========================= Choix d'ingr�dients =========================" << endl;
	cout << endl;
	cout << "1) Extra Fromage" << endl;
	cout << "2) Extra Sauce" << endl;
	cout << "3) Extra Saucisse" << endl;

	cout << endl << "4) Terminer" << endl;
	cout << endl;
	cout << endl << "Entrez le num�ro de l'option d�sir�e: ";
}

void MainDecorator::PoutineCustom() {

	Poutine* poutine = new ConcretePoutine;
	int choix;
	MenuIngredients();
	cin >> choix;
	cin.ignore();

	while (true)
	{
		switch (choix) {
		case 1:
			poutine = new concreteDecoratorFromage(poutine);
			cout << endl;
			cout << "Du fromage a �t� ajout�" << endl;
			break;
		case 2:
			poutine = new concreteDecoratorSauce(poutine);
			cout << endl;
			cout << "De la sauce a �t� ajout�e" << endl;
			break;
		case 3:
			poutine = new concreteDecoratorSaucisse(poutine);
			cout << endl;
			cout << "Des saucisses ont �t� ajout�es" << endl;
			break;
		case 4:
			cout << poutine->Creer() << endl << endl;
			return;
			break;
		}
		MenuIngredients();
		cin >> choix;
		cin.ignore();
	}
}