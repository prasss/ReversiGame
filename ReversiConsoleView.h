/*
 * ReversiConsoleView.h
 *
 *  Created on: 25-Nov-2020
 *      Author: prasanna
 */

#ifndef REVERSICONSOLEVIEW_H_
#define REVERSICONSOLEVIEW_H_
#include "ReversiBoard.h"
#include "ReversiPlayer.h"

class ReversiConsoleView {
public:

	/**
	 * This is the constructor for the ReversiConsoleView class
     * \param ReversiBoard board		: IN
	 */
	ReversiConsoleView();

	/**
	 * This is the function to be used to print the whole Reversi board
	 * \param ReversiBoard board		: IN
	 */
	void printBoard(ReversiBoard *board);

	/**
	 * This is the function to be used to print the valid moves for a particular player
	 * \param ReversiBoard board		: IN
	 * \param ReversiPlayer *player		: IN
	 */
	void printValidMoves(ReversiBoard *board, ReversiPlayer *player);

	/**
	 * This is the function to be used to print the score of the players
	 * \param ReversiBoard board		: IN
	 * \param ReversiPlayer *player1	: IN
	 * \param ReversiPlayer *player2	: IN
	 */
	void printScore(ReversiPlayer *player1, ReversiPlayer *player2, ReversiBoard *board);
};

#endif /* REVERSICONSOLEVIEW_H_ */
