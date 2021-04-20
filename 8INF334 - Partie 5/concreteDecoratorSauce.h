#pragma once
#include "Decorator.h"

class concreteDecoratorSauce : public Decorator
{
public:
	concreteDecoratorSauce(Poutine* poutine) : Decorator(poutine) {
		this->poutine = poutine;
	}
	string Creer() override {
		return Decorator::Creer() + " + Extra Sauce";
	}
};

