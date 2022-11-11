#pragma once

#include <sstream>
#include "BattleState.h"
#include "DEFINITIONS.h"
#include "GameState.h"
#include "MainMenuState.h"
#include <iostream>


	BattleState::BattleState(GameDataRef data) : _data(data)
	{

	}

	void BattleState::Init()
	{
		this->_data->assets.LoadTexture("Background", TLO_BITWY1);
		this->_data->assets.LoadTexture("Postac", POSTAC);
		this->_data->assets.LoadTexture("enemy", PTAK);
		this->_data->assets.LoadTexture("karta", KARTA);


		this->_background.setTexture(this->_data->assets.GetTexture("Background"));
		this->_maincharacter.setTexture(this->_data->assets.GetTexture("Postac"));
		this->_enemy.setTexture(this->_data->assets.GetTexture("enemy"));
		this->_karta1.setTexture(this->_data->assets.GetTexture("karta"));
		this->_karta2.setTexture(this->_data->assets.GetTexture("karta"));
		this->_karta3.setTexture(this->_data->assets.GetTexture("karta"));
		this->_karta4.setTexture(this->_data->assets.GetTexture("karta"));
		this->_karta5.setTexture(this->_data->assets.GetTexture("karta"));


		

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

			if (this->_data->input.IsSpriteClicked(this->_karta1, sf::Mouse::Left, this->_data->window))
			{
				
				this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
			}
			if (this->_data->input.IsSpriteClicked(this->_karta2, sf::Mouse::Left, this->_data->window))
			{

				this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
			}
			if (this->_data->input.IsSpriteClicked(this->_karta3, sf::Mouse::Left, this->_data->window))
			{

				this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
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

	void BattleState::Update(float dt)
	{

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





		this->_data->window.display();
	}
