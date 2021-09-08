#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int n,m,b;
const int maxn=10086,maxm=50505;
struct edge
{
	int v,w,next;
}e[maxm<<1];
int k,head[maxn],city[maxn],unin[maxn];
void add(int u,int v,int w)
{
	k++;
	e[k].v=v;
	e[k].w=w;
	e[k].next=head[u];
	head[u]=k;
}

int mid;bool flag;
inline int cmid(int l,int r){return (l+r+1)>>1;};

int dis[maxn];
bool vis[maxn];
#define M make_pair
typedef pair<int,int> pii;
priority_queue<pii,vector<pii>,greater<pii> >q;
bool dijk()
{
	int cnt=0;
	int k=unin[mid];
	memset(dis,127,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[1]=0;
	q.push(M(0,1));
	while(!q.empty() and cnt<n)
	{
		int d=q.top().first,u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;cnt++;
		for(int i=head[u];i;i=e[i].next)
		{
			int v=e[i].v,w=e[i].w;
			if(city[v]>k)
			{
				continue;
			}
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				q.push(M(dis[v],v)); 
			}
		}
	}
	if(dis[n]<=b){flag=1;return	0;}//到的了，上界可能更小 
	else return 1;//到不了，下界增加 
}
int main()
{
	//freopen("test.txt","r",stdin);
    cin>>n>>m>>b;
    for(int i=1;i<=n;i++)
    {
    	scanf("%d",&city[i]);
    	unin[i]=city[i];
    }
    sort(unin+1,unin+1+n);
    for(int i=1;i<=m;i++)
    {
    	int al,bl,cl;
    	scanf("%d%d%d",&al,&bl,&cl);
    	add(al,bl,cl);
    	add(bl,al,cl);
    }
    int l=1,r=n;
    while(l<r)
    {
    	mid=cmid(l,r);
    	if(city[1]>unin[mid])
    	{
    		l=mid;
    		continue;
		} 
    	if(dijk())l=mid;
    	else r=mid-1;
    }
    if(!flag)cout<<"AFK";
    else cout<<unin[l+1];
    return 0;
}
