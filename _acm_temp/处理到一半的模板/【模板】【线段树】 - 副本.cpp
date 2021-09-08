#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=1e5+7;
typedef long long ll;
int c[maxn];
struct tree{
	int l,r;
	ll val,tag;//值和懒惰标记 
}ts[maxn<<2],ti[maxn<<2],ta[maxn<<2];//sum,min,max
//ts[x].l是这个结点的左区间，nl(x)是这个结点的左结点编号 
inline int nl(int x){
	return x<<1;
}
inline int nr(int x){
	return (x<<1)|1;
}
inline int cmid(int l,int r){
	return l+(r-l>>1);
}
void pushup(int x){
	ts[x].val=ts[nl(x)].val+ts[nr(x)].val;
} 
void test(int x){
	for(int i=1;i<=x;i++){
		cout<<ts[i].val<<' ';
	}cout<<endl;
}
void build(int x,int l,int r){
	ts[x].l=l,ts[x].r=r;
	if(l==r){
		ts[x].val=c[l];
		return;
	}
	int mid=cmid(l,r);//1.二分深入 
	build(nl(x),l,mid);
	build(nr(x),mid+1,r);
	pushup(x);//2.并归 
}
inline void pushdowm(int x){//将x结点的tag标志下放 
	ll tag=ts[x].tag;//注意了，这个tag是以前保留的东西，不是这一次的
	//只有区间完全满足的条件，才会让tag保留不下放
	//而现在因为需要正确的子节点，才会让tag下放 
	int l=nl(x),r=nr(x);
	int cntl=ts[l].r-ts[l].l+1;
	int cntr=ts[r].r-ts[r].l+1;
	if(tag){
		ts[l].val+=tag*cntl;
		ts[r].val+=tag*cntr;
		ts[l].tag+=tag;//tag标志下放 
		ts[r].tag+=tag;
		ts[x].tag=0;//tag标志清空 
	}
}
void update(int x,int al,int ar,ll val){//目标l，目标r，值 
	
	if(al<=ts[x].l and ts[x].r<=ar){
		int cnt=ts[x].r-ts[x].l+1;
		ts[x].val+=val*cnt;//因为全覆盖，整个结点增加这么多值 
		ts[x].tag+=val;//标记没有下放的数量 
		return;
	}
	pushdowm(x);//无法全覆盖，不在目标范围，那么将tag 下放，然后让子节点去更新
	int mid=cmid(ts[x].l,ts[x].r);
	if(al<=mid)update(nl(x),al,ar,val);//对应的 子结点是否应该更新 
	if(ar>mid)update(nr(x),al,ar,val);
	pushup(x);
}
ll ask(int x,int al,int ar){
	if(al<=ts[x].l and ts[x].r<=ar)return ts[x].val;
	
	pushdowm(x);
	int mid=cmid(ts[x].l,ts[x].r);
	//cout<<mid<<endl;
	ll ans=0;
	
	if(al<=mid)ans+=ask(nl(x),al,ar);
	if(ar>mid)ans+=ask(nr(x),al,ar);
	return ans;
}
int main()
{
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
    	scanf("%d",&c[i]);
    }build(1,1,n);//用第一个编号做根节点
	for(int i=1;i<=m;i++){
		int t,l,r,val;
		scanf("%d",&t);
		if(t==1){
			scanf("%d%d%d",&l,&r,&val);
			update(1,l,r,val);
		}
		else{
			scanf("%d%d",&l,&r);
			printf("%lld\n",ask(1,l,r));
		}
	} return 0;
}
