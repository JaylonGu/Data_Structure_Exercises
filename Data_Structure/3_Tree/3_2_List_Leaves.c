/*
Given a tree, you are supposed to list all the leaves in the order of top down, and left to right.

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (≤10) which is the total number of nodes in the tree -- and hence the nodes are numbered from 0 to N−1. Then N lines follow, each corresponds to a node, and gives the indices of the left and right children of the node. If the child does not exist, a "-" will be put at the position. Any pair of children are separated by a space.

Output Specification:
For each test case, print in one line all the leaves' indices in the order of top down, and left to right. There must be exactly one space between any adjacent numbers, and no extra space at the end of the line.

Sample Input:
8
1 -
- -
0 -
2 7
- -
- -
5 -
4 6
Sample Output:
4 1 5
*/

#include <stdio.h>

#define MAXSIZE 10
#define Null -1

typedef int Tree;
struct TNode{
    Tree Left;
    Tree Right;
} T[MAXSIZE];

int main(){
    int i,N,check[MAXSIZE]={0};

    scanf("%d\n",&N);
    for(i=0;i<N;++i){
        char cl,cr;
        scanf("%c %c\n",&cl,&cr);
        if(cl!='-'){
            T[i].Left=cl-'0';
            check[T[i].Left]=1;
        }else T[i].Left=Null;

        if(cr!='-'){
            T[i].Right=cr-'0';
            check[T[i].Right]=1;
        }else T[i].Right=Null;
    }

    int root=0;
    for(;root<N;++root){
        if(!check[root]) break;
    }

    Tree Queue[MAXSIZE];
    int front=-1,rear=-1;
    Queue[++rear]=root;

    int flag=0;
    for(i=0;i<N;++i){
        int node=Queue[++front];
        if((T[node].Left==Null) && (T[node].Right)==Null){
            if(!flag) {
                flag=1;
                printf("%d",node);
            }else printf(" %d",node);
        }
        else if(T[node].Left!=Null) Queue[++rear]=T[node].Left;
        if(T[node].Right!=Null) Queue[++rear]=T[node].Right;
    }

    return 0;
}