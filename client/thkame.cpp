#include "thkame.hpp"

#include <iostream>

#include "../server/thkameserver.hpp"

// Ctor and Dtor
thk::THKame::~THKame() {}

void thk::THKame::init()
{
	std::cout << "Initialising THKame" << std::endl;

}
void thk::THKame::terminate()
{
}

/// Handle key down event to process key controls common to all samples.
void thk::THKame::onKeyDown(Urho3D::StringHash eventType, Urho3D::VariantMap& eventData)
{

}
/// Handle scene update event to control camera's pitch and yaw for all samples.
void thk::THKame::onSceneUpdate(Urho3D::StringHash eventType, Urho3D::VariantMap& eventData)
{

}
/// Handle touch begin event to initialize touch input on desktop platform.
void thk::THKame::onTouchBegin(Urho3D::StringHash eventType, Urho3D::VariantMap& eventData)
{

}
void thk::THKame::update(Urho3D::StringHash eventType, Urho3D::VariantMap& eventData)
{

}