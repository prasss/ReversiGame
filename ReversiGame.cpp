/*
 * ReversiGame.cpp
 *
 *  Created on: 27-Nov-2020
 *      Author: prasanna
 */

#include "ReversiGame.h"

ReversiGame::ReversiGame() {
	//empty constructor
}


void ReversiGame::gamePlay(ReversiPlayer *player1, ReversiPlayer *player2, ReversiBoard *board, ReversiConsoleView *view) {

		board->setField(3,3,player1->getColor());
		board->setField(3,4,player2->getColor());
		board->setField(4,4,player1->getColor());
		board->setField(4,3,player2->getColor());
		view->printBoard(board);
//		view->printValidMoves(board, player1);
//		view->printValidMoves(board, player2);


		uint8_t turnManageCounter = 0;

		do{

			string moveString;
			int r,c;

			if(turnManageCounter == 0){

				cout << "Turn of Player1 with color - " << player1->getColor() <<endl;
				cout << "Valid moves are as below..."<<endl;
				view->printValidMoves(board, player1);
				cout << "Enter Move! eg. A1: ";

				cin >> moveString;
				if(board->rcParser(r,c,moveString)){

					if(board->verifyValidMove(r,c,player1,board) && board->verifyPlaceEmpty(r,c))
							{
								board->setField(r,c,player1->getColor());
								board->drawLine(player1->getColor(),r,c,board);
								view->printBoard(board);
							}
					else{
						turnManageCounter = 1;
						cout << "Place already occupied, please retry Move!: ";
					}
				}
				else{
					turnManageCounter = 1;
					cout << "Invalid move, please retry Move!: ";
				}

			}
			else if(turnManageCounter == 1){
				cout << "Turn of Player2 with color - " << player2->getColor() <<endl;
				cout << "Valid moves are as below..."<<endl;
				view->printValidMoves(board, player2);
				cout << "Enter Move! eg. A1: ";
				cin >> moveString;
				if(board->rcParser(r,c,moveString)){

					if(board->verifyValidMove(r,c,player2,board) && board->verifyPlaceEmpty(r,c))
					{
						board->setField(r,c,player2->getColor());
						board->drawLine(player2->getColor(),r,c,board);
						view->printBoard(board);
					}
					else{
						turnManageCounter = 0;
						cout << "Place already occupied, please retry Move!: ";
					}
				}
				else{
					turnManageCounter = 0;
					cout << "Invalid move, please retry Move!: ";
				}
			}


			board->countScore(player1, board);
			board->countScore(player2, board);
			view->printScore(player1, player2, board);

			//for checking winning
//			player2->setValidMoves(0);

			board->checkIfWin(player1, player2, board);
			turnManageCounter++;
			turnManageCounter = turnManageCounter%2;

			//reset score after every round, to be counted again later
			player1->setScore(0);
			player2->setScore(0);

			cout << "player1->isWinner():"<<player1->isWinner()<<endl;
			cout << "player2->isWinner():"<<player2->isWinner()<<endl;

		}while(!player1->isWinner() || !player2->isWinner());


}
