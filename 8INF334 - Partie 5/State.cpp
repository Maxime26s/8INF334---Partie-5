#include "State.h"

void State::set_context(Commande* commande) {
	this->commande = commande;
}

std::string EnCoursDeCommande::CommanderAutrePoutine(std::string poutine) {
	commande->ajouterPoutine(poutine);
    return "La poutine " + poutine + " a bien été ajoutée à la commande \n";
}

std::string EnCoursDeCommande::PassagePaiement() {
	commande->setState(new EnCoursDePaiement());
    return "Passage au paiement \n";
}

std::string EnCoursDeCommande::Payer() {
    return "Veuillez valider votre commande et passer à l'étape du paiement avant de payer \n";
}

std::string EnCoursDeCommande::Recapitulatif() {
    return "Veuillez finaliser le paiement avant d'avoir accès au récapitulatif \n";
}

std::string EnCoursDeCommande::Retour() {
    return "Pas d'étape précédente \n";
}

std::string EnCoursDeCommande::StateActuel() {
    return "Actuellement en cours de commande \n";
}

std::string EnCoursDePaiement::CommanderAutrePoutine(std::string poutine) {
	return "Veuillez retourner à l'étape de commande afin de rajouter une poutine à la commande \n";
}

std::string EnCoursDePaiement::PassagePaiement() {
	return "Déjà en cours de paiement \n";
}

std::string EnCoursDePaiement::Payer() {
	commande->paiementValide();
	commande->setState(new CommandeValidee());
	return "Passage à l'étape de commande validée \n";
}

std::string EnCoursDePaiement::Recapitulatif() {
	return "Veuillez finaliser le paiement avant d'avoir accès au récapitulatif \n";
}

std::string EnCoursDePaiement::Retour() {
	commande->setState(new EnCoursDeCommande());
	return "Retour à l'étape de commande des poutines \n";
}

std::string EnCoursDePaiement::StateActuel() {
	return "Actuellement en cours de paiement \n";
}

std::string CommandeValidee::CommanderAutrePoutine(std::string poutine) {
	return "La commande a déjà été passée, il n'est pas possible d'ajouter une poutine \n";
}

std::string CommandeValidee::PassagePaiement() {
	return "La commande a déjà été payée \n";
}

std::string CommandeValidee::Payer() {
	return "La commande a déjà été payée \n";
}

std::string CommandeValidee::Recapitulatif() {
	return commande->getRecapitulatif();
}

std::string CommandeValidee::Retour() {
	return "La commande a déjà été finalisée \n";
}

std::string CommandeValidee::StateActuel() {
	return "Commande finalisée (archivée) \n";
}