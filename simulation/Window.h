#pragma once
#include<SFML/Graphics.hpp>
#include "EventManager.h"
class Window {
public:
	Window();
	Window(const std::string& l_title, const sf::Vector2u& l_size);
	~Window();
	void BeginDraw(); // Clear the window.
	void EndDraw(); // Display the changes.
	void Update();
	bool IsDone();
	bool IsFullscreen();
	sf::Vector2u GetWindowSize();
	void ToggleFullscreen(EventDetails*);
	void Draw(sf::Drawable& l_drawable);
	sf::RenderWindow& GetWindow();
	EventManager* GetEventManager();
	
private:
	void Setup(const std::string& l_title,
		const sf::Vector2u& l_size);
	void Destroy();
	void Create();
	void Close(EventDetails*);
	sf::RenderWindow m_window;
	sf::Vector2u m_windowSize;
	std::string m_windowTitle;
	bool m_isDone;
	bool m_isFullscreen;
	bool m_isFocused;
	EventManager m_eventManager;
};

