#include "Commande.h"

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
        commande = commande + "+ " + poutine;
}

void Commande::paiementValide()
{
    commande = commande + " Paiement validé";
}
