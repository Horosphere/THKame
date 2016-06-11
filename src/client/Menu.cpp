#include "Menu.hpp"

#include <iostream>

#include "THKameClient.hpp"

Menu::~Menu()
{
}


std::size_t MenuMain::getNKeys() const
{
	return 2;
}
void MenuMain::exec(THKameClient& client) const
{
	switch(client.state.menuSelected)
	{
	case 0:
		std::cout << "Case 0 selected\n";
		break;
	case 1:
		std::cout << "Case 1 selected\n";
		break;
	}
}


