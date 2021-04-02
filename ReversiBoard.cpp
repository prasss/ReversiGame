/*
 * ReversiBoard.cpp
 *
 *  Created on: 25-Nov-2020
 *      Author: prasanna
 */

#include "ReversiBoard.h"
#include "ReversiConsoleView.h"
#include <iostream>
#include <string>
using namespace std;

static char **tempArray;


ReversiBoard::ReversiBoard(uint8_t rows, uint8_t cols) {

	this->num_rows = rows;
	this->num_cols = cols;

	//	this->BA[this->num_rows][this->num_cols];

	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			this->BA[i][j] = '-';
		}
	}


}

char ReversiBoard::getField(uint8_t r, uint8_t c) {

	char temp = this->BA[r][c];
	return temp;
}

void ReversiBoard::setField(uint8_t r, uint8_t c, uint8_t color) {

	this->BA[r][c] = color;
}

void ReversiBoard::updateBoard(uint8_t warning_type) {
}

void ReversiBoard::displayWarning() {
}

char** ReversiBoard::getValidmoves(ReversiPlayer *player, ReversiBoard *board) {

	char** validArray = new char*[8];
	int numValidMoves = 0;

//	char validArray[8][8];
	bool nw, nn, ne, sw, ss, se, ww, ee;

	//initialise the valid array with blanks ("-");
	for(int i = 0; i < 8; i++){

		validArray[i] = new char[8];
		for(int j = 0; j < 8; j++){
			validArray[i][j] = '-';
		}
	}

	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){

			if(board->BA[i][j] == '-'){

				nw = isMoveValid(player->getColor(), -1, -1, i, j, board);
				nn = isMoveValid(player->getColor(), -1,  0, i, j, board);
				ne = isMoveValid(player->getColor(), -1,  1, i, j, board);

				sw = isMoveValid(player->getColor(),  1, -1, i, j, board);
				ss = isMoveValid(player->getColor(),  1,  0, i, j, board);
				se = isMoveValid(player->getColor(),  1,  1, i, j, board);

				ww = isMoveValid(player->getColor(),  0, -1, i, j, board);
				ee = isMoveValid(player->getColor(),  0,  1, i, j, board);


				if(nw || nn || ne || sw || ss || se || ww || ee){
//					cout <<" nw:"<<nw<<" nn:"<<nn<<" ne:"<<ne<<" sw:"<<sw<<" ss:"<<ss<<" se:"<<se<<" ww:"<<ww<<" ee:"<<ee<<endl;
					validArray[i][j] = player->getColor();
					numValidMoves++;
				}
			}
		}
	}
//	cout<< "numValidMoves:"<<numValidMoves;
	player->setValidMoves(numValidMoves);
	return validArray;
}

bool ReversiBoard::isMoveValid(char color, int dr, int dc, int r, int c, ReversiBoard *board) {

	char otherColor;


	if(color == 'b'){
		otherColor = 'w';
	}

	else if(color == 'w'){
		otherColor = 'b';
	}
	else{
		cout << "Problem in color check!" <<endl;
		return false;
	}

	if((r+dr < 0) || (r+dr > 7)){
		return false;
	}

	if((c+dc < 0) || (c+dc > 7)){
//		cout <<"c:"<< (int)c <<"  dc:"<< (int)dc<< endl;
		return false;
	}

	if(board->BA[r+dr][c+dc] != otherColor){
		return false;
	}

	if((r+dr+dr < 0) || (r+dr+dr >7)){
		return false;
	}

	if((c+dc+dc < 0) || (c+dc+dc >7)){
		return false;
	}


	return checkLineForMatch(color, dr, dc, r+dr+dr, c+dc+dc, board);
}


bool ReversiBoard::checkLineForMatch(char color, int dr, int dc, int r, int c, ReversiBoard *board) {

	if(board->BA[r][c] == color){
		return true;
	}

	if((r+dr < 0) || (r+dr >7)){
		return false;
	}

	if((c+dc < 0) || (c+dc >7)){
		return false;
	}

	return checkLineForMatch(color, dr, dc, r+dr, c+dc, board);
}


