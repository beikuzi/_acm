#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<queue>
#include<stack>
using namespace std;
//欧拉路径：一个路径 恰好 包括所有边1次
//欧拉回路：欧拉路径形成的回路
//即你要不重复道路情况下遍历所有路，如果还要回原点就是回路 
const int maxn=1e5+7,maxm=2e5+7;
int in[maxn],out[maxn];
int n,m;
typedef pair<int,int>pii;
#define M make_pair
priority_queue<int,vector<int>,greater<int> >q[maxn]; 
//priority_queue<int>q[maxn];
void init(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		out[u]++;
		in[v]++;
		q[u].push(v);//按照最小字典序压入下个目标,回溯入栈，则大的欧拉路径先入栈 
	}
}
//尽快让字典序最小的点入队，他才不容易因为失去了所有的出度而进入栈，越晚被搜到，出度为0的机会越大，越容易先入栈
//总之就是逼死大的和出度少的，出度越多回来就要越多 
//由于满足了欧拉路径，你要么去掉一个字典序小的环，要么搜到底 
//如果一个环的有向边被去掉，相当于全体入度、出度-1 
stack<int>ans;
void dfs(int u){
	while(!q[u].empty()){
		int v=q[u].top();q[u].pop();
		dfs(v); 
	}
	ans.push(u);
}
//有向图判定：起点：入度比出度少1，终点：比出度多1，其他的点入度出度一样 
//有向图回路：所有点入度等于出度
//无向图路径：2个点度数奇数，其他偶数
//无向图回路：全偶数
//只有先判定存在以后才能去找 ,可以用并查集去判定最基本的连通,即有向边视为无向边连通 
bool solve(){
	int srt=-1,end=-1,cnt=0;
	for(int i=1;i<=n;i++){
		if(in[i]!=out[i]){
			cnt++;
			if(in[i]==out[i]-1)srt=i;
			else if(in[i]==out[i]+1)end=i;
		}
	}
	if(cnt==0)srt=end=1;
	if(cnt!=0 and cnt!=2){//不是环，或者1起1终 
		return false;
	}
	if(srt==-1 or end==-1)return false;
	dfs(srt);
	while(!ans.empty()){
		printf("%d ",ans.top());
		ans.pop();
	}
	return true;
}
int main()
{
    init();
    if(!solve())printf("No");
    return 0;
}
