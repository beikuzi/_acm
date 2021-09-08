#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
using namespace std;
int n,m,s,t;
const int maxn=1e3+7,maxm=1e5+7; 
struct edge{
	int v,w,next;
}e[maxm<<1];
int head[maxn],k;
void add(int u,int v,int w){
	e[++k].next=head[u];
	head[u]=k;
	e[k].v=v,e[k].w=w;
}
queue<int>q;
int cnt[maxn];
bool bfs(int x){
	memset(cnt,0,sizeof(cnt));
	while(!q.empty())q.pop();
	q.push(x);cnt[x]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=head[u];i!=-1;i=e[i].next){
			int v=e[i].v,w=e[i].w;
			if(!w or cnt[v])continue;
			cnt[v]=cnt[u]+1;
			q.push(v);
		}
	}
	if(cnt[t]){
		for(int i=1;i<=n;i++)
	}
	return 0;
}
int dfs
int main()
{
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=1;i<=m;i++){
    	
    }
}
