#include "stdafx.h"
#include "Player.h"


g::Player::Player(sf::RenderWindow & window)
	: _window{ window }

	, _incrementSpeed(false)
	, _decrementSpeed(false)

	, _renderShape{ {200.0f, 200.0f} }
	, _position{ 1366 / 2.f + 200, 768 / 2.0f }
	, _speed{ 0.0f }
	, _velocityDir{ 0.0f, -1.0f }
{
	_renderShape.setFillColor(sf::Color::Blue);
}

g::Player::~Player()
{
}

void g::Player::update()
{
	if (_incrementSpeed) { _speed += _Acceleration; }
	if (_decrementSpeed) { _speed -= _Acceleration; }

	_position += _velocityDir * _speed;
	g::Collisions::LoopInWindow(_window.getSize(), _position, _renderShape.getSize());
}

void g::Player::render()
{
	_renderShape.setPosition(_position);
	_window.draw(_renderShape);
}

