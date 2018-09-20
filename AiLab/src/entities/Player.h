#pragma once

namespace app::ent
{
	class Player
	{
	public:
		Player() = delete;
		Player(Player const &) = delete;
		Player(Player &&) = delete;

		static uint32_t create(app::Registry & registry);
	};
}
