#pragma once


/*The Paddel is a simple sprite based object, but has access to key input
 *in its update functions
 *
 **/
class Game; // let it know there is a class called Game
#include "SimpleObj.h"

class Paddle : public SimpleObj 
{
public:
	Paddle();        //standard constructor
	
	~Paddle();        //standard destructor

		//list the functions we want to have (called methods in C++)	
	void  Update();
	bool  Update(Game* Game);
	void Draw();
	
	GLint ProgramObject; // though SimpleObj has a static shared Program Object we might want to use a different shader for this special type of user control oject
	
	
};
