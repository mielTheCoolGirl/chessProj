#include "Board.h"
#include "Rook.h"
#include "King.h"
#define A_VALUE 97
#define WHITE 1
#define BLACK 0
#define BLACK_CHECKS 2 
#define WHITE_CHECKS 1
Board::Board() : _isChecking(0)
{

	for (int i = 0; i < BOARD_LEN; i++)
	{
		for (int j = 0; j < BOARD_LEN; j++)
			board[i][j] = nullptr;
	}
	//putting all the rooks in place(for checking, in the main game it will be pawns)
	for (int i = 0; i < BOARD_LEN; i++)
	{
		std::string resCoord = "";
		char res = char(i + A_VALUE);
		resCoord += res;
		resCoord += "7";
		board[1][i] = new Rook('R', resCoord, WHITE);

	}
	for (int i = 0; i < BOARD_LEN; i++)
	{
		std::string resCoord = "";
		char res = char(i + A_VALUE);
		resCoord += res;
		resCoord += "2";
		board[6][i] = new Rook('p', resCoord, BLACK);
	}

	board[5][0] = new King('K', "a1", WHITE);//setting up a king to see if he eats


}

Board::~Board()
{
}

void Board::printBoard() const
{
	std::string boardRes = "";
	for (int i = 0; i < BOARD_LEN; i++)
	{
		for (int j = 0; j < BOARD_LEN; j++)
		{
			if (board[i][j] == nullptr)
				boardRes += "#";
			else
				boardRes += board[i][j]->getType();
			boardRes += " ";
		}
		boardRes += "\n";
	}
	std::cout << boardRes << std::endl;
}

int Board::getIsChecking() const
{
	return _isChecking;
}

void Board::setIsChecking(int state)
{
	_isChecking = state;
}

bool Board::checkDanger(Piece* king)
{
	std::string kingCoords = Piece::lettersToCoords(king->getCurrentCoords());
	int kingX = kingCoords[1] - '0';
	int kingY = kingCoords[0] - '0';
	if (pawnCheck(king, kingX, kingY) || checkHorizonAndVert(king, kingX, kingY)|| knightCheck(king,kingX,kingY))
		return true;
	return false;

}

bool Board::isInBounds(int x, int y)
{
	return !(x > BOARD_LEN - 1 || x < 0 || y > BOARD_LEN - 1 || y < 0);
}

bool Board::checkHorizonAndVert(Piece* king, int kingX, int kingY)
{
	for (int i = 0; i < BOARD_LEN; i++)
	{
		if (board[i][kingX] != nullptr)
		{
			if (board[i][kingX]->getColor() != king->getColor() &&
				tolower(board[i][kingX]->getType()) == 'r' || tolower(board[i][kingX]->getType()) == 'q')
			{
				//changing the check status into 1 if white checks black and 2 if black checks white
				if (board[i][kingX]->getColor())
				{
					_isChecking = WHITE_CHECKS;
				}
				else
				{
					_isChecking = BLACK_CHECKS;
				}
				return true;
			}

			if (board[kingY][i]->getColor() != king->getColor() &&
				(tolower(board[kingY][i]->getType()) == 'r' || tolower(board[kingY][i]->getType()) == 'q'))
			{
				//changing the check status into 1 if white checks black and 2 if black checks white
				if (board[kingY][i]->getColor())
				{
					_isChecking = WHITE_CHECKS;
				}
				else
				{
					_isChecking = BLACK_CHECKS;
				}
				return true;
			}
		}
	}
	
	return false;
}


