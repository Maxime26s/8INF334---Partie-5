#include "State.h"

void State::set_context(Commande* commande) {
	this->commande = commande;
}

std::string EnCoursDeCommande::CommanderAutrePoutine(std::string poutine) {
	commande->ajouterPoutine(poutine);
    return "La poutine " + poutine + " a bien �t� ajout�e � la commande \n";
}

std::string EnCoursDeCommande::PassagePaiement() {
	commande->setState(new EnCoursDePaiement());
    return "Passage au paiement \n";
}

std::string EnCoursDeCommande::Payer() {
    return "Veuillez valider votre commande et passer � l'�tape du paiement avant de payer \n";
}

std::string EnCoursDeCommande::Recapitulatif() {
    return "Veuillez finaliser le paiement avant d'avoir acc�s au r�capitulatif \n";
}

std::string EnCoursDeCommande::Retour() {
    return "Pas d'�tape pr�c�dente \n";
}

std::string EnCoursDeCommande::StateActuel() {
    return "Actuellement en cours de commande \n";
}

std::string EnCoursDePaiement::CommanderAutrePoutine(std::string poutine) {
	return "Veuillez retourner � l'�tape de commande afin de rajouter une poutine � la commande \n";
}

std::string EnCoursDePaiement::PassagePaiement() {
	return "D�j� en cours de paiement \n";
}

std::string EnCoursDePaiement::Payer() {
	commande->paiementValide();
	commande->setState(new CommandeValidee());
	return "Passage � l'�tape de commande valid�e \n";
}

std::string EnCoursDePaiement::Recapitulatif() {
	return "Veuillez finaliser le paiement avant d'avoir acc�s au r�capitulatif \n";
}

std::string EnCoursDePaiement::Retour() {
	commande->setState(new EnCoursDeCommande());
	return "Retour � l'�tape de commande des poutines \n";
}

std::string EnCoursDePaiement::StateActuel() {
	return "Actuellement en cours de paiement \n";
}

std::string CommandeValidee::CommanderAutrePoutine(std::string poutine) {
	return "La commande a d�j� �t� pass�e, il n'est pas possible d'ajouter une poutine \n";
}

std::string CommandeValidee::PassagePaiement() {
	return "La commande a d�j� �t� pay�e \n";
}

std::string CommandeValidee::Payer() {
	return "La commande a d�j� �t� pay�e \n";
}

std::string CommandeValidee::Recapitulatif() {
	return commande->getRecapitulatif();
}

std::string CommandeValidee::Retour() {
	return "La commande a d�j� �t� finalis�e \n";
}

std::string CommandeValidee::StateActuel() {
	return "Commande finalis�e (archiv�e) \n";
}