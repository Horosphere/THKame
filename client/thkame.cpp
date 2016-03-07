#include "thkame.hpp"

#include <iostream>

#include "../server/thkameserver.hpp"

// Ctor and Dtor
thk::THKame::~THKame() {}

void thk::THKame::init()
{
	using namespace Urho3D;
	std::cout << "Initialising THKame" << std::endl;

	SubscribeToEvent(E_TOUCHBEGIN, URHO3D_HANDLER(THKame, onTouchBegin));

	// Initialise window title & icon
	ResourceCache* cache = GetSubsystem<ResourceCache>();
	Graphics* graphics = GetSubsystem<Graphics>();
	Image* icon = cache->GetResource<Image>("textures/r32.png");
	graphics->SetWindowIcon(icon);
	graphics->SetWindowTitle("Touhou Kamichinjiru");

	XMLFile* xmlFile = cache->GetResource<XMLFile>("UI/DefaultStyle.xml");

	// Create console
	Console* console = engine_->CreateConsole();
	console->SetDefaultStyle(xmlFile);
	console->GetBackground()->SetOpacity(0.8f);
	// Create debug HUD.
	DebugHud* debugHud = engine_->CreateDebugHud();
	debugHud->SetDefaultStyle(xmlFile);


	// Subscribe key down event
	SubscribeToEvent(E_KEYDOWN, URHO3D_HANDLER(THKame, onKeyDown));
	// Subscribe scene update event
	SubscribeToEvent(E_SCENEUPDATE, URHO3D_HANDLER(THKame, onSceneUpdate));

}
void thk::THKame::terminate()
{
	engine_->DumpResources(true);
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