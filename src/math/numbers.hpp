#ifndef _THKAME_MATH_NUMBERS_HPP__
#define _THKAME_MATH_NUMBERS_HPP__

namespace thk
{

unsigned circularIncrease(unsigned, unsigned period);
unsigned circularDecrease(unsigned, unsigned period);


// Implementations

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
