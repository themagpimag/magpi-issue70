#pragma once
#include <string> // we're going to use strings so need the header
#include "OGL.h"
#include "stb_image.h"

class Game; // let SimpleObj class know there is a class called game, we can't include it because it also references SimpleOBJ

class SimpleObj
{
public:
	SimpleObj(); //standard constructor
	 ~SimpleObj(); //standard destructor



//list the functions we want to have (called methods in C++)
	virtual void Update();  // By making these virtual, it allows a class which inherets SimpleObj to replace these functions with their own versions
	virtual void Draw();
	virtual bool Update(Game*); // most of our autononous objects will use this upadate
// we will add this here so every object can test if it hit another objecvt
	bool DidIGetHit(SimpleObj* Obj2);
// list the variables we want our instances to have (called members in C++)
	float Xpos, Ypos;
	float Xspeed, Yspeed;
	float ScaleX;	// this is just a fun variable since our actual texture is quite large, and already shrunk but the vertex offsets
	float ScaleY;
// when we load our images we can store the width and height here it will help with collison
	float width;
	float height;
	std::string m_MyName;

	GLint TextureID;   		// each tile now has its own

	static GLint ProgramObject; //Objects need this
	// Get the attribute locations, we'll store these in values we can call handles.
	static GLint positionLoc;
	static GLint texCoordLoc;

	// if we want to position it somewhere we need to ask for the handle for the position uniform and other unfirms
	static GLint positionUniformLoc;
	static GLint samplerLoc;  //= glGetUniformLocation(ProgramObject, "s_texture");
	static GLint ScreenCoordLoc;  //= glGetUniformLocation(ProgramObject, "u_Screensize");
	static GLint ScaleLoc;  //= glGetUniformLocation(ProgramObject, "u_Scale");
	static GLuint VBO; // since we only have one type of object at the moment (a quad) we can make do with one vbo



};
