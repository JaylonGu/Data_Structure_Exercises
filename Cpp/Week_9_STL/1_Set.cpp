/*
001:Set
查看 提交 统计 提问
总时间限制: 5000ms 内存限制: 100000kB
描述
现有一整数集（允许有重复元素），初始为空。我们定义如下操作：
add x 把x加入集合
del x 把集合中所有与x相等的元素删除
ask x 对集合中元素x的情况询问
对每种操作，我们要求进行如下输出。
add 输出操作后集合中x的个数
del 输出操作前集合中x的个数
ask 先输出0或1表示x是否曾被加入集合（0表示不曾加入），再输出当前集合中x的个数，中间用空格格开。
输入
第一行是一个整数n，表示命令数。0<=n<=100000。
后面n行命令，如Description中所述。
输出
共n行，每行按要求输出。
样例输入
7
add 1
add 1
ask 1
ask 2
del 2
del 1
ask 1
样例输出
1
2
1 2
0 0
0
2
1 0
提示
Please use STL’s set and multiset to finish the task
*/

#include <iostream>
#include <set>
using namespace std;

multiset<int> mst;
set<int> st;


void add(int x){
    mst.insert(x);
    st.insert(x);
    cout<<mst.count(x)<<endl;

}

void del(int x){
    cout<<mst.count(x)<<endl;
    mst.erase(x);
}

void ask(int x){
    if(st.find(x)==st.end()) cout<<"0 0"<<endl;
    else{
        cout<<"1 "<<mst.count(x)<<endl;
    }
}


int main(){
    int n;
    cin>>n;
    char op[4];
    int x;
    for(int i=0;i<n;++i){
        cin>>op>>x;
        switch (op[1]){
            case 'd':
                add(x); break;
            case 'e':
                del(x); break;
            case 's':
                ask(x);
        }
    }
    return 0;
}