/*
 * ReversiPlayer.h
 *
 *  Created on: 26-Nov-2020
 *      Author: prasanna
 */

#ifndef REVERSIPLAYER_H_
#define REVERSIPLAYER_H_
#include <inttypes.h>

class ReversiPlayer {
private:
	bool myTurn;
	bool hasWon;
	char myColor;
	int myScore;
	int validMoves;

protected:

public:

	/*
	 * Constructor to intialise the player
	 * \param bool toPlay	:IN
	 * \param char color	:IN
	 */
	ReversiPlayer(bool toPlay, char color);


	/*
	 * This function checks sets a player as winner
	 * \return void
	 */
	void setWinner();

	/*
	 * This function checks if this player is to be declared as winner
	 * \return ReversiPlayer returns the player instance of the winner
	 */
	bool isWinner();

	/*
	 * This function gets the color of the player
	 * \return char, returns the player color as 'b' or 'w' as set through the constructor
	 */
	char getColor();

	/*
	 * This function gets who's turn it is to play
	 * \return bool, returns the player turn if 'TRUE' or 'FALSE'
	 */
	bool getTurn();

	/*
	 * This function gets the player's score
	 * \return int, returns the player score
	 */
	int getScore();

	/*
	 * This function sets the player's score
	 * \return void
	 */
	void setScore(int score);

	/*
	 * This function increments the player's score
	 * \return int, returns the player score
	 */
	int incrementScore();

	/*
	 * This function gets the player's number of valid moves
	 * \return int, returns the player's number of valid moves
	 */
	int getValidMoves();

	/*
	 * This function sets the player's number of valid moves
	 * \return int, returns the number of valid moves
	 */
	void setValidMoves(int moves);

};

#endif /* REVERSIPLAYER_H_ */
