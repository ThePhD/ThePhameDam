#include "StateStack.h"
#include <memory>

void StateStack::Render( ) {
	for ( std::size_t i = states.size( ); i-- > 0; ) {
		State& state = *states[ i ];
		state.Render( );
		if ( state.StopsRender )
			break;
	}
}

void StateStack::Update( ) {
	for ( std::size_t i = states.size(); i-- > 0; ) {
		State& state = *states[ i ];
		state.Update( );
		if ( state.StopsUpdate )
			break;
	}
}

State& StateStack::Peek( ) {
	return *states.back();
}

void StateStack::Pop( ) {
	states.pop_back( );
}

void StateStack::Push( State& state ) {
	states.push_back( std::addressof( state ) );
}

bool StateStack::Contains( State& state ) {
	State* target = std::addressof( state );
	auto searchit = std::find( states.begin( ), states.end( ), target );
	return searchit != states.end( );
}

StateStack::StateStack( ) {

}
