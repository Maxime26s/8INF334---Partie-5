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
        return "La poutine " + poutine + " a bien été ajoutée à la commande \n";
    }

    std::string PassagePaiement() {
        commande->setState(new EnCoursDePaiement());
        return "Passage au paiement \n";
    }

    std::string Payer() override {
        return "Veuillez valider votre commande et passer à l'étape du paiement avant de payer \n";
    }

    std::string Recapitulatif() override {
        return "Veuillez finaliser le paiement avant d'avoir accès au récapitulatif \n";
    }

    std::string Retour() {
        return "Pas d'étape précédente \n";
    }

    std::string StateActuel() {
        return "Actuellement en cours de commande \n";
    }
};

class EnCoursDePaiement : public State {
    std::string CommanderAutrePoutine(std::string poutine) override {
        return "Veuillez retourner à l'étape de commande afin de rajouter une poutine à la commande \n";
    }

    std::string PassagePaiement() {
        return "Déjà en cours de paiement \n";
    }

    std::string Payer() override {
        commande->paiementValide();
        commande->setState(new CommandeValidee());
        return "Passage à l'étape de commande validée \n";
    }

    std::string Recapitulatif() override {
        return "Veuillez finaliser le paiement avant d'avoir accès au récapitulatif \n";
    }

    std::string Retour() {
        commande->setState(new EnCoursDeCommande());
        return "Retour à l'étape de commande des poutines \n";
    }

    std::string StateActuel() {
        return "Actuellement en cours de paiement \n";
    }
};

class CommandeValidee : public State {
    std::string CommanderAutrePoutine(std::string poutine) override {
        return "La commande a déjà été passée, il n'est pas possible d'ajouter une poutine \n";
    }

    std::string PassagePaiement() {
        return "La commande a déjà été payée \n";
    }

    std::string Payer() override {
        return "La commande a déjà été payée \n";
    }

    std::string Recapitulatif() override {
        return commande->getRecapitulatif();
    }

    std::string Retour() {
        return "La commande a déjà été finalisée \n";
    }

    std::string StateActuel() {
        return "Commande finalisée (archivée) \n";
    }
};