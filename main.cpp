#include <iostream>
#include "parent_classes.h"

using namespace std;

float power(int a, int n){
    float res = 1;
    if(n > 0){
        for(int i = 0; i < n; i++){res *= a;}
        }
    else{
        for(int i = 0; i < -n; i++){res /= a;}
    }
    return res;
}


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
    FireBrick Brick0002(BrickSize::Double);
    Brick0002.Perforate();

    MyContainer.AddBrick(&Brick0001);
    MyContainer.AddBrick(&Brick0002);
    auto it = MyContainer.MkIterator();
    it->First();
    it->GetCurrent()->PrintPerforated();
    it->Next();
    it->GetCurrent()->PrintPerforated();

        //constSizeContainer test
        /*
    ConstSizeContainer MyConstContainer(5);
    MyConstContainer.AddBrick(&Brick0001);
    MyConstContainer.SetCurrent(0);
    MyConstContainer.GetCurrent()->PrintPerforated();
*/
    //Brick0001.PrintPerforated();
    cout << (int)Brick0001.GetSize() << endl;
    cout << (int)Brick0002.GetSize() << endl;
    return 0;

}
