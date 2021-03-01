/* 优先队列（Priority Queue） */
/* 数组实现 */
// 插入 O(1)
// 删除  查找最大关键字 O(n)
//      删除并移动元素 O(n)

/* 链表实现 */
// 插入 O(1)
// 删除 查找最大关键字 O(n)
//     删除结点 O(1)

/* 有序数组实现 */
// 插入  查找合适位置 O(n) or O(logn)
//      移动元素并插入 O(n)
// 删除  删除最后一个元素 O(1)

/* 有序链表实现 */
// 插入  查找合适位置 O(n)
//      插入 O(1)
// 删除  删除最后一个元素 O(1)

/* 完全二叉树实现 -> 堆 */
#define MaxData 10000
typedef struct HeapStruct *MaxHeap;
typedef int ElementType;
struct HeapStruct{
    ElementType *Elements;
    int Size;
    int Capacity;
};
// 创建空堆
MaxHeap Create(int MaxSize){
    MaxHeap H=(MaxHeap)malloc(sizeof(struct HeapStruct));
    H->Elements(ElementType*)=malloc((MaxSize+1)*sizeof(ElementType));
    H->Size=0;
    H->Capacity=MaxSize;
    H->Elements[0]=MaxData; // 哨兵，大于所有可能的值
    return H;
}
// 判满
bool IsFull( MaxHeap H )
{
    return (H->Size == H->Capacity);
}
// 判空
bool IsEmpty( MaxHeap H )
{
    return (H->Size == 0);
}
// 插入
void Insert(MaxHeap H, ElementType item){
    int i;
    if(IsFull(H)){
        printf("The Heap is full.\n");
        return;
    }
    i = ++H->Size;  // 指向最后一个元素的位置
    for(;H->Elements[i/2]<item;i/=2)
        H->Elements[i]=H->Elements[i/2];    // 向下过滤结点，i=1时i/2=0，遇到哨兵结点一定最大
    H->Elements[i]=item;
}
// 删除
#define ERROR -1
ElementType Delete(MaxHeap H){
    int Parent,Child;
    ElementType MaxItem,temp;
    if(IsEmpty(H)){
        printf("The heap is empty.\n");
        return ERROR;
    }
    MaxItem=H->Elements[1];

    temp=H->Elements[H->Size--]; /* 最后一个结点 */
    for(Parent=1;Parent*2<=H->Size;Parent=Child){
        Child=Parent*2;
        if((Child!=H->Size)&&(H->Elements[Child]<H->Elements[Child+1])) Child++;   // 选个大的儿子
        if(temp>=H->Element[Child]) break;
        else H->Elements[Parent]=H->Elements[Child];
    }
    H->Elements[Parent]=temp;
    return MaxItem；
}
// 最大堆的建立
// 方法一：一个个插入 O(NlogN)
// 方法二：O(N)
//      将N个元素按输入顺序存入，满足结构特性
//      调整各结点位置，满足有序特性
void PercDown( MaxHeap H, int p )
{ /* 下滤：将H中以H->Data[p]为根的子堆调整为最大堆 */
    int Parent, Child;
    ElementType X;

    X = H->Data[p]; /* 取出根结点存放的值 */
    for( Parent=p; Parent*2<=H->Size; Parent=Child ) {
        Child = Parent * 2;
        if( (Child!=H->Size) && (H->Data[Child]<H->Data[Child+1]) )
            Child++;  /* Child指向左右子结点的较大者 */
        if( X >= H->Data[Child] ) break; /* 找到了合适位置 */
        else  /* 下滤X */
            H->Data[Parent] = H->Data[Child];
    }
    H->Data[Parent] = X;
}
void BuildHeap( MaxHeap H )
{ /* 调整H->Data[]中的元素，使满足最大堆的有序性  */
  /* 这里假设所有H->Size个元素已经存在H->Data[]中 */
    int i;
    /* 从最后一个结点的父节点开始，到根结点1 */
    for( i = H->Size/2; i>0; i-- )
        PercDown( H, i );
}