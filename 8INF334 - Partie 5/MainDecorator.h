#pragma once
#include <iostream>
#include "Poutine.h"
#include "ConcretePoutine.h"
#include "concreteDecoratorFromage.h"
#include "concreteDecoratorSauce.h"
#include "concreteDecoratorSaucisse.h"

using namespace std;

class MainDecorator {
public:
	void Menu();
	void mainDecorator();
	void PoutineClassique();
	void PoutineCustom();
	void MenuIngredients();
};