#include <iostream>
#include <cstdio>
#include <map>
#include <cmath>
using namespace std;
multimap<int,int> mp;
void toErase( multimap<int,int>::iterator p1,multimap<int,int>::iterator p2)
{
	if( p1->first == p2->first) {
		if( p1->second < p2->second)
			mp.erase(p2);
		else
			mp.erase(p1);
	}
}
int main()
{
	mp.insert(make_pair(1000000000,1));
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n; ++i) {
		int id,power;
		scanf("%d%d",&id,&power);
		multimap<int,int>::iterator p = mp.insert(make_pair(power,id));
		multimap<int,int>::iterator pL = p; -- pL;
		multimap<int,int>::iterator pR = p; ++ pR;
		if( p == mp.begin()) {
			printf("%d %d\n",id,pR->second);
			toErase(p,pR);
		}
		else if( p == --mp.end()) {
			printf("%d %d\n",id,pL->second);
			toErase(p,pL);
		}
		else {
			int dL = abs(p->first - pL->first);
			int dR = abs(p->first - pR->first);
			if( dL < dR || dL == dR && pL->second < pR->second) {
				printf("%d %d\n",id,pL->second);
				toErase(p,pL);
			}
			else if( dL > dR || dL == dR && pL->second > pR->second) {
				printf("%d %d\n",id,pR->second);
				toErase(p,pR);
			}
		}
	}
	return 0;
}
