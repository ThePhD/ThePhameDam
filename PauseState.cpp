#include "PauseState.h"
#include <Furrovine++/Pipeline/RasterFontLoader.h>

using namespace Fur;

void PauseState::Render( ) {
	String text = "P a u s e";
	Vector2 measure = font.MeasureString( text );
	Fur::Viewport viewport = graphics->GetViewport( );
	nymphbatch->RenderString( font, text, viewport.Center() - ( measure / 2.0f ) );
}

PauseState::PauseState( Fur::Graphics::GraphicsDevice& graphics, Fur::Graphics::NymphBatch& nymphbatch ) 
: font( Fur::Pipeline::RasterFontLoader( graphics )( Fur::Text::RasterFontDescription( "Arial", 24.0f ) ) ), 
nymphbatch( &nymphbatch ), graphics( &graphics ) {
	StopsUpdate = true;
	StopsRender = false;
}
