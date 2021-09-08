#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
int n;
typedef long long ll;
const int maxn=5*1e4+7,maxm=maxn<<1;
struct edge{
	int v,next;
}e[maxm];
int head[maxn],k=-1;
void add(int u,int v){
	e[++k].next=head[u];
	head[u]=k;
	e[k].v=v;
}
int max_cnt[maxn],min_cnt=2e9,cnt[maxn];
void dfs(int u,int fa){
	cnt[u]=1;
	for(int i=head[u];i!=-1;i=e[i].next){
		int v=e[i].v;
		if(v==fa)continue;
		dfs(v,u);
		cnt[u]+=cnt[v];
		//cout<<u<<' '<<v<<' '<<cnt[u]<<endl;
		max_cnt[u]=max(max_cnt[u],cnt[v]); 
	}
	max_cnt[u]=max(max_cnt[u],n-cnt[u]);//cnt是从u往下的所有子树，选最大子树和除去自己的树 
	min_cnt=min(min_cnt,max_cnt[u]);
}
int main()
{
	memset(head,-1,sizeof(head));
    scanf("%d",&n);
    int u,v;
    for(int i=1;i<n;i++){
    	scanf("%d%d",&u,&v);
    	add(u,v);
    	add(v,u);
    }
    dfs(1,-1);
    //cout<<min_cnt<<endl;
    for(int i=1;i<=n;i++){
    	if(min_cnt==max_cnt[i])cout<<i<<' ';
    	//cout<<max_cnt[i]<<endl;
    }
    return 0;
}
