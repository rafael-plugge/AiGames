#include "stdafx.h"
#include "Grid.h"

void app::comp::to_json(js::json & j, app::comp::Grid const & grid)
{
	constexpr auto WIDTH = "width";
	constexpr auto HEIGHT = "height";

	if (auto const & jsonWidth = j.find(WIDTH); jsonWidth != j.end()) { (*jsonWidth) = grid.width; }
	else { j.push_back({ WIDTH, grid.width }); }

	if (auto const & jsonHeight = j.find(HEIGHT); jsonHeight != j.end()) { (*jsonHeight) = grid.height; }
	else { j.push_back({ HEIGHT, grid.height }); }
}

void app::comp::from_json(js::json const & j, app::comp::Grid & grid)
{
	if (auto const & jsonWidth = j.find("width"); jsonWidth == j.end()) { grid.width = 50u; }
	else { grid.width = jsonWidth->get<decltype(grid.width)>(); }

	if (auto const & jsonHeight = j.find("height"); jsonHeight == j.end()) { grid.height = 50u; }
	else { grid.height = jsonHeight->get<decltype(grid.height)>(); }

	grid.blocks =
		std::vector<std::vector<lab::Block>>(grid.height, std::vector<lab::Block>(grid.width, lab::Block()));;
}
