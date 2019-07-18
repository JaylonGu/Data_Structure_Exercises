/*
001:特殊密码锁
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 1024kB
描述
有一种特殊的二进制密码锁，由n个相连的按钮组成（n<30），按钮有凹/凸两种状态，用手按按钮会改变其状态。

然而让人头疼的是，当你按一个按钮时，跟它相邻的两个按钮状态也会反转。当然，如果你按的是最左或者最右边的按钮，该按钮只会影响到跟它相邻的一个按钮。

当前密码锁状态已知，需要解决的问题是，你至少需要按多少次按钮，才能将密码锁转变为所期望的目标状态。

输入
两行，给出两个由0、1组成的等长字符串，表示当前/目标密码锁状态，其中0代表凹，1代表凸。
输出
至少需要进行的按按钮操作次数，如果无法实现转变，则输出impossible。
样例输入
011
000
样例输出
1
*/

#include <iostream>
#include <cstring>
#include <memory>
using namespace std;

int GetBit(int c,int i){
    return (c>>i) & 1;
}
void SetBit(int &c,int i,int v){
    if(v)
        c |= (1<<i);
    else
        c &= ~(1<<i);
}
void Flip(int &c, int i){
    c ^= (1<<i);
}

int Count1(int c,int len){
    int count=0;
    for(int i=0;i<len;++i){
        if(GetBit(c,i)==1) ++count;
    }
    return count;
}

int main(){
    int orilock,lock,result,switchs;
    char c_lock[30],c_result[30];
    cin>>c_lock>>c_result;
    int len=strlen(c_lock);
    memset(&orilock,0,sizeof(orilock));
    memset(&result,0,sizeof(result));
    memset(&switchs,0,sizeof(switchs));

    for(int i=0;i<len;++i){
        SetBit(orilock,i,c_lock[i]-'0');
        SetBit(result,i,c_result[i]-'0');
    }

    int min=30;

    for(int i=0;i<2;++i){
        memcpy(&lock,&orilock,sizeof(orilock));
        SetBit(switchs,0,i);

        for(int j=0;j<len;++j){
            if(GetBit(switchs,j)==1) {
                if(j>0) Flip(lock,j-1);
                Flip(lock,j);
                if(j<len-1) Flip(lock,j+1);
            }

            if(GetBit(lock,j)==GetBit(result,j)) SetBit(switchs,j+1,0);
            else SetBit(switchs,j+1,1);
        }

        if(lock==result) {
            int count=Count1(switchs,len);
            if(count<min) min=count;
        }
    }

    if(min<30) cout<<min;
    else cout<<"impossible";
    return 0;
}