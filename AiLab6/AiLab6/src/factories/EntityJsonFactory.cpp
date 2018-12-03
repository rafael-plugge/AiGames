#include "stdafx.h"
#include "EntityJsonFactory.h"

#include "components/Location.h"
#include "components/Dimensions.h"
#include "components/RenderRect.h"
#include "components/RenderGrid.h"

app::fact::EntityJsonFactory::EntityJsonFactory(js::json const & j)
	: EntityFactory()
	, m_json(j)
{
}

app::Entity const app::fact::EntityJsonFactory::create()
{
	app::Entity const entity = m_registry.create();

	for (auto itt = m_json.begin(), end = m_json.end(); itt != end; ++itt)
	{
		if (itt.key() == "location")
		{
			auto location = itt->get<comp::Location>();
			m_registry.assign<decltype(location)>(entity, location);
		}
		else if (itt.key() == "dimensions")
		{
			auto dimensions = itt->get<comp::Dimensions>();
			m_registry.assign<decltype(dimensions)>(entity, dimensions);
		}
		else if (itt.key() == "renderRect")
		{
			auto renderRect = itt->get<comp::RenderRect>();
			m_registry.assign<decltype(renderRect)>(entity, renderRect);
		}
		else if (itt.key() == "renderGrid")
		{
			auto renderGrid = itt->get<comp::RenderGrid>();
			m_registry.assign<decltype(renderGrid)>(entity, renderGrid);
		}
	}

	return entity;
}
