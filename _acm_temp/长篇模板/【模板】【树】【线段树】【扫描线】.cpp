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
	int dic;//+1��ʾ���棬-1��ʾ���� 
	bool operator <(const Line &l) const{
		return y<l.y;
	}
}line[maxn];
struct tree{
	struct node{
		ll v;//����һ��ӵ�е��߶εĳ��� 
		int l,r,cnt;
		void set(int x,int y){
			l=x,r=y,cnt=0;
		}
		bool range(ll x,ll y){//�����߶������֪����Ӧ�ĵ����ɢ����ֻ������ 
			return x<=ept[l] and ept[r+1]<=y;//�õ��Ƕˣ�����������Ƕ�r��r+1 
		}
		bool outrange(ll x,ll y){
			return y<=ept[l] or ept[r+1]<=x;
		} 
	}t[maxn<<4];//����ɨ����Ҫ��һ����Ȼ��add���ж�����������������һ�Σ��ٶ�һ�� 
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
		line[i+n]={x1,x2,y2,-1};//ѹ�������߶�
		ept[i]=x1,ept[i+n]=x2;//ѹ�����Ҷ˵� 
	}
}
int main()
{
    init();
    sort(line+1,line+1+2*n);//��Ϊ���ϻ��ߴ��¿�ʼɨ���൱����һ��ǰ׺ 
    sort(ept+1,ept+1+2*n);
    int tot=unique(ept+1,ept+2*n+1)-(ept+1);//��ɢ��ȥ�س�tot 
    t.build(1,tot-1);//�߶���ά����tot-1�� 
    ll ans=0;
	for(int i=1;i<2*n;i++){
		t.add(line[i].l,line[i].r,line[i].dic);//ÿ���߶ζ����뵽�߶�����Χ�� 
		ans+=t.t[1].v*(line[i+1].y-line[i].y);//ֱ����һ�����߶α仯֮ǰ������һ���ģ����Գ� 
	}
	cout<<ans;
    return 0;
}
/*
2
10 10 20 20
15 15 25 25.5
*/
