/**
* Jennifer Aber
* chessBoard.cpp
**/



#include <iostream>
#include "ChessBoard.h"
using namespace std;


ChessBoard::ChessBoard()
{
	boardSize = 8;
	boardPtr = allocateBoard(boardSize);

}

ChessBoard::ChessBoard(int size)
{
	if (size < 4) {
		boardSize = 4;
	}
	if (size >= 4 && size <= 12) {
		boardSize = size;
	}
	if (size > 12) {
		boardSize = 12;
	}

	boardPtr = allocateBoard(boardSize);
}

char** ChessBoard::allocateBoard(int boardSize) {

	//creates a new chessBoard object on the heap

	char** board = new char* [boardSize];

	for (int i = 0; i < boardSize; i++) {
		board[i] = new char[boardSize];
		for (int j = 0; j < boardSize; j++) {
			board[i][j] = '*';
		}
	}
	return board;

}

void ChessBoard::deleteBoard() {

	for (int i = 0; i < boardSize; i++) {

		delete[] boardPtr[i];

	}

	delete[] boardPtr;
	boardPtr = nullptr;

}

void ChessBoard::setSize(int size) {

	deleteBoard();
	if (size < 4) {
		boardSize = 4;
	}
	if (size >= 4 && size <= 12) {
		boardSize = size;
	}
	if (size > 12) {
		boardSize = 12;
	}
	boardPtr = allocateBoard(boardSize);

}

int ChessBoard::getSize() {

	return boardSize;
}

void ChessBoard::displayBoard() {

	// : added between elements in the array to provide better spacing

	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			cout << ":" << boardPtr[i][j];
		}
		cout << endl;
	}

}

bool ChessBoard::placeQueens(int col) {

	int row = 0;

	//if a queen is placed in the last column, function returns true

	if (col >= boardSize) {
		return true;
	}

	else {
		while (row < boardSize) {
			if (isNotAttacked(row, col)) {
				boardPtr[row][col] = 'Q';
				if (!placeQueens(col + 1)) {

					//removes last queen placed
					boardPtr[row][col] = '*';


					row = row + 1;
				}
				else {
					return true;
				}
			}
			else {
				row = row + 1;
			}

		}
	}
	//backtracking by returning false 
	return false;
}

bool ChessBoard::isNotAttacked(int row, int col) {

	//checks current row
	for (int j = 0; j < boardSize; j++) {
		if (boardPtr[row][j] == 'Q') {
			return false;
		}
	}

	//checks up and to the left on the diagonal
	for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
		if (boardPtr[i][j] == 'Q') {
			return false;
		}
	}

	//checks down and to the left on the diagonal
	for (int i = row, j = col; i < boardSize && j >= 0; i++, j--) {
		if (boardPtr[i][j] == 'Q') {
			return false;
		}
	}

	return true;
}

bool ChessBoard::solve() {
	
	//starts in the left-most column
	placeQueens(0);

	//if a solution has been found
	return true;

}

ChessBoard::~ChessBoard() {

	deleteBoard();

}



