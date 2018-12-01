#include "stdafx.h"
#include "EntityFactory.h"

app::fact::EntityFactory::EntityFactory()
	: m_registry(app::Reg::get())
{
}
