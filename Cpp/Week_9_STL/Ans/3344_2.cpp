//by Guo Wei
#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
map<int,set<int> > mp;
//second 是 实力为 first的id的集合 
int main()
{
	set<int> st;
	st.insert(1);
	mp.insert(make_pair(1000000000,st)); 
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n; ++i) {
		int id,power;
		scanf("%d%d",&id,&power);
		map<int,set<int> >::iterator pL = mp.lower_bound(power);
		if( pL == mp.end()) 
			//所有现有的人的实力都比 power小 
			printf("%d %d\n",id ,* (mp.rbegin()->second.begin()));
		else if( pL == mp.begin()) 
			//所有现有的人的实力都大于等于 power
			printf("%d %d\n",id,* (mp.begin()->second.begin()));
		else {
			if( pL->first == power) 
				printf("%d %d\n",id,* (pL->second.begin()));
			else {
				int d1 = abs(pL->first - power);
				map<int,set<int> >::iterator p = pL;
				--p;
				int d2 =  abs(p->first - power);
				if( d1 < d2 ) 
					printf("%d %d\n",id, * (pL->second.begin()));
				else if( d1 > d2) 
					printf("%d %d\n",id,* (p->second.begin()));
				else {
					printf("%d %d\n",id ,min(*(pL->second.begin()),*(p->second.begin())));
				}
			}
		}
		mp[power].insert(id);
	}
	return 0;
}
