#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "EnemyBird.h"


	class BattleState : public State
	{
	public:
		BattleState(GameDataRef data);

		EnemyBird birb;

		void Init();

		
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _background;

		sf::Sprite _maincharacter;
		sf::Sprite _endturnbutton;

		sf::Sprite _enemy;

		sf::Sprite _karta1;
		sf::Sprite _karta2;
		sf::Sprite _karta3;
		sf::Sprite _karta4;
		sf::Sprite _karta5;

		sf::Sound _music;



	};
