#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<queue>
using namespace std;
typedef long long ll;
ll cpow(ll x,ll y){
	if(y==0)return 1;
	ll t=cpow(x,y/2);
	ll ans=t*t;
	if(y&1)ans*=x;
	return ans;
}
ll cn2(ll n){
	ll x=(1<<n)+1;
	ll y=(1<<n)-1;
	return (cpow(x,n)>>((n>>1)*n))&y;
}
ll fal(ll n){
	if(n==1)return 1;
	if(n&1==1)return n*fal(n-1);
	ll temp=fal(n>>1);
	return cn2(n)*temp*temp;
}
int main()
{
	cout<<fal(20);
}
