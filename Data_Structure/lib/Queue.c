/* 队列的概念 */
// 只能在一端插入，在另一端删除的线性表

/* 队列的应用 */


/* 顺序实现 */
/* 顺环队列 */
#define ERROR NULL
typedef int Position;   /* 此处Positon为数组下标 */
typedef int ElementType;
struct QNode {
    ElementType *Data;     /* 存储元素的数组，此时数组长度尚未给定 */
    Position Front, Rear;  /* 队列的头、尾指针 */
    int MaxSize;           /* 队列最大容量 */
};
typedef struct QNode *Queue;

Queue CreateQueue( int MaxSize )
{
    Queue Q = (Queue)malloc(sizeof(struct QNode));
    Q->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    Q->Front = Q->Rear = 0;
    Q->MaxSize = MaxSize;
    return Q;
}

bool IsFull( Queue Q )
{
    return ((Q->Rear+1)%Q->MaxSize == Q->Front);
}

bool AddQ( Queue Q, ElementType X )
{
    if ( IsFull(Q) ) {
        printf("队列满");
        return false;
    }
    else {
        Q->Rear = (Q->Rear+1) % Q->MaxSize;
        Q->Data[Q->Rear] = X;
        return true;
    }
}

bool IsEmpty( Queue Q )
{
    return (Q->Front == Q->Rear);
}

ElementType DeleteQ( Queue Q )
{
    if ( IsEmpty(Q) ) { 
        printf("队列空");
        return ERROR;
    }
    else  {
        Q->Front =(Q->Front+1)%Q->MaxSize;
        return  Q->Data[Q->Front];
    }
}


/* 链表实现 */
/* 链表尾只能做删除，不能做插入 */
typedef struct Node *PtrToNode;
struct Node { /* 队列中的结点 */
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode Position; /* 此处Postion为内存地址 */

struct QNode {
    Position Front, Rear;  /* 队列的头、尾指针 */
    int MaxSize;           /* 队列最大容量，可无 */
};
typedef struct QNode *Queue;

bool IsEmpty( Queue Q )
{
    return ( Q->Front == NULL);
}

void AddQ(Queue Q, ElementType X)
{
    PtrToNode TmpCell=(PtrToNode) malloc (sizeof(struct Node));
    TmpCell->Data = X;
    TmpCell->Next = NULL;
    if(IsEmpty(Q)){
        Q->Front=TmpCell;
        Q->Rear=TmpCell;
    }else{
        Q->Rear->Next=TmpCell;
        Q->Rear=TmpCell;
    }
}

ElementType DeleteQ( Queue Q )
{
    Position FrontCell; 
    ElementType FrontElem;

    if  ( IsEmpty(Q) ) {
        printf("队列空");
        return ERROR;
    }
    else {
        FrontCell = Q->Front;
        if ( Q->Front == Q->Rear ) {    /* 若队列只有一个元素 */
            Q->Front = NULL;
            Q->Rear = NULL; /* 删除后队列置为空 */
        }
        else                     
            Q->Front = Q->Front->Next;
        
        FrontElem = FrontCell->Data;
        free( FrontCell );  /* 释放被删除结点空间  */
        return  FrontElem;
    }
}