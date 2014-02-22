#include "JamState.h"

void JamState::Render( ) {
	shepard.Render( );
	for ( std::size_t i = 0; i < sheeps.size( ); ++i ) {
		sheeps[ i ].Render( );
	}
}

void JamState::Update( ) {
	shepard.Update( );
	for ( std::size_t i = 0; i < sheeps.size( ); ++i ) {
		sheeps[ i ].Update( );
	}
}

JamState::JamState( Fur::Graphics::GraphicsDevice& graphics, Fur::Graphics::GraphicsDevice2D& graphics2d, 
	Fur::Text::TextResources& textresources, 
	Fur::Graphics::NymphBatch& nymphbatch,
	Fur::Input::MouseDevice& mousedevice )
: graphics( &graphics ), graphics2d( &graphics2d ), textresources( &textresources ), nymphbatch( &nymphbatch ), mouse( &mousedevice ), shepard( mousedevice, nymphbatch ) {
	sheeps.reserve( 100 );
	for ( std::size_t u = 0; u < 5; ++u ) {
		sheeps.emplace_back( shepard, nymphbatch );
	}
}
