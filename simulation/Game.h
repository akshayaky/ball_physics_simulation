#pragma once
#include "Window.h"
#include "Object.h"
//#include<vector>
class Game
{
public:
	Game();
	~Game();
	void HandleInput();
	void Update();
	void Render();
	Window* GetWindow();
	sf::Time GetElapsed();
	void RestartClock();
	void MoveSprite(EventDetails* eventDetails);
	void CheckCollision();
private:
	//void MoveObject();
	//void ApplyForces();
	//void SetPosition(sf::Vector2u);
	sf::Texture m_objectTexture;
	Window m_window;
	sf::Clock m_clock;
	sf::Time m_elapsed;
	std::vector<Object> m_objects;
	float dist(sf::Vector2f, sf::Vector2f);
	
};
