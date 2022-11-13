#pragma once


#include <iostream>



class EnemyBird 
{
public:

	int hp = 100;
	int shield = 0;
	bool Ealive = 1;

	int Atak();

	void TakeDamage(int damage);
	void Update();


};

