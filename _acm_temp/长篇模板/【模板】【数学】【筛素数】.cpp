#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<bitset>
using namespace std;
typedef long long ll;
const int maxn=1e8+7;
inline int readi(){
	int x=0,b=1;
	char ch=getchar();
	while('0'>ch or ch>'9'){
		if(ch=='-')b=-1;
		ch=getchar();
	}
	while('0'<=ch and ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}return x*b;
}
inline ll readl(){
	ll x=0,b=1;
	char ch=getchar();
	while('0'>ch or ch>'9'){
		if(ch=='-')b=-1;
		ch=getchar();
	}
	while('0'<=ch and ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}return x*b;
}
bool sp(int x){//单体 
	switch(x){
		case 1:return 0;
		case 2:return 1;
		case 3:return 1;
		default:{
			if(x%6!=5 and x%6!=1)return 0;
			int r=sqrt(x);
			for(int i=5;i<=r;i+=6){
				if(x%i==0 or x%(i+2)==0)return 0;
			}
			return 1;
		}
	}return '?'; 
}
//----------------------------------------------------------------------
bitset<maxn>p;//表示i是不是素数 
int pr[maxn];//素数表，第i个素数是啥 
int n,k;//k表示现在的素数表拥有几个素数 
void ol(){
	p[1]=false;
	p.set();//全部设为1
	for(int i=2;i<=n;i++){
		if(p[i])pr[++k]=i;//加入素数表 
		for(int j=1;j<=k and i*pr[j]<=n;j++){//在范围内用素数表筛 
			p[i*pr[j]]=false;
			if(i%pr[j]==0)break;
			//i能分解出一个已经存在的质数，i=z*f    （z是表中存在质数 
			//与其用z*f来合成，不如之后用新的数*z来合成（不会重复 
		}
	} 
}
void init(){
	n=readi();
	ol();
}
void solve(){
	for(int i=1;i<=k;i++){
		printf("%d,",pr[i]);
	} 
}
int main()
{
    init();
    solve();
    return 0;
}
