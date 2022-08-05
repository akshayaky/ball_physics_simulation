#include "Object.h"
void Object::Init()
{
	m_object.setTexture(m_objectTexture);
	
	this->position.x = 300;
	this->position.y = 30;	
	
	this->velocity = sf::Vector2f(-100, 0);
	this->acceleration = sf::Vector2f(0, 100);
}
Object::Object(const sf::Texture& m_texture)
{
	m_objectTexture = m_texture;
	Init();
	m_object.setPosition(this->position.x, this->position.y);
}

Object::Object(const sf::Texture& m_texture, sf::Vector2u pos)
{
	m_objectTexture = m_texture;
	Init();
	this->position = (sf::Vector2f)pos;
	m_object.setPosition(this->position.x, this->position.y);
}

Object::~Object(){ }

sf::Sprite Object::GetObject(){ return m_object; }


void Object::ApplyForces(sf::Time m_elapsed)
{
	

	sf::Vector2u l_windSize = sf::Vector2u(800, 700);
	sf::Vector2u l_textSize = m_objectTexture.getSize();

	if ((m_object.getPosition().x >
		l_windSize.x - l_textSize.x) || (m_object.getPosition().x < 0 ))
	{
		this->velocity.x *= -1;
	}
	if ((m_object.getPosition().y >
		l_windSize.y - l_textSize.y) || (m_object.getPosition().y < 0))
	{
		this->velocity.y *= -1;
	}

	float fElapsed = m_elapsed.asSeconds();
	this->velocity += this->acceleration * fElapsed;
	this->position += this->velocity * fElapsed;
	
	this->SetPosition(this->position);
}

void Object::SetTexture(){ m_object.setTexture(m_objectTexture); }

void Object::Render(Window& m_window)
{
	
	m_window.BeginDraw();
	m_window.Draw(m_object);
	m_window.EndDraw();
}

void Object::SetPosition(sf::Vector2f pos)
{
	m_object.setPosition(pos.x, pos.y);
}

sf::Vector2f Object::GetPosition()
{
	return m_object.getPosition();
}

sf::Vector2f Object::GetVelocity()
{
	return this->velocity;
}

void Object::ChangeVelocity(sf::Vector2f vel)
{
	this->velocity = vel;
}