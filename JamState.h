#pragma once

#include "types.h"
#include "State.h"
#include "Shepard.h"
#include "Sheep.h"
#include "Wolf.h"
#include <Furrovine++/Input/MouseDevice.h>
#include <Furrovine++/Graphics/NymphBatch.h>
#include <Furrovine++/Graphics/GraphicsDevice2D.h>

class JamState : public State {
private:
	Fur::Graphics::GraphicsDevice* graphics;
	Fur::Graphics::GraphicsDevice2D* graphics2d;
	Fur::Text::TextResources* textresources;
	Furrovine::Graphics::NymphBatch* nymphbatch;
	Fur::Input::MouseDevice* mouse;
	Fur::Text::RasterFont font;

	Shepard shepard;
	std::vector<Sheep> sheeps;
	std::vector<Wolf> wolves;
	float grace;

public:

	JamState( Fur::Graphics::GraphicsDevice& graphics, 
		Fur::Graphics::GraphicsDevice2D& graphics2d,
		Fur::Text::TextResources& textresources,
		Fur::Graphics::NymphBatch& nymphbatch,
		Fur::Input::MouseDevice& mouseddevice );

	virtual void Update( ) override;

	virtual void Render( ) override;

};
