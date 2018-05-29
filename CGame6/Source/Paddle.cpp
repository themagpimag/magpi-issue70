
#include "Paddle.h"

// we need some libries to read the key
#include <termios.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <iostream>
#include "Input.h"
#include "Bullet.h"
#include "Game.h"
// we need to save the original terminal io settings
struct termio original_termio;
struct termio new_termio;
Input InputSys;

Paddle::Paddle() {
	Xpos = 512;
	Ypos = 200; 
	width = 32;
	height = 8;
	
// even though we no longer test the char, we can keep this here
// because it has the benefit of redirecting our char input so we 
// don't type things as we press the keys
	
	int fd = fileno(stdin);
	ioctl(fd, TCGETA, &original_termio);
	new_termio = original_termio;
	new_termio.c_cc[VMIN] = 0;
	new_termio.c_cc[VTIME] = 0;
	new_termio.c_lflag = 0;
	ioctl(fd, TCSETA, &new_termio);
	
// init the new system	
	InputSys.Init();

};         //standard constructor
Paddle::~Paddle() {
	
	int fd = fileno(stdin);
	ioctl(fd, TCSETA, &original_termio); // put the old one back
	
};         //standard destructor
void Paddle::Update()
{
}

bool Paddle::Update(Game* G)
	{
	
		
		float	 SavedXpos = Xpos;
		float	 SavedYpos = Ypos;
		
		static int FireDebounce = 0;
	
	
			if (InputSys.Keys[KEY_A]) Xpos -= 8;
			if (InputSys.Keys[KEY_S]) Xpos += 8;

	
			
			if (InputSys.Keys[KEY_SPACE] && FireDebounce == 0)
			{
				Bullet* B = new Bullet();
				B->Xpos = this->Xpos;   // we don't need to use "this" here, buit since both classes use the same variable name, it helps with clarity
				B->Ypos = this->Ypos+6;
				B->TextureID = G->MyBall->TextureID;  // we will use our xpos, ypos and lets use the Texture ID of the ball, which will be shrunk by scale to make a bullet
				B->height = 6;
				B->width = 6; // give our bullets some size
				
				
				G->MyBullets.push_back(B);   // this is how we add bullets to our vector held in the Game class that called this instance
				FireDebounce = 8; // this means it will wait 8 frames before we can fire again
			}
			
		
		
		// lets just make sure our paddle has not gone too far with a simple test
		if(Xpos <24 || Xpos > 1024 - 24) // || means OR, we also have && which means AND
			{
				 // so our test is asking if Xpos is too far to the left, OR too far to the right..
				Xpos = SavedXpos;  // if it is reset the positon to the value it was before.
			}	
		
		if (FireDebounce != 0) FireDebounce--; // and this is what counts down the 8 frames for us
		
		return true;
	}


void	Paddle::Draw()
{
	SimpleObj::Draw();
}
