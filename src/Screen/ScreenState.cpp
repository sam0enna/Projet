#include "ScreenState.hpp"

ScreenState::ScreenState()
{
	
}

ScreenState::~ScreenState(){
	
}

int ScreenState::getType()
{
	return type;
}
void ScreenState::load(){}
void ScreenState::unload(){}
void ScreenState::move(int x,int y){}
void ScreenState::draw(RenderWindow &window){}
