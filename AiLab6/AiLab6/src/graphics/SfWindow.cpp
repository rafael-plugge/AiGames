﻿#include "stdafx.h"
#include "SfWindow.h"
#ifdef _USE_SFML

const sf::Color app::gra::SfWindow::s_clearColor = app::gra::SfWindow::backgroundColor();

app::gra::SfWindow::SfWindow()
	: Window()
	, m_sfWindow(std::make_unique<decltype(m_sfWindow)::element_type>())
{
}

app::gra::SfWindow::SfWindow(SfWindowParams const parameters)
	: Window(parameters)
	, m_contextSettings(parameters.contextSettings)
	, m_sfWindow(std::make_unique<decltype(m_sfWindow)::element_type>(sf::VideoMode(m_size.width, m_size.height), m_title, this->createStyle(m_style), m_contextSettings))
{
}

app::gra::SfWindow::~SfWindow()
{
}

bool app::gra::SfWindow::create(SfWindowParams const parameters)
{
	try
	{
		m_title = parameters.title;
		m_size = { parameters.width, parameters.height };
		m_style = parameters.style;
		m_contextSettings = parameters.contextSettings;

		m_sfWindow->create(sf::VideoMode(m_size.width, m_size.height), m_title, this->createStyle(m_style), m_contextSettings);
		m_open = true;
		return m_open;
	}
	catch (...)
	{
		m_open = false;
		return false;
	}
}

void app::gra::SfWindow::pollEvents()
{
	sf::Event e;
	while (m_sfWindow->pollEvent(e))
	{
		switch (e.type)
		{
		case sf::Event::Closed:
			m_sfWindow->close();
			m_open = false;
			break;
		default:
			break;
		}
	}
}

void app::gra::SfWindow::clear() const
{
	m_sfWindow->clear(s_clearColor);
}

void app::gra::SfWindow::display() const
{
	m_sfWindow->display();
}

std::uint32_t app::gra::SfWindow::createStyle(WindowStyle const & style) const
{
	std::uint32_t sfStyle = 0u;

	switch (style)
	{
	case WindowStyle::Fullscreen:
		sfStyle = sf::Style::Close | sf::Style::Fullscreen | sf::Style::Titlebar;
		break;
	case WindowStyle::Borderless:
		sfStyle = sf::Style::Close | sf::Style::Titlebar;
		break;
	case WindowStyle::Default:
	default:
		sfStyle = sf::Style::Default;
		break;
	}

	return sfStyle;
}

#endif // _USE_SFML
