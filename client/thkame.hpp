#pragma once

#include <Urho3D/Engine/Application.h>
#include <Urho3D/Graphics/Camera.h>
#include <Urho3D/Engine/Console.h>
#include <Urho3D/UI/Cursor.h>
#include <Urho3D/Engine/DebugHud.h>
#include <Urho3D/Engine/Engine.h>
#include <Urho3D/IO/FileSystem.h>
#include <Urho3D/Graphics/Graphics.h>
#include <Urho3D/Input/Input.h>
#include <Urho3D/Input/InputEvents.h>
#include <Urho3D/Graphics/Renderer.h>
#include <Urho3D/Resource/ResourceCache.h>
#include <Urho3D/Scene/Scene.h>
#include <Urho3D/Scene/SceneEvents.h>
#include <Urho3D/UI/Sprite.h>
#include <Urho3D/Graphics/Texture2D.h>
#include <Urho3D/Core/Timer.h>
#include <Urho3D/UI/UI.h>
#include <Urho3D/Resource/XMLFile.h>

namespace thk
{

enum State
{
	MAIN_MENU = 0,
	IN_GAME,
	TRANSITIONING
};

class THKame final: public Urho3D::Application
{
	URHO3D_OBJECT(THKame, Urho3D::Application);

private:

	// Game variables
	bool isPaused;
	// State of Game(main menu, ingame, etc.)
	State state;

public:
	THKame(Urho3D::Context* context);
	~THKame();
	void init();
	void terminate();

	/// Handle key down event to process key controls common to all samples.
	void onKeyDown(Urho3D::StringHash eventType, Urho3D::VariantMap& eventData);
	/// Handle scene update event to control camera's pitch and yaw for all samples.
	void onSceneUpdate(Urho3D::StringHash eventType, Urho3D::VariantMap& eventData);
	/// Handle touch begin event to initialize touch input on desktop platform.
	void onTouchBegin(Urho3D::StringHash eventType, Urho3D::VariantMap& eventData);
	void update(Urho3D::StringHash eventType, Urho3D::VariantMap& eventData);

};

} // namespace thk

// Implementations
inline thk::THKame::THKame(Urho3D::Context* context): Application(context), state(MAIN_MENU) {}
