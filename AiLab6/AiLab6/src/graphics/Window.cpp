#include "stdafx.h"
#include "Window.h"

app::gra::Window::Window()
	: m_open(false)
	, m_size{ 800u, 600u }
	, m_title("Window")
	, m_style(WindowStyle::Default)
{
}

app::gra::Window::Window(WindowParams const parameters)
	: m_open(true)
	, m_size{ parameters.width, parameters.height }
	, m_title(parameters.title)
	, m_style(parameters.style)
{
}

app::gra::Window::~Window()
{
}
