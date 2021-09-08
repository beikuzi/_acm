#include<iostream>
#include<cstdio>
#include<algorithm> 
using namespace std;
typedef pair<int,int>pii; //位置和积分 
#define M(x,y) make_pair(x,y)
inline int cmid(int l,int r){return (l+r+1)>>1;}
bool cmp(pii x,pii y)
{
	return x.first<y.first;
}
const int maxn=233333;
int sum[maxn];
int main()
{
    int t;cin>>t;
    while(t--)
    {
    	int n,m;scanf("%d%d",&n,&m);
    	pii c[n+1];
    	
    	for(int i=1;i<=n;i++)
    	{
    		int p,q;
    		scanf("%d%d",&p,&q);
    		c[i]=M(p,q);
    		//sort(c+1,c+n+1,cmp);
    		sum[i]=c[i].second+sum[i-1];
    	}
    	
    	int ansmax=-1,range;
    	for(int i=1;i<=n;i++)
    	{
    		range=c[i].first+m*2;//位置+双半径=范围右值 
    		int l=i,r=n;
			while(l<r)
			{
				int mid=cmid(l,r);
				if(c[mid].first<=range)l=mid;
				else r=mid-1;
			} 
			ansmax=max(ansmax,sum[r]-sum[i-1]);
    	}printf("%d\n",ansmax);
    }return 0;
}
