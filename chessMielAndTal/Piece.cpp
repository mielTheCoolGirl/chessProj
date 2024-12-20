#include "Piece.h"

Piece::Piece(const char& type, const std::string& currentCoords, const bool& color): 
    _color(color), _type(type),_currentCoords(currentCoords)
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

void Piece::setType(const char& newType)
{
    this->_type = newType;
}

void Piece::setCurrentCoords(const std::string& newCoords)
{
    this->_currentCoords = newCoords;
}

bool Piece::getColor() const
{
    return _color;
}

void Piece::setColor(const bool& color)
{
    _color = color;
}

