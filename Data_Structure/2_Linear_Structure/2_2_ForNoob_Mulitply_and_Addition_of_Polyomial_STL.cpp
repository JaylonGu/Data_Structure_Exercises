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
#include <map>
using namespace std;

typedef map<int,int,greater<int>> poly;

void Read(int &n, poly &p);
void Print(poly &p);
void Add(poly &p1, poly &p2);
void Multiply(poly &p1, poly &p2);

int main(){
    int n1,n2;
    poly p1,p2;
    Read(n1,p1);
    Read(n2,p2);

    Multiply(p1,p2);
    Add(p1,p2);

    return 0;
}

inline void Read(int &n, poly &p){
    cin>>n;
    int m=n,coef,expon;
    while(m--){
        cin>>coef>>expon;
        p.insert(make_pair(expon,coef));
    }
}

void Print(poly &p){
    poly::iterator v=p.begin();
    int size=p.size();
    for(int i=0;i<size-1;i++){
        cout<<v->second<<" "<<v->first<<" ";
        v++;
    }
    cout<<v->second<<" "<<v->first<<endl;
}

void Add(poly &p1, poly &p2){
    poly::iterator v1=p1.begin(),v2=p2.begin();
    poly p;
    while(v1!=p1.end() && v2!=p2.end()){
        if(v1->first>v2->first){
            p.insert(make_pair(v1->first,v1->second));
            v1++;
        }else if(v1->first<v2->first){
            p.insert(make_pair(v2->first,v2->second));
            v2++;
        }
        else{
            int sum=v1->second+v2->second;
            if(sum)
                p.insert(make_pair(v1->first,sum));
            v1++;v2++;
        }
    }
    while(v1!=p1.end()){
        p.insert(make_pair(v1->first,v1->second));
        v1++;
    }
    while(v2!=p2.end()){
        p.insert(make_pair(v2->first,v2->second));
        v2++;
    }
    Print(p);
}

void Multiply(poly &p1, poly &p2){
    poly p;
    for(poly::iterator v1=p1.begin();v1!=p1.end(); v1++){
        for(poly::iterator v2=p2.begin();v2!=p2.end(); v2++){
            int coef=v1->second*v2->second;
            if(coef){
                int expon=v1->first+v2->first;
                if(p.find(expon)==p.end()){
                    p.insert(make_pair(expon,coef));
                }else{
                    p[expon]+=coef;
                    if(!p[expon]) p.erase(expon);
                }
            }
        }
    }
    Print(p);
}