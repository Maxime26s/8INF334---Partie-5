#pragma once
#include "Poutine.h"

class ConcretePoutine : public Poutine 
{
public:
	string Creer() override {
		return "Frite + Sauce + Fromage";
	}
};