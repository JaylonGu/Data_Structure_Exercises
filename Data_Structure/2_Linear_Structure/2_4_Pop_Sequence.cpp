/*
Given a stack which can keep M numbers at most. Push N numbers in the order 
of 1, 2, 3, ..., N and pop randomly. You are supposed to tell if a given sequence 
of numbers is a possible pop sequence of the stack. For example, if M is 5 and N 
is 7, we can obtain 1, 2, 3, 4, 5, 6, 7 from the stack, but not 3, 2, 1, 7, 5, 6, 4.

Input Specification:
Each input file contains one test case. For each case, the first line contains 
3 numbers (all no more than 1000): M (the maximum capacity of the stack), 
N (the length of push sequence), and K (the number of pop sequences to be checked). 
Then K lines follow, each contains a pop sequence of N numbers. All the numbers in a 
line are separated by a space.

Output Specification:
For each pop sequence, print in one line "YES" if it is indeed a possible pop sequence 
of the stack, or "NO" if not.

Sample Input:
5 7 5
1 2 3 4 5 6 7
3 2 1 7 5 6 4
7 6 5 4 3 2 1
5 6 4 3 7 2 1
1 7 6 5 4 3 2
Sample Output:
YES
NO
NO
YES
NO
*/

#include <iostream>
using namespace std;

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

        bool Pop()
        {
            if ( this->IsEmpty() ) {
                return false;
            }
            else{
                Top--;
                return true;
            }
        }

        ElementType GetValue()
        {
            if ( this->IsEmpty() ) {
                return ERROR;
            }
            else 
                return ( Data[Top] );
        }
};
typedef SNode *Stack;


int main(){
    int M,N,K;
    cin>>M>>N>>K;
    while(K--){
        SNode S(M);
        int *Test=new int[N];
        for(int i=0;i<N;++i) cin>>Test[i];
        int check=0;
        S.Push(1);
        // 一边压栈一边比较，如果相同则出栈，不同则继续压栈，直到把1~N都压过一次栈
        for(int i=2;i<=N;++i){
            while(Test[check]==S.GetValue()) {
                S.Pop();
                check++;
            }
            if(S.Push(i)) ;else break;
        }

        // 剩余数字一个个出栈并比较，有一个不同就No
        while(check < N){
            if(Test[check]==S.GetValue()) {
                S.Pop();
                check++;
            }else break;
        }

        if(check==N) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}