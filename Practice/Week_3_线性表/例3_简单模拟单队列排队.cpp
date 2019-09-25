/*
用程序简单模拟一个单队列多窗口的排队模式：
设某银行有一个固定能容纳N个顾客的等候区，顾客想进银行，若等候区有空则可进，否则被拒绝进入。
每当银行柜员叫号时，等候区中最先进入的顾客离开等候区前往柜台办理业务，若叫号时等候区无人，则此次叫号作废。

输入格式:
第一行输入一个不大于20的正整数N，表示银行等候区能容纳的人数，
接下来用若干行表示依时间顺序先后发生的“顾客想进银行”或“叫号”事件，格式分别是：

顾客想进银行，用 In <id> 表示，其中<id>是顾客编号，为不大于100000的正整数；
叫号，用Calling表示。
最后一行是一个#符号，表示输入结束。
注意：

题目输入保证每个顾客的编号是独一无二的，即：不会出现想进银行的顾客与已经在等候区的顾客编号相同的情况。
保证后一个事件一定在前一个事件完成之后才发生，即：不需要考虑事件之间的“同步”问题。
输出格式:
对于输入的每个事件，按同样顺序在一行内输出事件的结果，格式分别是：

顾客想进银行，若顾客进入，则输出 <id> joined. Total:<t> 其中<id>是该顾客的编号，<t>是顾客进入后，等候区的人数
顾客想进银行，若因等候区满而被拒绝，则输出 <id> rejected. 其中<id>是该顾客的编号
叫号，若有顾客前往柜台，则输出 <id> called. Total:<t> 其中<id>是该顾客的编号，<t>是顾客去柜台后，等候区的人数
叫号，等候区无人，则输出 No one!
输入样例:
3
In 101
In 102
In 103
In 104
Calling
In 105
Calling
Calling
Calling
Calling
#
输出样例:
101 joined. Total:1
102 joined. Total:2
103 joined. Total:3
104 rejected.
101 called. Total:2
105 joined. Total:3
102 called. Total:2
103 called. Total:1
105 called. Total:0
No one!
*/

#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue<string> q;
    int N;
    cin>>N;
    string op,id;
    cin>>op;
    while(op!="#"){
        if(op=="In"){
            cin>>id;
            if(q.size()==N){
                cout<<id<<" rejected."<<endl;
            }else{
                q.push(id);
                cout<<id<<" joined. Total:"<<q.size()<<endl;
            }
        }else{
            if(q.size()){
                id=q.front();
                q.pop();
                cout<<id<<" called. Total:"<<q.size()<<endl;
            }else{
                cout<<"No one!\n";
            }
        }
        cin>>op;
    }

    return 0;
}