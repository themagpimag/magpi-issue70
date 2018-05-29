/*
Simple example of a main function creating a game class and updating it

Take note, warnings have been enabled to allow you to find and fix the issues they warn about

*/

#include "Game.h"
#include <stdio.h>
#include <iostream>
#include <streambuf>
#include <stdlib.h>
#include <string>
#include <sstream>

int main(int argc, char *argv[])
{


	Game TheGame; // create an instance of  game.

	TheGame.Update();

}
