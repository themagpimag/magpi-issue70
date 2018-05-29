
/*
 *new balls behave the same as normal balls, but don't actually generate new ones (or it would fill the screen)
 *they can be hit by the bat though
 **/


#include "NewBall.h"
#include "Game.h"


NewBall::NewBall() {}
         //standard constructor
NewBall::~NewBall() {}
         //standard destructor

void NewBall::Update()
{}
// returning a bool allows us to provide a yes/no or true/false, or in this case alive/dead value, if we return true we are alive and well, if not...curtains!
bool NewBall::Update(Game* G)
{
	// this week just make the ball bounce around, next week we will make them bounce off the tiles	
	Xpos += Xspeed;
	Ypos += Yspeed;
	if (Xpos < 24) Xspeed = -Xspeed;
	if (Xpos > 1024 - 24) Xspeed = -Xspeed;
	if (Ypos > 768 - 24) Yspeed = -Yspeed;
	if (Ypos < 160) Yspeed = -Yspeed;
	
	
	// we need to test of we hit the bat, just a simple test this time we will refine later
	if(DidIGetHit(G->MyBat))
	{
		Yspeed = -Yspeed;
	}
	
	// ok so now we need to test if we hit a bullet
	for(int i = 0 ; i < Game::MyBullets.size() ; i++)
	{
		bool test = DidIGetHit(Game::MyBullets[i]);
		if (test == true)
		{
			delete Game::MyBullets[i];  // delete the bullet
			Game::MyBullets.erase(Game::MyBullets.begin() + i);
			return false; // return false and the ball itself will be removed
		}
	}	
	
	return true;
}


void	NewBall::Draw()
{
	SimpleObj::Draw();
}