#include "JamState.h"

void JamState::Render( ) {
	player.Render( );
}


void JamState::Update( ) {

}

JamState::JamState( Fur::Graphics::GraphicsDevice& graphics, Fur::Graphics::GraphicsDevice2D& graphics2d, 
	Fur::Text::TextResources& textresources, 
	Fur::Graphics::NymphBatch& nymphbatch,
	Fur::Input::MouseDevice& mousedevice )
: graphics( &graphics ), graphics2d( &graphics2d ), textresources( &textresources ), nymphbatch( &nymphbatch ), mouse( &mousedevice ) {

}
