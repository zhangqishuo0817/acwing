从 1∼n
 这 n
 个整数中随机选出 m
 个，输出所有可能的选择方案。

输入格式
两个整数 n,m
 ,在同一行用空格隔开。

输出格式
按照从小到大的顺序输出所有方案，每行 1
 个。

首先，同一行内的数升序排列，相邻两个数用一个空格隔开。

其次，对于两个不同的行，对应下标的数一一比较，字典序较小的排在前面（例如 1 3 5 7 排在 1 3 6 8 前面）。

数据范围
n>0
 ,
0≤m≤n
 ,
n+(n−m)≤25
# include<cstdio>
# include<cstring>
# include<iostream>

using namespace std;

int m,n;
const int N=10;
int st[N];
bool used[N];

void dfs(int u){
	if(u>m){
		for(int i=1;i<=m;i++){
			printf("%d ",st[i]);
		}
		puts("");
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!used[i]){
			st[u]=i;
			used[i]=true;
			dfs(u+1);
			
			st[u]=0;
			used[i]=false;
		}
	}
}
int main(){
	cin>>n>>m;
	
	dfs(1);
	
	return 0;
}