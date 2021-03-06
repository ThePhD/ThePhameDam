#pragma once

#include "State.h"
#include <vector>

class StateStack {
private:
	std::vector<State*> states;

public:

	StateStack( );

	void Push( State& state );

	void Pop( );

	State& Peek( );
	
	bool Contains( State& state );

	void Update( );

	void Render( );

};