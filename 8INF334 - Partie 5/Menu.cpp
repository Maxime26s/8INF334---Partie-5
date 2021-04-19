#include "Menu.h"

Menu::Menu() {
    poutines = std::vector<std::string>();
}

std::string Menu::ajouterPoutine(std::string nom)
{
    if (chercherPoutine(nom) != -1)
        return "La poutine existe déjà.\n";

    poutines.push_back(nom);
    return "La poutine a été ajoutée.\n";
}

std::string Menu::retirerPoutine(int index)
{
    if (index < 1 || index > poutines.size())
        return "La poutine n'a pas été trouvée.\n";

    poutines.erase(poutines.begin()+ index -1);
    return "La poutine #" + std::to_string(index) + " a été effacée\n";
}

std::string Menu::retirerPoutine(std::string nom)
{
    int index = chercherPoutine(nom);
    if (index == -1)
        return "La poutine n'a pas été trouvée.\n";

    poutines.erase(poutines.begin() + index);
    return "\"#" + std::to_string(index + 1) + " - " + nom + "\" a été effacé(e)\n";
}

std::string Menu::modifierPoutine(std::string newNom, int index)
{
    if (index < 1 || index > poutines.size())
        return "La poutine n'a pas été trouvée.\n";

    poutines[index - 1] = newNom;
    return "La poutine #" + std::to_string(index) + " a été renomée sous le nom \"" + newNom + "\"\n";
}

std::string Menu::modifierPoutine(std::string newNom, std::string nom)
{
    int index = chercherPoutine(nom);
    if (index == -1)
        return "La poutine n'a pas été trouvée.\n";

    poutines.erase(poutines.begin() + index);
    return "\"#" + std::to_string(index + 1) + " - " + nom + "\" a été renomé(e) sous le nom \"" + newNom + "\"\n";
}

std::string Menu::deplacerPoutine(int newNum, int index)
{
    if (index < 1 || index > poutines.size())
        return "La poutine n'a pas été trouvée.\n";
    if (newNum > poutines.size())
        return "Le nouveau numéro n'existe pas.\n";

    std::string poutine = poutines[index -1];
    retirerPoutine(index);
    if (newNum == poutines.size() + 1)
        ajouterPoutine(poutine);
    else
        poutines.insert(poutines.begin() + newNum-1, poutine);
    
    return "La poutine #" + std::to_string(index) + " a été déplacée au #" + std::to_string(newNum) + "\n";
}

std::string Menu::deplacerPoutine(int newNum, std::string nom)
{
    int index = chercherPoutine(nom);
    if (index == -1)
        return "La poutine n'a pas été trouvée.\n";

    std::string poutine = poutines[index];
    retirerPoutine(index+1);
    poutines.insert(poutines.begin() + newNum, poutine);

    return "La poutine #" + std::to_string(index+1) + " a été déplacée au #" + std::to_string(newNum) + "\n";
}

int Menu::chercherPoutine(std::string nom)
{
    for (int i = 0; i < poutines.size(); i++)
        if (poutines[i] == nom)
            return i;

    return -1;
}

std::string Menu::obtenirMenu()
{
    std::string menu = "";
    if (poutines.size() == 0)
        return "Le menu est vide.\n";

    for (int i = 0; i < poutines.size(); i++) {
        menu += "#" + std::to_string(i + 1) + " - " + poutines[i] + "\n";
    }
    return menu;
}
