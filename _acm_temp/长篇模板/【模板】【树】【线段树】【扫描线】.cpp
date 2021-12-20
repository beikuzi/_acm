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
typedef long long ll;
int n;
const int maxn=1e5+7;
#define lt(x) (x<<1)
#define rt(x) ((x<<1)|1)
#define mid(x,y) (x+(y-x>>1))
ll ept[maxn];
struct Line{
	ll l,r,y;
	int dic;//+1表示下面，-1表示上面 
	bool operator <(const Line &l) const{
		return y<l.y;
	}
}line[maxn];
struct tree{
	struct node{
		ll v;//就是一行拥有的线段的长度 
		int l,r,cnt;
		void set(int x,int y){
			l=x,r=y,cnt=0;
		}
		bool range(ll x,ll y){//由于线段排序后不知道对应的点的离散排序，只能这样 
			return x<=ept[l] and ept[r+1]<=y;//用的是端，所以这里的是段r点r+1 
		}
		bool outrange(ll x,ll y){
			return y<=ept[l] or ept[r+1]<=x;
		} 
	}t[maxn<<4];//开了扫描线要多一倍，然后add的判定条件额外往下走了一次，再多一倍 
	void pushup(int x){
		if(t[x].cnt) t[x].v=ept[t[x].r+1]-ept[t[x].l];
		else t[x].v=t[lt(x)].v+t[rt(x)].v;
	}
	void build(int l,int r,int x=1){
		t[x].set(l,r);
		if(l==r){
			t[x].v=0;
			return;
		}
		int mid=mid(l,r);
		build(l,mid,lt(x));
		build(mid+1,r,rt(x));
		pushup(x);
	}
	void add(ll l,ll r,int k,int x=1){
		if(t[x].outrange(l,r))return ;
		if(t[x].range(l,r)){
			t[x].cnt+=k; 
			pushup(x);
			return;
		}
		add(l,r,k,lt(x));
		add(l,r,k,rt(x));
		pushup(x);	
	}
}t; 

void init(){
	n=readi();
	for(int i=1;i<=n;i++){
		ll x1=readi(),y1=readi(),x2=readi(),y2=readi();
		line[i]={x1,x2,y1,1};
		line[i+n]={x1,x2,y2,-1};//压入上下线段
		ept[i]=x1,ept[i+n]=x2;//压入左右端点 
	}
}
int main()
{
    init();
    sort(line+1,line+1+2*n);//因为从上或者从下开始扫，相当于是一种前缀 
    sort(ept+1,ept+1+2*n);
    int tot=unique(ept+1,ept+2*n+1)-(ept+1);//离散化去重成tot 
    t.build(1,tot-1);//线段树维护段tot-1个 
    ll ans=0;
	for(int i=1;i<2*n;i++){
		t.add(line[i].l,line[i].r,line[i].dic);//每个线段都加入到线段树范围内 
		ans+=t.t[1].v*(line[i+1].y-line[i].y);//直到下一次行线段变化之前，都是一样的，可以乘 
	}
	cout<<ans;
    return 0;
}
/*
2
10 10 20 20
15 15 25 25.5
*/
