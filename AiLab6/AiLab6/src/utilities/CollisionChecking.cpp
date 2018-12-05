#include "stdafx.h"
#include "CollisionChecking.h"

bool app::util::CollisionChecking::pointToRectangle(math::Vector2f const & point, math::Vector2f const & rectPosition, math::Vector2f const & rectSize)
{
	return (rectPosition.x < point.x  && point.x < (rectPosition.x + rectSize.x))
		&& (rectPosition.y < point.y && point.y < (rectPosition.y + rectSize.y));
}
