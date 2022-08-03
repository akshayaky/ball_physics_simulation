#include<iostream>
#include<SFML/Graphics.hpp>
#include "Window.h"
#include "EventManager.h"
#include "Game.h"
Window::Window()
{
	sf::Vector2u l_size = sf::Vector2u(600, 300);
	Setup("Default Title", l_size);
}

Window::Window(const std::string& l_title, const sf::Vector2u& l_size)
{
	Setup(l_title, l_size);
}

Window::~Window() { Destroy(); }

void Window::Setup(const std::string& l_title, const sf::Vector2u& l_size)
{
	m_isFocused = true;
	m_eventManager.AddCallback("Fullscreen_toggle", &Window::ToggleFullscreen, this);
	m_eventManager.AddCallback("Window_close",&Window::Close, this);
	
	m_windowTitle = l_title;
	m_windowSize = l_size;
	m_isFullscreen = false;
	m_isDone = false;
	Create();
}

void Window::Create() 
{
	auto style = (m_isFullscreen ? sf::Style::Fullscreen : sf::Style::Default);
	m_window.create({ m_windowSize.x, m_windowSize.y, 32 }, m_windowTitle, style);
	//m_window.setFramerateLimit(60);
}

void Window::Destroy()
{
	m_window.close();
}

void Window::Update()
{
	sf::Event event;
	while (m_window.pollEvent(event)) {
		if (event.type == sf::Event::LostFocus) {
			m_isFocused = false;
			m_eventManager.SetFocus(false);
		}
		else if (event.type == sf::Event::GainedFocus) {
			m_isFocused = true;
			m_eventManager.SetFocus(true);
		}
		m_eventManager.HandleEvent(event);
	}
	m_eventManager.Update();
}

void Window::ToggleFullscreen(EventDetails* eventDetails)
{
	m_isFullscreen = !m_isFullscreen;
	Destroy();
	Create();

}

void Window::BeginDraw() { m_window.clear(sf::Color::Black); }
void Window::EndDraw() { m_window.display(); }

bool Window::IsDone() { return m_isDone; }
bool Window::IsFullscreen() { return m_isFullscreen; }
sf::Vector2u Window::GetWindowSize() { return m_windowSize; }

void Window::Draw(sf::Drawable& l_drawable)
{
	m_window.draw(l_drawable);
}

sf::RenderWindow& Window::GetWindow()
{
	return m_window;
}

EventManager* Window::GetEventManager()
{
	return &m_eventManager;
}

void Window::Close(EventDetails* eventDetails) { m_isDone = true; }
