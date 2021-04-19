#pragma once
#include "State.h"
#include <string>

class Commande
{
private:
    State* state_;
    std::string commande = "";
public:
    Commande(State* state) : state_(nullptr) {
        this->setState(state);
    }
    ~Commande() {
        delete state_;
    }

    void setState(State* state);
    void ajouterPoutine(std::string poutine);
    void paiementValide();

    std::string CommanderAutrePoutine(std::string poutine) {
        return state_->CommanderAutrePoutine(poutine);
    }

    std::string PassagePaiement() {
        return state_->PassagePaiement();
    }

    std::string Payer() {
        return state_->Payer();
    }

    std::string Recapitulatif() {
        return state_->Recapitulatif();
    }

    std::string getRecapitulatif() {
        return  commande + "\n";
    }

    std::string Retour() {
        return state_->Retour();
    }

    std::string StateActuel() {
        return state_->StateActuel();
    }      
};

