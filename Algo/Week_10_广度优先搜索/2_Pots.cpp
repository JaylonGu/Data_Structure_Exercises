/*
002:Pots
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
You are given two pots, having the volume of A and B liters respectively. The following operations can be performed:

FILL(i)        fill the pot i (1 ≤ i ≤ 2) from the tap;
DROP(i)      empty the pot i to the drain;
POUR(i,j)    pour from pot i to pot j; after this operation either the pot j is full (and there may be some water left in the pot i), or the pot i is empty (and all its contents have been moved to the pot j).
Write a program to find the shortest possible sequence of these operations that will yield exactly C liters of water in one of the pots.

输入
On the first and only line are the numbers A, B, and C. These are all integers in the range from 1 to 100 and C≤max(A,B).

输出
The first line of the output must contain the length of the sequence of operations K. The following K lines must each describe one operation. If there are several sequences of minimal length, output any one of them. If the desired result can’t be achieved, the first and only line of the file must contain the word ‘impossible’.

样例输入
3 5 4
样例输出
6
FILL(2)
POUR(2,1)
DROP(1)
POUR(2,1)
FILL(2)
POUR(2,1)
*/

#include <iostream>
#include <stack>
using namespace std;

int visited[101][101]{0};

struct pots{
    int A,B,op;
    struct pots* prev;
};

string op[6]={"FILL(1)","FILL(2)","DROP(1)","DROP(2)","POUR(1,2)","POUR(2,1)"};

struct pots q[1000];

int main(){
    int A,B,C;
    cin>>A>>B>>C;
    int front=0, rear=0;

    q[rear].A=0;
    q[rear].B=0;
    q[rear++].prev=NULL;
    visited[0][0]=1;

    while(front!=rear){
        int tmpA=q[front].A;
        int tmpB=q[front].B;
        if(tmpA==C || tmpB==C) break;

        for(int i=0;i<6;++i){
            int tmptmpA, tmptmpB;
            switch(i){
                case 0:
                    if(!visited[A][tmpB]){
                        visited[A][tmpB]=1;
                        q[rear].A=A;
                        q[rear].B=tmpB;
                        q[rear].op=0;
                        q[rear++].prev=&q[front];
                    }
                    break;
                case 1:
                    if(!visited[tmpA][B]){
                        visited[tmpA][B]=1;
                        q[rear].A=tmpA;
                        q[rear].B=B;
                        q[rear].op=1;
                        q[rear++].prev=&q[front];
                    }
                    break;
                case 2:
                    if(!visited[0][tmpB]){
                        visited[0][tmpB]=1;
                        q[rear].A=0;
                        q[rear].B=tmpB;
                        q[rear].op=2;
                        q[rear++].prev=&q[front];
                    }
                    break;
                case 3:
                    if(!visited[tmpA][0]){
                        visited[tmpA][0]=1;
                        q[rear].A=tmpA;
                        q[rear].B=0;
                        q[rear].op=3;
                        q[rear++].prev=&q[front];
                    }
                    break;
                case 4:
                    tmptmpA=(tmpB+tmpA>B) ? (tmpA-(B-tmpB)):0;
                    tmptmpB=(tmpB+tmpA>B) ? B : (tmpA+tmpB);
                    if(!visited[tmptmpA][tmptmpB]){
                        visited[tmptmpA][tmptmpB]=1;
                        q[rear].A=tmptmpA;
                        q[rear].B=tmptmpB;
                        q[rear].op=4;
                        q[rear++].prev=&q[front];
                    }
                    break;
                case 5:
                    tmptmpA=(tmpB+tmpA>A) ? A : (tmpA+tmpB);
                    tmptmpB=(tmpB+tmpA>A) ? (tmpB-(A-tmpA)) : 0;
                    if(!visited[tmptmpA][tmptmpB]){
                        visited[tmptmpA][tmptmpB]=1;
                        q[rear].A=tmptmpA;
                        q[rear].B=tmptmpB;
                        q[rear].op=5;
                        q[rear++].prev=&q[front];
                    }
            }
        }

        front++;
    }

    if(front==rear) cout<<"impossible"<<endl;
    else{
        stack<int> s;
        struct pots *p=&q[front];
        while(p->prev){
            s.push(p->op);
            p=p->prev;
        }
        cout<<s.size()<<endl;
        while(!s.empty()){
            cout<<op[s.top()]<<endl;
            s.pop();
        }
    }

    return 0;
}