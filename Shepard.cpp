#include "Shepard.h"
#include <Furrovine++/Colors.h>
#include <Furrovine++/Pipeline/TextureLoader.h>
#include <Furrovine++/intersect2.h>

using namespace Fur;
using namespace Fur::Pipeline;
using namespace Fur::Graphics;
using namespace Fur::Input;

void Shepard::Render( ) {
	batch->Render( canesprite, canesprite.Bounds( ), Fur::Colors::White, pos, 0.0f, Vector2::One );
}

void Shepard::Update( ) {
	Fur::Rectanglef bounds( 0, 0, 800, 600 ); // all the assumptions~
	pos = mouse->Position( );
	//pos = max( min( pos, bounds.max ), bounds.min );
}

Shepard::Shepard( Fur::Input::MouseDevice& mousedevice, Fur::Graphics::NymphBatch& nymphbatch ) : mouse( &mousedevice ), batch( &nymphbatch ) {
	canesprite = TextureLoader( nymphbatch.Device( ) )( String( "Shepard.png" ) );
}