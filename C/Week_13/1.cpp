/*
001:冷血格斗场
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
为了迎接08年的奥运会，让大家更加了解各种格斗运动，facer新开了一家冷血格斗场。格斗场实行会员制，但是新来的会员不需要交入会费，而只要同一名老会员打一场表演赛，证明自己的实力。

我们假设格斗的实力可以用一个正整数表示，成为实力值，两人的实力值可以相同。另外，每个人都有一个唯一的id，也是一个正整数。为了使得比赛更好看，每一个新队员都会选择与他实力最为接近的人比赛，即比赛双方的实力值之差的绝对值越小越好，如果有多个人的实力值与他差别相同，则他会选择id最小的那个。

不幸的是，Facer一不小心把比赛记录弄丢了，但是他还保留着会员的注册记录。现在请你帮facer恢复比赛纪录，按照时间顺序依次输出每场比赛双方的id。

输入
第一行一个数n(0 < n <=100000)，表示格斗场新来的会员数（不包括facer）。以后n行每一行两个数，按照入会的时间给出会员的id和实力值。一开始，facer就算是会员，id为1，实力值1000000000。

输出
N行，每行两个数，为每场比赛双方的id，新手的id写在前面。

样例输入
3
2 3
3 1
4 2
样例输出
2 1
3 2
4 2
*/

#include <iostream>
#include <map>
using namespace std;

typedef multimap<int,int> Member;

int main(){
    // freopen("in.txt","r",stdin);
    Member members;
    members.insert(make_pair(1000000000,1));

    int n;
    cin>>n;

    for(int i=0;i<n;++i){
        int strength, id;
        cin>>id>>strength;
        Member::iterator lower=members.lower_bound(strength),upper;
        upper=lower;
        if(lower!=members.begin()) {
            lower--;
            int l=strength-lower->first, u=upper->first-strength;
            if(l<u) {
                int min=lower->second;
                int lstrength=lower->first;
                --lower;
                for(;lower!=members.begin()&&lower->first==lstrength;--lower){
                    if(lower->second<min) min=lower->second; 
                }
                if(lower->first==lstrength && lower->second<min) min=lower->second; 
                cout<<id<<" "<<min<<endl;
            }
            else if(l>u) {
                int min=upper->second;
                int ustrength=upper->first;
                ++upper;
                for(;upper!=members.end()&&upper->first==ustrength;++upper){
                    if(upper->second<min) min=upper->second;
                }
                cout<<id<<" "<<min<<endl;
            }
            else {
                int min=lower->second;
                int lstrength=lower->first, ustrength=upper->first;
                for(;lower!=members.begin()&&lower->first==lstrength;--lower){
                    if(lower->second<min) min=lower->second; 
                }
                if(lower->first==lstrength && lower->second<min) min=lower->second; 
                for(;upper!=members.end()&&upper->first==ustrength;++upper){
                    if(upper->second<min) min=upper->second;
                }
                cout<<id<<" "<<min<<endl;
            }
        }
        else{
            int min=lower->second;
            int lstrength=lower->first;
            ++lower;
            for(;lower!=members.end()&&lower->first==lstrength;++lower){
                if(lower->second<min) min=lower->second;
            }
            cout<<id<<" "<<min<<endl;
        }

        members.insert(make_pair(strength,id));
    }

    return 0;
}