/*
Given a constant K and a singly linked list L, you are supposed to reverse the links of every K elements on L. For example, given L being 1→2→3→4→5→6, if K=3, then you must output 3→2→1→6→5→4; if K=4, you must output 4→3→2→1→5→6.

Input Specification:
Each input file contains one test case. For each case, the first line contains the address of the first node, a positive N (≤10
​5
​​ ) which is the total number of nodes, and a positive K (≤N) which is the length of the sublist to be reversed. The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.

Then N lines follow, each describes a node in the format:

Address Data Next
where Address is the position of the node, Data is an integer, and Next is the position of the next node.

Output Specification:
For each case, output the resulting ordered linked list. Each node occupies a line, and is printed in the same format as in the input.

Sample Input:
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
Sample Output:
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1
*/

#include<iostream>
#define MaxSize 100005
using namespace std;
int main(){
	int Data[MaxSize];
	int Next[MaxSize];
	int list[MaxSize];
	int FirstAdd,N,K;
	scanf("%d %d %d",&FirstAdd,&N,&K);
	for(int i=0;i<N;i++){
		int tmpAdd,tmpData,tmpNext;
		scanf("%d %d %d",&tmpAdd,&tmpData,&tmpNext);
		Data[tmpAdd] = tmpData;
		Next[tmpAdd] = tmpNext;
	}
	int sum=0;   // 累计有效结点数 
	while(FirstAdd!=-1){   // 当尾结点为 -1 时结束 
		list[sum++] = FirstAdd;   // 记录所有Address
		FirstAdd = Next[FirstAdd];  // 找下一个结点 
	}
	for(int i=0;i<sum-sum%K;i+=K){  // 每 K 个结点一个区间 
		for(int j=0;j<K/2;j++){  // 反转链表
			int t = list[i+j];
			list[i+j] = list[i+K-j-1];
			list[i+K-j-1] = t; 
		}
	}
	for(int i=0;i<sum-1;i++)
		printf("%05d %d %05d\n",list[i],Data[list[i]],list[i+1]);
	printf("%05d %d -1\n",list[sum-1],Data[list[sum-1]]);
	return 0;
}