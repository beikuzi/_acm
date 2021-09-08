#include<iostream>
#include<set>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=50505;
struct edge
{
	int v,w,next;
}e[maxn<<1];
int head[maxn],k;
void add(int u,int v,int w)
{
	k++;
	e[k].v=v;
	e[k].w=w;
	e[k].next=head[u];
	head[u]=k;
}
int n,m;
inline int cmid(int l,int r) {return (l+r+1)>>1;}

int ans;
int dfslen(int u,int fa)
{
	int sum1=0,sum2=0;
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].v;
		if(v==fa)continue;
		sum2=max(sum2,dfslen(v,u)+e[i].w);
		if(sum1<sum2)swap(sum1,sum2);
	}
	ans=max(ans,sum1+sum2);
	return sum1;
}
int trlen(int u)
{
	dfslen(u,0);
	return ans;
}

multiset<int> s[maxn];
multiset<int>::iterator it;
int mid;
int dfs(int u,int fa)
{
	s[u].clear();
	int k=mid;
	int len=0;
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].v;
		if(v==fa)continue;
		len=dfs(v,u)+e[i].w;
		if(len>=k)ans++;
		else s[u].insert(len); 
	}
	int Max=0;
	//cout<<s[u].size()<<endl;
	while(!s[u].empty())
	{
		//cout<<mid<<' '<<*s[u].begin() <<endl;
		if(s[u].size()==1)return max(Max,*s[u].begin() );
		it=s[u].lower_bound(k-*s[u].begin() );
		if(it==s[u].begin() and s[u].count(*it)==1 )it++;
		if(it==s[u].end() )
		{
			Max=max(Max,*s[u].begin() );
			s[u].erase(s[u].find(*s[u].begin() )); 
		}
		else
		{
			ans++;
			s[u].erase(s[u].find(*it) )  ;
			s[u].erase(s[u].find(*s[u].begin() ));
		}
	}
	return Max;
}
bool gred2()
{
	ans=0;
	dfs(1,0);
	return ans>=m;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<n;i++)
    {
    	int al,bl,cl;
    	scanf("%d%d%d",&al,&bl,&cl);
    	add(al,bl,cl);
    	add(bl,al,cl);
    }
    int l=1,r=trlen(1);
    while(l<r)
    {
    	mid=cmid(r,l);
    	if(gred2() )l=mid;
    	else r=mid-1;
    	//cout<<mid<<' '<<ans<<'?'<<endl;
    }
    cout<<l;
    return 0;
}
