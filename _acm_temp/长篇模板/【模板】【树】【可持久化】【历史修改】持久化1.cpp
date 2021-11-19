#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<vector>
#include<queue>
using namespace std;
//֧����ʷ�����޸ĺ� ��ʷ��ѯ 
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
int n,m;
const int maxn=1e6+7;
int root[maxn];//��ʷ�汾�ĸ��ڵ�
#define mid(x,y) (x+(y-x>>1))
int pt[maxn];//pt���߶����ĳ�ֵ
struct tree{
	int tot=0;//�߶����½ڵ�
	struct seg{
		int l,r,nl,nr;
		int v;
		void set(int x,int y){
			l=x,r=y;
		}
		bool range(int x,int y){
			return x<=l and r<=y;
		}
	}t[maxn*4+maxn*20];//ÿ���°汾���������logn ���½ڵ㣬log 1e6��(19,20)֮��
#define lt(x) t[x].nl
#define rt(x) t[x].nr
	int build(int l,int r){
		int x=++tot;
		t[x].set(l,r);
		if(l==r){
			t[x].v=pt[l];
			return x;
		}
		int mid=mid(l,r);
		lt(x)=build(l,mid);
		rt(x)=build(mid+1,r);
		t[x].v=t[lt(x)].v+t[rt(x)].v;
		return x;
	} 
	int clone(int x){
		t[++tot]=t[x];
		return tot;//�����ɽڵ㣬�������޸� 
	}
	int mdf(int k,int l,int r,int x=1){//�����޸� 
		x=clone(x);
		if(t[x].range(l,r)){
			t[x].v=k;
			return x;
		}
		int mid=mid(t[x].l,t[x].r);
		if(l<=mid)lt(x)=mdf(k,l,r,lt(x));
		if (r>mid)rt(x)=mdf(k,l,r,rt(x));
		return x;
	}
	int ask(int l,int r,int x=1){
		if(t[x].range(l,r)){
			return t[x].v;
		}
		int res=0;
		int mid=mid(t[x].l,t[x].r);
		if(l<=mid)res+=ask(l,r,lt(x));
		if(r>mid) res+=ask(l,r,rt(x));
		return res;
	}
}t; 
void init(){
	n=readi(),m=readi();
	for(int i=1;i<=n;i++){
		pt[i]=readi();
	}
	root[0]=t.build(1,n);
	
}
int main()
{
    init();
    int kk=0;
    for(int i=1;i<=m;i++){
		int rt=readi(),op=readi(),node=readi();
		switch(op){
			case 1:{
				root[++kk]=t.tot+1;
				t.mdf(readi(),node,node,root[rt]);
				break;
			}
			case 2:{
				root[++kk]=root[rt];
				printf("%d\n",t.ask(node,node,root[rt]));
				break;
			}
		}
	}
    return 0;
}
