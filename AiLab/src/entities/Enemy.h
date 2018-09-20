#pragma once

namespace app::ent
{
	class Enemy
	{
	public:
		Enemy() = delete;
		Enemy(Enemy const &) = delete;
		Enemy(Enemy &&) = delete;

		static uint32_t create(app::Registry & registry);
	};
}