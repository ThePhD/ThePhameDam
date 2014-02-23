#include "JamState.h"
#include <Furrovine++/Pipeline/RasterFontLoader.h>
#include <Furrovine++/intersect2.h>
#include <random>

using namespace Fur;

void JamState::Render( ) {
	shepard.Render( );
	for ( std::size_t i = 0; i < wolves.size( ); ++i ) {
		wolves[ i ].Render( );
	}
	for ( std::size_t i = 0; i < sheeps.size( ); ++i ) {
		sheeps[ i ].Render( );
	}
	if ( sheeps.size( ) > 0 )
		return;
	String text = "Game Over";
	Vector2 measure = font.MeasureString( text );
	Fur::Viewport viewport = graphics->GetViewport( );
	nymphbatch->RenderString( font, text, viewport.Center( ) - ( measure / 2.0f ) );
}

void JamState::Update( ) {
	Fur::Rectanglef bounds( -100, -100, 900, 700 ); // all the assumptions~

	std::random_device rd;
	std::mt19937 gen( rd( ) );
	std::uniform_int_distribution<> dist( 0, 10 );
	
	grace -= 1;

	if ( grace < 0 && dist( gen ) == 0 ) {
		wolves.emplace_back( shepard, *nymphbatch );
	}

	shepard.Update( );
	for ( std::size_t s = 0; s < sheeps.size( ); ++s ) {
		Sheep& sheep = sheeps[ s ];
		sheep.Update( );
	}
	for ( std::size_t w = 0; w < wolves.size( ); ++w ) {
		Wolf& wolf = wolves[ w ];
		wolf.Update( );
		if ( !Fur::intersect( bounds, wolf.pos ) ) {
			wolves.erase( wolves.begin( ) + w );
			--w;
			continue;
		}
	}
	for ( std::size_t s = 0; s < sheeps.size( ); ++s ) {
		Sheep& sheep = sheeps[ s ];
		Fur::Circle sheeparea;
		sheeparea.radius = 5;
		sheeparea.origin = sheep.pos;
		sheep.Update( );
		for ( std::size_t w = 0; w < wolves.size( ); ++w ) {
			Wolf& wolf = wolves[ w ];
			Fur::Circle wolfarea;
			wolfarea.radius = 10;
			wolfarea.origin = wolf.pos;
			if ( Fur::intersect( wolfarea, sheeparea ) ) {
				sheeps.erase( sheeps.begin( ) + s );
				--s;
				break;
			}
		}
	}

}

JamState::JamState( Fur::Graphics::GraphicsDevice& graphics, Fur::Graphics::GraphicsDevice2D& graphics2d, 
	Fur::Text::TextResources& textresources, 
	Fur::Graphics::NymphBatch& nymphbatch,
	Fur::Input::MouseDevice& mousedevice )
: graphics( &graphics ), graphics2d( &graphics2d ), 
textresources( &textresources ), nymphbatch( &nymphbatch ), 
mouse( &mousedevice ), shepard( mousedevice, nymphbatch ),
font( Fur::Pipeline::RasterFontLoader( graphics )( Fur::Text::RasterFontDescription( "Arial", 24.0f ) ) ) {
	sheeps.reserve( 100 );
	for ( std::size_t u = 0; u < 10; ++u ) {
		sheeps.emplace_back( shepard, nymphbatch );
	}
	grace = 120;
}
