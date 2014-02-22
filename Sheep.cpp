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
	const float tickstomax = 10.0f; // Assuming 60 fps at the moment
	Vector2 target = shepard->pos;
	Vector2 direction = pos.direction( target );
	// Get a number representing how close we need to be.
	if ( target.distance_to( pos ) > speed ) {
		++ticks;
		// We're not close enough
	}
	else {
		// Decay speed a bit
		ticks *= 0.90f;
	}
	float coefficient = Mathema<float>::MiniMax( ( ticks / tickstomax ), 0.0f, 10.0f * ( speed / 90.0f ) );
	Vector2 targetvelocity = direction * ( speed * coefficient );
	vel.lerp( targetvelocity, 0.25f );

	pos += vel * ( 1.0f / 60.0f ); // until we get game time in here, assuming 60 FPS
}

Sheep::Sheep( Shepard& shep, Fur::Graphics::NymphBatch& nymphbatch ) : shepard( &shep ), batch( &nymphbatch ) {
	sheepsprite = TextureLoader( nymphbatch.Device( ) )( String( "Sheep.png" ) );
	speed = 90.0f - 30.0f * static_cast<float>( std::rand( ) / static_cast<float>( RAND_MAX ) );
	ticks = 0.0f;
}
