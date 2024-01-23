/**
* Jennifer Aber
* ChessBoard.h
**/





#ifndef CHESSBOARD_H
#include <iostream>
using namespace std;


class ChessBoard {

private:
	char** boardPtr = new char*[8];
	int boardSize = 8;

	/**
	* Places queens in unattacked locations on the board.  Returns true 
	* if able to successfully place a queen in each column.  If a queen cannot
	* be placed in a given column, this function removes the last queen placed 
	* and increments the row, placing it in the following row if possible.
	* 
	* @col The column where the first queen will be placed.
	* @pre In order to place a queen in each column, 0 must be passed
	* as the value for col. This function searches from left to right for available
	* locations to place a queen and ends when col >=boardSize.  
	* @return bool
	**/

	bool placeQueens(int col);

	/**
	* Creates a 2D array on the heap.  Uses a for loop to populate the array with asterisks.
	* 
	* @boardSize the size of the array.
	* @pre this function requires as input an integer boardSize to determine size of the array.
	* @return char**
	**/

	char** allocateBoard(int boardSize);

	/**
	* Using a for loop, this function deletes the pointers to each array of 1D pointers.
	* It then deletes boardPtr and sets the value to null.
	* 
	* @return void
	**/

	void deleteBoard();

	/**
	* Using for loops, this function checks along the current row to the left for a queen. 
	* It also checks along a diagonal to the upper left and the lower left to determine if the location 
	* is under attack.
	* 
	* @row the row of the location under consideration for placement of a queen 
	* @column the column of the location under consideration for placement of a queen 
	* @pre this function only checks rows and columns to the left, therefore it will not work
	* if attempting to place queens from right to left
	* @return bool 
	**/

	bool isNotAttacked(int row, int col);

public:

	/**
	* Default constructor sets boardSize to 8, points boardPtr to object created by calling
	* allocateBoard(int boardSize).
	**/

	ChessBoard();

	/**
	* Constructor passes a size parameter to the allocateBoard function, creating a 2D array of
	* size between 4 and 12.  Includes if statements to limit the size of the board to this range. 
	* 
	* @size the size of the board to be created.
	**/

	ChessBoard(int size);

	/**
	* Default destructor, calls deleteBoard().
	**/

	~ChessBoard();

	/**
	* Deletes the existing board using the deleteBoard() function and sets up a new board with the 
	* size specified.  Includes if statements to limit the size of the board to this range.  
	* 
	* @size the size of the board to be created.
	* @return void
	**/
	
	void setSize(int size);

	/**
	* Returns the size of the board.
	* 
	* @return int
	**/
	int getSize();

	/**
	* This function calls placeQueens(int col) to solve the NQueens puzzle, and returns true 
	* if the puzzle is successfully solved.  
	* 
	* @pre must pass an integer for the starting column when calling placeQueens().
	* @return bool
	**/

	bool solve();

	/**
	* This function outputs the contents of the 2D array pointed to by boardPtr using a for loop.
	*
	* @return void
	**/

	void displayBoard();
	
	

};

#endif 



