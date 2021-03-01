/*
02-线性结构2 一元多项式的乘法与加法运算 (20分)
设计函数分别求两个一元多项式的乘积与和。

输入格式:
输入分2行，每行分别先给出多项式非零项的个数，再以指数递降方式输入一个多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔。

输出格式:
输出分2行，分别以指数递降方式输出乘积多项式以及和多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。零多项式应输出0 0。

输入样例:
4 3 4 -5 2  6 1  -2 0
3 5 20  -7 4  3 1
输出样例:
15 24 -25 22 30 21 -10 20 -21 8 35 6 -33 5 14 4 -15 3 18 2 -6 1
5 20 -4 4 -5 2 9 1 -2 0
*/


#include <iostream>
using namespace std;

struct Poly{
    int coef;
    int expon;
};

void Read(int n, struct Poly p[]);
void Print(struct Poly p[], int n);
void Attach(struct Poly p[], int i, int &l, int coef, int expon);
void Delete(struct Poly p[], int i, int &l);
void Add(int n1, int n2, struct Poly p1[], struct Poly p2[]);
void Multiply(int n1, int n2, struct Poly p1[], struct Poly p2[]);

int main(){
    int n1,n2;
    cin>>n1;
    struct Poly p1[n1];
    Read(n1,p1);
    cin>>n2;
    struct Poly p2[n2];
    Read(n2,p2);

    Multiply(n1,n2,p1,p2);
    Add(n1,n2,p1,p2);

    return 0;
}

inline void Read(int n, struct Poly p[]){
    for(int i=0;i<n;++i){
        cin>>p[i].coef>>p[i].expon;
    }
}

void Add(int n1, int n2, struct Poly p1[], struct Poly p2[]){
    int n=n1+n2;
    int i=0,i1=0,i2=0;
    struct Poly p[n];
    while(i1<n1 && i2<n2){
        if(p1[i1].expon>p2[i2].expon){
            p[i++]=p1[i1++];
        }else if(p1[i1].expon<p2[i2].expon){
            p[i++]=p2[i2++];
        }else{
            p[i].coef=p1[i1].coef+p2[i2].coef;
            if(p[i].coef!=0){
                p[i++].expon=p1[i1].expon;
                i1++;i2++;
                n--;
            }else{
                i1++;i2++;
                n-=2;
            }
        }
    }
    while(i1<n1){
        p[i++]=p1[i1++];
    }
    while(i2<n2){
        p[i++]=p2[i2++];
    }
    Print(p,n);
}

void Multiply(int n1, int n2, struct Poly p1[], struct Poly p2[]){
    if(n1==0 || n2==0) {
        cout<<"0 0"<<endl;
    }else{
        int l=0;
        struct Poly p[n1*n2+1];
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                int coef=p1[i].coef*p2[j].coef;
                if(coef){
                    int expon=p1[i].expon+p2[j].expon;
                    int k=0;
                    if(l==0){
                        Attach(p,k,l,coef,expon);
                    }else{
                        int tmpl=l;
                        for(;k<l;k++){
                            if(p[k].expon==expon){
                                p[k].coef+=coef;
                                if(!p[k].coef) Delete(p,k,l);
                                break;
                            }else if(p[k].expon<expon){
                                Attach(p,k,l,coef,expon);
                                break;
                            }
                        }
                        if(k==tmpl) Attach(p,k,l,coef,expon);
                    }
                }
            }
        }
        Print(p,l);
    }
}

void Print(struct Poly p[], int n){
    for(int i=0;i<n-1;i++){
        cout<<p[i].coef<<" "<<p[i].expon<<" ";
    }
    if(n>0){
        cout<<p[n-1].coef<<" "<<p[n-1].expon<<endl;
    }else{
        cout<<"0 0"<<endl;
    }
}

void Attach(struct Poly p[], int i, int &l, int coef, int expon){
    for(int j=l; j>i; j--){
        p[j]=p[j-1];
    }
    p[i].coef=coef;
    p[i].expon=expon;
    l++;
}

void Delete(struct Poly p[], int i, int &l){
    if(l==0) return;
    if(l==1) {l--;return;}
    for(int j=i;j<l;j++){
        p[j]=p[j+1];
    }
    l--;
}