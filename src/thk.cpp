#include "thk.hpp"

#include <Urho3D/Engine/Engine.h>
#include <Urho3D/Graphics/Graphics.h>
#include <Urho3D/Input/Input.h>
#include <Urho3D/Resource/ResourceCache.h>
#include <Urho3D/UI/UI.h>

URHO3D_DEFINE_APPLICATION_MAIN(THKame)

THKame::THKame(Urho3D::Context* context): Urho3D::Application(context)
{

}

void THKame::Setup()
{
	engineParameters_["WindowTitle"]="Touhou Kamechinjiru";
	engineParameters_["WindowWidth"]=1024;
	engineParameters_["WindowHeight"]=768;
	engineParameters_["WindowResizable"]=false;
	engineParameters_["FullScreen"]=false; // true by default
	engineParameters_["ResourcePaths"]="resources";

}

void THKame::Start()
{
	using namespace Urho3D;
	ResourceCache* cache = GetSubsystem<ResourceCache>();
	GetSubsystem<UI>()->GetRoot()->SetDefaultStyle(cache->GetResource<XMLFile>("UI/DefaultStyle.xml"));
	
	GetSubsystem<Input>()->SetMouseVisible(true);
}

void THKame::Stop()
{
}
