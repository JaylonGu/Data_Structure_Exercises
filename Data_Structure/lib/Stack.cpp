#define ERROR -1

typedef int Position;
typedef int ElementType;

class SNode{
    private:
        ElementType *Data;
        Position Top;
        int MaxSize;
    public:
        SNode(int _MaxSize){
            Data = new ElementType[_MaxSize];
            Top = -1;
            MaxSize = _MaxSize;
        }

        ~SNode(){
            delete [] Data;
        }

        bool IsFull()
        {
            return (Top == MaxSize-1);
        }

        bool Push(ElementType X )
        {
            if (this->IsFull() ) {
                printf("Stack is Full");
                return false;
            }
            else {
                Data[++Top] = X;
                return true;
            }
        }

        bool IsEmpty()
        {
            return (Top == -1);
        }

        ElementType Pop()
        {
            if ( this->IsEmpty() ) {
                printf("Stack is Empty");
                return ERROR;
            }
            else 
                return ( Data[Top--] );
        }
};
typedef SNode *Stack;