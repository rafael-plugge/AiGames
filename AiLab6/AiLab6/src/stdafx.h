﻿// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

// Define what libraries to use
#define _USE_SFML
//#define _USE_SDL


#ifdef _DEBUG

/*********************************/
/**    BEGIN Debug Libraries    **/
/*********************************/
#ifdef _USE_SFML

#pragma comment(lib,"sfml-graphics-d.lib")
#pragma comment(lib,"sfml-audio-d.lib")
#pragma comment(lib,"sfml-system-d.lib")
#pragma comment(lib,"sfml-window-d.lib")
#pragma comment(lib,"sfml-network-d.lib")

#endif // _USE_SFML
/*********************************/
/**     END Debug Libraries     **/
/*********************************/

#else

/*********************************/
/**   BEGIN Release Libraries   **/
/*********************************/
#ifdef _USE_SFML

#pragma comment(lib,"sfml-graphics.lib")
#pragma comment(lib,"sfml-audio.lib")
#pragma comment(lib,"sfml-system.lib")
#pragma comment(lib,"sfml-window.lib")
#pragma comment(lib,"sfml-network.lib")

#endif // _USE_SFML
/*********************************/
/**    END Release Libraries    **/
/*********************************/

#endif

/*********************************/
/** BEGIN Independant Libraries **/
/*********************************/
#ifdef _USE_SDL

#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2main.lib")
#pragma comment(lib, "SDL2test.lib")
#pragma comment(lib, "SDL2_image.lib")

#endif // _USE_SDL
/*********************************/
/**  END Independant Libraries  **/
/*********************************/

// STL Common C libraries
#include <cstddef>
#include <cstdint>

// STL Containers
#include <iterator>
#include <array>
#include <list>
#include <forward_list>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <queue>

// STL Dynamic Memory Management Libraries
#include <new>
#include <scoped_allocator>
#include <memory>
#include <memory_resource>

// STL Error Libraries
#include <exception>
#include <stdexcept>
#include <system_error>

// STL Utility libraries
#include <type_traits>
#include <random>
#include <chrono>
#include <functional>
#include <tuple>
#include <initializer_list>
#include <limits>
#include <variant>
#include <optional>

// STL Input/Output libraries
#include <string>
#include <sstream>
#include <istream>
#include <ostream>
#include <fstream>
#include <iostream>
#include <filesystem>

// STL Multithreading libraries
#include <thread>
#include <atomic>
#include <mutex>
#include <shared_mutex>
#include <future>
#include <condition_variable>

/*********************************/
/**         Includes here       **/
/*********************************/

#ifdef _USE_SFML

// SFML Library
#include <SFML/System.hpp>
#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>

#endif // _USE_SFML

#ifdef _USE_SDL

// SDL Library
#define SDL_MAIN_HANDLED
#include <SDL/SDL.h>

// SDL Image Library
#include <SDL/SDL_image.h>

#endif // _USE_SDL

// Entt Library
#include <Entt/entt.hpp>

// Json Library
#include <Js/json.hpp>

#include "input/Keyhandler.h"
#include "input/MouseHandler.h"

// Global constants
namespace app
{
	namespace inp
	{
		using Keyhandler = KeyHandler<sf::Keyboard::Key>;
		using Mousehandler = MouseHandler<sf::Mouse::Button>;
	}
}

#include "utilities/Console.h"
