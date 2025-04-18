#include "parent_classes.h"
#include <iostream>

BrickSize Brick::GetSize() {return Size;}

void Brick::Perforate() {
    Perforated = true;
}
bool Brick::IsPerforated(){
    return Perforated;
}

void Brick::PrintPerforated(){
    if(Perforated){std::cout << "Brick is perforated\n";} else{std::cout << "Brick isn't perforated\n";}
}
//VectorBrickContainerIterator
VectorBrickContainerIterator::VectorBrickContainerIterator(const std::vector<BrickPtr> *brickstorage)
    {
        BrickStorage = brickstorage;
        this->First();
    }

BrickPtr VectorBrickContainerIterator::GetCurrent() {return *it;}

void VectorBrickContainerIterator::First() {it = BrickStorage->begin();}

void VectorBrickContainerIterator::Next() {if(!this->IsDone()){it++;}}

bool VectorBrickContainerIterator::IsDone() {return (it >= BrickStorage->end());}

// VectorBrickContainer
void VectorBrickContainer::SetCurrent(unsigned int a){Pointer = a;}

BrickPtr VectorBrickContainer::GetCurrent(){return BrickStorage[Pointer];}

void VectorBrickContainer::AddBrick(BrickPtr NewBrick){BrickStorage.push_back(NewBrick); Counter++;}

unsigned int VectorBrickContainer::GetCount(){return Counter;}

Iterator<BrickPtr> *VectorBrickContainer::MkIterator() {
    return new VectorBrickContainerIterator(&BrickStorage);
}
//ConstSizeContainerIterator

ConstSizeContainerIterator::ConstSizeContainerIterator(BrickPtr **brickstorage, unsigned int counter){
    BrickStorage = *brickstorage;
    Pointer = 0;
    Counter = counter;
}

void ConstSizeContainerIterator::First() {Pointer = 0;}

void ConstSizeContainerIterator::Next() {if(!this->IsDone()){Pointer++;}}

bool ConstSizeContainerIterator::IsDone() {return Pointer >= Counter;}

BrickPtr ConstSizeContainerIterator::GetCurrent() {return BrickStorage[Pointer];}

//ConstSizeContainer
void ConstSizeContainer::SetCurrent(unsigned int a){Pointer = a;}

BrickPtr ConstSizeContainer::GetCurrent(){return BrickStorage[Pointer];}

void ConstSizeContainer::AddBrick(BrickPtr NewBrick){
    if(Counter < MaxSize){
        BrickStorage[Counter] = NewBrick; Counter++;
    }
    else {std::cout << "Container is full!\n";}
}

unsigned int ConstSizeContainer::GetCount(){return Counter;}

ConstSizeContainer::ConstSizeContainer(unsigned int maxsize){BrickStorage = new BrickPtr[maxsize]; MaxSize = maxsize;}

Iterator<BrickPtr> *ConstSizeContainer::MkIterator() {
    return new ConstSizeContainerIterator(&BrickStorage, Counter);
}

//ITERATORPERFORATED

//IteratorPerforated::IteratorPerforated(Iterator<BrickPtr> *it) {It = it;}

//void IteratorPerforated::First() { It->First(); }

//void IteratorPerforated::Next() { It->Next()}

//bool IteratorPerforated::IsDone() { return It->IsDone(); }

//Type IteratorPerforated::GetCurrent() { return It->GetCurrent(); }

//IteratorPerforated::~IteratorPerforated() { delete It; }

