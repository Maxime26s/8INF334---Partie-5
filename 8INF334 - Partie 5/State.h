#pragma once
#include "Commande.h"
#include <string>

class State {

protected:
    Commande* commande;

public:
    virtual ~State() {
    }

    void set_context(Commande* commande) {
        this->commande = commande;
    }

    virtual std::string CommanderAutrePoutine(std::string poutine) = 0;
    virtual std::string PassagePaiement() = 0;
    virtual std::string Payer() = 0;
    virtual std::string Recapitulatif() = 0;
    virtual std::string Retour() = 0;
    virtual std::string StateActuel() = 0;
};


class EnCoursDeCommande : public State {
public:
    std::string CommanderAutrePoutine(std::string poutine) override {
        commande->ajouterPoutine(poutine);
        return "La poutine " + poutine + " a bien �t� ajout�e � la commande \n";
    }

    std::string PassagePaiement() {
        commande->setState(new EnCoursDePaiement());
        return "Passage au paiement \n";
    }

    std::string Payer() override {
        return "Veuillez valider votre commande et passer � l'�tape du paiement avant de payer \n";
    }

    std::string Recapitulatif() override {
        return "Veuillez finaliser le paiement avant d'avoir acc�s au r�capitulatif \n";
    }

    std::string Retour() {
        return "Pas d'�tape pr�c�dente \n";
    }

    std::string StateActuel() {
        return "Actuellement en cours de commande \n";
    }
};

class EnCoursDePaiement : public State {
    std::string CommanderAutrePoutine(std::string poutine) override {
        return "Veuillez retourner � l'�tape de commande afin de rajouter une poutine � la commande \n";
    }

    std::string PassagePaiement() {
        return "D�j� en cours de paiement \n";
    }

    std::string Payer() override {
        commande->paiementValide();
        commande->setState(new CommandeValidee());
        return "Passage � l'�tape de commande valid�e \n";
    }

    std::string Recapitulatif() override {
        return "Veuillez finaliser le paiement avant d'avoir acc�s au r�capitulatif \n";
    }

    std::string Retour() {
        commande->setState(new EnCoursDeCommande());
        return "Retour � l'�tape de commande des poutines \n";
    }

    std::string StateActuel() {
        return "Actuellement en cours de paiement \n";
    }
};

class CommandeValidee : public State {
    std::string CommanderAutrePoutine(std::string poutine) override {
        return "La commande a d�j� �t� pass�e, il n'est pas possible d'ajouter une poutine \n";
    }

    std::string PassagePaiement() {
        return "La commande a d�j� �t� pay�e \n";
    }

    std::string Payer() override {
        return "La commande a d�j� �t� pay�e \n";
    }

    std::string Recapitulatif() override {
        return commande->getRecapitulatif();
    }

    std::string Retour() {
        return "La commande a d�j� �t� finalis�e \n";
    }

    std::string StateActuel() {
        return "Commande finalis�e (archiv�e) \n";
    }
};