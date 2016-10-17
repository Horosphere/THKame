#ifndef _THKAME_CLIENT_RENDER_RENDER_HPP__
#define _THKAME_CLIENT_RENDER_RENDER_HPP__

#include "../../entities/Entity.hpp"
#include "../../math/Transform.hpp"
#include "../../client/Resources.hpp"

namespace thk
{

class Render
{
public:
	virtual ~Render() = default;

	Render(sf::RenderWindow* const w, Resources* const r, Transform* toScreen):
		window(w), resources(r), toScreen(toScreen) {}

	virtual void draw(Entity const* const) const = 0;

protected:
	sf::RenderWindow* window;
	Resources* resources;
	Transform* toScreen;
};

} // namespace thk

#endif // !_THKAME_CLIENT_RENDER_RENDER_HPP__
