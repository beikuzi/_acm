#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<vector>
#include<queue>
using namespace std;
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
#define inf 0x7fffffff
const int maxn=1e6+7;
int pt[maxn];
struct tree{
	struct node{
		int l,r;
		int v,mx;//总和、最值 
		int a,cov;//加法标记，覆盖标记 
		bool tag;//标记是否存在cov 
		void set(int x,int y){
			l=x,r=y;
			a=0;
			cov=tag=0;
			mx=-inf;
		}
		void set(){
			a=0;
			cov=tag=0;
		}
		void cover(int k){
			cov=mx=k;
			a=0; 
			v=cov*(r-l+1);
			tag=1;
		}
		void add(int k){
			a+=k,mx+=k;
			v+=k*(r-l+1);
		}
		void change(int k){
			if(tag)cover(k+cov);
			else add(k);
		}
		bool range(int x,int y){
			return x<=l and r<=y;
		}
	}t[maxn<<2];
#define lt(x) (x<<1)
#define rt(x) ((x<<1)|1)
#define mid(x,y) (x+(y-x>>1))
	void pushup(int x){
		t[x].v=t[lt(x)].v+t[rt(x)].v;
		t[x].mx=max(t[lt(x)].mx,t[rt(x)].mx);
	}
	void pushdown(int x){
		if(t[x].tag){
			t[lt(x)].cover(t[x].cov);
			t[rt(x)].cover(t[x].cov);
		} 
		else{
			t[lt(x)].add(t[x].a);
			t[rt(x)].add(t[x].a); 
		}
		t[x].set();
	}
	void build(int l,int r,int x=1){
		t[x].set(l,r);
		if(l==r){
			t[x].v=t[x].mx=pt[l];
			return;
		}
		int mid=mid(l,r);
		build(l,mid,lt(x));
		build(mid+1,r,rt(x));
		pushup(x);
	}
	void mdf(int l,int r,int k,int x=1){
		if(t[x].range(l,r)){
			t[x].cover(k);
			return;
		}
		pushdown(x);
		int mid=mid(t[x].l,t[x].r);
		if(l<=mid)mdf(l,r,k,lt(x));
		if(r>mid) mdf(l,r,k,rt(x));
		pushup(x);
	}
	void add(int l,int r,int k,int x=1){
		if(t[x].range(l,r)){
			t[x].change(k);
			return;
		}
		int mid=mid(t[x].l,t[x].r);
		pushdown(x);
		if(l<=mid)add(l,r,k,lt(x));
		if(r>mid) add(l,r,k,rt(x));
		pushup(x);
	}
	int ask_sum(int l,int r,int x=1){
		if(t[x].range(l,r)){
			return t[x].v;
		}
		pushdown(x);
		int res=0;
		int mid=mid(t[x].l,t[x].r);
		if(l<=mid)res+=ask_sum(l,r,lt(x));
		if(r>mid) res+=ask_sum(l,r,rt(x));
		return res;
	}
	int ask_mx(int l,int r,int x=1){
		if(t[x].range(l,r)){
			return t[x].mx;
		}
		pushdown(x);
		int res1=-inf,res2=-inf;
		int mid=mid(t[x].l,t[x].r);
		if(l<=mid)res1=ask_mx(l,r,lt(x));
		if(r>mid) res2=ask_mx(l,r,rt(x));
		return max(res1,res2);
	}
	void test(int n){
		for(int i=1;i<=n;i++){
			cout<<ask_mx(i,i)<<' ';
		}cout<<endl;
	}
}at;
int n,m;
void init(){
	n=readi();
	for(int i=1;i<=n;i++){
		pt[i]=readi();
	}
	at.build(1,n);
}

int main()
{
    init();
    m=readi();
    for(int i=1;i<=m;i++){
    	int op=readi();
    	int x=readi(),y=readi(); 
    	switch(op){
    		case 1:{
    			int res=at.ask_mx(x,y);
    			printf("%d\n",res);
    			break;
    		}
    		case 2:{
    			int res=at.ask_sum(x,y);
    			printf("%d\n",res);
    			break;
    		}
    		case 3:{
    			int k=readi();
    			at.mdf(x,y,k);
    			break;
    		}
    		case 4:{
    			int k=readi();
    			at.add(x,y,k);
    			break;
    		}
    	}
    	at.test(n);
    }
    return 0;
}
