#include "stdafx.h"
#include "Dimensions.h"

void app::comp::to_json(js::json & j, app::comp::Dimensions const & dimensions)
{
	constexpr auto SIZE = "size";
	constexpr auto ORIGIN = "origin";

	if (auto const & result = j.find(SIZE); result != j.end()) { (*result) = dimensions.size; }
	else { j.push_back({ SIZE, dimensions.size }); }

	if (auto const & result = j.find(ORIGIN); result != j.end()) { (*result) = dimensions.origin; }
	else { j.push_back({ ORIGIN, dimensions.origin }); }
}

void app::comp::from_json(js::json const & j, app::comp::Dimensions & dimensions)
{
	constexpr auto ORIGIN = "origin";

	dimensions.size = j.at("size").get<decltype(dimensions.size)>();

	if (auto const & result = j.find(ORIGIN); result != j.end()) { dimensions.origin = result->get<decltype(dimensions.origin)>(); }
	else { dimensions.origin = math::Vector2f{ dimensions.size.x / 2.0f, dimensions.size.y / 2.0f }; }
}
