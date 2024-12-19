#include "Piece.h"

Piece::Piece(char type, std::string currentCoords): _type(type),_currentCoords(currentCoords)
{
}

Piece::~Piece()
{
}

std::string Piece::lettersToCoords(std::string coords)
{
    coords[0] -= LOWER_LET_TO_NUM;
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

void Piece::setType(char newType)
{
    _type = newType;
}

void Piece::setCurrentCoords(std::string newCoords)
{
    _currentCoords = newCoords;
}

