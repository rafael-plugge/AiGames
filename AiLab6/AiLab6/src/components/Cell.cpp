#include "stdafx.h"
#include "Cell.h"

void app::comp::to_json(js::json & j, app::comp::Cell const & cell)
{
	//constexpr auto T = "T";

	//if (auto const & result = j.find(T); result != j.end()) { (*result) = {}; }
	//else { j.push_back({ T, { } }); }
}

void app::comp::from_json(js::json const & j, app::comp::Cell & cell)
{
	//cell.i = j.at("T").get<decltype(cell.i)>();
}
