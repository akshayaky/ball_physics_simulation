#include "Object.h"
void Object::Init()
{
	//m_objectTexture.loadFromFile("Ball1.png");
	m_object.setTexture(m_objectTexture);
	//sf::Vector2u pos = m_window.GetWindowSize();
	
	this->position.x = 300;
	this->position.y = 30;
	
	
	this->velocity = sf::Vector2f(-100, 0);
	this->acceleration = sf::Vector2f(0, 100);

	m_increment = sf::Vector2i(400, 400);
	gravity = -9.8;
	bounce = 500;
	bounce_temp = bounce;
	reduce = 0.04;
	temp = 10;
	maxIter = 100;
	iter = 0;
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


//void Object::ApplyForces(sf::Time m_elapsed)
//{
//	float d = bounce * 3;
//	sf::Vector2u l_windSize = sf::Vector2u(800, 700);
//	sf::Vector2u l_textSize = m_objectTexture.getSize();
//
//	if ((m_object.getPosition().x >
//		l_windSize.x - l_textSize.x && m_increment.x > 0) ||
//		(m_object.getPosition().x < 0 && m_increment.x < 0))
//	{
//		//m_increment.x = -m_increment.x;
//	}
//	if ((m_object.getPosition().y >
//		l_windSize.y - l_textSize.y && bounce > 0) ||
//		(m_object.getPosition().y < 0 && bounce < 0))
//	{
//		bounce *= -0.9;
//	}
//
//
//
//
//	float fElapsed = m_elapsed.asSeconds();;
//	m_object.setPosition(m_object.getPosition().x, m_object.getPosition().y + d * fElapsed);
//	bounce -= (gravity)*reduce;
//	if (bounce < 3 && bounce > -3)
//	{
//		//bounce = 0;
//	}
//
//	if ((m_object.getPosition().y > l_windSize.y - l_textSize.y))
//	{
//		//printf(" %f \n", bounce);
//		if ((bounce > 0 and bounce_temp > 0) || (bounce < 0 and bounce_temp < 0))
//		{
//			iter++;
//		}
//	}
//	if ((m_object.getPosition().y >
//		l_windSize.y - l_textSize.y && bounce > 0) ||
//		(m_object.getPosition().y < 0 && bounce < 0))
//	{
//		bounce *= -0.5;
//	}
//	reduce += 0.00001;
//
//}

void Object::ApplyForces(sf::Time m_elapsed)
{
	

	sf::Vector2u l_windSize = sf::Vector2u(800, 700);
	sf::Vector2u l_textSize = m_objectTexture.getSize();

	if ((m_object.getPosition().x >
		l_windSize.x - l_textSize.x) || (m_object.getPosition().x < 0 ))
	{
		this->velocity.x *= -1;
		//this->acceleration.x *= 0;
	}
	if ((m_object.getPosition().y >
		l_windSize.y - l_textSize.y) || (m_object.getPosition().y < 0))
	{
		this->velocity.y *= -1;
		//this->acceleration.y *= 0;
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