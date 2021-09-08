#include<iostream>
#include<algorithm> 
#include<stack>
#include<cstdio>
using namespace std;
const int maxn=1e5+7;
struct edge{
	int v,next;
}e[maxn];
int k,head[maxn];
void add(int u,int v){
	k++;
	e[k].v=v;
	e[k].next=head[u];
	head[u]=k;
}
int tot,mtot,n;
int dfn[maxn],low[maxn],vis[maxn];
int col[maxn],dye[maxn];
stack<int> s;
void tarj(int u){
	low[u]=dfn[u]=++tot;
	s.push(u);vis[u]=1;
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].v;
		if(!dfn[v]){
			tarj(v);
			low[u]=min(low[u],low[v]);
		}
		else if(vis[v])low[u]=min(low[u],dfn[v]);
	}
	int tab;
	if(dfn[u]==low[u]){
		mtot++;
		do{
			tab=s.top();s.pop();
			col[tab]=mtot;
			dye[mtot]++;
			vis[tab]=0;
		}while(tab!=u);
	}
}
int ans[maxn];
int dfs(int u){
	int v=e[head[u]].v;
	if(ans[v]){
		return ans[u]=ans[v]+1;
	}return ans[u]=dfs(v)+1;
}
int main()
{
	scanf("%d",&n);
	int v;
    for(int i=1;i<=n;i++){
    	scanf("%d",&v);
    	if(v==i)ans[i]=1;
    	add(i,v);
    }
    for(int i=1;i<=n;i++){
    	if(!dfn[i])tarj(i);
    }
    for(int i=1;i<=n;i++){//»· 
    	if(dye[col[i]]!=1)ans[i]=dye[col[i]];
    	//cout<<i<<' '<<col[i]<<' '<<dye[col[i]]<<' '<<ans[i]<<endl;
    }
    for(int i=1;i<=n;i++)if(!ans[i])dfs(i);
	//Á´ 
    
    for(int i=1;i<=n;i++)printf("%d\n",ans[i]);
    return 0;
}
