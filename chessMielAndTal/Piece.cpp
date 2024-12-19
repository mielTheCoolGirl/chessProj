#include "Piece.h"

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
    default:
        coords[2] = '!';
    }
}
