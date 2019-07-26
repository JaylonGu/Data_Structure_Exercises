/* Tree */
// Child-Sibling Method
typedef int ElementType;
typedef struct TNode *Position;
typedef Position Tree;
struct TNode{
    ElementType Data;
    Tree FirstChild;
    Tree NextSibling;
};

/* Binary Tree */
typedef struct BTNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
} *BinTree;

/* Traversal */
// 递归 Recursion
void PreOrderTraversal (BinTree BT){
    if(BT){
        printf("%d",BT->Data);
        PreOrderTraversal(BT->Left);
        PreOrderTraversal(BT->Right);
    }
}

void InOrderTraversal (BinTree BT){
    if(BT){
        InOrderTraversal(BT->Left);
        printf("%d",BT->Data);
        InOrderTraversal(BT->Right);
    }
}

void PostOrderTraversal (BinTree BT){
    if(BT){
        PostOrderTraversal(BT->Left);
        PostOrderTraversal(BT->Right);
        printf("%d",BT->Data);
    }
}

// 非递归 使用堆栈
#include "../2_线性结构/Stack.c"
typedef BinTree ElementType;

void InOrder (BinTree BT){
    BinTree T=BT;
    Stack S = CreateStack (MaxSize);
    while( T || !IsEmpty(S) ){
        while(T){   // 一直向左并将沿途结点压入堆栈
            Push(S,T); // 第一次碰到根节点
            T=T->Left;
        }
        if (!IsEmpty(S)){
            T=Pop(S);
            printf("%d",T->Data);  // 第二次碰到根节点
            T=T->Right; // 没有右结点则为NULL继续Pop
        }
    }
}

void PreOrder (BinTree BT){
    BinTree T=BT;
    Stack S = CreateStack (MaxSize);
    while( T || !IsEmpty(S) ){
        while(T){
            printf("%d",T->Data);
            Push(S,T); // 第一次碰到根节点
            T=T->Left;
        }
        if (!IsEmpty(S)){
            T=Pop(S); // 第二次碰到根节点
            T=T->Right;
        }
    }
}

// 层序遍历
#include "../2_线性结构/Queue.c"
void LevelOrderTraversal (BinTree BT){
    Queue Q; BinTree T;
    if(!BT) return;
    Q=CreateQueue(MaxSize);
    AddQ(Q,BT);
    while(!IsEmpty(Q)){
        T=DeleteQ(Q);
        printf("%d\n",T->Data);
        if(T->Left) AddQ(Q,T->Left);
        if(T->Right) AddQ(Q,T->Right);
    }
}
