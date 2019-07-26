/*
给定一个插入序列就可以唯一确定一棵二叉搜索树。然而，一棵给定的二叉搜索树却可以由多种不同的插入序列得到。
例如分别按照序列{2, 1, 3}和{2, 3, 1}插入初始为空的二叉搜索树，都得到一样的结果。于是对于输入的各种插
入序列，你需要判断它们是否能生成一样的二叉搜索树。

输入格式:
输入包含若干组测试数据。每组数据的第1行给出两个正整数N (≤10)和L，分别是每个序列插入元素的个数和需要检
查的序列个数。第2行给出N个以空格分隔的正整数，作为初始插入序列。最后L行，每行给出N个插入的元素，属于L
个需要检查的序列。

简单起见，我们保证每个插入序列都是1到N的一个排列。当读到N为0时，标志输入结束，这组数据不要处理。

输出格式:
对每一组需要检查的序列，如果其生成的二叉搜索树跟对应的初始序列生成的一样，输出“Yes”，否则输出“No”。

输入样例:
4 2
3 1 4 2
3 4 1 2
3 2 4 1
2 1
2 1
1 2
0
输出样例:
Yes
No
No
 */

#include <stdio.h>
#include <stdlib.h>
/* 树的表示 */
typedef struct TreeNode *Tree;
struct TreeNode{
    int v;
    Tree Left,Right;
    int flag;   // 判别是否一致用，没被访问过为0，被访问过为1
};

Tree NewNode(int V){
    Tree T=(Tree)malloc(sizeof(struct TreeNode));
    T->v=V;
    T->Left=T->Right=NULL;
    T->flag=0;
    return T;
}

Tree Insert(Tree T, int V){
    if(!T) T=NewNode(V);
    else{
        if(V>T->v)
            T->Right=Insert(T->Right,V);
        else
            T->Left=Insert(T->Left,V);
    }
    return T;
}

Tree MakeTree(int N){
    Tree T;
    int i,v;
    scanf("%d",&v);
    T=NewNode(v);
    for(i=1;i<N;++i){
        scanf("%d",&v);
        T=Insert(T,v);
    }
    return T;
}

int check(Tree T,int V){
    if(T->flag){    /* 访问过 */
        if(V<T->v) return check(T->Left,V);
        else if(V>T->v) return check(T->Right,V);
        else return 0;
    }else{  /* 没访问过 */
        if(V==T->v){
            T->flag=1;
            return 1;
        }else return 0;
    }
}

int Judge(Tree T,int N){
    int i,V,flag=1;
    scanf("%d",&V);

    if(V!=T->v) flag=0;
    else T->flag=1;

    for(i=1;i<N;++i){
        scanf("%d",&V);
        if(flag && (!check(T,V))) flag=0;   /* 读完数据 */
    }

    return flag;
}

void ResetT(Tree T){
    if(T->Left) ResetT(T->Left);
    if(T->Right) ResetT(T->Right);
    T->flag=0;
}

void FreeTree(Tree T){
    if(T->Left) FreeTree(T->Left);
    if(T->Right) FreeTree(T->Right);
    free(T);
}


int main(){
/*
对每组数据
    读入N和L
    根据第一行序列建树T
    依据树T分别判别后面的L个序列是否能与T形成同一搜索树并输出结果
*/
    int N,L,i;
    Tree T;
    scanf("%d",&N);
    while(N){
        scanf("%d",&L);
        T=MakeTree(N);
        for(i=0;i<L;i++){
            if(Judge(T,N)) printf("Yes\n");
            else printf("No\n");
            ResetT(T); /* 清除T中的标记flag */
        }
        FreeTree(T);
        scanf("%d",&N);
    }
    return 0;
}