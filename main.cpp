#include <iostream>
using namespace std;

enum class BrickSize:int
{
    Normal,
    OneAndHalf,
    Double
};

enum class BrickMaterial:int
{
    Clay,
    CalciumSilicate,
    FireClay
};

enum class BrickType:int
{
    Bilding,
    Fire,
    Facing
};

class Brick
{
protected:
    bool Perforated = false;
    BrickSize Size;
    BrickMaterial Material;
    BrickType Type;
public:
    bool IsPerforated() {return Perforated;}
    void PrintPerforated() {if(Perforated){cout << "Brick is perforated\n";} else{cout << "Brick isn't perforated\n";}}
    virtual BrickMaterial GetMaterial() = 0;
    virtual BrickSize GetSize() = 0;
    virtual BrickType GetType() = 0;

};


class FireBrick: public Brick
{
public:
    FireBrick(BrickSize sizeBrick) {Size = sizeBrick; Type = BrickType::Fire; Material = BrickMaterial::FireClay;}
    BrickType GetType() {return BrickType::Fire;}
    BrickMaterial GetMaterial() {return BrickMaterial::FireClay;}
    BrickSize GetSize() {return Size;}
};    

class BildingBrick: public Brick
{
public:
      BildingBrick(BrickSize sizeBrick, BrickMaterial material) {Type = BrickType::Bilding; Size = sizeBrick; Material = material;}
      BrickType GetType() {return BrickType::Bilding;}
      BrickMaterial GetMaterial() {return Material;}
      BrickSize GetSize() {return Size;}
};

class FacingBrick: public Brick
{
public:
      FacingBrick(BrickSize sizeBrick, BrickMaterial material) {Type = BrickType::Facing; Size = sizeBrick; Material = material;}
      BrickType GetType() {return BrickType::Facing;}
      BrickMaterial GetMaterial() {return Material;}
      BrickSize GetSize() {return Size;}
};

int main()
{
    FireBrick Brick0001(BrickSize::Normal);
    Brick0001.PrintPerforated();
    int a = 0;
    return 0;
}
