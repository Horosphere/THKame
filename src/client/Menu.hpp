#ifndef _THKAME_CLIENT_MENU_HPP__
#define _THKAME_CLIENT_MENU_HPP__

#include <cstddef>

class THKameClient;

/**
 * Class for a menu in THKame.
 * Each menu does not store its state showing up in the client.
 */
class Menu
{
	enum Type
	{
		Main,

		max
	};
public:
	virtual ~Menu();

	virtual std::size_t getNKeys() const = 0;
	/**
	 * "Click" on the menu item. The entire state of the client is passed to do
	 * useful work.
	 */
	virtual void exec(THKameClient&) const = 0;
};

class MenuMain final: public Menu
{
public:
	virtual std::size_t getNKeys() const;
	virtual void exec(THKameClient&) const;
};

#endif // !_THKAME_CLIENT_MENU_HPP__
