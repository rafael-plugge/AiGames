#include "stdafx.h"
#include "BaseFactory.h"

app::fact::BaseFactory::BaseFactory(app::Registry & registry)
	: m_registry(registry)
{
}
