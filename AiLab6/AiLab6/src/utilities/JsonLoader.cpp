#include "stdafx.h"
#include "JsonLoader.h"

js::json app::util::JsonLoader::load(std::string const & filepath)
{
	auto filestream = std::ifstream(filepath);
	auto j = js::json();
	filestream >> j;
	return std::move(j);
}
