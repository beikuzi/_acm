#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
long long cost_0[10]={0,9,8,7,6,5,4,3,2,1};
long long cost_1[10]={1,0,9,8,7,6,5,4,3,2};
long long c[10];
inline long long cmid(long long l,long long r){return (l+r+1)>>1;}
bool cal(long long v,long long k)
{
	long long p[10];for(long long i=0;i<10;i++)p[i]=c[i];
	long long one=v*2,zero=v;
	for(long long i=11;i>=2;i--)
	{
		long long t=min(p[i%10],one);
		one-=t;p[i%10]-=t;
		k-=t*cost_1[i%10];
		if(k<0)return false;
		if(one==0)break;
	}if(one!=0)return false;
	
	for(long long i=10;i>=1;i--)
	{
		long long t=min(p[i%10],zero);
		zero-=t;p[i%10]-=t;
		k-=t*cost_0[i%10];
		if(k<0)return false;
		if(zero==0)break;
	}if(zero!=0)return false;
	return true;
}
int main()
{
    long long t;cin>>t;
    while(t--)
    {
    	long long l=0,r=0;
    	memset(c,0,sizeof(c));
    	long long n,k;scanf("%lld%lld",&n,&k);
    	while(n--)
    	{
    		long long a,b;scanf("%lld%lld",&a,&b);
    		c[a]=b;
    		r+=b;
    		//cout<<r<<endl;
    	}r/=3;
    	while(l<r)
    	{
    		long long mid=cmid(l,r);
    		if(cal(mid,k))l=mid;
    		else r=mid-1;
    	}
    	printf("%lld\n",l);
    }
}
