#include "Wolf.h"

#include <random>

#include <Furrovine++/Graphics/Nymphbatch.h>
#include <Furrovine++/Colors.h>
#include <Furrovine++/Pipeline/TextureLoader.h>

using namespace Fur;
using namespace Fur::Pipeline;
using namespace Fur::Graphics;


void Wolf::Render( ) {
	batch->Render( wolfsprite, wolfsprite.Bounds( ), Colors::White, pos );
}

void Wolf::Update( ) {
	
	pos += vel * speed * ( 1.0f / 60.0f ); // until we get game time in here, assuming 60 FPS

}

Wolf::Wolf( Shepard& shep, Fur::Graphics::NymphBatch& nymphbatch ) : batch( &nymphbatch ) {
	wolfsprite = TextureLoader( nymphbatch.Device( ) )( String( "Wolf.png" ) );
	std::random_device rd;
	std::mt19937 gen( rd( ) ); 
	std::uniform_int_distribution<> dist( 0, 1 );
	bool horizontal = static_cast<bool>( dist( gen ) );
	bool opposite = static_cast<bool>( dist( gen ) );
	speed = 500.0f - 130.0f * static_cast<float>( std::rand( ) / static_cast<float>( RAND_MAX ) );
	if ( horizontal ) {
		pos.x = opposite ? 600.0f : 0.0f;
		pos.y = shep.pos.y;
		vel.x = opposite ? -1.0f : 1.0f;
		vel.y = 0.0f;
	}
	else {
		pos.y = opposite ? 600.0f : 0.0f;
		pos.x = shep.pos.x;
		vel.y = opposite ? -1.0f : 1.0f;
		vel.x = 0.0f;
	}
}
