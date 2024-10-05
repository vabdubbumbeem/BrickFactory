#include "parent_classes.h"
#include <iostream>



bool Brick::IsPerforated(){
    return Perforated;
}

void Brick::PrintPerforated(){
    if(Perforated){std::cout << "Brick is perforated\n";} else{std::cout << "Brick isn't perforated\n";}
}

typedef Brick BrickPtr;



void VectorBrickContainer::SetCurrent(unsigned int a){Pointer = a;}

BrickPtr VectorBrickContainer::GetCurrent(){return BrickStorage[Pointer];}

void VectorBrickContainer::AddBrick(BrickPtr NewBrick){BrickStorage.push_back(NewBrick); Counter++;}

unsigned int VectorBrickContainer::GetCount(){return Counter;}

//VectorBrickContainer::VectorBrickContainer()


