#pragma once

#include "SimpleObj.h"
class Game;

class Bullet :public  SimpleObj
{
public:
	Bullet();   //standard constructor
	~Bullet();   //standard destructor

		//list the functions we want to have (called methods in C++)	
	void Update();
	bool Update(Game* G);
	void Draw();
	
	
};

