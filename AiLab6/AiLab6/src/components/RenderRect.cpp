#include "stdafx.h"
#include "RenderRect.h"

#include "visitors/RenderVisitor.h"

void app::comp::to_json(js::json & j, app::comp::RenderRect const & renderRect)
{
	std::visit(app::vis::RenderVisitor{ j }, renderRect.fill);
}

void app::comp::from_json(js::json const & j, app::comp::RenderRect & renderRect)
{
	if (auto const & jsonColor = j.find("color"); jsonColor != j.end())
	{
		auto color = sf::Color();
		color.r = jsonColor->at("red").get<decltype(color.r)>();
		color.g = jsonColor->at("green").get<decltype(color.g)>();
		color.b = jsonColor->at("blue").get<decltype(color.b)>();
		if (auto const & jsonAlpha = jsonColor->find("alpha"); jsonAlpha != jsonColor->end()) { color.a = jsonAlpha->get<decltype(color.a)>(); }
		else { color.a = static_cast<decltype(color.a)>(255u); }
		renderRect.fill = std::move(color);
	}
	else if (auto const & jsonTexture = j.find("texture"); jsonTexture != j.end())
	{
		renderRect.fill = nullptr;
		if (auto const & jsonFilepath = jsonTexture->find("filepath"); jsonFilepath != jsonTexture->end())
		{
			auto texture = std::make_unique<sf::Texture>();
			renderRect.fill =
				texture->loadFromFile(jsonFilepath->get<std::string>()) ? std::move(texture) : nullptr;
		}
	}
}
