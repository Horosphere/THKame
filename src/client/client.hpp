#ifndef _THKAME_CLIENT_CLIENT_HPP__
#define _THKAME_CLIENT_CLIENT_HPP__

#include <SFML/Graphics.hpp>

uint8_t menuIncrease(uint8_t selected, uint8_t nButtons);
uint8_t menuDecrease(uint8_t selected, uint8_t nButtons);

inline uint8_t
menuIncrease(uint8_t selected, uint8_t nButtons)
{
	return (selected + 1) % nButtons;
}

inline uint8_t
menuDecrease(uint8_t selected, uint8_t nButtons)
{
	return selected == 0 ? nButtons - 1: selected - 1;
}
#endif // !_THKAME_CLIENT_CLIENT_HPP__
