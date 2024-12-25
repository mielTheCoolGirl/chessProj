#include "Board.h"
#include "Rook.h"
#include "Bishop.h"
#include "King.h"

#define LOWER_LET_TO_NUM 97
#define ASC_NUM_TO_NUM '0'

using std::cout;
using std::endl;

Board::Board(const std::string& build)
{
	int index = 0;
	std::string src = "";
	for (int i = 0; i < BOARD_LEN; i++)
	{
		for (int j = 0; j < BOARD_LEN; j++)
		{
			src += char(j + LOWER_LET_TO_NUM);
			src += char(i + ASC_NUM_TO_NUM + 1);
			index = i * BOARD_LEN + j;
			switch (tolower(build[index]))
			{
			case 'k':
				board[i][j] = new King(build[index], src);
				break;
			case 'r':
				board[i][j] = new Rook(build[index], src);
				break;
			default:
				board[i][j] = nullptr;
			}
		}
	}
}

Board::~Board()
{
	for (int i = 0; i < BOARD_LEN; i++)
	{
		for (int j = 0; j < BOARD_LEN; j++)
		{
			if (board[i][j] != nullptr)
			{
				delete board[i][j];
				board[i][j] = nullptr;
			}
		}

	}

}

void Board::printBoard() const
{
	std::string boardRes = "";
	cout << "  ";
	for (char xAxis = 'a'; xAxis < 'i'; xAxis++)
	{
		std::cout << xAxis << " ";
	}
	cout << endl;
	

	for (int i = 0; i < BOARD_LEN; i++)
	{
		std::cout << BOARD_LEN - i << " ";
		for (int j = 0; j < BOARD_LEN; j++)
		{
			if (board[i][j] == nullptr)
				cout << "# ";
			else
				cout << board[i][j]->getType() << " ";
		}
		cout << endl;
	}
	cout << endl;
}


bool Board::checkDanger(Piece* king)
{
	std::string kingCoords = Piece::lettersToCoords(king->getCurrentCoords());
	int kingX = kingCoords[1] - '0';
	int kingY = kingCoords[0] - '0';
	if (kingDanger(king, kingX, kingY) ||pawnCheck(king, kingX, kingY) || knightCheck(king, kingX, kingY) || checkHorizonAndVert(king, kingX, kingY) || diagonalCheck(king, kingX, kingY))
	{
		return true;
	}
	
	return false;

}

bool Board::isInBounds(int x, int y)
{
	return !(x > BOARD_LEN - 1 || x < 0 || y > BOARD_LEN - 1 || y < 0);
}

bool Board::checkHorizonAndVert(Piece* king, int kingX, int kingY)
{
	bool kingColor = king->getColor();
	bool potCheck = true; //Potiential check
	Piece* p = nullptr;
	for (int y = kingY + 1; y < BOARD_LEN && potCheck == true; y++) //check below to king
	{
		p = board[y][kingX];
		if (p != nullptr)
		{
			if (kingColor != p->getColor() && (tolower(p->getType()) == 'q' || tolower(p->getType()) == 'r'))
			{
				return true;
			}
			else
			{
				potCheck = false;
			}
		}
	}
	potCheck = true;
	for (int y = kingY - 1; y >= 0 && potCheck == true; y--) //check above the king
	{
		p = board[y][kingX];
		if (p != nullptr)
		{
			if (kingColor != p->getColor() && (tolower(p->getType()) == 'q' || tolower(p->getType()) == 'r'))
			{
				return true;
			}
			else
			{
				potCheck = false;
			}
		}
	}
	potCheck = true;
	for (int x = kingX + 1; x < BOARD_LEN && potCheck == true; x++) //check right to the king
	{
		p = board[kingY][x];
		if (p != nullptr)
		{
			if (kingColor != p->getColor() && (tolower(p->getType()) == 'q' || tolower(p->getType()) == 'r'))
			{
				return true;
			}
			else
			{
				potCheck = false;
			}
		}
	}
	potCheck = true;
	for (int x = kingX - 1; x >= 0 && potCheck == true; x--) //check left to the king
	{
		p = board[kingY][x];
		if (p != nullptr)
		{
			if (kingColor != p->getColor() && (tolower(p->getType()) == 'q' || tolower(p->getType()) == 'r'))
			{
				return true;
			}
			else
			{
				potCheck = false;
			}
		}
	}
	return false;
}