bool Board::pawnCheck(Piece* king, int kingX, int kingY)
{
	//if the king's white we check for black pawn movement(since black peices move from downwards up in the board)
	
	/*if (king->getColor())
	{
		if (kingY + 1 < BOARD_LEN)
		{
			if (board[kingY + 1][kingX + 1] != nullptr)
			{
				if (board[kingY + 1][kingX + 1]->getColor() != king->getColor() && tolower(board[kingY + 1][kingX + 1]->getType()) == 'b' || tolower(board[kingY + 1][kingX + 1]->getType()) == 'q' || tolower(board[kingY + 1][kingX + 1]->getType()) == 'p' || tolower(board[kingY + 1][kingX + 1]->getType()) == 'k')
				{
					if (board[kingY + 1][kingX + 1]->getColor())
					{
						_isChecking = 1;
					}
					else
					{
						_isChecking = 2;
					}
					return true;
				}
			}
		}
		if (kingX - 1 >= 0)
		{
			if (board[kingY + 1][kingX - 1] != nullptr)
			{
				if (board[kingY + 1][kingX - 1]->getColor() != king->getColor() && tolower(board[kingY + 1][kingX - 1]->getType()) == 'b' || tolower(board[kingY + 1][kingX - 1]->getType()) == 'q' || tolower(board[kingY + 1][kingX - 1]->getType()) == 'p' || tolower(board[kingY + 1][kingX - 1]->getType()) == 'k')
				{
					if (board[kingY + 1][kingX - 1]->getColor())
					{
						_isChecking = 1;
					}
					else
					{
						_isChecking = 2;
					}
					return true;
				}

			*/
		
		
				
	if (king->getColor() == WHITE)
	{
		if ((isInBounds(kingX - 1, kingY - 1) && board[kingY - 1][kingX - 1] != nullptr && board[kingY - 1][kingX - 1]->getType() == 'p') || 
			(isInBounds(kingX + 1, kingY - 1) && board[kingY - 1][kingX + 1] != nullptr && board[kingY - 1][kingX + 1]->getType() == 'p'))
		{
			_isChecking = BLACK_CHECKS;
			return true;
		}
	}
	else //black color
	{
		if ((isInBounds(kingX - 1, kingY - 1) && board[kingY - 1][kingX - 1] != nullptr && board[kingY - 1][kingX - 1]->getType() == 'P') ||
			(isInBounds(kingX + 1, kingY - 1) && board[kingY - 1][kingX + 1] != nullptr && board[kingY - 1][kingX + 1]->getType() == 'P'))
		{
			_isChecking = WHITE_CHECKS;
			return true;
		}
	}
	//white pawns eat from up to down digaonlly
	/*else
	{
		if (kingY - 1 >= 0)
		{
			if (board[kingY - 1][kingX - 1] != nullptr)
			{
				if (board[kingY - 1][kingX - 1]->getColor() != king->getColor() && tolower(board[kingY - 1][kingX - 1]->getType()) == 'b' || tolower(board[kingY - 1][kingX - 1]->getType()) == 'q' || tolower(board[kingY - 1][kingX - 1]->getType()) == 'p' || tolower(board[kingY - 1][kingX - 1]->getType()) == 'k')
				{
					if (board[kingY - 1][kingX - 1]->getColor())
					{
						_isChecking = 1;
					}
					else
					{
						_isChecking = 2;
					}
					return true;
				}
			}
		}
		if (kingX + 1 < BOARD_LEN)
		{
			if (board[kingY - 1][kingX + 1] != nullptr)
			{
				if (board[kingY - 1][kingX + 1]->getColor() != king->getColor() && tolower(board[kingY - 1][kingX + 1]->getType()) == 'b' || tolower(board[kingY - 1][kingX + 1]->getType()) == 'q' || tolower(board[kingY - 1][kingX + 1]->getType()) == 'p' || tolower(board[kingY - 1][kingX + 1]->getType()) == 'k')
				{
					if (board[kingY - 1][kingX + 1]->getColor())
					{
						_isChecking = 1;
					}
					else
					{
						_isChecking = 2;
					}
					return true;
				}
			}
		}
		
	}*/
	return false;
	
}

