#include "Menu.hpp"

#include <iostream>

#include "Client.hpp"

thk::Menu::~Menu()
{
}

void thk::Menu::escape(Client& client) const
{
	delete client.menuStack.top();
	client.menuStack.pop();
}

