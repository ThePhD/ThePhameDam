#pragma once

#include "types.h"
#include "Shepard.h"

struct Sheep {
private:
	Fur::Graphics::NymphBatch* batch;
	Fur::Graphics::Texture2D sheepsprite;

public:
	
	Fur::Vector2 pos;
	Fur::Vector2 vel;
	Fur::Vector2 acc;
	float speed;
	float ticks;
	Shepard* shepard;

	Sheep( Shepard& shep, Fur::Graphics::NymphBatch& nymphbatch );

	void Update( );

	void Render( );

};
