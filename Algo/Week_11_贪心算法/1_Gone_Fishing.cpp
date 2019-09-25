/*
001:Gone Fishing
查看提交统计提问
总时间限制: 2000ms 内存限制: 65536kB
描述
John is going on a fishing trip. He has h hours available (1 <= h <= 16), and there are n lakes in the area (2 <= n <= 25) all reachable along a single, one-way road. John starts at lake 1, but he can finish at any lake he wants. He can only travel from one lake to the next one, but he does not have to stop at any lake unless he wishes to. For each i = 1,...,n - 1, the number of 5-minute intervals it takes to travel from lake i to lake i + 1 is denoted ti (0 < ti <=192). For example, t3 = 4 means that it takes 20 minutes to travel from lake 3 to lake 4. To help plan his fishing trip, John has gathered some information about the lakes. For each lake i, the number of fish expected to be caught in the initial 5 minutes, denoted fi( fi >= 0 ), is known. Each 5 minutes of fishing decreases the number of fish expected to be caught in the next 5-minute interval by a constant rate of di (di >= 0). If the number of fish expected to be caught in an interval is less than or equal to di , there will be no more fish left in the lake in the next interval. To simplify the planning, John assumes that no one else will be fishing at the lakes to affect the number of fish he expects to catch.
Write a program to help John plan his fishing trip to maximize the number of fish expected to be caught. The number of minutes spent at each lake must be a multiple of 5.
输入
You will be given a number of cases in the input. Each case starts with a line containing n. This is followed by a line containing h. Next, there is a line of n integers specifying fi (1 <= i <=n), then a line of n integers di (1 <=i <=n), and finally, a line of n - 1 integers ti (1 <=i <=n - 1). Input is terminated by a case in which n = 0.
输出
For each test case, print the number of minutes spent at each lake, separated by commas, for the plan achieving the maximum number of fish expected to be caught (you should print the entire plan on one line even if it exceeds 80 characters). This is followed by a line containing the number of fish expected.
If multiple plans exist, choose the one that spends as long as possible at lake 1, even if no fish are expected to be caught in some intervals. If there is still a tie, choose the one that spends as long as possible at lake 2, and so on. Insert a blank line between cases.
样例输入
2 
1 
10 1 
2 5 
2 
4 
4 
10 15 20 17 
0 3 4 3 
1 2 3 
4 
4 
10 15 50 30 
0 3 4 3 
1 2 3 
0 
样例输出
45, 5 
Number of fish expected: 31 

240, 0, 0, 0 
Number of fish expected: 480 

115, 10, 50, 35 
Number of fish expected: 724 
来源
East Central North America 1999
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct fish{
    int id;
    int fishnum;
    
    fish(int _id, int _fishnum):id(_id),fishnum(_fishnum){}

    bool operator<(fish f){
        if(fishnum>f.fishnum) return true;
        else if(fishnum==f.fishnum) return id<f.id;
        else return false;
    }
};

int main(){
    freopen("in2_2.txt","r",stdin);
    int n,h;
    cin>>n;
    while(n){
        cin>>h;
        int t[25];
        int f[26];
        int d[26];
        h*=12; // transfer to how many 5 minutes
        for(int i=1;i<=n;++i) cin>>f[i];
        for(int i=1;i<=n;++i) cin>>d[i];
        for(int i=1;i<n;++i) cin>>t[i];
        int max=0;

        vector<fish> v;
        for(int i=1;i<=n;++i){
            int fishnum=f[i];
            int j=1;
            while(fishnum>0 && j<=h){
                v.emplace_back(i,fishnum);
                fishnum-=d[i];
                j++;
            }
        }

        sort(v.begin(),v.end());

        int maxtime[26]{0,h};

        for(int k=1;k<=n;++k){
            int traveltime=0;
            for(int i=1; i<=k-1;++i){
                traveltime+=t[i];
            }
            int remainh=h-traveltime;
            if(remainh<=0) break;
            int time[26]{0};
            int total=0;


            for(auto fi : v){
                if(fi.id<=k){
                    total+=fi.fishnum;
                    remainh--;
                    time[fi.id]++;
                }
                if(!remainh) break;
            }

            if(remainh) time[1]+=remainh;

            if(total>max){
                max=total;
                memcpy(maxtime,time,sizeof(time));
            }

        }

        for(int i=1;i<=n;++i){
            cout<<5*maxtime[i];
            if(i!=n) cout<<", ";
        }
        cout<<endl;
        cout<<"Number of fish expected: "<<max<<endl<<endl;

        cin>>n;
    }
    return 0;
}