/*
004:第四周程序填空题3
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
写一个二维数组类 Array2,使得下面程序的输出结果是：

0,1,2,3,

4,5,6,7,

8,9,10,11,

next

0,1,2,3,

4,5,6,7,

8,9,10,11,

程序：

#include <iostream>
#include <cstring>
using namespace std;

class Array2 {
// 在此处补充你的代码
};

int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}
输入
无
输出
0,1,2,3,
4,5,6,7,
8,9,10,11,
next
0,1,2,3,
4,5,6,7,
8,9,10,11,
样例输入
None
样例输出
0,1,2,3,
4,5,6,7,
8,9,10,11,
next
0,1,2,3,
4,5,6,7,
8,9,10,11,
*/

#include <iostream>
#include <cstring>
using namespace std;

class Array2 {
// 在此处补充你的代码
    private:
        int **matrix;
        int row,col;
    public:
        Array2(){};
        Array2(int _row,int _col){
            row=_row;
            col=_col;
            matrix=new int*[_row];
            for(int i=0;i<_row;++i){
                matrix[i]=new int[_col];
            }
        }
        ~Array2(){
            for(int i=0;i<row;++i) delete [] matrix[i];
            delete [] matrix;
        }
        int* operator[](int i){
            return matrix[i];
        }
        int operator()(int _row,int _col){
            return matrix[_row][_col];
        }
};

int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}