bool Board::knightCheck(Piece* king, int kingX, int kingY)
{
	
	if (kingY + 1 < BOARD_LEN)
	{
		if (kingX - 2 >= 0)
		{
			if (kingX - 2 >= 0)
			{
				if (board[kingY + 1][kingX - 2] != nullptr)
				{
					if (board[kingY + 1][kingX - 2]->getColor() != king->getColor() && tolower(board[kingY + 1][kingX - 2]->getType()) == 'n')
					{
						if (board[kingY + 1][kingX - 2]->getColor())
						{
							_isChecking = 1;
						}
						else
						{
							_isChecking = 2;
						}
						return true;
					}
				}
				
			}
			if (board[kingY + 2][kingX - 1] != nullptr)
			{
				if (board[kingY + 2][kingX - 1]->getColor() != king->getColor() && tolower(board[kingY + 2][kingX - 1]->getType()) == 'n')
				{
					if (board[kingY + 2][kingX - 1]->getColor())
					{
						_isChecking = 1;
					}
					else
					{
						_isChecking = 2;
					}
					return true;
				}
			}

		}
		
		if (kingX+1<BOARD_LEN)
		{
			if (board[kingY + 2][kingX + 1] != nullptr)
			{
				if (board[kingY + 2][kingX + 1]->getColor() != king->getColor() && tolower(board[kingY + 2][kingX + 1]->getType()) == 'n')
				{
					if (board[kingY + 2][kingX + 1]->getColor())
					{
						_isChecking = 1;
					}
					else
					{
						_isChecking = 2;
					}
					return true;
				}
			}
			
			if (kingX + 2 < BOARD_LEN)
			{
				if (board[kingY + 1][kingX + 2] != nullptr)
				{
					if (board[kingY + 1][kingX + 2]->getColor() != king->getColor() && tolower(board[kingY + 1][kingX + 2]->getType()) == 'n')
					{
						if (board[kingY + 1][kingX + 2]->getColor())
						{
							_isChecking = 1;
						}
						else
						{
							_isChecking = 2;
						}
						return true;
					}
				}
				
			}
		}

	}
	
	if (kingY - 1 >= 0)
	{
	
		if (kingX - 1 >= 0)
		{
			if (board[kingY - 2][kingX - 1] != nullptr)
			{
				if (board[kingY - 2][kingX - 1]->getColor() != king->getColor() && tolower(board[kingY - 2][kingX - 1]->getType()) == 'n')
				{
					if (board[kingY - 2][kingX - 1]->getColor())
					{
						_isChecking = 1;
					}
					else
					{
						_isChecking = 2;
					}
					return true;
				}
				if (kingX - 2 >= 0)
				{
					if (board[kingY - 1][kingX - 2] != nullptr)
					{
						if (board[kingY - 1][kingX - 2]->getColor() != king->getColor() && tolower(board[kingY - 1][kingX - 2]->getType()) == 'n')
						{
							if (board[kingY - 1][kingX - 2]->getColor())
							{
								_isChecking = 1;
							}
							else
							{
								_isChecking = 2;
							}
							return true;
						}
					}
				}

			}
			
		}
		
		

		if (kingX + 1 < BOARD_LEN)
		{
			if (board[kingY - 2][kingX + 1] != nullptr)
			{
				if (board[kingY - 2][kingX + 1]->getColor() != king->getColor() && tolower(board[kingY - 2][kingX + 1]->getType()) == 'n')
				{
					if (board[kingY - 2][kingX + 1]->getColor())
					{
						_isChecking = 1;
					}
					else
					{
						_isChecking = 2;
					}
					return true;
				}
			}
			
			if (kingX + 2 < BOARD_LEN)
			{
				if (board[kingY - 1][kingX + 2] != nullptr)
				{
					if (board[kingY - 1][kingX + 2]->getColor() != king->getColor() && tolower(board[kingY - 1][kingX + 2]->getType()) == 'n')
					{
						if (board[kingY - 1][kingX + 2]->getColor())
						{
							_isChecking = 1;
						}
						else
						{
							_isChecking = 2;
						}
						return true;
					}
				}
				
			}

		}
		
	}

	return false;
}

bool Board::diagonalCheck(Piece* king, int kingX, int kingY)
{
	for (int i = kingX, j = kingY; i < BOARD_LEN && j < BOARD_LEN; i++, j++)
	{
		if (board[j][i] != nullptr)
		{
			if (board[j][i]->getColor() != king->getColor() && tolower(board[j][i]->getType()) == 'b' || tolower(board[j][i]->getType()) == 'q')
			{
				if (board[j][i]->getColor())
				{
					_isChecking = 1;
				}
				else
				{
					_isChecking = 2;
				}
				return true;
			}
		}
	}

	for (int i = kingX, j = kingY; i >= 0 && j >= 0; i--, j--)
	{
		if (board[j][i] != nullptr)
		{
			if (board[j][i]->getColor() != king->getColor() && tolower(board[j][i]->getType()) == 'b' || tolower(board[j][i]->getType()) == 'q')
			{
				if (board[j][i]->getColor())
				{
					_isChecking = 1;
				}
				else
				{
					_isChecking = 2;
				}
				return true;
			}
		}
	}

	for (int i = kingX, j = kingY; i >= 0 && j < BOARD_LEN; i--, j++)
	{
		if (board[j][i] != nullptr)
		{
			if (board[j][i]->getColor() != king->getColor() && tolower(board[j][i]->getType()) == 'b' || tolower(board[j][i]->getType()) == 'q')
			{
				if (board[j][i]->getColor())
				{
					_isChecking = 1;
				}
				else
				{
					_isChecking = 2;
				}
				return true;
			}
		}
	}
	for (int i = kingX, j = kingY; i < BOARD_LEN && j >= 0; i++, j--)
	{
		if (board[j][i] != nullptr)
		{
			if (board[j][i]->getColor() != king->getColor() && tolower(board[j][i]->getType()) == 'b' || tolower(board[j][i]->getType()) == 'q')
			{
				if (board[j][i]->getColor())
				{
					_isChecking = 1;
				}
				else
				{
					_isChecking = 2;
				}
				return true;
			}
		}
	}
	return false;
}


