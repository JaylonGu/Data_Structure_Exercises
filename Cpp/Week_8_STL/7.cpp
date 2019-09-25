/*
007:List
查看 提交 统计 提问
总时间限制: 4000ms 内存限制: 65536kB
描述
写一个程序完成以下命令：
new id ——新建一个指定编号为id的序列(id<10000)
add id num——向编号为id的序列加入整数num
merge id1 id2——合并序列id1和id2中的数，并将id2清空
unique id——去掉序列id中重复的元素
out id ——从小到大输出编号为id的序列中的元素，以空格隔开

输入
第一行一个数n，表示有多少个命令( n＜＝２０００００)。以后n行每行一个命令。
输出
按题目要求输出。
样例输入
16
new 1
new 2
add 1 1
add 1 2
add 1 3
add 2 1
add 2 2
add 2 3
add 2 4
out 1
out 2
merge 1 2
out 1
out 2
unique 1
out 1
样例输出
1 2 3 
1 2 3 4
1 1 2 2 3 3 4

1 2 3 4
*/

#include <iostream>
#include <string>
#include <map>
#include <list>
using namespace std;

int main(){
    int n;
    cin>>n;
    map<int,list<int> > mp;
    while(n--){
        string s;
        cin>>s;
        int id,id1,id2,num;
        switch (s[0])
        {
        case 'n':
            cin>>id;
            mp[id];
            break;
        case 'a':
            cin>>id>>num;
            mp[id].push_back(num);
            break;
        case 'm':
            cin>>id1>>id2;
            mp[id1].merge(mp[id2]);
            break;
        case 'u':
            cin>>id;
            mp[id].sort();
            mp[id].unique();
            break;
        case 'o':
            cin>>id;
            mp[id].sort();
            for(list<int>::iterator i=mp[id].begin();i!=mp[id].end();i++) 
                cout<<*i<<" ";
            cout<<endl;
        }
    }
    return 0;
}