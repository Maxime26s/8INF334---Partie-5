#pragma once
#include "Poutine.h"

class Decorator : public Poutine
{
protected:
	Poutine* poutine;
public:
	Decorator(Poutine* poutine) {
		this->poutine = poutine;
	}
	string Creer() override {
		return this->poutine->Creer();
	}
};

