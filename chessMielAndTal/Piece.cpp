#include "Piece.h"

Piece::Piece(char type, std::string currentCoords): _type(type),_currentCoords(currentCoords)
{
}

std::string Piece::lettersToCoords(std::string coords)
{
    char firstLetter = coords[0];
    char secondLetter = coords[2];
    switch (firstLetter)
    {
        case 'a':
            coords[0] = '1';
            break;
        case 'b':
            coords[0] = '2';
            break;
        case 'c':
            coords[0] = '3';
            break;
        case 'd':
            coords[0] = '4';
            break;
        case 'e':
            coords[0] = '5';
            break;
        case 'f':
            coords[0] = '6';
            break;

        case 'g':
            coords[0] = '7';
            break;

        case 'h':
            coords[0] = '8';
            break;
        default:
                coords[0] = '!';
    }
    switch (secondLetter)
    {
    case 'a':
        coords[2] = '1';
        break;
    case 'b':
        coords[2] = '2';
        break;
    case 'c':
        coords[2] = '3';
        break;
    case 'd':
        coords[2] = '4';
        break;
    case 'e':
        coords[2] = '5';
        break;
    case 'f':
        coords[2] = '6';
        break;

    case 'g':
        coords[0] = '7';
        break;

    case 'h':
        coords[0] = '8';
        break;
    default:
        coords[2] = '!';
    }
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

