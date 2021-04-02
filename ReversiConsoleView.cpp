/*
 * ReversiConsoleView.cpp
 *
 *  Created on: 25-Nov-2020
 *      Author: prasanna
 */

#include "ReversiConsoleView.h"
#include <iostream>
using namespace std;


ReversiConsoleView::ReversiConsoleView() {

//empty constructor
}

void ReversiConsoleView::printBoard(ReversiBoard *board) {

	cout << "\nTo make a move, enter the Row Alphabet A->H and Column numbers 1->8\n"<< endl;

	char alpha = 'A';
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			if(i==0 && j==0){
				cout <<" |_1_||_2_||_3_||_4_||_5_||_6_||_7_||_8_|"<<endl;
				}

			if(j==0){
				cout << char(i+int(alpha));
			}
			cout <<"| " << board->getField(i,j) << " |" ;
		}
		cout << endl;
	}

}

void ReversiConsoleView::printValidMoves(ReversiBoard *board, ReversiPlayer *player) {

	char **tempArray = board->getValidmoves(player,board);

			char alpha = 'A';
				for(int i = 0; i < 8; i++){
					for(int j = 0; j < 8; j++){
						if(i==0 && j==0){
							cout <<"\n |_1_||_2_||_3_||_4_||_5_||_6_||_7_||_8_|"<<endl;
							}

						if(j==0){
							cout << char(i+int(alpha));
						}
						cout <<"| " << tempArray[i][j] << " |" ;
					}
					cout << endl;
				}
}

void ReversiConsoleView::printScore( ReversiPlayer *player1, ReversiPlayer *player2, ReversiBoard *board) {
	cout<< "------------------"<<endl;
	cout<< "| Player 1: "<< player1->getScore() <<" |"<<endl;
	cout<< "| Player 2: "<< player2->getScore() <<" |"<<endl;
	cout<< "------------------"<<endl;
}
