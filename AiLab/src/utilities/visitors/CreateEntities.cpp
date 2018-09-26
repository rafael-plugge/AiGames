#include "stdafx.h"
#include "CreateEntities.h"

void app::visitor::CreateEntities::operator()(app::fact::EnemyFactory & enemyFactory)
{
	enemyFactory.create();
}

void app::visitor::CreateEntities::operator()(app::fact::PlayerFactory & playerFactory)
{
	playerFactory.create();
}

void app::visitor::CreateEntities::operator()(app::fact::BaseFactory & baseFactory)
{
	baseFactory.create();
}
