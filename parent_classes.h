#pragma once

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
    virtual BrickMaterial GetMaterial() = 0;
    virtual BrickSize GetSize() = 0;
    virtual BrickType GetType() = 0;

};
