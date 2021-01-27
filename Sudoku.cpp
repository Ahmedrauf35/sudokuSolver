#include "Sudoku.h"


namespace ds {

bool Sudoku::isPresent(int col, int num) // function to check whether "it" is in column 
{
	for (int row = 0; row < 9; row++)
	{
		if(grid[row][col] == num)
		{
			return true;
		}
	}
	return false; 
}

bool Sudoku::isPresentRow(int row, int num) // same as above but for row
{
	for(int col = 0; col < 9; col++)
	{
		if(grid[row][col] == num)
		{
			return true;
		}
	}
	return false;
}
bool Sudoku::isPresBox(int strtrow, int strtcol, int num) // same but for 3x3
{
	for(int row = 0; row < 3; row++) // checks in a 3x3 box 
	{
		for(int col = 0; col < 3; col++)
		{
			if(grid[row+strtrow][col+strtcol] == num){
				return true;
			}
		}
	}
	return false;
}
bool Sudoku::findEmpt(int& row, int& col){ // returns true if empty i.e is solved
	for(row = 0; row < 9; row++)
	{
		for(col = 0; col < 9; col++)
		{
			if(grid[row][col] == 0)
			{
				return true;
			}
		}
	}
	return false;
}
bool Sudoku::isValid(int row, int col, int num){ // although not really, trying to "curry" all above functions
	return !isPresentRow(row, num) && !isPresent(col, num) && !isPresBox(row - row % 3, col - col % 3, num) && grid[row][col] == 0;
}

void Sudoku::readFrom1DArray(int *board) {
  // TODO: read the grid in the 1D array `board` to the 2D array
  // `this->grid`
  // NOTE: the `board` contains 81 `int`s, `this->grid` is 9x9
	int count = 0;
	for(int row = 0; row <= 8; row++) // ends at 8 bc array starts from 0, so 0-8 is 9 rows 
	{
		for(int col = 0; col <= 8; col++)
		{
			grid[row][col] = board[count];
			count++;
		}
	}
}
bool Sudoku::solve() { 
   int row, col;

  if(!findEmpt(row, col)) // if none are empty, board is filled in already 
   {
   	return true;
   }
   for(int num = 1; num <= 9; num++) // not array, is "num" so must start from digits 1-9
   {
   		if(isValid(row, col, num)) 
   		{
   			grid[row][col] = num;
   		if(solve()) // if fully solved
   		{
   			return true;
   		}
   		grid[row][col] = 0; // part of backtracking, 
   		}
   
   }
   return false;

}

} // namespace ds
