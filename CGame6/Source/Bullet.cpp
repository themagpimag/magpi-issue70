



#include "Bullet.h"
#include "Game.h"
#include <vector>


Bullet::Bullet() {
	this->ScaleX = 6;
	this->ScaleY = 6;
	
	
}
;         //standard constructor
Bullet::~Bullet() {
	printf("done\n");
}
;         //standard destructor




void Bullet::Update()
{
// not really used
	
}

/*
 *Bullets have a very simple motion, the move stright up, and test to see if the hit anything
 *if they hit a tile they simply die, if they hit a ball the ball and the bullet die
 **/
bool Bullet::Update(Game* G)
{
	this->Ypos += 6.0;  // move a fair distance
	
	int GridX = Xpos / 16;
	int	GridY = (768 - Ypos) / 16;
	if (G->PlayField[GridY][GridX] !=0) return false; // we have to die
	
	
	return true; 
}


void	Bullet::Draw()
{
	SimpleObj::Draw();
}