#pragma once
#include <string>

using namespace std;

class Poutine{
private:
	string nom;
public:
	virtual string Creer() = 0;
};