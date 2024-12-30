#include "Piece.h"
#include "Rook.h"
class Rook;
#include "King.h"
class King;

Piece::Piece(const char& type, const std::string& currentCoords): 
    _type(type), _currentCoords(currentCoords)
{
    if (islower(type))
    {
        _color = BLACK;
    }
    else
    {
        _color = WHITE;
    }
    if (tolower(type) == 'p')
    {
        _isFirstTurn = TRUE;
    }
    else
    {
        _isFirstTurn = FALSE;
    }
    
}

Piece::~Piece()
{
}

Piece* Piece::eat(Board& b, const std::string& targetCoords)
{
    return b.board[int(targetCoords[0] - '0')][int(targetCoords[1] - '0')];
    
}


std::string Piece::lettersToCoords(std::string letters) //a2 [6][0]
{
    std::string coords = "";
    int letterToNum = letters[0] - LOWER_LET_TO_NUM;
    int yAxis = BOARD_LEN - (letters[1] - ASC_NUM_TO_NUM);
    coords = std::to_string(yAxis);
    coords += std::to_string(letterToNum);
    return coords;
}


char Piece::getType() const
{
    return _type;
}

std::string Piece::getCurrentCoords() const
{
    return _currentCoords;
}

void Piece::setType(const char& newType)
{
    this->_type = newType;
}

void Piece::setCurrentCoords(const std::string newCoords)
{
    _currentCoords = newCoords;
}

bool Piece::getColor() const
{
    return _color;
}

void Piece::setColor(const bool& color)
{
    _color = color;
}

bool Piece::getFirstTurn() const
{
    return _isFirstTurn;
}

void Piece::setFirstTurn(const bool state)
{
    _isFirstTurn = state;
}