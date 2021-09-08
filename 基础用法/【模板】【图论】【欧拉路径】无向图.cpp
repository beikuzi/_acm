#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<stack>
using namespace std;
const int maxn=520;
int g[maxn][maxn],du[maxn];
int n,m;
stack<int>ans;
//详细看有向图 
void init(){
	scanf("%d",&m);
	//有向图删掉出度，无向图删掉度，都是贪心逼掉大值少度 
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		g[u][v]++;
		g[v][u]++;
		du[u]++,du[v]++;
		n=max(n,max(u,v));
	}
}
void dfs(int u){
	for(int v=1;v<=n;v++){
		if(g[u][v]){
			g[u][v]--;
			g[v][u]--;
			dfs(v);
		}
	}
	ans.push(u);
}
void solve(){
	//无向图路径：2个点度数奇数，其他偶数
	int srt=0,end=0,cnt=0;
	for(int i=1;i<=n;i++){
		if(du[i]&1){
			if(srt)end=i;
			else srt=i;
			cnt++;
		}
	}
	if(cnt==0)srt=end=1;
	if(srt==0 or end==0)printf("fuxk");
	if(cnt!=0 and cnt!=2)printf("fuxk");
	dfs(srt);
	while(!ans.empty()){
		printf("%d\n",ans.top());
		ans.pop();
	}
}
int main()
{
    init();
    solve();
    return 0;
}
