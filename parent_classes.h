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
    BrickMaterial GetMaterial();
    BrickSize GetSize();
    BrickType GetType();

};
typedef Brick *BrickPtr;

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

class VectorBrickContainer: public Container{
protected:
    std::vector<BrickPtr> BrickStorage;
public:
    //VectorBrickContainer();
    ~VectorBrickContainer(){BrickStorage.clear();}
    void SetCurrent(unsigned int a);
    void AddBrick(BrickPtr NewBrick);
    BrickPtr GetCurrent();
    unsigned int GetCount();
};

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

