#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n,m,k,a,l;
ll pow(ll x,ll y,int c){
	if(y==0)return 1;
	ll t=pow(x,y>>1,c);
	ll ans=(t%c)*(t%c);
	if(y&1)ans*=(x%c);
	return ans%c;
}
ll cas0(ll x,ll mod){
	//�����ݣ�����
	
	ll ans=pow(x,mod-2,mod);
	return ans;
}
ll cas1(){
	//��n����������������˺���mod�Ľ�� 
	//1/b����������Ķ������b����Ԫ 
	ll n,mod,a,b,ans=1;//(a/b)mod c 
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&a,&b);
		ll t=a%mod * (pow(b,mod-2,mod)%mod)%mod;
		ans=ans*t%mod;
	}
	return (ans+1)%mod;
    printf("%lld",(ans+1)%mod);
}
const int maxn=3e6+7;
ll inv[maxn];
void cas2(ll n,ll mod){
	//�����㷨����1��n��������ˣ�����n������˻���mod�Ľ�� 
	inv[1]=1;
	for(int i=2;i<=n;i++){
		inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	}
	for(int i=1;i<=n;i++){
		printf("%lld\n",inv[i]);
	}
}

int gcd(int x,int y){
	return (!y)?x:gcd(y,x%y);
}
void exgcd(ll x,ll y,ll &a,ll &b){
	if(!y)a=1,b=0;
	else exgcd(y,x%y,b,a),a-=x/y*b;
}
ll cas3(){
	//��չŷ����ã��������� 
	//���߲����������������������Ҳ��ʹ�� 
	ll x,mod,a,b;
	scanf("%lld%lld",&x,&mod);
	exgcd(x,mod,a,b);
	ll ans=(a%mod+mod)%mod;
	return ans;
} 

int main()
{
	ll n, mod;
	scanf("%lld%lld",&n,&mod);
	cas2(n,mod);
    
    return 0;
}

