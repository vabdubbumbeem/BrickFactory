#pragma once
#include <vector>
#include "sqlite3.h"

enum class BrickType:int
{
    undefined=-1,
    Bilding,
    Fire,
    Facing
};

enum class BrickMaterial:int
{
    undefined=-1,
    Clay,
    CalciumSilicate,
    FireClay
};

enum class BrickSize:int
{
    undefined=-1,
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

class nullBrick: public Brick
{
    nullBrick(){
        Size = BrickSize::undefined;
        Material = BrickMaterial::undefined;
        Type = BrickType::undefined;
    }
};

//ITERATOR
template<class Type> class Iterator
{
protected:
    Iterator() {}

public:
    virtual ~Iterator() {} // диструктор
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
    ~VectorBrickContainer(){
        for(auto i = BrickStorage.begin(); i < BrickStorage.end(); i++){
            delete *i;
        }
        BrickStorage.clear();
    }
    void SetCurrent(unsigned int a);
    void AddBrick(BrickPtr NewBrick);
    BrickPtr GetCurrent();
    unsigned int GetCount();
    Iterator<BrickPtr> *MkIterator();
};
//CONSTSIZECONTAINERITERATOR
class ConstSizeContainerIterator : public Iterator<BrickPtr>
{
private:
    const BrickPtr *BrickStorage;
    unsigned int Pointer = 0;
    unsigned int Counter = 0;
public:
    ConstSizeContainerIterator(BrickPtr **brickstorage, unsigned int counter);
    void First();
    void Next();
    bool IsDone();
    BrickPtr GetCurrent();
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
    Iterator<BrickPtr> *MkIterator();
};

//ITERATORDECORATOR
template<class Type>
class IteratorDecorator : public Iterator<Type>
{
protected:
    Iterator<Type> *It;
public:
    //IteratorDecorator(Iterator<Type> *it)
    //{
    //    It = it;
    //}
    virtual ~IteratorDecorator() { } // деструктор
    void First() { It->First(); }
    void Next() { if(!It->IsDone()){It->Next();} }
    bool IsDone() { return It->IsDone(); }
    Type GetCurrent() { return It->GetCurrent(); }
};

//ITERATORPERFORATED
template<class Type>
class IteratorPerforated : public IteratorDecorator<Type>
{
protected:
    Iterator<Type> *It;
public:
    IteratorPerforated(Iterator<BrickPtr> *it){
        It = it;
        this->First();
    }
    //~IteratorPerforated() { delete It; } // диструктор
    void First() {
        It->First();
        while(!It->GetCurrent()->IsPerforated() && !It->IsDone()){
            It->Next();
        }
    }
    void Next() {
        if(!It->IsDone()){
            It->Next();
            while(!It->IsDone()){
                if(!It->GetCurrent()->IsPerforated() ){
                    It->Next();
                }
                else{
                    break;
                }
            }
        }
    }
    bool IsDone() {return It->IsDone();}
    Type GetCurrent() {return It->GetCurrent();}
};

//ITERATORDOUBLE
template<class Type>
class IteratorDouble : public IteratorDecorator<Type>
{protected:
    Iterator<Type> *It;
public:
    IteratorDouble(Iterator<BrickPtr> *it){
        It = it;
        this->First();
    }
    void First() {It->First(); while(It->GetCurrent()->GetSize() != BrickSize::Double && !It->IsDone()) {It->Next();}}
    void Next() {
        if(!It->IsDone()){
            It->Next();
            while(!It->IsDone()){
                if(It->GetCurrent()->GetSize() != BrickSize::Double){
                    It->Next();
                }
                else{
                    break;
                }
            }
        }
    }
    //Next() -- illegal instruction
    bool IsDone() {return It->IsDone();}
    Type GetCurrent() {return It->GetCurrent();}
};

//SQLContaierIterator
class SQLContaierIterator: public Iterator<BrickPtr>
{
private:
    const BrickPtr *BrickStorage;
    unsigned int Pointer = 0;
    unsigned int Counter = 0;
public:
    SQLContaierIterator(BrickPtr **brickstorage, unsigned int counter);
    void First();
    void Next();
    bool IsDone();
    BrickPtr GetCurrent();
};

//SQLContainer
class SQLContainer: public Container{
protected:
public:
Iterator<BrickPtr> SQLContaierIterator();
};
