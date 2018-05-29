


#include "Ball.h"
#include "NewBall.h" // since we're going to reference them here we need to know what they are
#include "Game.h"


Ball::Ball() {
	Xpos = 200;
	Ypos = 200;
	Xspeed = -6;
	Yspeed = + 6;
	width = 16;
	height = 16;
	hitDebounce = 0;
}
;         //standard constructor
Ball::~Ball() {}
;         //standard destructor

void Ball::Update() // we're not going to use this
{
}

//Our Ball is going to bounce a
bool Ball::Update(Game* G) // we are going to use this
{

	static int DelayTillNext = 0; // this is a little check to stop us creating multiple new balls.

// this week just make the ball bounce around, next week we will make them bounce off the tiles	same as we did with triangles and squares
	Xpos += Xspeed;
	Ypos += Yspeed;
	if (Xpos < 24) Xspeed = -Xspeed;
	if (Xpos > 1024 - 24) Xspeed = -Xspeed;
	if (Ypos > 768-24) Yspeed = -Yspeed;
	if (Ypos < 160) Yspeed = -Yspeed;


	// but we can test whats under the ball	and use that to do cool things
	int GridX = Xpos / 16;
	int	GridY = (768-Ypos) / 16;
	if (G->PlayField[GridY][GridX] == 8 && DelayTillNext == 0)
	{ // create 2 newballs.
		NewBall* NB = new NewBall();
		NB->Xpos = this-> Xpos;  // we don't need to use "this" here, buit since both classes use the same variable name, it helps with clarity
		NB->Ypos = this-> Ypos;
		NB->TextureID = this->TextureID; // we will use our xpos, ypos and texture id the same as the ball
		NB->Xspeed = -this->Xspeed * 1.5;
		NB->Yspeed = -this->Yspeed * 1.5; // but modify the speed a little
		NB->width = this->width;
		NB->height = this->height;

		G->MyObjects.push_back(NB); // this is how we add objects to our vector held in the Game class that called this instance

// lets make another, slighlty different
		NB = new NewBall();
		NB->Xpos = this->Xpos;   // we don't need to use "this" here, buit since both classes use the same variable name, it helps with clarity
		NB->Ypos = this->Ypos;
		NB->TextureID = this->TextureID;
		NB->Xspeed = this->Xspeed * 1.2; // for variety don't make the exactly alike
		NB->Yspeed = -this->Yspeed * 1.2;
		NB->width = this->width;
		NB->height = this->height;

		G->MyObjects.push_back(NB);
		DelayTillNext = 4; // add a little delay time before we do this again
	}
	if (DelayTillNext != 0)	DelayTillNext--;


// so its a bat ball game, we have to make sure we hit the bat, if so change the balls yspeed
// this is just a simple basic test, it needs more refinement but we'll do that later.
	if(DidIGetHit(G->MyBat) && hitDebounce == 0)
	{
		Yspeed = -Yspeed;
		hitDebounce = 3; // wait 3 frames before doing this again

	}
	if (hitDebounce != 0) hitDebounce--;


	// ok so now we need to test if we hit a bullet
	for(int i = 0 ; i < G->MyBullets.size() ; i++)
	{
		bool test = DidIGetHit(Game::MyBullets[i]);
		if (test == true)
		{
			delete Game::MyBullets[i]; // delete the bullet
			Game::MyBullets.erase(Game::MyBullets.begin() + i);
	// as this is our main ball, we're not going to delete the ball, just the bullet for effect

			break;		 // this allows us to break out of the loop since we don't want to continue to test.
		}
	}

	return true; // all is good
}


void	Ball::Draw()
{
	SimpleObj::Draw();


}
