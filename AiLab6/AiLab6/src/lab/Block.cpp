#include "stdafx.h"
#include "Block.h"

bool const & app::lab::Block::getIsClicked() const
{
	return this->m_clicked;
}

sf::Color const & app::lab::Block::getFill() const
{
	return this->m_fill;
}

app::lab::Block & app::lab::Block::setClicked(bool const & clicked)
{
	this->m_clicked = clicked;
	this->m_fill = this->getFillColor(this->m_clicked);
	return *this;
}

app::lab::Block & app::lab::Block::setClicked(bool && clicked)
{
	this->m_clicked = std::move(clicked);
	this->m_fill = this->getFillColor(this->m_clicked);
	return *this;
}

sf::Color app::lab::Block::getFillColor(bool const & clicked)
{
	return (this->m_clicked)
		? sf::Color(240u, 30u, 30u, 255u)
		: sf::Color(30u, 30u, 240u, 255u);;
}
