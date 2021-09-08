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
	ll val,tag;//ֵ�������� 
}ts[maxn<<2],ti[maxn<<2],ta[maxn<<2];//sum,min,max
//ts[x].l��������������䣬nl(x)��������������� 
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
	int mid=cmid(l,r);//1.�������� 
	build(nl(x),l,mid);
	build(nr(x),mid+1,r);
	pushup(x);//2.���� 
}
inline void pushdowm(int x){//��x����tag��־�·� 
	ll tag=ts[x].tag;//ע���ˣ����tag����ǰ�����Ķ�����������һ�ε�
	//ֻ��������ȫ������������Ż���tag�������·�
	//��������Ϊ��Ҫ��ȷ���ӽڵ㣬�Ż���tag�·� 
	int l=nl(x),r=nr(x);
	int cntl=ts[l].r-ts[l].l+1;
	int cntr=ts[r].r-ts[r].l+1;
	if(tag){
		ts[l].val+=tag*cntl;
		ts[r].val+=tag*cntr;
		ts[l].tag+=tag;//tag��־�·� 
		ts[r].tag+=tag;
		ts[x].tag=0;//tag��־��� 
	}
}
void update(int x,int al,int ar,ll val){//Ŀ��l��Ŀ��r��ֵ 
	
	if(al<=ts[x].l and ts[x].r<=ar){
		int cnt=ts[x].r-ts[x].l+1;
		ts[x].val+=val*cnt;//��Ϊȫ���ǣ��������������ô��ֵ 
		ts[x].tag+=val;//���û���·ŵ����� 
		return;
	}
	pushdowm(x);//�޷�ȫ���ǣ�����Ŀ�귶Χ����ô��tag �·ţ�Ȼ�����ӽڵ�ȥ����
	int mid=cmid(ts[x].l,ts[x].r);
	if(al<=mid)update(nl(x),al,ar,val);//��Ӧ�� �ӽ���Ƿ�Ӧ�ø��� 
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
    }build(1,1,n);//�õ�һ����������ڵ�
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
