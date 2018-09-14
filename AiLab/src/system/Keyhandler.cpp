#include "stdafx.h"
#include "Keyhandler.h"

void g::Keyhandler::updateKey(KeyType const & key, bool const & pressed)
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

void g::Keyhandler::update()
{
	_keyPrevMap = _keyNowMap;
}

bool g::Keyhandler::isKeyDown(KeyType const & key) const
{
	if (auto const & itt = _keyNowMap.find(key); itt != _keyNowMap.end())
	{
		auto const & [key, value] = *itt;
		return value;
	}
	return false;
}

bool g::Keyhandler::isKeyUp(KeyType const & key) const
{
	if (auto const & itt = _keyNowMap.find(key); itt != _keyNowMap.end())
	{
		auto const &[key, value] = *itt;
		return !value;
	}
	return false;
}

bool g::Keyhandler::isKeyPressed(KeyType const & keyPressed) const
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
