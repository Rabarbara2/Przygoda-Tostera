#include "EnemyBird.h"
#include <iostream>






int hp = 100;
int shield = 0;
bool Ealive = 1;
void EnemyBird::Atak()
{

}
void EnemyBird::TakeDamage(int damage)
{
	hp = hp - damage;
}

void EnemyBird::Update()
{
	if (hp <= 0)
	{
		std::cout << "umraem" << std::endl;
		Ealive = 0;
	}

}