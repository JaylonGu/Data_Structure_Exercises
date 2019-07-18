/*
002:拨钟问题
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
有9个时钟，排成一个3*3的矩阵。

|-------|    |-------|    |-------|
|       |    |       |    |   |   |
|---O   |    |---O   |    |   O   |
|       |    |       |    |       |
|-------|    |-------|    |-------|
    A            B            C    

|-------|    |-------|    |-------|
|       |    |       |    |       |
|   O   |    |   O   |    |   O   |
|   |   |    |   |   |    |   |   |
|-------|    |-------|    |-------|
    D            E            F    

|-------|    |-------|    |-------|
|       |    |       |    |       |
|   O   |    |   O---|    |   O   |
|   |   |    |       |    |   |   |
|-------|    |-------|    |-------|
    G            H            move    
(图 1)
现在需要用最少的移动，将9个时钟的指针都拨到12点的位置。共允许有9种不同的移动。如下表所示，每个移动会将若干个时钟的指针沿顺时针方向拨动90度。



移动    影响的时钟
 
 1         ABDE
 2         ABC
 3         BCEF
 4         ADG
 5         BDEFH
 6         CFI
 7         DEGH
 8         GHI
 9         EFHI    
输入
9个整数，表示各时钟指针的起始位置，相邻两个整数之间用单个空格隔开。其中，0=12点、1=3点、2=6点、3=9点。
输出
输出一个最短的移动序列，使得9个时钟的指针都指向12点。按照移动的序号从小到大输出结果。相邻两个整数之间用单个空格隔开。
样例输入
3 3 0 
2 2 2 
2 1 2 
样例输出
4 5 8 9 
*/

#include<iostream>
using namespace std;
int main()
{
    int clock[10],move[10],sum;
    for(int j=1;j<=9;j++)
        cin>>clock[j];
    for(move[1]=0;move[1]<4;move[1]++)
        for(move[2]=0;move[2]<4;move[2]++)
            for(move[3]=0;move[3]<4;move[3]++)
                for(move[4]=0;move[4]<4;move[4]++)
                    for(move[5]=0;move[5]<4;move[5]++)
                        for(move[6]=0;move[6]<4;move[6]++)
                            for(move[7]=0;move[7]<4;move[7]++)
                                for(move[8]=0;move[8]<4;move[8]++)
                                    for(move[9]=0;move[9]<4;move[9]++)
                                    {
                                        sum=0;
                                        sum+=(clock[1]+move[1]+move[2]+move[4])%4;
                                        sum+=(clock[2]+move[1]+move[2]+move[3]+move[5])%4;
                                        sum+=(clock[3]+move[2]+move[3]+move[6])%4;
                                        sum+=(clock[4]+move[1]+move[4]+move[5]+move[7])%4;
                                        sum+=(clock[5]+move[1]+move[3]+move[5]+move[7]+move[9])%4;
                                        sum+=(clock[6]+move[3]+move[5]+move[6]+move[9])%4;
                                        sum+=(clock[7]+move[4]+move[7]+move[8])%4;
                                        sum+=(clock[8]+move[5]+move[7]+move[8]+move[9])%4;
                                        sum+=(clock[9]+move[6]+move[8]+move[9])%4;
                                        if(sum==0)
                                        {
                                            for(int j=1;j<=9;j++)
                                                while((move[j]--)>0)
                                                    cout<<j<<" ";
                                            return 0;
                                        }
                                    }
}