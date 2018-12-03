#include "stdafx.h"
#include "SfWindow.h"
#ifdef _USE_SFML

const sf::Color app::gra::SfWindow::s_clearColor = app::gra::SfWindow::backgroundColor();

app::gra::SfWindow::SfWindow(app::inp::Keyhandler & keyHandler, app::inp::Mousehandler & mouseHandler)
	: Window()
	, m_sfWindow(std::make_unique<decltype(m_sfWindow)::element_type>())
	, m_keyHandler(keyHandler)
	, m_mouseHandler(mouseHandler)
{
}

app::gra::SfWindow::SfWindow(app::inp::Keyhandler & keyHandler, app::inp::Mousehandler & mouseHandler, SfWindowParams const parameters)
	: Window(parameters)
	, m_contextSettings(parameters.contextSettings)
	, m_sfWindow(std::make_unique<decltype(m_sfWindow)::element_type>(sf::VideoMode(m_size.width, m_size.height), m_title, this->createStyle(m_style), m_contextSettings))
	, m_keyHandler(keyHandler)
	, m_mouseHandler(mouseHandler)
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
		case sf::Event::KeyPressed:
			m_keyHandler.updateKey(e.key.code, true);
			break;
		case sf::Event::KeyReleased:
			m_keyHandler.updateKey(e.key.code, false);
			break;
		case sf::Event::MouseButtonPressed:
			m_mouseHandler.updateButton(e.mouseButton.button, true);
			break;
		case sf::Event::MouseButtonReleased:
			m_mouseHandler.updateButton(e.mouseButton.button, false);
			break;
		case sf::Event::MouseMoved:
			m_mouseHandler.updatePosition(e.mouseMove.x, e.mouseMove.y);
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

void app::gra::SfWindow::draw(sf::Drawable const & drawable, sf::RenderStates const & states)
{
	m_sfWindow->draw(drawable, states);
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
