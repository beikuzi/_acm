#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<vector>
#include<queue>
using namespace std;
//HDU-5306 
inline int readi(){
	int x=0;
	char ch=getchar();
	while('0'>ch or ch>'9'){
		ch=getchar();
	}
	while('0'<=ch and ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}return x;
}
typedef long long ll;
#define mid(x,y) (x+(y-x>>1))
#define lt(x) (x<<1)
#define rt(x) ((x<<1)|1)
const int maxn=1e6+7; 
/*
不同点
1.使用最大值(v)，次大值(-1)和最值下放标记(-1)
2.pushup要合并两个子节点的最值，得到次大值，和最值个数的数量 （值合并仍然存在 
3.建树时注意1的初始化 
4.下放的时候，如果第二最值仍大于，还要继续下放 
*/
int pt[maxn];
struct tree{
	struct node{
		int l,r;
		int cnt;//最大值的数量 
		ll v;
		int tag;//最值标记 
		int mx,mx2;//最值 
		void set(int x,int y){//结点的初始化 
			l=x,r=y,tag=-1;//tag取-1前提是最值>=0 
		}
		void set(){
			tag=-1;
		}
		void tg(int k){//让那个节点的总和、标记，根据 k来更新 
			v-=(ll)cnt*(mx-k);//更新总和 
			mx=tag=k;//最值和标记 
		}
		bool range(int x,int y){//判断这个结点是不是在目标以内，不用再下放，标记停留在这个结点 
			return x<=l and r<=y;
		}
	}t[maxn<<2];
	void pushup(int x){
		node t1=t[lt(x)],t2=t[rt(x)];
		t[x].v=t1.v+t2.v;
		if(t1.mx==t2.mx){//如果相等，合并数量 
			t[x].mx=t1.mx;
			t[x].cnt=t1.cnt+t2.cnt;
			t[x].mx2=max(t1.mx2,t2.mx2);
		}
		else{
			if(t1.mx<t2.mx)swap(t1,t2);//否则以大的为基准 
			t[x].mx=t1.mx;
			t[x].cnt=t1.cnt;
			t[x].mx2=max(t2.mx,t1.mx2);//注意这里是最大值和次大值 
		}
	}
	void build(int l,int r,int x=1){
		t[x].set(l,r);
		if(l==r){
			t[x].mx=t[x].v=pt[l];
			t[x].cnt=1;
			t[x].mx2=-1;
			return;
		}
		int mid=mid(l,r);
		build(l,mid,lt(x));
		build(mid+1,r,rt(x));
		pushup(x);
	}
	void pushdown(int x){
		if(~t[x].tag){//如果有标记 
			if(t[x].tag<t[lt(x)].mx)t[lt(x)].tg(t[x].tag);
			if(t[x].tag<t[rt(x)].mx)t[rt(x)].tg(t[x].tag);
			t[x].set();
		}
	}
	void lmt(int val,int l,int r,int x=1){//使得区间不高过指定值 
		if(t[x].r<l or t[x].l>r or t[x].mx<=val)return;//超过范围或已经达到限度
		pushdown(x);

		if(t[x].mx2>=val){//如果第二最值还是大于 ,下面的要继续更新 ,因为最值不对 
			lmt(val,l,r,lt(x));
			lmt(val,l,r,rt(x));
			pushup(x);
		} 
		else{
			if(t[x].range(l,r)){
				t[x].tg(val);
				return;
			}
			int mid=mid(t[x].l,t[x].r);
			if(l<=mid)lmt(val,l,r,lt(x));
			if(r>mid )lmt(val,l,r,rt(x));
			pushup(x);
		}
	}
	int ask_max(int l,int r,int x=1){
		if(t[x].range(l,r)){
			return t[x].mx;
		}
		pushdown(x);
		int mid=mid(t[x].l,t[x].r);
		int res1=-1,res2=-1;
		if(l<=mid)res1=ask_max(l,r,lt(x));
		if(r>mid) res2=ask_max(l,r,rt(x));
		return max(res1,res2);
	}
	ll ask_sum(int l,int r,int x=1){
		if(t[x].range(l,r)){
			return t[x].v;
		}
		pushdown(x);
		int mid=mid(t[x].l,t[x].r);
		ll res=0;
		if(l<=mid)res=ask_sum(l,r,lt(x));
		if(r>mid)res+=ask_sum(l,r,rt(x));
		return res;
	}
	void test(int n){
		for(int i=1;i<=n;i++){
			cout<<ask_sum(i,i)<<endl;
		}
	}
}gt; 
int n,m;
void init(){
	n=readi(),m=readi();
	for(int i=1;i<=n;i++){
		//pt[i]=readi();
		scanf("%d",&pt[i]);
	}
	gt.build(1,n);
}
int main()
{
	int t=readi();
	while(t--){
		init();
		for(int i=1;i<=m;i++){
			int op=readi();
			int x=readi(),y=readi();
			switch(op){
				case 0:{
					int val=readi();
					gt.lmt(val,x,y);
					break;
				}
				case 1:{
					int res=gt.ask_max(x,y);
					printf("%d\n",res);
					break;
				}
				case 2:{
					ll res=gt.ask_sum(x,y);
					printf("%lld\n",res);
					break;
				}
			}
			//gt.test(n);
		}
	}
    return 0;
}
