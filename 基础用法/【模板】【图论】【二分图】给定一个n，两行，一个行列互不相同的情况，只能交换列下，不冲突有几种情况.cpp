#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int maxn=4e5+1;
queue<int>q[maxn];
bool vis[maxn];
void dfs(int x){
	vis[x]=true;
	while(!q[x].empty()){
		int v=q[x].front();
		q[x].pop();
		if(!vis[v])dfs(v);
	}
}

int c[maxn],d[maxn];
int main()
{
    int t;scanf("%d",&t);
    while(t--){
    	memset(vis,0,sizeof(vis));
    	//memset(q,0,sizeof(q));
    	int n;scanf("%d",&n);
    	for(int i=1;i<=n;i++)q[i]=queue<int>();
    	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
    	for(int i=1;i<=n;i++)scanf("%d",&d[i]);
    	for(int i=1;i<=n;i++){
    		q[c[i]].push(d[i]);
    		q[d[i]].push(c[i]);
    	}
    	ll ans=1;
    	//����1��Ӧx����������һ�е�1����һ�е�x��Ҫ����
		//ÿ�ָ�������ɿ��ɶ����� 
    	for(int i=1;i<=n;i++){
    		if(!vis[i]){
    			ans=ans*2%mod;
    			dfs(i);
    		}
    	}
    	printf("%lld\n",ans);
    }
    return 0;
}
