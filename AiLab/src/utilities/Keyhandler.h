#pragma once

namespace app::utils
{
	template<typename KeyType>
	class Keyhandler
	{
	public:
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

	#pragma region Implementation


	template<typename KeyType>
	void app::utils::Keyhandler<KeyType>::updateKey(KeyType const & key, bool const & pressed)
	{
		if (auto itt = _keyNowMap.find(key); itt != _keyNowMap.end())
		{
			auto &[key, value] = *itt;
			value = pressed;
		}
		else
		{
			_keyNowMap.insert({ key, pressed });
			_keyPrevMap.insert({ key, !pressed });
		}
	}

	template<typename KeyType>
	void app::utils::Keyhandler<KeyType>::update()
	{
		_keyPrevMap = _keyNowMap;
	}

	template<typename KeyType>
	bool app::utils::Keyhandler<KeyType>::isKeyDown(KeyType const & key) const
	{
		if (auto const & itt = _keyNowMap.find(key); itt != _keyNowMap.end())
		{
			auto const &[key, value] = *itt;
			return value;
		}
		return false;
	}

	template<typename KeyType>
	bool app::utils::Keyhandler<KeyType>::isKeyUp(KeyType const & key) const
	{
		if (auto const & itt = _keyNowMap.find(key); itt != _keyNowMap.end())
		{
			auto const &[key, value] = *itt;
			return !value;
		}
		return false;
	}

	template<typename KeyType>
	bool app::utils::Keyhandler<KeyType>::isKeyPressed(KeyType const & keyPressed) const
	{
		if (auto const & itt = _keyNowMap.find(keyPressed); itt != _keyNowMap.end())
		{
			auto const &[key, value] = *itt;

			if (auto const & prevItt = _keyPrevMap.find(key); prevItt != _keyPrevMap.end())
			{
				auto const &[prevKey, prevValue] = *prevItt;
				return value && !prevValue;
			}
			return value;
		}
		return false;
	}


	#pragma endregion

}