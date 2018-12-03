#include "stdafx.h"
#include "BackgroundFactory.h"

app::fact::BackgroundFactory::BackgroundFactory(js::json const & j)
	: EntityFactory()
	, m_json(j)
{
}
