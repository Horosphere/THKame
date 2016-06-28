#ifndef _THKAME_CLIENT_MENUMAIN_HPP__
#define _THKAME_CLIENT_MENUMAIN_HPP__

#include "Menu.hpp"

namespace thk
{


/**
 * The main menu. Does not explicitly store a state
 */
class MenuMain final: public Menu
{
public:
	virtual std::size_t getNKeys() const override;
	virtual void exec(Client&) override;
	virtual void escape(Client&) const override;
	virtual void draw(sf::RenderWindow&, ResourceManager&,
			std::size_t selected) const override;

private:
};


} // namespace thk
#endif // !_THKAME_CLIENT_MENUMAIN_HPP__
