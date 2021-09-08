#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring> 
#include<queue>
using namespace std;
const int maxn=1e3+7,maxm=1e4+7;
typedef long long ll;
struct edge{
	ll v,w,next;
}e[maxm];
int head[maxn],vis[maxn],pre[maxn],k=-1;//ע��k 
ll dis[maxn];//����������xor1�൱��-1��ż��xor1�� +1
void add(int u,int v,int w){
	e[++k].next=head[u];
	head[u]=k;
	e[k].v=v,e[k].w=w;
}
bool bfs(int s,int t){
	queue<ll>q;//ע��д��bfs���棬��Ϊ����ʱδ��� 
	memset(vis,0,sizeof(vis));
	dis[s]=2e9;//1.Դͷ����ˮ 
	q.push(s);vis[s]=1;//2.ѹ���� 
	
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=head[u];i!=-1;i=e[i].next){
			//���������ַ�ʽ��һ�����ƽ�ȥ������vis��һ����ȡ��������vis
			//����dijkԭ����̰����̵㣬�㱻ѹ��ܶ�Σ�����ֻ��ȡ����vis
			//Ek�㷨������ô�ߣ���ֻ�Ӵ�һ��,�ƽ�ȥvis 
			ll v=e[i].v,w=e[i].w;
			if(!w or vis[v])continue;//3.�ж��Ƿ��������� 
			dis[v]=min(dis[u],w);//4.����Ǹ���ʽ���£�����dis����memset 
			q.push(v);vis[v]=1;//5.ѹ���� 
			pre[v]=i;//6.Ϊdfs��׼�������ж��Ƿ����� �˳���dfs 
			if(v==t)return 1;
		}
	}return 0; 
}
ll dfs(int s,int t){
	int u=t;
	while(u!=s){
		int i=pre[u];//1.��ǰ���� 
		e[i].w-=dis[t];//2.������٣��������� 
		e[i^1].w+=dis[t];
		u=e[i^1].v;//3.ѭ����һ����� 
	}return dis[t]; 
}
int n,m,s,t;
int loc[maxn][maxn];
int main()
{
    memset(head,-1,sizeof(head));
    scanf("%d%d%d%d",&n,&m,&s,&t);
    int u,v,w;
    for(int i=1;i<=m;i++){
    	scanf("%d%d%d",&u,&v,&w);
    	if(loc[u][v]==0){//1.�ж��ǲ����ر� 
    		add(v,u,0);//2.����ͷ��� 
    		add(u,v,w);
    		loc[u][v]=k;//3.��¼λ�� 
    	}
    	else e[loc[u][v]].w+=w;//4.�ر� 
    }
    ll ans=0;
    while(bfs(s,t)){
    	ans+=dfs(s,t);
    }printf("%lld",ans);
    return 0;
}
