#define MAXSIZE 1000
typedef ElementType int;
typedef struct LNode *List;
struct LNode{
    ElementType Element[MAXSIZE];
    int Length;
}

/* 顺序查找 Sequential Search */
// T(N)=O(N)
int SequentialSearch(List Tbl, ElementType K){
    int i;
    Tbl->Element[0]=K;  // 哨兵，数组从1开始存放
    for(i=Tbl->Length;Tbl->Element[i]!=K;i--);
    return i;
}

/* 二分查找 Binary Search */
// 前提为有序存放 && 数据在数组中
// T(N)=O(logN)
int BinarySearch(List Tbl, ElementType K){
    int left, right, mid, NotFound=-1;
    left=1; // 数组从1开始存放
    right=Tbl->Length;
    while (left<=right){
        mid=(left+right)/2;
        if(K<Tbl->Element[mid]) right=mid-1;
        else if(K>Tbl->Element[mid]) left=mid+1;
        else return mid;
    }
    return NotFound;
}