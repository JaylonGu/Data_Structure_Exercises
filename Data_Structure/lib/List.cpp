#define MAXSIZE 10000
typedef int Position;

template <typename ElementType>
class List{
private:
    ElementType Data[MAXSIZE];
    Position Last;
public:
    List(){}
    ElementType FindKth(int K){}
    Position Find(ElementType X){}
    void Insert(ElementType X, Position i){}
    void Delete(Position i){}
    int Length(){}
};

template <typename ElementType>
class LList{
private:
    ElementType Data;
    LList<ElementType>* Next;
public:

};
