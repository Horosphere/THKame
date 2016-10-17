#ifndef _THKAME_CLIENT_RENDER_RENDERBULLET_HPP__
#define _THKAME_CLIENT_RENDER_RENDERBULLET_HPP__

#include "Render.hpp"
#include "../../entities/Bullet.hpp"

namespace thk
{

class RenderBullet: public Render
{
public:
	using Render::Render;

	virtual void draw(Entity const* const) const override;
};

} // namespace thk

#endif // !_THKAME_CLIENT_RENDER_RENDERBULLET_HPP__
