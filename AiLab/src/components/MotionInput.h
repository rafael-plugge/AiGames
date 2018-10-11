#pragma once

namespace app::comp
{
	struct MotionInput
	{
		bool increaseSpeed = false;
		bool decreaseSpeed = false;
		bool rotateLeft = false;
		bool rotateRight = false;
		bool stop = false;
	};
}