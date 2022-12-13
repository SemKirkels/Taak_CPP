#include "cpu.h"

CPU::CPU()
{

}

int CPU::placeSymbol()
{
    srand(time(NULL));
    location = (rand() % 9);

    return location;
}

CPU::~CPU()
{

}
