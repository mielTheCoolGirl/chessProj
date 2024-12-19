#include "Bishop.h"
Bishop::Bishop(char bishopType, std::string coords) :LinearMovement(bishopType, coords)
{

}
Bishop::~Bishop()
{
}
bool Bishop::legalMovement()
{
    return false;
}
