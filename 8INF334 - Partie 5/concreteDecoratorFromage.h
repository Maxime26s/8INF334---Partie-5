#pragma once
#include "Decorator.h"

class concreteDecoratorFromage : public Decorator
{
public:
	concreteDecoratorFromage(Poutine* poutine) : Decorator(poutine) {
		this->poutine = poutine;
	}
	string Creer() override {
		return Decorer();
	}
	string Decorer() {
		return Decorator::Creer() + " + Extra Fromage";
	}
};

