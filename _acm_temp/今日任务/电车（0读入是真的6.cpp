#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
typedef pair<int,int> pii;
#define M make_pair
priority_queue<pii,vector<pii>,greater<pii> >q;
const int maxn=233;
int dis[maxn],head[maxn],vis[maxn];
int n,k,cnt;
struct edge
{
	int v,w,next;
}e[maxn*maxn];
void add(int u,int v,int w)
{
	k++;
	e[k].v=v;
	e[k].w=w;
	e[k].next=head[u];
	head[u]=k;
}
void dijk(int s)
{
	dis[s]=0;q.push(M(0,s));
	while(!q.empty() and cnt<n)
	{
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		cnt++;vis[u]=1;
		for(int i=head[u];i!=-1;i=e[i].next)
		{
			int v=e[i].v,w=e[i].w;
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				q.push(M(dis[v],v));
			}
		}
	}
}
int main()
{
    memset(head,-1,sizeof(head));
    memset(dis,127,sizeof(dis));
    int a,b;
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++)
    {
    	int x,y=0;
    	scanf("%d",&x);
    	if(x==0)continue;
		else scanf("%d",&y);
    	if(i!=y)
    	{
    		add(i,y,0);
    		//add(y,i,0);
    	}
    	for(int j=2;j<=x;j++)
    	{
    		scanf("%d",&y);
    		if(i!=y)
    		{
    			add(i,y,1);
    			//add(y,i,1);
    		}
    	}
    }
    dijk(a);
    //for(int i=1;i<=n;i++)cout<<dis[i]<<' ';cout<<endl;
    if(dis[b]==2139062143)cout<<-1;
    else cout<<dis[b];
    return 0;
}
