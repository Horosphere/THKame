#pragma once

#include <Urho3D/Engine/Application.h>

class THKame final: public Urho3D::Application
{
	// URHO3D_OBJECT(THKame, Urho3D::Application)

public:
	THKame(Urho3D::Context* context);

	virtual void Setup() override;
	virtual void Start() override;
	virtual void Stop() override;
};

