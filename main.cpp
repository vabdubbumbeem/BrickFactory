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
    for (int i = 0; i < 30; i++){
        MyContainer.AddBrick(new FireBrick(BrickSize::Double));
    }


    auto it = MyContainer.MkIterator();
    it->First();

    it->Next();
    it->GetCurrent()->Perforate();
    //it->GetCurrent()->PrintPerforated();
    it->First();



    //IteratorDouble<BrickPtr> itd(it);
    IteratorPerforated<BrickPtr> itdp(it);
    //IteratorPerforated<BrickPtr> itp(&itd);

    itdp.First();
    while(!itdp.IsDone()){
        itdp.GetCurrent()->PrintPerforated();

        itdp.Next();
    }
    //itp.GetCurrent()->PrintPerforated();


    return 0;

}
