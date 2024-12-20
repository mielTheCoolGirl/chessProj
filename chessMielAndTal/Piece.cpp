#include "Piece.h"

Piece::Piece(const char& type, const string& currentCoords, const bool& color): 
    _color(color), _type(type),_currentCoords(currentCoords)
{
}

Piece::~Piece()
{
}

std::string Piece::lettersToCoords(string coords)
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

void Piece::setType(const char& newType)
{
    this->_type = newType;
}

void Piece::setCurrentCoords(const string& newCoords)
{
    this->_currentCoords = newCoords;
}

