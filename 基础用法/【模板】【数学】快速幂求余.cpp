#include<iostream>
using namespace std;
typedef long long ll;
//!!!!!!!!!!!!!!!!
//����pow������ģ�壬������ƥ�����ʺϵ��Ǹ�
//Ҳ���ǽ��鲻Ҫ����������ʹ��ll��intҲ��������Լ����ص�ll��ll��  
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
