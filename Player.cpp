#include "Player.h"
#include <Furrovine++/Colors.h>

void Player::Render( ) {
	Fur::Vector2 pos = mouse->Position( );
	batch->Render( cane, cane.Bounds( ), Fur::Colors::White, pos, 0.0f, Fur::Vector2::One );

}

void Player::Update( ) {
	
}

Player::Player( Fur::Input::MouseDevice& mousedevice, Fur::Graphics::NymphBatch& nymphbatch ) : mouse( &mousedevice ), batch( &nymphbatch ) {

}
