#include<iostream>
using namespace std;
typedef long long ll;
//!!!!!!!!!!!!!!!!
//对于pow，存在模板，会优先匹配最适合的那个
//也就是建议不要重名，否则即使是ll，int也不会进到自己重载的ll，ll的  
ll pow(ll x,ll y,ll c){
	if(y==0)return 1;
	ll t=pow(x,y/2,c);
	ll ans=(t%c)*(t%c);
	if(y&1)ans*=(x%c);
	return ans%c;
}
ll cpow(ll x,ll y,ll c){
	x%=c;
	ll res=1;
	while(y){
		if(y&1){
			res*=x;
			res%=c;
		}
		x*=x;
		x%=c;
		y>>=1;
	}
	return res;
} 
int main()
{
    cout<<cpow(2,10,6);
}