bool ReversiBoard::rcParser(int &row, int &column, string CinData) {

	cout << "string:"<<CinData << " Row:"<< CinData[0] << " Col:" << CinData[1] <<endl;
	column = (int)CinData[1] - '0' - 1;

	if(CinData[0] == 'A'){
		row = 0;
	}
	if(CinData[0] == 'B'){
		row = 1;
	}
	if(CinData[0] == 'C'){
		row = 2;
	}
	if(CinData[0] == 'D'){
		row = 3;
	}
	if(CinData[0] == 'E'){
		row = 4;
	}
	if(CinData[0] == 'F'){
		row = 5;
	}
	if(CinData[0] == 'G'){
		row = 6;
	}
	if(CinData[0] == 'H'){
		row = 7;
	}

	if(row >=0 && row <=7 && column >=0 && column <=7){
		return true;
	}
	else{
		return false;
	}

	cout << "\nRow: "<< row << "  Col:" << column <<endl;
}

bool ReversiBoard::verifyPlaceEmpty(uint8_t r, uint8_t c) {

	if(this->BA[r][c] == '-'){
		return true;
	}
	else{
		return false;
	}
}

bool ReversiBoard::verifyValidMove(uint8_t r, uint8_t c, ReversiPlayer *player, ReversiBoard *board) {

	tempArray = getValidmoves(player,board);
	bool valid = false;

	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			if(tempArray[i][j] == player->getColor()){
				valid = true;
			}
		}
	}
	delete[] tempArray;
	return valid;
}

void ReversiBoard::drawLine(char color, int r, int c, ReversiBoard *board) {

	checkIfOpp(color, -1, -1, r, c, board);
	checkIfOpp(color, -1,  0, r, c, board);
	checkIfOpp(color, -1,  1, r, c, board);

	checkIfOpp(color,  1, -1, r, c, board);
	checkIfOpp(color,  1,  0, r, c, board);
	checkIfOpp(color,  1,  1, r, c, board);

	checkIfOpp(color,  0, -1, r, c, board);
	checkIfOpp(color,  0,  1, r, c, board);

}

bool ReversiBoard::checkIfOpp(char color, int dr, int dc, int r, int c, ReversiBoard *board) {

//	cout <<"c:"<< (int)c <<"  dc:"<< (int)dc <<"r:"<< (int)r <<"  dr:"<< (int)dr<< endl;

		if((r+dr < 0) || (r+dr >7)){
			return false;
		}

		if((c+dc < 0) || (c+dc >7)){
			return false;
		}

		if(board->BA[r+dr][c+dc] == '-'){
			return false;
		}

		if(board->BA[r+dr][c+dc] == color){
			return true;
		}

		if(checkIfOpp(color,  dr, dc, r+dr, c+dc, board)){
			board->BA[r+dr][c+dc] = color;
			cout<<"\n ***swapped!***"<<endl;
			return true;
		}
		else{
			return false;
		}

}

bool ReversiBoard::checkLineForSwap(char color, int dr, int dc,	int r, int c, ReversiBoard *board){

	if(board->BA[r][c] == color){

		return true;
	}




	return checkLineForSwap(color, dr, dc, r+dr+dr, c+dc+dc, board);
}

void ReversiBoard::countScore(ReversiPlayer *player, ReversiBoard *board) {
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			if(board->BA[i][j] == player->getColor()){
				player->incrementScore();
			}
		}
	}
}

void ReversiBoard::checkIfWin(ReversiPlayer *player1, ReversiPlayer *player2, ReversiBoard *board) {

	if(player1->getValidMoves() == 0){
		player2->setWinner();
		cout <<" PLayer 2 has won!!!"<<endl;
	}

	if(player2->getValidMoves() == 0){
		player1->setWinner();
		cout <<" PLayer 1 has won!!!"<<endl;
	}
}
