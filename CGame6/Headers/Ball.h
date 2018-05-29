#pragma once

#include "SimpleObj.h"


class Game;
class Ball : public  SimpleObj
{
public:
	Ball();     //standard constructor
	~Ball();     //standard destructor

		//list the functions we want to have (called methods in C++)	
	void Update(); // this update will replace the update in the base class
	bool Update(Game* Game);
	void Draw();

	int hitDebounce;
};
