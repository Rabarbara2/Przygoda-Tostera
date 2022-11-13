#pragma once


#include <iostream>



class EnemyBird 
{
public:

	int hp = 100;
	int shield = 0;
	bool Ealive = 1;

	void Atak();

	void TakeDamage(int damage);
	void Update();


};

