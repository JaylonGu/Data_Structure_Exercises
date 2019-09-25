//By Guo Wei
#include <iostream>
#include <cstdio>
#include <set>
#include <string>
#include <cstring>

using namespace std;
typedef  multiset<int>::iterator PTR;

int main()
{
	int n;
	multiset<int> mst;
	set<int> st; //加入过的都放到这里
	PTR p;
	scanf("%d",&n);
	for(int i = 0;i < n; ++i) {
		char cmd[20];
		int x;
		scanf("%s%d",cmd,&x);
		switch(cmd[1]) {
			case 'd': //add
				st.insert(x);
				mst.insert(x);
				printf("%d\n",mst.count(x));
				break;
			case 'e': //del ///重点
				printf("%d\n",mst.count(x));
				p = mst.find(x);
				if( p != mst.end()) {
					pair<PTR,PTR> range = mst.equal_range(x);	///重点 
					mst.erase(range.first,range.second);
				}
				break;
			case 's': //ask
				set<int>::iterator pp = st.find(x);
				if(pp!= st.end()) 
					printf("1 %d\n",mst.count(x));
				else
					printf("0 %d\n",mst.count(x));
				break;
		}
	}
	return 0;
}
