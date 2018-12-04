#include "stdafx.h"
#include "CellsFactory.h"

#include "components/Location.h"
#include "components/Dimensions.h"
#include "components/Cell.h"
#include "components/RenderRect.h"

app::fact::CellsFactory::CellsFactory(js::json const & j)
	: EntityFactory()
	, m_json(j)
{
}

std::optional<app::Entity const> app::fact::CellsFactory::create()
{
	constexpr std::size_t width = 50u;
	constexpr std::size_t height = 50u;

	auto cellsLocation = m_json.at("location").get<comp::Location>();
	auto cellsDimensions = m_json.at("dimensions").get<comp::Dimensions>();
	auto cell = m_json.at("cell").get<comp::Cell>();
	auto renderRect = m_json.at("renderRect").get<comp::RenderRect>();

	auto dimensions = comp::Dimensions();
	dimensions.size = {
		cellsDimensions.size.x / static_cast<float>(width)
		, cellsDimensions.size.y / static_cast<float>(height)
	};
	dimensions.origin = { 0.0f, 0.0f };

	for (std::size_t j = 0u; j < height; j++)
	{
		for (std::size_t i = 0u; i < width; i++)
		{
			app::Entity const entity = m_registry.create();

			auto location = comp::Location();
			location.position = {
				cellsLocation.position.x + (dimensions.size.x * i)
				, cellsLocation.position.y + (dimensions.size.y * j)
			};
			location.orientation = 0.0f;
			m_registry.assign<decltype(location)>(entity, std::move(location));

			m_registry.assign<decltype(dimensions)>(entity, dimensions);
			m_registry.assign<decltype(cell)>(entity, cell);
			m_registry.assign<decltype(renderRect)>(entity, renderRect);
		}
	}
	return {};
}
