#include "Button.h"



Button::Button()
{
	this->active = false;
}

Button::~Button(){}

sf::RectangleShape Button::Deco()
{
	return rec;
}


void Button::swapButton(sf::RectangleShape button)
{
	rec = button;
}

bool Button::isActive()
{
	return active;
	//sf::RectangleShape rec;
}

void Button::changeActivity(bool activity)
{
	active = activity;
}
