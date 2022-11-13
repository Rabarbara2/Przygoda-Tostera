#pragma once


#include <iostream>
#include "GameOverState.h"


class Protagonist
{
public:

	int Php = 100;
	int Pshield = 0;
	bool Palive = 1;


	void PTakeDamage(int damage);

	void PUpdate();

private:
	GameDataRef _data;

};
