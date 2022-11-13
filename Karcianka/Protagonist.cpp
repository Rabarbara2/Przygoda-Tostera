#include "Protagonist.h"



int Php = 100;
int Pshield = 0;
bool Palive = 1;

void Protagonist::PTakeDamage(int damage)
{
	Php = Php - damage;
}

void Protagonist::PUpdate()
{
	if (Php <= 0)
	{
		std::cout << "umra³em jestem bohaterem" << std::endl;
		Palive = 0;
	}
	
}