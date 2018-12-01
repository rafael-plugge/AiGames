#include "stdafx.h"
#include "GridFactory.h"

// Components
#include "components/Location.h"
#include "components/Dimensions.h"
#include "components/RenderRect.h"

app::fact::GridFactory::GridFactory(js::json const & j)
	: m_json(j)
{
}

app::Entity const app::fact::GridFactory::create()
{
	app::Entity const entity = m_registry.create();

	auto location = m_json.at("location").get<comp::Location>();
	m_registry.assign<decltype(location)>(entity, location);

	auto dimensions = m_json.at("dimensions").get<comp::Dimensions>();
	m_registry.assign<decltype(dimensions)>(entity, dimensions);

	auto renderRect = m_json.at("render").get<comp::RenderRect>();
	m_registry.assign<decltype(renderRect)>(entity, renderRect);

	return entity;
}
