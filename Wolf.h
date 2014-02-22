#pragma once

#include "types.h"
#include "Shepard.h"
#include <Furrovine++/Circle.h>
#include <Furrovine++/Graphics/NymphBatch.h>
#include <Furrovine++/Graphics/Texture2D.h>

struct Wolf {
private:
	Fur::Graphics::NymphBatch* batch;
	Fur::Graphics::Texture2D wolfsprite;

public:

	Fur::Vector2 pos;
	Fur::Vector2 vel;
	Fur::Vector2 acc;
	float speed;
	
	Wolf( Shepard& shep, Fur::Graphics::NymphBatch& nymphbatch );

	void Update( );

	void Render( );

};
