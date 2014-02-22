#pragma once

#include "types.h"
#include <Furrovine++/Input/MouseDevice.h>
#include <Furrovine++/Graphics/NymphBatch.h>
#include <Furrovine++/Graphics/Texture2D.h>

class Shepard {
private:
	Fur::Input::MouseDevice* mouse;
	Fur::Graphics::NymphBatch* batch;
	Fur::Graphics::Texture2D canesprite;

public:
	Fur::Vector2 pos;

	Shepard( Fur::Input::MouseDevice& mousedevice, Fur::Graphics::NymphBatch& nymphbatch );

	void Update( );

	void Render( );

};
