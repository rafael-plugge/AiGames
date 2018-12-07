#include "stdafx.h"
#include "GridFactory.h"

// Components
#include "components/Location.h"
#include "components/Dimensions.h"
#include "components/Grid.h"
#include "components/RenderGrid.h"

app::fact::GridFactory::GridFactory(js::json const & json)
	: m_json(json)
{
}

std::optional<app::Entity const> app::fact::GridFactory::create()
{
	app::Entity const entity = m_registry.create();

	auto location = m_json.at("location").get<comp::Location>();
	m_registry.assign<decltype(location)>(entity, std::move(location));

	auto dimensions = m_json.at("dimensions").get<comp::Dimensions>();
	m_registry.assign<decltype(dimensions)>(entity, std::move(dimensions));

	auto grid = m_json.at("grid").get<comp::Grid>();
	m_registry.assign<decltype(grid)>(entity, std::move(grid));

	auto renderGrid = m_json.at("renderGrid").get<comp::RenderGrid>();
	m_registry.assign<decltype(renderGrid)>(entity, std::move(renderGrid));

	return entity;
}
