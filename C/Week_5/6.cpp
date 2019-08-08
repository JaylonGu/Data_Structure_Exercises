/*
006:图像模糊处理
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
给定n行m列的图像各像素点的灰度值，要求用如下方法对其进行模糊化处理：

1. 四周最外侧的像素点灰度值不变；

2. 中间各像素点新灰度值为该像素点及其上下左右相邻四个像素点原灰度值的平均（舍入到最接近的整数）。

输入
第一行包含两个整数n和m，表示图像包含像素点的行数和列数。1 <= n <= 100，1 <= m <= 100。
接下来n行，每行m个整数，表示图像的每个像素点灰度。相邻两个整数之间用单个空格隔开，每个元素均在0~255之间。
输出
n行，每行m个整数，为模糊处理后的图像。相邻两个整数之间用单个空格隔开。
样例输入
4 5
100 0 100 0 50
50 100 200 0 0
50 50 100 100 200
100 100 50 50 100
样例输出
100 0 100 0 50
50 80 100 60 0
50 80 100 90 200
100 100 50 50 100
*/

#include <iostream>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int** matrix=new int*[n];
    int** tmp=new int*[n];
    for(int i=0;i<n;++i) {
        matrix[i]=new int[m];
        tmp[i]=new int[m];
    }

    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j){
            cin>>matrix[i][j];
            tmp[i][j]=matrix[i][j];        
        }

    for(int i=1;i<n-1;++i)
        for(int j=1;j<m-1;++j){
            int t=tmp[i][j]+tmp[i-1][j]+tmp[i+1][j]+tmp[i][j-1]+tmp[i][j+1];
            if(t%5<3) matrix[i][j]=t/5;
            else matrix[i][j]=t/5+1;
        }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cout<<matrix[i][j];
            if(j!=m-1) cout<<" ";
        }
        if(i!=n-1) cout<<endl;
    }
    return 0;
}