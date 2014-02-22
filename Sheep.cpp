#include "Sheep.h"

#include <Furrovine++/Graphics/Nymphbatch.h>
#include <Furrovine++/Colors.h>
#include <Furrovine++/Pipeline/TextureLoader.h>

using namespace Fur;
using namespace Fur::Pipeline;
using namespace Fur::Graphics;
using namespace Fur::Input;


void Sheep::Render( ) {
	batch->Render( sheepsprite, sheepsprite.Bounds(), Colors::White, pos );
}

void Sheep::Update( ) {
	const float maxturn = Mathema<float>::Pi;
	const float tickstomax = 40.0f; // Assuming 60 fps at the moment
	Vector2 target = shepard->pos;
	Vector2 direction = pos.direction( target );
	if ( target.distance_to( pos ) > speed ) {
		++ticks;
		// Get a number representing how close we need to be.
		float coefficient = Mathema<float>::MiniMax( ( ticks / tickstomax ), 0.0f, 1.0f );
		// We're not close enough
		vel = direction * ( speed * coefficient );
	}
	else {
		vel *= 0.95f;
		// Decay speed extremely
		ticks = 0.0f;
	}

	pos += vel * ( 1.0f / 60.0f ); // until we get game time in here, assuming 60 FPS
}

Sheep::Sheep( Shepard& shep, Fur::Graphics::NymphBatch& nymphbatch ) : shepard( &shep ), batch( &nymphbatch ) {
	sheepsprite = TextureLoader( nymphbatch.Device( ) )( String( "Sheep.png" ) );
	speed = 5.0f;
	ticks = 0.0f;
}
