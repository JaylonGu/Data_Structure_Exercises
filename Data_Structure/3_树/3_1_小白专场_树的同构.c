/* 二叉树的表示 */
// 静态链表：结构数组表示二叉树
#include <stdio.h>
#define MAXTREE 10
#define ElementType char
#define Tree int
#define Null -1

struct TreeNode{
    ElementType Element;
    Tree Left;
    Tree Right;
}T1[MAXTREE],T2[MAXTREE]; // 无父结点的为根

Tree BuildTree(struct TreeNode T[]);
int isomorphic(Tree R1, Tree R2);

int main(){
    Tree R1,R2;

    R1=BuildTree(T1); 
    R2=BuildTree(T2);

    if(isomorphic(R1,R2)) printf("Yes\n");
    else printf("No\n");
    return 0;
}

Tree BuildTree(struct TreeNode T[]){
    int N;
    Tree Root=Null;
    scanf("%d\n",&N);

    if(N){
        int i,check[MAXTREE]={0}; //用于判断是否是根节点
        char cl,cr;

        for(i=0;i<N;++i){
            scanf("%c %c %c\n",&T[i].Element,&cl,&cr);

            if(cl != '-'){
                T[i].Left=cl-'0';
                check[T[i].Left]=1;
            }
            else T[i].Left=Null;

            if(cr != '-'){
                T[i].Right=cr-'0';
                check[T[i].Right]=1;
            }
            else T[i].Right=Null;
        }

        for(i=0;i<N;++i){
            if (!check[i]) break;
        }
        Root=i;
    }

    return Root;
}

int isomorphic(Tree R1, Tree R2){
    if((R1==Null) && (R2=Null)) // both empty
        return 1;

    if(((R1==Null)&&(R2!=Null)) || ((R1!=Null)&&(R2==Null)))    //one of them is empty
        return 0;

    if(T1[R1].Element != T2[R2].Element)    // roots are different
        return 0;

    if((T1[R1].Left==Null) && (T2[R2].Left==Null)) // both have no left subtree
        return isomorphic(T2[R2].Right,T2[R2].Right);

    if(((T1[R1].Left!=Null) && (T2[R2].Left!=Null)) && 
        (T1[T1[R1].Left].Element==T2[T2[R2].Left].Element))
        return (isomorphic(T1[R1].Left,T2[R2].Left) && 
                isomorphic(T1[R1].Right,T2[R2].Right));
    else
        return (isomorphic(T1[R1].Left,T2[R2].Right) && 
                isomorphic(T1[R1].Right,T2[R2].Left));
}