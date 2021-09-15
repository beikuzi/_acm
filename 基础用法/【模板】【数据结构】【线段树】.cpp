#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cctype>
using namespace std;
typedef long long ll;
inline int readi(){
	int x=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch)){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x;
}
inline int readl(){
	ll x=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch)){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
const int maxn=1e6+7;
ll pt[maxn];//point£¬µãÖµ 
struct tree{
	int lt,rt;
	ll val,tag;
}ts[maxn<<2];
inline int nl(int x){
	return x<<1;
}
inline int nr(int x){
	return (x<<1)|1;
}
inline int cmid(int lt,int rt){
	return lt+(rt-lt>>1);
}
void pushup(int x){
	ts[x].val=ts[nl(x)].val+ts[nr(x)].val;
}
void pushdowm(int x){
	ll tag=ts[x].tag;
	if(!tag)return;
	int lt=nl(x),rt=nr(x);
	int lcnt=ts[lt].rt-ts[lt].lt+1;
	int rcnt=ts[rt].rt-ts[rt].lt+1;
	
	ts[lt].tag+=tag;
	ts[lt].val+=tag*lcnt;
	ts[rt].tag+=tag;
	ts[rt].val+=tag*rcnt;
	ts[x].tag=0;
}
void build(int x,int lt,int rt){
	ts[x].lt=lt;
	ts[x].rt=rt;
	if(lt==rt){
		ts[x].val=pt[lt];
		return; 
	}
	int mid=cmid(lt,rt);
	build(nl(x),lt,mid);
	build(nr(x),mid+1,rt);
	pushup(x);
}
int al=0,ar=0;
void adj(int lt,int rt){
	al=lt;
	ar=rt;
}
void update(int x,ll val){ 
	if(al<=ts[x].lt and ts[x].rt<=ar){
		int cnt=ts[x].rt-ts[x].lt+1;
		ts[x].tag+=val;
		ts[x].val+=val*cnt;
		return;
	}
	pushdowm(x);
	int mid=cmid(ts[x].lt,ts[x].rt);
	if(al<=mid)update(nl(x),val);
	if(ar>mid)update(nr(x),val);
	pushup(x);
}
ll ask(int x){
	if(al<=ts[x].lt and ts[x].rt<=ar)return ts[x].val;
	pushdowm(x);
	int mid=cmid(ts[x].lt,ts[x].rt);
	ll ans=0;
	if(al<=mid)ans+=ask(nl(x)); 
	if(ar>mid)ans+=ask(nr(x));
	return ans;
}

void build(int lt,int rt){
	build(1,lt,rt);
}
void update(ll val){
	update(1,val);
}
ll ask(){
	ask(1);
}

int n,m;
void init(){
	n=readi();
	m=readi();
	for(int i=1;i<=n;i++){
		pt[i]=readi();
	}
	build(1,n);
	
} 
void solve(){
	for(int i=1,crt,x,y,z;i<=m;i++){
		crt=readi();
		x=readi();y=readi();
		adj(x,y);
		if(crt==1){
			z=readi();
			update(z);
		}
		else if(crt==2){
			printf("%lld\n",ask());
		}
	}	
}
int main(){
	init();
	solve();
	return 0;
}
