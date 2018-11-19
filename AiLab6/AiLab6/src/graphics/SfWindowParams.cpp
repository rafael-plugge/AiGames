#include "stdafx.h"
#include "SfWindowParams.h"

const sf::ContextSettings app::gra::SfWindowParams::s_defaultSettings = sf::ContextSettings();

app::gra::SfWindowParams::SfWindowParams(std::string title, std::size_t width, std::size_t height, WindowStyle style, sf::ContextSettings contextSettings)
	: WindowParams(title, width, height, style)
	, contextSettings(contextSettings)
{
}
