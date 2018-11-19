#include "stdafx.h"
#include "SDLWindow.h"
#ifdef _USE_SDL

app::gra::SDLWindow::SDLWindow()
	: Window()
	, m_sdlWindow(nullptr)
	, m_renderer(nullptr)
{
}

app::gra::SDLWindow::SDLWindow(SDLWindowParams const parameters)
	: Window(parameters)
	, m_sdlWindow(this->createWindow())
	, m_renderer(this->createRenderer())
{
}

app::gra::SDLWindow::~SDLWindow()
{
}

bool app::gra::SDLWindow::create(SDLWindowParams const parameters)
{
	m_title = parameters.title;
	m_size = { parameters.width, parameters.height };
	m_style = parameters.style;

	m_sdlWindow = this->createWindow();
	m_open = (m_sdlWindow != nullptr);
	return m_sdlWindow != nullptr;
}

void app::gra::SDLWindow::pollEvents()
{
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		switch (e.type)
		{
		case SDL_QUIT:
			m_open = false;
			break;
		default:
			break;
		}
	}
}

void app::gra::SDLWindow::clear() const
{
	SDL_RenderClear(m_renderer.get());
}

void app::gra::SDLWindow::display() const
{
	SDL_RenderPresent(m_renderer.get());
}

std::unique_ptr<SDL_Window, app::gra::SDLDeleter> app::gra::SDLWindow::createWindow() const
{
	constexpr struct
	{
		const int x = SDL_WINDOWPOS_CENTERED;
		const int y = SDL_WINDOWPOS_CENTERED;
	}position;
	SDL_Window * window = nullptr;
	std::uint32_t const style = this->createStyle(m_style);

	try
	{
		window = SDL_CreateWindow(m_title.c_str(), position.x, position.y, static_cast<int>(m_size.width), static_cast<int>(m_size.height), style);
		if (window == nullptr)
		{
			auto errorMsg = std::stringstream(std::ios::out);
			errorMsg << "Error creating SDL Window: [" << SDL_GetError() << "]";
			throw std::exception(errorMsg.str().c_str());
		}

		auto pWindow = std::unique_ptr<SDL_Window, SDLDeleter>(nullptr);
		pWindow.reset(window);
		return std::move(pWindow);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return nullptr;
	}
}

std::unique_ptr<SDL_Renderer, app::gra::SDLDeleter> app::gra::SDLWindow::createRenderer() const
{
	if (m_sdlWindow == nullptr) { return nullptr; }

	SDL_Renderer * renderer = nullptr;
	try
	{
		renderer = SDL_CreateRenderer(m_sdlWindow.get(), -1, SDL_RENDERER_ACCELERATED);

		if (renderer == nullptr)
		{
			auto errorMsg = std::stringstream(std::ios::out);
			errorMsg << "Error creating SDL Renderer: [" << SDL_GetError() << "]";
			throw std::exception(errorMsg.str().c_str());
		}

		auto pRenderer = std::unique_ptr<SDL_Renderer, SDLDeleter>(nullptr);
		return std::move(pRenderer);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return nullptr;
	}
}

std::uint32_t const app::gra::SDLWindow::createStyle(WindowStyle const & style) const
{
	std::uint32_t sdlStyle = SDL_WINDOW_OPENGL;
	switch (style)
	{
	case WindowStyle::Fullscreen:
		sdlStyle = sdlStyle | SDL_WINDOW_FULLSCREEN_DESKTOP;
		break;
	case WindowStyle::Borderless:
		sdlStyle = sdlStyle | SDL_WINDOW_BORDERLESS;
		break;
	case WindowStyle::Default:
	default:
		sdlStyle = sdlStyle | SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN;
		break;
	}
	return sdlStyle;
}

#endif // _USE_SDL
