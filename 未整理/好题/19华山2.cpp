#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring> 
using namespace std;
typedef pair<int,int> pii;
#define M(x,y) make_pair(x,y)
bool cmp(pii x,pii y)
{
	return x.second<y.second;
}
int c[2333];
pii val[2333];
int main()
{
    int n,m,k;cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
    	int p,q;scanf("%d%d",&p,&q);
    	val[i]=M(q,p);
    }sort(val+1,val+1+n,cmp);
    for(int i=1;i<n;i++)
    {
    	for(int j=m;j>=val[i].first;j--)
    	{
    		//cout<<j<<" "<<c[j]<<" "<<c[j-val[i].first]+val[i].second<<endl;
    		c[j]=max(c[j],c[j-val[i].first]+val[i].second);
    		//for(int q=1;q<=m;q++)cout<<c[q]<<" ";cout<<endl;
    	}
    	
    }
    int ans=max(c[m],c[m-1]+val[n].second-k);
    if(val[n].first<=m)ans=max(ans,c[m-val[n].first]+val[n].second);
    printf("%d",ans);
    return 0;
}
