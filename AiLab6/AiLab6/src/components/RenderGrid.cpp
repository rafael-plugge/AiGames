#include "stdafx.h"
#include "RenderGrid.h"

void app::comp::to_json(js::json & j, app::comp::RenderGrid const & renderGrid)
{
	constexpr auto SIZE = "size";
	constexpr auto STROKE = "stroke";
	constexpr auto COLOR = "color";
	constexpr auto RED = "red";
	constexpr auto GREEN = "green";
	constexpr auto BLUE = "blue";
	constexpr auto ALPHA = "alpha";
	constexpr auto THICKNESS = "thickness";

	if (auto const & result = j.find(SIZE); result != j.end()) { (*result) = renderGrid.size; }
	else { j.push_back({ SIZE, renderGrid.size }); }

	if (auto const & jsonStroke = j.find(STROKE); jsonStroke != j.end())
	{
		auto const & stroke = renderGrid.stroke.value_or(sf::Color::White);
		if (auto const & jsonColor = jsonStroke->find(COLOR); jsonColor != jsonStroke->end()) {
			if (auto const & jsonRed = jsonColor->find(RED); jsonRed != jsonColor->end()) { (*jsonRed) = stroke.r; }
			else { jsonColor->push_back({ RED, stroke.r }); }

			if (auto const & jsonGreen = jsonColor->find(GREEN); jsonGreen != jsonColor->end()) { (*jsonGreen) = stroke.g; }
			else { jsonColor->push_back({ GREEN, stroke.g }); }

			if (auto const & jsonBlue = jsonColor->find(BLUE); jsonBlue != jsonColor->end()) { (*jsonBlue) = stroke.b; }
			else { jsonColor->push_back({ BLUE, stroke.b }); }

			if (auto const & jsonAlpha = jsonColor->find(ALPHA); jsonAlpha != jsonColor->end()) { (*jsonAlpha) = stroke.a; }
			else { jsonColor->push_back({ ALPHA, stroke.a }); }
		}
		else
		{
			jsonStroke->push_back({
				COLOR, {
					{ RED, stroke.r },
					{ GREEN, stroke.g },
					{ BLUE, stroke.b },
					{ ALPHA, stroke.a }
				}
				});
		}
		auto const & thickness = renderGrid.thickness.value_or(static_cast<decltype(renderGrid.thickness)::value_type>(0));
		if (auto const & jsonThickness = jsonStroke->find(THICKNESS); jsonThickness != jsonStroke->end()) { (*jsonThickness) = thickness; }
		else { jsonStroke->push_back({ THICKNESS, thickness }); }
	}
}

void app::comp::from_json(js::json const & j, app::comp::RenderGrid & renderGrid)
{
	renderGrid.size = j.at("size").get<decltype(renderGrid.size)>();
	constexpr auto STROKE = "stroke";
	if (auto const & jsonStroke = j.find(STROKE); jsonStroke != j.end())
	{
		if (auto const & jsonColor = jsonStroke->find("color"); jsonColor != jsonStroke->end())
		{
			auto color = sf::Color();
			color.r = jsonColor->at("red").get<decltype(color.r)>();
			color.g = jsonColor->at("green").get<decltype(color.g)>();
			color.b = jsonColor->at("blue").get<decltype(color.b)>();
			if (auto const & jsonAlpha = jsonColor->find("alpha"); jsonAlpha != jsonColor->end()) { color.a = jsonAlpha->get<decltype(color.a)>(); }
			else { color.a = static_cast<decltype(color.a)>(255u); }
			renderGrid.stroke = std::move(color);
		}
		if (auto const & jsonThickness = jsonStroke->find("thickness"); jsonThickness != jsonStroke->end())
		{
			float thickness = jsonThickness->get<decltype(thickness)>();
			renderGrid.thickness = std::move(thickness);
		}
	}
}
