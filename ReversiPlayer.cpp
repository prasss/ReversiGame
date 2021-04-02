/*
 * ReversiPlayer.cpp
 *
 *  Created on: 26-Nov-2020
 *      Author: prasanna
 */

#include "ReversiPlayer.h"
#include <iostream>

ReversiPlayer::ReversiPlayer(bool toPlay, char color){
	this->myTurn = toPlay;
	this->myColor = color;
	this->hasWon = false;
	this->myScore = 0;
	this->validMoves = 1;
}

char ReversiPlayer::getColor(){

	return this->myColor;
}

bool ReversiPlayer::getTurn(){

	return this->myTurn;
}

bool ReversiPlayer::isWinner() {
	return this->hasWon;
}

int ReversiPlayer::getScore() {
	return this->myScore;
}

int ReversiPlayer::incrementScore(){
	return this->myScore++;
}

int ReversiPlayer::getValidMoves() {
	return this->validMoves;
}

void ReversiPlayer::setValidMoves(int moves){
	this->validMoves = moves;
}

void ReversiPlayer::setWinner() {
	this->hasWon = true;
}

void ReversiPlayer::setScore(int score) {
	this->myScore = score;
}
