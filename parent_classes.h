#pragma once
#include <vector>

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
typedef Brick BrickPtr;

class Container
{
protected:
    BrickPtr *BrickStorage;
    unsigned int Maxsize = -1;
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
    //~VectorBrickContainer();
    void SetCurrent(unsigned int a);
    void AddBrick(BrickPtr NewBrick);
    BrickPtr GetCurrent();
    unsigned int GetCount();
};
