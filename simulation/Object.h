#pragma once
#include<SFML/Graphics.hpp>
#include "Window.h"
class Object
{
public:
	Object(const sf::Texture&);
	Object(const sf::Texture&, sf::Vector2u);
	~Object();

	void Init();
	sf::Sprite GetObject();
	void SetTexture();

	void ApplyForces(sf::Time m_elapsed);
	void Render(Window& window);
	void SetPosition(sf::Vector2f);
	sf::Vector2f GetPosition();
	void ChangeVelocity(sf::Vector2f);
	sf::Vector2f GetVelocity();
private:
	
	sf::Texture m_objectTexture;
	sf::Vector2i m_increment;
	sf::Sprite m_object;
	

	//physics parameters
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Vector2f acceleration;

};

