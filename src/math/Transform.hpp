#ifndef _THKAME_MATH_TRANSFORM_HPP__
#define _THKAME_MATH_TRANSFORM_HPP__

#include "numbers.hpp"

namespace thk
{

/**
 * Transform a number from scene coordinate to screen coordinate
 * Scene coordinate: [0, 1] * [0, 1]
 * Screen coordinate: [0, 1280] * [0, 960]
 */
class Transform
{
public:
	Transform() noexcept;

	real trX(real x) const
	{
		return x * scaleX + translateX;
	}
	real trY(real y) const
	{
		return y * scaleY + translateY;
	}
	real trLX(real u) const
	{
		return u * scaleX;
	}
	real trLY(real v) const
	{
		return v * scaleY;
	}

private:
	real scaleX, scaleY;
	real translateX, translateY;
};


// Implementations

inline Transform::Transform() noexcept:
	scaleX(1280), scaleY(960), translateX(0), translateY(0)
{
}

} // namespace thk

#endif // !_THKAME_MATH_TRANSFORM_HPP__
