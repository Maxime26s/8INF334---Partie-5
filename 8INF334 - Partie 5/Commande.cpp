#include "State.h"

Commande::Commande(State* state) : state_(nullptr) {
    this->setState(state);
}

Commande::~Commande() {
    delete state_;
}

void Commande::setState(State* state)
{
    this->state_ = state;
    this->state_->set_context(this);
}

void Commande::ajouterPoutine(std::string poutine)
{
    if (commande == "")
        commande = poutine;
    else
        commande = commande + " + " + poutine;
}

void Commande::paiementValide()
{
    commande = commande + ", Paiement validé";
}

std::string Commande::CommanderAutrePoutine(std::string poutine) {
    return state_->CommanderAutrePoutine(poutine);
}

std::string Commande::PassagePaiement() {
    return state_->PassagePaiement();
}

std::string Commande::Payer() {
    return state_->Payer();
}

std::string Commande::Recapitulatif() {
    return state_->Recapitulatif();
}

std::string Commande::getRecapitulatif() {
    return  commande + "\n";
}

std::string Commande::Retour() {
    return state_->Retour();
}

std::string Commande::StateActuel() {
    return state_->StateActuel();
}
