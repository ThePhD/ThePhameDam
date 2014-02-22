#include <ctime>
#include "types.h"
#include "StateStack.h"
#include "JamState.h"
#include "PauseState.h"

#include <Furrovine++/FurrovineGame.h>
#include <Furrovine++/Text/RasterFont.h>
#include <Furrovine++/Graphics/Window.h>
#include <Furrovine++/Graphics/BlendState.h>
#include <Furrovine++/Graphics/NymphBatch.h>
#include <Furrovine++/Text/TextResources.h>
#include <Furrovine++/Pipeline/ImageLoader.h>
#include <Furrovine++/Pipeline/TextureLoader.h>
#include <Furrovine++/Input/MouseDevice.h>
#include <Furrovine++/Input/KeyboardDevice.h>

using namespace Furrovine;
using namespace Furrovine::IO;
using namespace Furrovine::Graphics;
using namespace Furrovine::Text;
using namespace Furrovine::Pipeline;
using namespace Furrovine::Input;

class PhameDam : public FurrovineGame {
private:
	WindowDriver windowdriver;
	Window window;
	GraphicsDevice graphics;
	GraphicsDevice2D graphics2d;
	TextResources textresources;
	NymphBatch batch;
	MouseDevice mousedevice;
	KeyboardDevice keyboarddevice;
	MessageQueue messages;
	StateStack states;
	JamState jamstate;
	PauseState pausestate;
	Texture2D texture;
	Image2D image;
	
public:

	PhameDam( ) : FurrovineGame( ),
	windowdriver( ),
	window( windowdriver, WindowDescription( "~ The Phame Dam ~" ) ),
	graphics( window ),
	graphics2d( graphics ),
	batch( graphics ),
	jamstate( graphics, graphics2d, textresources, batch, mousedevice ),
	pausestate( graphics, batch ) {
		WindowService = window;
		GraphicsService = graphics;
		Graphics2DService = graphics2d;
		states.Push( jamstate );
		graphics.SetBlend( BlendState::AlphaBlend );
		window.Show( );
		//Woops!
		TargetTimeStep( TimeSpan::FromSeconds( 1.0 / 60.0 ) );
	}

protected:

	void Loop( ) {
		optional<MessageData> opmessage;
		windowdriver.Push( window, messages );
		while ( ( opmessage = messages.pop( ) ) ) {
			MessageData& message = opmessage.value();
			switch ( message.header.id ) {
			case MessageId::Mouse: {
				Message<MouseEvent> mouse = message.as<MouseEvent>( );
				Input::MouseState::ManipulateState( mouse.item.Buttons, mouse.item.Relative.x, mouse.item.Relative.y, 0 );
				Input::MouseState::ManipulateState( mouse.item.Wheel.x, false, mouse.item.Relative.x, mouse.item.Relative.y, 0 );
				Input::MouseState::ManipulateState( mouse.item.Wheel.y, true, mouse.item.Relative.x, mouse.item.Relative.y, 0 );
				break; }
			case MessageId::Keyboard: {
				Message<KeyboardEvent> keyboard = message.as<KeyboardEvent>( );
				Input::KeyboardState::ManipulateState( keyboard.item.Key, keyboard.item.Down, 0 );
				break; }
			case MessageId::Window: {
				Message<WindowEvent> windowm = message.as<WindowEvent>( );
				switch ( windowm.item.Signal ) {
				case WindowEventSignal::Quit:
				case WindowEventSignal::Destroy:
					Exit( );
					break;
				}
				windowm.item;
				break; }
			case MessageId::None:
			default:
				break;
			}
		}
		FurrovineGame::Loop( );
	}

	void Update( ) {
		mousedevice.Update( );
		keyboarddevice.Update( );
		if ( keyboarddevice.Pressed( Key::Enter ) ) {
			State& currstate = states.Peek( );
			if ( &currstate != &pausestate ) {
				states.Push( pausestate );
			}
			else {
				states.Pop( );
			}
		}
		states.Update( );
	}

	void Render( ) {
		graphics.Clear( Colors::Black );
		batch.Begin( );
		states.Render( );
		batch.End( );
	}

};

int main( ) {
	std::srand( static_cast<unsigned int>( std::time( 0 ) ) );
	PhameDam phamedam{ };
	phamedam.Run( );
}
