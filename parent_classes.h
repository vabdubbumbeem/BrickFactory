#pragma once
#include <vector>
#include "sqlite3.h"

enum class BrickType:int
{
    Bilding,
    Fire,
    Facing
};

enum class BrickMaterial:int
{
    Clay,
    CalciumSilicate,
    FireClay
};

enum class BrickSize:int
{
    Normal,
    OneAndHalf,
    Double
};

//BRICK
class Brick
{
protected:
    bool Perforated = false;
    BrickSize Size;
    BrickMaterial Material;
    BrickType Type;
public:
    bool IsPerforated();
    void PrintPerforated();
    void Perforate();
    BrickMaterial GetMaterial();
    BrickSize GetSize();
    BrickType GetType();

};
typedef Brick *BrickPtr;

//ITERATOR
template<class Type> class Iterator
{
protected:
    Iterator() {}

public:
    //virtual ~Iterator() {} // диструктор
    virtual void First() = 0;
    virtual void Next() = 0;
    virtual bool IsDone() = 0;
    virtual Type GetCurrent() = 0;
};

//VECTORBRICKCONTAINERITERATOR
class VectorBrickContainerIterator : public Iterator<BrickPtr>
{
private:
    const std::vector<BrickPtr> *BrickStorage;
    std::vector<BrickPtr>::const_iterator it;

public:
    VectorBrickContainerIterator(const std::vector<BrickPtr> *brickstorage);
    void First();
    void Next();
    bool IsDone();
    BrickPtr GetCurrent();
};

//CONTAINER
class Container
{
protected:
    BrickPtr *BrickStorage;
    unsigned int MaxSize = 0;
    unsigned int Pointer = 0;
    unsigned int Counter = 0;
public:
    virtual BrickPtr GetCurrent() = 0;
    virtual unsigned int GetCount() = 0;
    virtual void SetCurrent(unsigned int a) = 0;
    virtual void AddBrick(BrickPtr NewBrick) = 0;
};

//VECTORBRICKCONTAINER
class VectorBrickContainer: public Container{
protected:
    std::vector<BrickPtr> BrickStorage;
public:
    //VectorBrickContainer();
    //~VectorBrickContainer(){BrickStorage.clear();}
    void SetCurrent(unsigned int a);
    void AddBrick(BrickPtr NewBrick);
    BrickPtr GetCurrent();
    unsigned int GetCount();
    Iterator<BrickPtr> *MkIterator(const std::vector<BrickPtr> *brickstorage);
    Iterator<BrickPtr> *MkIterator();
};

//CONSTSIZECONTAINER
class ConstSizeContainer: public Container{
protected:
    BrickPtr *BrickStorage;
    unsigned int MaxSize = 0;
    unsigned int Pointer = 0;
    unsigned int Counter = 0;
public:
    ~ConstSizeContainer(){delete BrickStorage;};
    ConstSizeContainer(unsigned int maxsize);
    void SetCurrent(unsigned int a);
    void AddBrick(BrickPtr NewBrick);
    BrickPtr GetCurrent();
    unsigned int GetCount();
};


