#pragma once
#include <iostream>
#include "Menu.h"

int mainSingleton();
std::string menuAdmin();
std::string menuClient();
std::string demanderTexte(std::string question);
int demanderNum(std::string question);