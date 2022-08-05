#include<SFML/Graphics.hpp>
#include "Window.h"
#include "Game.h"
#include<iostream>
#include<cmath>
Game::Game() : m_window("Chapter 2", sf::Vector2u(800, 700))
{
	m_objectTexture.loadFromFile("Ball1.png");
	m_objects.push_back(Object(m_objectTexture));
	m_objects.push_back(Object(m_objectTexture,sf::Vector2u(500, 300)));
	m_window.GetEventManager()->AddCallback("Move", &Game::MoveSprite, this);
}

Game::~Game(){}

float Game::dist(sf::Vector2f pos1, sf::Vector2f pos2)
{
	float dx = pos1.x - pos2.x;
	float dy = pos1.y - pos2.y;
	
	return std::sqrt((dx * dx) + (dy * dy));

}


void Game::Update() {
	//HandleInput();
	m_window.Update(); // Update window events.
	float radius = this->m_objectTexture.getSize().x;
	for (int i = 0; i < m_objects.size();i++)
	{
		for (int j = i + 1; j < m_objects.size();j++)
		{
			if (dist(m_objects[i].GetPosition(), m_objects[j].GetPosition()) <= radius)
			{
				sf::Vector2f v1 = m_objects[i].GetVelocity();
				sf::Vector2f v2 = m_objects[j].GetVelocity();
				float m1 = 1;
				float m2 = 1;
				sf::Vector2f v1f = (v1 * (m1 - m2) + 2 * m1 * v2) / (m1 + m2);
				sf::Vector2f v2f = (v2 * (m2 - m1) + 2 * m2 * v1) / (m1 + m2);
				m_objects[i].ChangeVelocity(v1f);
				m_objects[j].ChangeVelocity(v2f);
			}
		}
	}

	for (int i = 0; i < m_objects.size(); i++)
	{
		m_objects[i].ApplyForces(m_elapsed);
	}

}

void Game::HandleInput()
{
	sf::Event event;

	while (m_window.GetWindow().pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			m_window.GetWindow().close();

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2u pos = (sf::Vector2u)sf::Mouse::getPosition(m_window.GetWindow());
			m_objects.push_back(Object(m_objectTexture, pos));
		}
	}
}

void Game::Render()
{
	m_window.BeginDraw();
	for (int i = 0; i < m_objects.size(); i++)
	{
		sf::Sprite m = m_objects[i].GetObject();
		m_objects[i].SetTexture();
		m_window.Draw(m);
	}
	m_window.EndDraw();
}

Window* Game::GetWindow()
{
	return &m_window;
}

sf::Time Game::GetElapsed() { return m_elapsed; }

void Game::RestartClock() { m_elapsed = m_clock.restart(); }

void Game::MoveSprite(EventDetails* eventDetails) {
	sf::Vector2u mousePos =
		(sf::Vector2u)m_window.GetEventManager()->GetMousePos(&m_window.GetWindow());
	m_objects.push_back(Object(m_objectTexture, mousePos));
	std::cout << "Moving sprite to: "
		<< mousePos.x << ":"
		<< mousePos.y << std::endl;
}

void Game::CheckCollision()
{
	
}