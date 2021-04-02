/*
 * ReversiBoard.h
 *
 *  Created on: 25-Nov-2020
 *      Author: prasanna
 */

#ifndef REVERSIBOARD_H_
#define REVERSIBOARD_H_
#include "ReversiPlayer.h"
//#include "ReversiConsoleView.h"
#include <inttypes.h>
#include <iostream>
using namespace std;


typedef enum{MOVE_OK, INVALID_MOVE} warning_t;
typedef enum{EMPTY, P1_OCCUPIED, P2_OCCUPIED} state_t;

class ReversiBoard {
private:
	uint8_t num_rows;
	uint8_t num_cols;
	char BA[8][8];

public:
	/**
	 * This is the constructor for the ReversiBoard class
     * @param[IN] rows		: IN
     * @param[IN] cols		: IN
	 */
	ReversiBoard(uint8_t rows, uint8_t cols);

	/**
	 * This is the function to be used to fetch the color of a particular board position
     * @param uint8_t r	 	: IN input row data
     * @param uint8_t c	 	: IN input column data
     * @return char
	 */
	char getField(uint8_t r, uint8_t c);

	/**
	 * This is the function to be used to set the state of a particular board position and returns a warning type if any
     * \param uint8_t r			: IN
	 * \param uint8_t c			: IN
	 * \param uint8_t colour	: IN
	 */
	void setField(uint8_t r, uint8_t c, uint8_t color);

	/**
	 * This function updates the board after a player has made a move and also checks for the warning flag
	 * \param uint8_t warning_type		: OUT
	 */
	void updateBoard(uint8_t warning_type);

	/**
	 * This function is used to print out the particular warnings on the console
     * \param uint8_t warning_type		: IN
	 */
	void displayWarning();

	/**
	 * This function is used to get Valid moves that can be made by the current player
     * \param ReversiPlayer player		: IN
     * \param ReversiBoard board		: IN
	 */
	char** getValidmoves(ReversiPlayer *player, ReversiBoard *board);

	/**
	 * This function is a helper function for the getValidmoves() function
     * \param char color		: IN
     * \param uint8_t dr				: IN	(delta row)
     * \param uint8_t dc				: IN	(delta column)
     * \param uint8_t r					: IN	(row val)
     * \param uint8_t c					: IN	(column val)
     * \param ReversiBoard board		: IN
	 */
	bool isMoveValid(char color, int dr, int dc, int r, int c, ReversiBoard *board);


	/**
	 * This function is a helper function for the isMoveValid() function, to further check for the whole line
     * \param char color		: IN
     * \param uint8_t dr				: IN	(delta row)
     * \param uint8_t dc				: IN	(delta column)
     * \param uint8_t r					: IN	(row val)
     * \param uint8_t c					: IN	(column val)
     * \param ReversiBoard board		: IN
	 */
	bool checkLineForMatch(char color, int dr, int dc, int r, int c, ReversiBoard *board);

	/**
	 * This function is used to get the row and column entries from the user and check if valid
	 * \param int &row					: OUT
     * \param &column					: OUT
     * \param string CinData			:IN
     * \return bool
	 */
	bool rcParser(int &row, int &column, string CinData);

	/**
	 * This function is used to check if the place(r, c) is occupied by a '-' or not
	 * \param uint8_t r					: IN
     * \param uint8_t r					: IN
     * \return bool
	 */
	bool verifyPlaceEmpty(uint8_t r, uint8_t c);

	/**
	 * This function is used to verify whether a particular move was valid (after entering color)
	 * \param uint8_t r					: IN
     * \param uint8_t r					: IN
     * \param ReversiPlayer *player		: IN
     * \param ReversiBoard *board		: IN
     * \return bool
	 */
	bool verifyValidMove(uint8_t r, uint8_t c, ReversiPlayer *player, ReversiBoard *board);

	/**
	 * This function is used to draw a line/ turn pieces when a correct move is made
	 * \param uint8_t r					: IN
     * \param uint8_t r					: IN
     * \return bool
	 */
	void drawLine(char color, int r, int c, ReversiBoard *board);

	/**
	 * This function is a helper function for the drawLine() function
     * \param char color				: IN
     * \param uint8_t dr				: IN	(delta row)
     * \param uint8_t dc				: IN	(delta column)
     * \param uint8_t r					: IN	(row val)
     * \param uint8_t c					: IN	(column val)
     * \param ReversiBoard board		: IN
	 */
	bool checkIfOpp(char color, int dr, int dc, int r, int c, ReversiBoard *board);


	/**
	 * This function is a helper function for the checkIfOpp() function, to further check for the whole line for the swap
     * \param char color		: IN
     * \param uint8_t dr				: IN	(delta row)
     * \param uint8_t dc				: IN	(delta column)
     * \param uint8_t r					: IN	(row val)
     * \param uint8_t c					: IN	(column val)
     * \param ReversiBoard board		: IN
	 */
	bool checkLineForSwap(char color, int dr, int dc, int r, int c, ReversiBoard *board);

	/**
	 * This function is used to count the score for a particular player
	 * \param ReversiPlayer *player		: IN
	 * \param ReversiBoard *board		: IN
	 */
	void countScore(ReversiPlayer *player, ReversiBoard *board);

	/**
	 * This function is used to check if any player has won, by check if the players is left with any more valid moves
	 * \param ReversiPlayer *player1	: IN
	 * \param ReversiPlayer *player2	: IN
	 * \param ReversiBoard *board		: IN
	 */
	void checkIfWin(ReversiPlayer *player1, ReversiPlayer *player2, ReversiBoard *board);
};

#endif /* REVERSIBOARD_H_ */
