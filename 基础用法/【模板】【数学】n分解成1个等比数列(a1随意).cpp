#include<iostream>
#include<cstdio>
#include<algorithm> 
using namespace std;
typedef long long ll;
int n;
ll pow(ll x,ll y){
	if(y==0)return 1;
	ll t=pow(x,y/2);
	ll ans=t*t;
	if(y&1)ans*=x;
	return ans;
} 
int cal(ll q){
	int res=0,p=0;
	while(1){
		ll t=pow((long long)q,(long long)++p)-1;
		if(n*(q-1)/t>=n)continue;
		if(n*(q-1)/t<1)break;
		if(n*(q-1)%t==0)res++;
	}
	return res;
}
int main()
{
    scanf("%d",&n);
    int ans=0;
    for(int i=1;i<n;i++)ans+=(n%i==0);
    for(int i=2;i<n;i++){//q
		ans+=cal(i);
	}
	cout<<ans;
	return 0;
}
