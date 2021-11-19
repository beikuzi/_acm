#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
typedef long long ll;
inline int readi(){
	int x=0;
	char ch=getchar();
	while('0'>ch or ch>'9')ch=getchar();
	while('0'<=ch and ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}return x;
}
inline ll readl(){
	ll x=0;
	char ch=getchar();
	while('0'>ch or ch>'9')ch=getchar();
	while('0'<=ch and ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}return x;
}
int lowbit(int x){
	return x&-x;
} 
int n,m;
const int maxn=1e3+7;

struct op{
	struct tree{
		ll t1,t2,t3,t4;
	}t[maxn][maxn];
	void add(ll x,ll y,ll z){
		for(int i=x;i<=n;i+=lowbit(i)){
			for(int j=y;j<=m;j+=lowbit(j)){
				t[i][j].t1+=z;
				t[i][j].t2+=z*x;
				t[i][j].t3+=z*y;
				t[i][j].t4+=z*x*y;
			}
		}
	}
	void range_add(ll x1,ll y1,ll x2,ll y2,ll z){
		add(x1,y1,z);
		add(x1,y2+1,-z);
		add(x2+1,y1,-z);
		add(x2+1,y2+1,z);
	}
	ll ask(ll x,ll y){
		ll res=0;
		for(int i=x;i;i-=lowbit(i)){
			for(int j=y;j;j-=lowbit(j)){
				res+=(x+1)*(y+1)*t[i][j].t1
					-(y+1)*t[i][j].t2
					-(x+1)*t[i][j].t3
					+t[i][j].t4;
			}
		}return res;
	}
	ll range_ask(ll x1,ll y1,ll x2,ll y2){
		return ask(x2,y2)-ask(x2,y1-1)-ask(x1-1,y2)+ask(x1-1,y1-1);
	}
}o;
ll pt[maxn][maxn];
void init(){
	n=readi(),m=readi();
	register ll z;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			z=readl();
			o.range_add(i,j,i,j,z);
		}
	}
}
void solve(){
	int q=readi();
	while(q--){
		ll z=readl();
		switch(z){
			case 1:{
				ll x1=readl(),y1=readl(),x2=readl(),y2=readl();
				printf("%lld\n",o.range_ask(x1,y1,x2,y2));
				break;
			}
			case 2:{
				z=readl();
				ll x1=readl(),y1=readl(),x2=readl(),y2=readl();
				o.range_add(x1,y1,x2,y2,z);
				break;
			}
		}
	}
}
int main()
{
    init();
    solve();
    return 0;
}
