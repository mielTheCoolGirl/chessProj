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

Piece* Piece::eat(Board& b, const std::string& dstCoords)
{
    std::string numSrc = lettersToCoords(_currentCoords);
    std::string numDst = lettersToCoords(dstCoords);

    int srcY = int(numSrc[0] - '0'), srcX = int(numSrc[1] - '0');
    int dstY = int(numDst[0] - '0'), dstX = int(numDst[1] - '0');
    std::string prevCoords = _currentCoords;
    Piece* eaten = b.board[dstY][dstX];
    Piece* king = b.findKing(b.board[srcY][srcX]->getColor());

    b.board[dstY][dstX] = b.board[srcY][srcX];
    b.board[srcY][srcX] = nullptr;
    b.board[dstY][dstX]->setCurrentCoords(dstCoords); //new coords of piece

    if (b.checkDanger(king)) //if king is checked
    {
        b.board[dstY][dstX]->setCurrentCoords(prevCoords);
        b.board[srcY][srcX] = b.board[dstY][dstX];
        b.board[dstY][dstX] = eaten;
        throw(4); //check expn
    }
    delete eaten;
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

int Piece::getFirstTurn() const
{
    return _isFirstTurn;
}

void Piece::setFirstTurn(const int state)
{
    _isFirstTurn = state;
}