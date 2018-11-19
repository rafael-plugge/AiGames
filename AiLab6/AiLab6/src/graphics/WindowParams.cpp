#include "stdafx.h"
#include "WindowParams.h"

const std::string app::gra::WindowParams::s_defaultTitle = "Window";

app::gra::WindowParams::WindowParams(std::string title, std::size_t width, std::size_t height, WindowStyle style)
	: title(title)
	, width(width)
	, height(height)
	, style(style)
{
}
