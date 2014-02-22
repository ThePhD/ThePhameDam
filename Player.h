#pragma once

#include "types.h"
#include <Furrovine++/Input/MouseDevice.h>
#include <Furrovine++/Graphics/NymphBatch.h>
#include <Furrovine++/Graphics/Texture2D.h>

class Player {

	Fur::Input::MouseDevice* mouse;
	Fur::Graphics::NymphBatch* batch;

	Player( Fur::Input::MouseDevice& mousedevice, Fur::Graphics::NymphBatch& nymphbatch );

	void Update( );

	void Render( );

};
