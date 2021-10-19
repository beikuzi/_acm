#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
const int maxn=1e3+7;
int n,m;
int edge[maxn][maxn];
typedef long long ll;
inline int readi(){
	int x=0,b=1;
	char ch=getchar();
	while('0'>ch or ch>'9'){
		if(ch=='-')b=-1;
		ch=getchar();
	}
	while('0'<=ch and ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}return x*b;
}
inline ll readl(){
	ll x=0,b=1;
	char ch=getchar();
	while('0'>ch  or ch>'9'){
		if(ch=='-')b=-1;
		ch=getchar();
	}
	while('0'<=ch and ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}return x*b;
}
int vis[maxn],g[maxn];
void init(){
	memset(vis,0,sizeof(vis));
	memset(g,0,sizeof(g));
	n=readi(),m=readi();
	register int u,v;
	for(int i=1;i<=m;i++){
		u=readi(),v=readi();
		edge[u][v]=1;
	}
}
bool cp(int u){
	for(int v=1;v<=n;v++){
		if(!vis[v] and edge[u][v]){
			vis[v]=1;
			if(!g[v] or cp(g[v])){//没有配偶or配偶可以让出去 
				g[v]=u;//让g[v]，回溯让出配偶，然后给v分配配偶u 
				return true;
			}
		}
	}return false;
}
void solve(){
	int ans=0;
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		if(cp(i)){
			ans++;
		}
	}
	printf("%d",ans);
}
int main()
{
    init();
    solve();
    return 0;
}
