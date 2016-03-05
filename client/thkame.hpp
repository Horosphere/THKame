#pragma once

#include <Urho3D/Engine/Application.h>
#include <Urho3D/Core/CoreEvents.h>
#include <Urho3D/Core/ProcessUtils.h>
#include <Urho3D/Input/Input.h>
#include <Urho3D/UI/Font.h>
#include <Urho3D/UI/Text.h>
#include <Urho3D/UI/UI.h>

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

	// Callback functions
	static void callbackKeys(int key, int scancode, int action, int mods);

	static THKame& instance();
};

} // namespace thk

// Implementations
inline thk::THKame::THKame(Urho3D::Context* context): Application(context), state(MAIN_MENU) {}

inline void thk::THKame::callbackKeys(int key, int scancode, int action, int mods)
{

}

inline thk::THKame& thk::THKame::instance()
{
	static THKame thkame;
	return thkame;
}