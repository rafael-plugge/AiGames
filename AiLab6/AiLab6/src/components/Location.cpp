#include "stdafx.h"
#include "Location.h"

void app::comp::to_json(js::json & j, app::comp::Location const & location)
{
	j["position"] = location.position;
	j["orientation"] = location.orientation;
}

void app::comp::from_json(js::json const & j, app::comp::Location & location)
{
	location.position = j.at("position").get<decltype(location.position)>();
	location.orientation = j.at("orientation").get<decltype(location.orientation)>();
}
