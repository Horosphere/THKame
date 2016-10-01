#ifndef _THKAME_MATH_TRANSFORM_HPP__
#define _THKAME_MATH_TRANSFORM_HPP__

#include "numbers.hpp"

namespace thk
{

/**
 * Transform a number from scene coordinate to screen coordinate
 * Scene coordinate: [-1, 1] * [-1, 1]
 * Screen coordinate: [0, 1280] * [0, 960]
 */
class Transform
{
public:
	Transform() noexcept;

	int trX(real x) const
	{
		return x * scaleX + translateX;
	}
	int trY(real y) const
	{
		return y * scaleY + translateY;
	}
	int trLX(real u) const
	{
		return u * scaleX;
	}
	int trLY(real v) const
	{
		return v * scaleY;
	}

private:
	real scaleX, scaleY;
	real translateX, translateY;
};


// Implementations

inline Transform::Transform() noexcept:
	scaleX(640), scaleY(480), translateX(640), translateY(480)
{
}

} // namespace thk

#endif // !_THKAME_MATH_TRANSFORM_HPP__
