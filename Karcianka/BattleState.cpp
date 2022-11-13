#pragma once

#include <sstream>
#include "BattleState.h"
#include "DEFINITIONS.h"
#include "GameState.h"
#include "MainMenuState.h"
#include <iostream>
#include "EnemyBird.h"
#include "Protagonist.h"

	BattleState::BattleState(GameDataRef data) : _data(data)
	{

	}
	int turn = 1;
	EnemyBird birb;
	Protagonist protagonista;

	void BattleState::Init()
	{
		birb.Ealive = 1;
		birb.hp = 100;
		protagonista.Palive = 1;
		protagonista.Php = 100;



		this->_data->assets.LoadTexture("Background", TLO_BITWY1_FILEPATH);
		this->_data->assets.LoadTexture("Postac", POSTAC_FILEPATH);
		this->_data->assets.LoadTexture("enemy", PTAK_FILEPATH);
		this->_data->assets.LoadTexture("karta", KARTA_FILEPATH);
		this->_data->assets.LoadTexture("endturnbutton", ENDTURNBUTTON_FILEPATH);



		this->_background.setTexture(this->_data->assets.GetTexture("Background"));
		this->_maincharacter.setTexture(this->_data->assets.GetTexture("Postac"));
		this->_enemy.setTexture(this->_data->assets.GetTexture("enemy"));
		this->_karta1.setTexture(this->_data->assets.GetTexture("karta"));
		this->_karta2.setTexture(this->_data->assets.GetTexture("karta"));
		this->_karta3.setTexture(this->_data->assets.GetTexture("karta"));
		this->_karta4.setTexture(this->_data->assets.GetTexture("karta"));
		this->_karta5.setTexture(this->_data->assets.GetTexture("karta"));
		this->_endturnbutton.setTexture(this->_data->assets.GetTexture("endturnbutton"));





		

		this->_maincharacter.setPosition(0, SCREEN_HEIGHT /3 *2 - (this->_maincharacter.getLocalBounds().height));
		this->_enemy.setPosition((SCREEN_WIDTH - (this->_enemy.getGlobalBounds().width)), SCREEN_HEIGHT /3 *2 - (this->_enemy.getLocalBounds().height));
		
		this->_karta1.setPosition(SCREEN_WIDTH/5 - this->_karta1.getLocalBounds().width *1.5, SCREEN_HEIGHT - (this->_karta1.getLocalBounds().height + 1));
		this->_karta2.setPosition(SCREEN_WIDTH / 5 *2 - this->_karta1.getLocalBounds().width * 1.5, SCREEN_HEIGHT - (this->_karta2.getLocalBounds().height + 1));

		this->_karta3.setPosition(SCREEN_WIDTH / 5 *3- this->_karta1.getLocalBounds().width * 1.5, SCREEN_HEIGHT - (this->_karta3.getLocalBounds().height + 1));

		this->_karta4.setPosition(SCREEN_WIDTH / 5 *4- this->_karta1.getLocalBounds().width * 1.5, SCREEN_HEIGHT - (this->_karta4.getLocalBounds().height + 1));

		this->_karta5.setPosition(SCREEN_WIDTH / 5 *5- this->_karta1.getLocalBounds().width * 1.5, SCREEN_HEIGHT - (this->_karta5.getLocalBounds().height + 1));



	}

	void BattleState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}
			if (this->_data->input.IsSpriteClicked(this->_endturnbutton, sf::Mouse::Left, this->_data->window))
			{
				turn = turn * (-1);
				if (turn == 1) // tura gracza
				{
					//gracz robi wziuuum

				}
				if (turn == -1)
				{
					protagonista.PTakeDamage(birb.Atak());

				
					
					turn = turn * (-1);

				}

			}
			if (turn == 1) // jak tura jest moja to mo¿na u¿ywaæ kart
			{
				if (this->_data->input.IsSpriteClicked(this->_karta1, sf::Mouse::Left, this->_data->window))
				{
					birb.TakeDamage(50);

				}
				if (this->_data->input.IsSpriteClicked(this->_karta2, sf::Mouse::Left, this->_data->window))
				{
					protagonista.PTakeDamage(50);
				}
				if (this->_data->input.IsSpriteClicked(this->_karta3, sf::Mouse::Left, this->_data->window))
				{

				
				}
				if (this->_data->input.IsSpriteClicked(this->_karta4, sf::Mouse::Left, this->_data->window))
				{

					this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
				}
				if (this->_data->input.IsSpriteClicked(this->_karta5, sf::Mouse::Left, this->_data->window))
				{

					this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
				}
			}
		}
	}

	void BattleState::Update(float dt)
	{
		


		birb.Update();
		protagonista.PUpdate();
		if (protagonista.Palive == 0)
		{
			this->_data->machine.AddState(StateRef(new GameOverState(_data)), true);
		}
		if (birb.Ealive == 0)
		{
			this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
		}
	}

	void BattleState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_maincharacter);
		this->_data->window.draw(this->_enemy);
		this->_data->window.draw(this->_karta1);
		this->_data->window.draw(this->_karta2);
		this->_data->window.draw(this->_karta3);
		this->_data->window.draw(this->_karta4);
		this->_data->window.draw(this->_karta5);
		this->_data->window.draw(this->_endturnbutton);






		this->_data->window.display();
	}
