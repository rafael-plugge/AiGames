#pragma once

namespace g
{
	class Keyhandler
	{
	public:
		using KeyType = sf::Keyboard::Key;
	public:
		Keyhandler() = default;

		void updateKey(KeyType const & key, bool const & pressed);
		void update();

		bool isKeyDown(KeyType const & key) const;
		bool isKeyUp(KeyType const & key) const;
		bool isKeyPressed(KeyType const & key) const;
	private:
		std::map<const KeyType, bool> _keyNowMap;
		std::map<const KeyType, bool> _keyPrevMap;
	};

}