bool Board::pawnCheck(Piece* king, int kingX, int kingY)
{					
	if (king->getColor() == WHITE)
	{
		if ((isInBounds(kingX + 1, kingY + 1) && board[kingY + 1][kingX + 1] != nullptr && board[kingY + 1][kingX + 1]->getType() == 'p') ||
			(isInBounds(kingX + 1, kingY - 1) && board[kingY - 1][kingX + 1] != nullptr && board[kingY - 1][kingX + 1]->getType() == 'p'))
		{
			return true;
		}
	}
	else //black color
	{
		if ((isInBounds(kingX - 1, kingY - 1) && board[kingY - 1][kingX - 1] != nullptr && board[kingY - 1][kingX - 1]->getType() == 'P') ||
			(isInBounds(kingX + 1, kingY - 1) && board[kingY - 1][kingX + 1] != nullptr && board[kingY - 1][kingX + 1]->getType() == 'P'))
		{
			return true;
		}
	}
	return false;
	
}

bool Board::knightCheck(Piece* king, int kingX, int kingY)
{
	//storing all the possible attack places of knight's x and y across the board 
	int amountOfMovs = 8;
	int posX, posY;
	int knightMoveOptions[8][2] = { {-1,-2},{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2}};
	for (int i = 0; i < amountOfMovs; i++)
	{
		posX = knightMoveOptions[i][0] + kingX;
		posY = knightMoveOptions[i][1] + kingY;
		if (posX < BOARD_LEN && posX >= 0 && posY < BOARD_LEN && posY >= 0)
		{
			if (board[posY][posX] != nullptr)
			{
				if (board[posY][posX]->getColor() != king->getColor() && tolower(board[posY][posX]->getType()) == 'n')
				{
					/*if (board[posY][posX]->getColor())
					{
						_isChecking = WHITE_CHECKS;
					}
					else
					{
						_isChecking = BLACK_CHECKS;
					}*/
					return true;
				}
			}
		}
	}
	

	return false;
}

bool Board::diagonalCheck(Piece* king, int kingX, int kingY)
{
	bool possibleThreat = true;
	for (int i = kingX + 1, j = kingY + 1; i < BOARD_LEN && j < BOARD_LEN && possibleThreat == true; i++, j++)
	{
		if (board[j][i] != nullptr)
		{
			if (board[j][i]->getColor() != king->getColor() && tolower(board[j][i]->getType()) == 'b' || tolower(board[j][i]->getType()) == 'q')
			{
				possibleThreat = true;
			}
			else //if its a piece that doesnt threaten the king(diagonally)
			{
				possibleThreat = false;
			}
		}
	}

	possibleThreat = true;
	for (int i = kingX - 1, j = kingY - 1; i >= 0 && j >= 0 && possibleThreat == true; i--, j--)
	{
		if (board[j][i] != nullptr)
		{
			if (board[j][i]->getColor() != king->getColor() && tolower(board[j][i]->getType()) == 'b' || tolower(board[j][i]->getType()) == 'q')
			{
				possibleThreat = true;
			}
			else
			{
				possibleThreat = false;
			}
	
		}
	}
	
	possibleThreat = true;
	for (int i = kingX - 1, j = kingY + 1; i >= 0 && j < BOARD_LEN && possibleThreat == true; i--, j++)
	{
		if (board[j][i] != nullptr)
		{
			if (board[j][i]->getColor() != king->getColor() && tolower(board[j][i]->getType()) == 'b' || tolower(board[j][i]->getType()) == 'q')
			{
				possibleThreat = true;
			}
			else
			{
				possibleThreat = false;
			}
		}
	}

	possibleThreat = true;
	for (int i = kingX + 1, j = kingY - 1; i < BOARD_LEN && j >= 0 && possibleThreat == true; i++, j--)
	{
		if (board[j][i] != nullptr)
		{
			if (board[j][i]->getColor() != king->getColor() && tolower(board[j][i]->getType()) == 'b' || tolower(board[j][i]->getType()) == 'q')
			{
				possibleThreat = true;
			}
			else
			{
				possibleThreat = false;
			}
		}
	}
	return possibleThreat;
}

bool Board::kingDanger(Piece* king, int kingX, int kingY)
{
	for (int i = kingY - 1; i <= kingY + 1; i++)
	{
		for (int j = kingX - 1; j <= kingX + 1; j++)
		{
			if (isInBounds(j, i) && board[i][j] != nullptr && board[i][j]->getColor() != king->getColor() && tolower(board[i][j]->getType()) == 'k')
			{
				return true;
			}
		}
	}
	return false;
}

Piece* Board::findKing(const bool& color)
{
	for (int i = 0; i < BOARD_LEN;i++)
	{
		for (int j = 0; j < BOARD_LEN;j++)
		{
			if (board[i][j] != nullptr && board[i][j]->getColor() == color && tolower(board[i][j]->getType()) == 'k')
			{
				return board[i][j];
			}
		}
	}
}


