#include <iostream>
#include "parent_classes.h"

using namespace std;


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
    VectorBrickContainer MyContainer;

    FireBrick Brick0001(BrickSize::OneAndHalf);
    MyContainer.AddBrick(Brick0001);
    MyContainer.SetCurrent(0);
    MyContainer.GetCurrent().PrintPerforated();
    //Brick0001.PrintPerforated();
    cout << (int)Brick0001.GetSize() << endl;
    cout << (int)Brick0001.GetMaterial() << endl;
    return 0;
}
