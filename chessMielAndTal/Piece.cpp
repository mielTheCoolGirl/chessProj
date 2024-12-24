#include "Piece.h"
#include "Rook.h"
class Rook;
#include "King.h"
class King;
Piece::Piece(const char& type, const std::string& currentCoords, const bool& color): 
    _color(color), _type(type),_currentCoords(currentCoords)
{
}

Piece::~Piece()
{
}

Piece* Piece::eat(Board& b, const std::string& targetCoords)
{
    Piece* p = b.board[int(targetCoords[0] - ASC_NUM_TO_NUM)][int(targetCoords[1] - ASC_NUM_TO_NUM)];
    if (p == nullptr)
    {
        return nullptr;
    }

    switch (tolower(p->getType()))
    {
    case 'r':
        return new Rook(p->_type, p->_currentCoords, p->_color);
    default:
        return nullptr;
    }
}


std::string Piece::lettersToCoords(std::string coords) //a2 [6][0]
{
    int letterToNum = coords[0] - LOWER_LET_TO_NUM;
    int yAxis = BOARD_LEN - (coords[1] - ASC_NUM_TO_NUM);
    return  std::to_string(yAxis) + std::to_string(letterToNum);
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

Piece& Piece::operator=(const Piece& other)
{
    if (this == &other)
    {
        return *this;
    }

    this->_color = other._color;
    this->_type = other._type;
    this->_currentCoords = other._currentCoords;

    return *this;
}

