#include <stdio.h>
#include <stdlib.h>
/* 多项式的表示 */
// 数组： 编程简单，调试容易；需要事先确定数组大小
// 链表： 动态性强；编程略复杂，调试比较复杂
// 可以用动态数组
// 此处用链表表示
typedef struct PolyNode *Polynomial;
struct PolyNode{
    int coef;
    int expon;
    Polynomial link;
};

/* 程序框架 */
Polynomial ReadPoly();
void PrintPoly(Polynomial P);
Polynomial Mult(Polynomial P1, Polynomial P2);
Polynomial Add(Polynomial P1, Polynomial P2);

int main(){
    Polynomial P1,P2,PP,PS;
    P1=ReadPoly();
    P2=ReadPoly();
    PP=Mult(P1,P2);
    PrintPoly(PP);
    PS=Add(P1,P2);
    PrintPoly(PS);

    return 0;
}

/* 读多项式 */
void Attach(int c,int e,Polynomial* Rear);
// Rear处理有两种方式
// 1. Rear初值为NULL，在Attach中根据Rear是否为NULL做不同处理
// *2. Rear初值指向一个空节点，最后free这个临时节点
Polynomial ReadPoly(){
    Polynomial P,Rear,t;
    int N,c,e;
    scanf("%d",&N);
    P=(Polynomial) malloc(sizeof(struct PolyNode)); // 临时表头空节点
    P->link=NULL;
    Rear=P;

    while(N--){
        scanf("%d %d",&c,&e);
        Attach(c,e,&Rear);  // 把读入的数据，加到链表尾
    }

    t=P;P=P->link;free(t); // 删除临时空节点

    return P;
}

/* 加法实现 */
Polynomial Add(Polynomial P1, Polynomial P2){
    Polynomial t1,t2,P,Rear,t;
    int sum;
    t1=P1;t2=P2;
    P=(Polynomial) malloc(sizeof(struct PolyNode));
    Rear=P;

    while(t1&&t2){
        if(t1->expon == t2->expon){
            sum=t1->coef+t2->coef;
            if(sum) Attach(sum,t1->expon,&Rear);
            t1=t1->link;
            t2=t2->link;
        }else if(t1->expon > t2->expon){
            Attach(t1->coef,t1->expon,&Rear);
            t1=t1->link;
        }else{
            Attach(t2->coef,t2->expon,&Rear);
            t2=t2->link;
        }
    }

    while(t1){
        Attach(t1->coef,t1->expon,&Rear);
        t1=t1->link;
    }
    while(t2){
        Attach(t2->coef,t2->expon,&Rear);
        t2=t2->link;
    }

    Rear->link=NULL;
    t=P;P=P->link;free(t);

    return P;
}

/* 乘法实现 */
// 1. 乘法运算转换为加法运算
// *2. 逐项插入
Polynomial Mult(Polynomial P1, Polynomial P2){
    Polynomial t1,t2,P,Rear,t;
    int c,e;

    if(!P1 || !P2) return NULL;

    t1=P1;t2=P2;
    P=(Polynomial) malloc(sizeof(struct PolyNode));
    Rear=P;

    while(t2){  //P1的第一项分别乘P2，得到P
        Attach(t1->coef*t2->coef,t1->expon+t2->expon,&Rear);
        t2=t2->link;
    }

    t1=t1->link;
    while(t1){
        t2=P2;Rear=P;
        while(t2){
            c = t1->coef * t2->coef;
            e = t1->expon + t2->expon;
            while(Rear->link && Rear->link->expon>e) //找插入位置
                Rear=Rear->link;
            if(Rear->link&&Rear->link->expon==e){ //指数相同，更改原节点系数
                if(Rear->link->coef+c){
                    Rear->link->coef+=c;
                }else{
                    // 系数等于0，则删除此节点；
                    t=Rear->link;
                    Rear->link=t->link;
                    free(t);
                }
            }else{ // 指数不同，插入新节点
                t=(Polynomial) malloc(sizeof(struct PolyNode));
                t->coef=c;t->expon=e;
                t->link=Rear->link;
                Rear->link=t; Rear=Rear->link;
            }
            t2=t2->link;
        }
        t1=t1->link;
    }

    Rear->link=NULL;
    t=P;P=P->link;free(t);

    return P;
}

/* 多项式的输出 */
void PrintPoly(Polynomial P){
    int flag=0; //调整格式用，因为最后一项后面没有空格

    if(!P) {printf("0 0\n"); return; }

    while(P){   // 主框架
        if(!flag) flag=1;
        else printf(" "); //除了第一项外，后面都是空格，系数，指数
        printf("%d %d",P->coef,P->expon);
        P=P->link;
    }
    printf("\n");
}

/* 辅助函数 */
void Attach(int c,int e,Polynomial* pRear){
    Polynomial P;
    P=(Polynomial) malloc(sizeof(struct PolyNode));
    P->coef=c;
    P->expon=e;
    P->link=NULL;
    (*pRear)->link=P;
    *pRear=P;
}