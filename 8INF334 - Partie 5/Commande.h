#pragma once
#include <string>

class State;

class Commande
{
private:
    State* state_;
    std::string commande = "";
public:
    Commande(State* state);

    ~Commande();

    void setState(State* state);

    void ajouterPoutine(std::string poutine);

    void paiementValide();

    std::string CommanderAutrePoutine(std::string poutine);

    std::string PassagePaiement();

    std::string Payer();

    std::string Recapitulatif();

    std::string getRecapitulatif();

    std::string Retour();

    std::string StateActuel();

    
};

