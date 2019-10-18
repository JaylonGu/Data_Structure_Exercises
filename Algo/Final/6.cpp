/*

*/

#include<iostream>
#include<cstring>
using namespace std;
int flag=0;
string pq[10];//存储棋盘
bool test(int x,int y,char p)//判读在X，Y位置上放p是否可行
{
	pq[x][y]='0';
	for(int i=0;i<9;++i) if(pq[x][i]==p||pq[i][y]==p) return false;
	int a=x/3+1,b=y/3+1;
	for(int i=(a-1)*3;i<3*a;++i)	
		for(int j=(b-1)*3;j<3*b;++j)
			if(pq[i][j]==p) return false;
	return true;
}
void dfs(int x,int y)
{
	int nx=-1,ny=-1;
	for(int i=x;i<9;++i){
		int fg=0;
		for(int j=0;j<9;++j)
			if(!(i==x&&j==y)&&pq[i][j]=='0'){nx=i;ny=j;fg=1;break;}
		if(fg) break;
	}			
	for(int i=1;i<=9;++i)
		if(test(x,y,'0'+i)){
			if(flag) return;
			pq[x][y]='0'+i;
			if(nx==-1){flag=1;return;}
			dfs(nx,ny);
			if(flag) return;
			pq[x][y]='0';
		}
}
int main()
{
	int t;
	cin>>t;
	while(t--){
		flag=0;
		for(int i=0;i<9;++i) cin>>pq[i];
		int posx,posy;
		for(int i=0;i<9;++i){//按先行后列寻找第一个未被填充的位置
			int fg=0;
			for(int j=0;j<9;++j)
				if(pq[i][j]=='0'){fg=1;posx=i;posy=j;break;}
			if(fg) break;
		}
		dfs(posx,posy);
		for(int i=0;i<9;++i) cout<<pq[i]<<endl;
	}
	return 0;
}