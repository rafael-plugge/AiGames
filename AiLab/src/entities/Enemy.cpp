#include "stdafx.h"
#include "Enemy.h"

std::default_random_engine g::Enemy::_randomGeneratorEngine = std::default_random_engine();
std::uniform_real_distribution<float> g::Enemy::_randomDistribution = std::uniform_real_distribution<float>(-(g::pi<float>() / 2.0f), g::pi<float>() / 2.0f);

g::Enemy::Enemy(sf::RenderWindow & window)
	: _window(window)
	, _renderShape{ {150.0f, 150.0f} }
	, _position{ 1366 / 2.0f - 200, 768 / 2.0f }
	, _speed{ 10.f }
	, _velocityDir{ 0.0f, -1.0f }
{
	_renderShape.setFillColor(sf::Color::Red);
	this->generateNewDirection();
}

void g::Enemy::update()
{
	_position += _velocityDir * _speed;
	g::Collisions::LoopInWindow(_window.getSize(), _position, _renderShape.getSize());
}

void g::Enemy::render()
{
	_renderShape.setPosition(_position);
	_window.draw(_renderShape);
}

void g::Enemy::generateNewDirection()
{
	const float randomAngleInRadians = this->randomAngle();
	_velocityDir = { std::cosf(randomAngleInRadians), std::sinf(randomAngleInRadians) };
}

const float g::Enemy::randomAngle()
{
	return _randomDistribution(_randomGeneratorEngine);
}
