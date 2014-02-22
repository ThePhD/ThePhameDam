#include "Shepard.h"
#include <Furrovine++/Colors.h>
#include <Furrovine++/Pipeline/TextureLoader.h>

using namespace Fur;
using namespace Fur::Pipeline;
using namespace Fur::Graphics;
using namespace Fur::Input;

void Shepard::Render( ) {
	batch->Render( canesprite, canesprite.Bounds( ), Fur::Colors::Red, pos, 0.0f, Vector2::One );

}

void Shepard::Update( ) {
	pos = mouse->Position( );
}

Shepard::Shepard( Fur::Input::MouseDevice& mousedevice, Fur::Graphics::NymphBatch& nymphbatch ) : mouse( &mousedevice ), batch( &nymphbatch ) {
	canesprite = TextureLoader( nymphbatch.Device( ) )( String( "Shepard.png" ) );
}