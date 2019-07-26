# include "../3_树/Tree.c"
typedef BinTree Position;
/* 操作集 */
// 查找
// 递归
Position FindX(ElementType X, BinTree BST){  // 尾递归
    if(BST==NULL) return NULL;
    else if(BST->Data==X) return BST;
    else if(X>BST->Data) return Find(X,BST->Right);
    else return Find(X,BST->Left);
}

Position FindMin(BinTree BST){
    if(BST==NULL) return NULL;
    else if(BST->Left==NULL) return BST;
    else return FindMin(BST->Left);
}

Position FindMax(BinTree BST){
    if(BST==NULL) return NULL;
    else if(BST->Right==NULL) return BST;
    else return FindMin(BST->Right);
}
//非递归
Position Findx(ElementType X, BinTree BST){   // 查找效率取决于树的高度->平衡二叉树
    while(BST){
        if(BST->Data==X) return BST;
        else if(X>BST->Data) BST=BST->Right;
        else BST=BST->Left;
    }
    return NULL;
}

Position Findmin(BinTree BST){
    if(BST)
        while(BST->Left) BST=BST->Left;
    return BST;
}

Position Findmax(BinTree BST){
    if(BST)
        while(BST->Right) BST=BST->Right;
    return BST;
}

// 插入
// 类似FindX
BinTree Insert(ElementType X, BinTree BST){
    if(!BST){
        BST=malloc(sizeof(struct TreeNode));
        BST->Data=X;
        BST->Left=BST->Right=NULL;
    }else
    {
        if(X<BST->Data)
            BST->Left=Insert(X,BST->Left);
        else if(X>BST->Data)
            BST->Right=Insert(X,BST->Right);
    }
    return BST;
}

// 删除
BinTree Delete(ElementType X, BinTree BST){
    Position Tmp;
    if(!BST) printf("Not Found");
    else if(X<BST->Data)
        BST->Left=Delete(X,BST->Left);
    else if(X>BST->Right)
        BST->Right=Delete(X,BST->Right);
    else
    {
        if(BST->Left && BST->Right){
            Tmp=FindMin(BST->Right);
            BST->Data=Tmp->Data;
            BST->Right=Delete(BST->Data,BST->Right);
        }else{
            Tmp=BST;
            if(!BST->Left)  // 有右孩子或无子结点
                BST=BST->Right;
            else if(!BST->Right)    // 有左孩子或无子结点
                BST=BST->Left;
            free(Tmp);
        }
    }
    return BST;
}


