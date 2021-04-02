/*
 * main.cpp
 *
 *  Created on: 25-Nov-2020
 *      Author: prasanna
 */

#include <iostream>
#include "ReversiBoard.h"
#include "ReversiPlayer.h"
#include "ReversiConsoleView.h"
#include "ReversiGame.h"

int main(){

	ReversiPlayer P1(1,'w');
	ReversiPlayer P2(0,'b');

	ReversiBoard myBoard(8,8);


	ReversiConsoleView rcv;

	ReversiGame game;

	game.gamePlay(&P1, &P2, &myBoard, &rcv);


	return 0;
}


