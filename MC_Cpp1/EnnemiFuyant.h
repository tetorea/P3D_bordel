#pragma once

#include "Ennemi.h"

class EnnemiFuyant : public Ennemi
{
public:
	EnnemiFuyant( const Vec2i& pos, int vie = 10 ) : Ennemi( pos, vie ) {};

	virtual bool action();

};

