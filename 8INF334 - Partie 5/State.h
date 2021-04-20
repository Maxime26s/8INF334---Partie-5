#pragma once
#include "Commande.h"

class State {

protected:
    Commande* commande = nullptr;

public:
    virtual ~State() {
    }

    void set_context(Commande* commande);

    virtual std::string CommanderAutrePoutine(std::string poutine) = 0;
    virtual std::string PassagePaiement() = 0;
    virtual std::string Payer() = 0;
    virtual std::string Recapitulatif() = 0;
    virtual std::string Retour() = 0;
    virtual std::string StateActuel() = 0;
};


class EnCoursDeCommande : public State {
    std::string CommanderAutrePoutine(std::string poutine);
    std::string PassagePaiement();
    std::string Payer();
    std::string Recapitulatif();
    std::string Retour();
    std::string StateActuel();
};

class EnCoursDePaiement : public State {
    std::string CommanderAutrePoutine(std::string poutine);
    std::string PassagePaiement();
    std::string Payer();
    std::string Recapitulatif();
    std::string Retour();
    std::string StateActuel();
};

class CommandeValidee : public State {
    std::string CommanderAutrePoutine(std::string poutine);
    std::string PassagePaiement();
    std::string Payer();
    std::string Recapitulatif();
    std::string Retour();
    std::string StateActuel();
};