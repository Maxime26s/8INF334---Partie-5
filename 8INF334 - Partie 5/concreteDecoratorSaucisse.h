#pragma once
#include "Decorator.h"

class concreteDecoratorSaucisse : public Decorator
{
public:
	concreteDecoratorSaucisse(Poutine* poutine) : Decorator(poutine) {
		this->poutine = poutine;
	}
	string Creer() override {
		return Decorer();
	}
	string Decorer() {
		return Decorator::Creer() + " + Extra Saucisses";
	}
};

