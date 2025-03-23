#include "parent_classes.h"
#include <iostream>



bool Brick::IsPerforated(){
    return Perforated;
}

void Brick::PrintPerforated(){
    if(Perforated){std::cout << "Brick is perforated\n";} else{std::cout << "Brick isn't perforated\n";}
}

// VectorBrickContainer
void VectorBrickContainer::SetCurrent(unsigned int a){Pointer = a;}

BrickPtr VectorBrickContainer::GetCurrent(){return BrickStorage[Pointer];}

void VectorBrickContainer::AddBrick(BrickPtr NewBrick){BrickStorage.push_back(NewBrick); Counter++;}

unsigned int VectorBrickContainer::GetCount(){return Counter;}


//ConstSizeContainer
void ConstSizeContainer::SetCurrent(unsigned int a){Pointer = a;}

BrickPtr ConstSizeContainer::GetCurrent(){return BrickStorage[Pointer];}

void ConstSizeContainer::AddBrick(BrickPtr NewBrick){
    if(Counter < MaxSize){
        BrickStorage[Counter] = NewBrick; Counter++;
    }
}

unsigned int ConstSizeContainer::GetCount(){return Counter;}

ConstSizeContainer::ConstSizeContainer(unsigned int maxsize){BrickStorage = new BrickPtr[maxsize]; MaxSize = maxsize;}


