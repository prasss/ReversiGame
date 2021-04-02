/*
 * ReversiGame.h
 *
 *  Created on: 27-Nov-2020
 *      Author: prasanna
 */

#ifndef REVERSIGAME_H_
#define REVERSIGAME_H_
#include "ReversiConsoleView.h"
#include "ReversiPlayer.h"
#include "ReversiBoard.h"

class ReversiGame {
public:
	ReversiGame();

	/**
	 * This function is the main function that drives the game
     * \param ReversiPlayer *player1	: IN
     * \param ReversiPlayer *player2	: IN
     * \param ReversiBoard *board		: IN
     * \param ReversiConsoleView *view	: IN
	 */
	void gamePlay(ReversiPlayer *player1, ReversiPlayer *player2, ReversiBoard *board, ReversiConsoleView *view);
};

#endif /* REVERSIGAME_H_ */
