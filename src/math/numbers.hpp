#ifndef _THKAME_MATH_NUMBERS_HPP__
#define _THKAME_MATH_NUMBERS_HPP__

namespace thk
{

typedef float real;

real clamp(real, real min, real max) noexcept;

/**
 * @brief Increase a number and wrap into the interval [0, period - 1]
 */
unsigned circularIncrease(unsigned val, unsigned period);
/**
 * @brief Decrease a number and wrap into the interval [0, period - 1]
 */
unsigned circularDecrease(unsigned val, unsigned period);


// Implementations

inline real clamp(real v, real min, real max) noexcept
{
	return v < min ? min :
	       v > max ? max : v;
}
inline unsigned
circularIncrease(unsigned i, unsigned period)
{
	return i < period - 1 ? i + 1 : 0;
}
inline unsigned
circularDecrease(unsigned i, unsigned period)
{
	return i == 0 ? period - 1 : i - 1;
}

} // namespace thk

#endif // !_THKAME_MATH_NUMBERS_HPP__
