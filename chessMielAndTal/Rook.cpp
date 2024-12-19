#include "Rook.h"
Rook::Rook(char rookType, std::string coords):LinearMovement(rookType,coords)
{

}

Rook::~Rook()
{
}

bool Rook::legalMovement()
{
	return false;
}
