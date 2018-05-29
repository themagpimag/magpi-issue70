#pragma once
#pragma once

#include "SimpleObj.h"

class NewBall :public  SimpleObj
{
public:
	NewBall();     //standard constructor
	
	~NewBall();     //standard destructor
	

		//list the functions we want to have (called methods in C++)	
	void Update();
	bool Update(Game* G);

	void Draw();
	
	
};

