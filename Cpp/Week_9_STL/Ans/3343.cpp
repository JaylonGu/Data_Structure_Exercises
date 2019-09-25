//By Guo Wei
/*
为了使得比赛更好看，每一个新队员都会选择与他实力最为接近的人比赛，即比赛双方的实力值之差的绝对值越小越好，如果有两个人的实力值与他差别相同，则他会选择比他弱的那个（显然，虐人必被虐好）。
*/
#include <list>
#include <string>
#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;
multimap<unsigned int,unsigned int> fights;
int main()
{
	unsigned int  n,id,force;
	//freopen("d:\\tmp\\warm.txt","r",stdin);
	scanf("%d",&n);
	fights.insert(make_pair(1000000000,1));
	while(n--)
	{
		scanf("%d%d",&id,&force);
		//pair< multimap<unsigned int,unsigned int>::iterator,bool > sp;
		multimap<unsigned int,unsigned int>::iterator sp,tmpp;
		sp = fights.insert(make_pair(force,id));
		multimap<unsigned int,unsigned int>::iterator p1,p2;
		if( sp == fights.begin()) {
			tmpp = fights.begin(); 
			tmpp ++;
			printf("%d %d\n",sp->second, tmpp->second);
		}
		else if( sp == (--fights.end()) ) {
			tmpp = sp; 
			tmpp --;

			printf("%d %d\n",sp->second, (tmpp)->second);
		}
		else {
			p1 = sp;
			p1 --;
			p2 = sp;
			p2 ++;	
			if( sp->first - p1->first  > ( p2->first - sp->first) )
				printf("%d %d\n",sp->second,p2->second);
			else
				printf("%d %d\n",sp->second,p1->second);
		}

	}

}
