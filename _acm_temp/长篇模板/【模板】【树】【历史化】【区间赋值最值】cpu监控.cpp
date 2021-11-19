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
const int maxn=1e6+7;
#define inf 0x7fffffff
int pt[maxn];
struct tree{
	struct node{
		int l,r;
		int mx,hmx;//��ֵ����ʷ��ֵ 
		int a,ha;//�ӷ���Ǻͣ���ʷ�ӷ�ǰ׺�ͣ���ֵ���(Ҳ���������������˵����������һ�ε�ֵ 
		int cov,hcov;//���Ǻ���ʷ��󸲸� 
		bool tag;//�Ƿ���ڸ��Ǳ�ǣ����ڸ��ǿ��Դ��ڸ��������Զ���һ������Ƿ���ڸ��� 
		void set(int x,int y){
			l=x,r=y;
			a=ha=0;
			tag=cov=hcov=0;
		}
		void set(){//������ 
			a=ha=0;
			tag=cov=hcov=0;
		}
		bool range(int x,int y){
			return x<=l and r<=y;
		}
		void cover(int k,int hk){//������һ����㵱ǰ����ֵ����ʷ����ֵ,��Ϊ�Ǹ��������޸ģ�Ҫ�·�
			//Ҫ������ʷ���ǣ����ǣ���ʷ��ֵ����ֵ
			cov=mx=k;
			if(tag)hcov=max(hcov,hk);
			else hcov=hk,tag=1;
			hmx=max(hmx,hk);
		}
		void add(int k,int hk){//������ʷ��ֵ����ʷ�ӷ�����ǰ��ֵ�ͼӷ� 
			ha=max(ha,hk+a);//��ʷ�ӷ���ǣ����ڵ�ļӷ���Ǻ��ӽڵ�ļӷ���ǣ�ǰ׺�� 
			hmx=max(hmx,hk+mx);  
			a+=k;mx+=k;
		}
		void change(int k,int hk){//������ڸ��Ǳ�ǣ���ô�ӷ�+����=���Ǽӷ� 
			if(tag)cover(k+cov,hk+cov);//���� 
			else add(k,hk);//ֱ�Ӽ� 
		}
	}t[maxn<<2];
#define lt(x) (x<<1)
#define rt(x) ((x<<1)|1)
#define mid(x,y) (x+(y-x>>1))
	void pushup(int x){
		t[x].mx=max(t[lt(x)].mx,t[rt(x)].mx);
		t[x].hmx=max(t[lt(x)].hmx,t[rt(x)].hmx);
	}
	void build(int l,int r,int x=1){
		t[x].set(l,r);
		t[x].mx=t[x].hmx=-inf;
		if(l==r){
			t[x].mx=t[x].hmx=pt[l];
			return;
		}
		int mid=mid(l,r);
		build(l,mid,lt(x));
		build(mid+1,r,rt(x));
		pushup(x);
	}
	void pushdown(int x){
		//�ȼӷ����·ţ�Ȼ���Ǹ��ǵĸ����·� 
		t[lt(x)].change(t[x].a,t[x].ha);
		t[rt(x)].change(t[x].a,t[x].ha);
		if(t[x].tag){//������ڸ��Ǳ�� 
			t[lt(x)].cover(t[x].cov,t[x].hcov);
			t[rt(x)].cover(t[x].cov,t[x].hcov);
		}
		t[x].set();
	}
	void mdf(int l,int r,int k,int x=1){
		if(t[x].range(l,r)){
			t[x].cover(k,k);
			return;
		}
		int mid=mid(t[x].l,t[x].r);
		pushdown(x);
		if(l<=mid)mdf(l,r,k,lt(x));
		if (r>mid)mdf(l,r,k,rt(x));
		pushup(x);
	}
	void add(int l,int r,int k,int x=1){
		if(t[x].range(l,r)){
			t[x].change(k,k);
			return;
		}
		int mid=mid(t[x].l,t[x].r);
		pushdown(x);
		if(l<=mid)add(l,r,k,lt(x));
		if(r>mid) add(l,r,k,rt(x));
		pushup(x);
	}
	int ask_max(int l,int r,int x=1){
		if(t[x].range(l,r)){
			return t[x].mx;
		}
		int mid=mid(t[x].l,t[x].r);
		pushdown(x);
		int res1=-inf,res2=-inf;
		if(l<=mid)res1=ask_max(l,r,lt(x));
		if(r>mid) res2=ask_max(l,r,rt(x));
		return max(res1,res2);
	}
	int ask_hmax(int l,int r,int x=1){
		if(t[x].range(l,r)){
			return t[x].hmx;
		}
		int mid=mid(t[x].l,t[x].r);
		pushdown(x);
		int res1=-inf,res2=-inf;
		if(l<=mid)res1=ask_hmax(l,r,lt(x));
		if(r>mid) res2=ask_hmax(l,r,rt(x));
		return max(res1,res2);
	}
	void test(int n){
		cout<<n<<endl;
		for(int i=1;i<=n;i++){
			cout<<ask_max(i,i)<<endl;
		}
	}
}ht; 
int n,m;
void init(){
	n=readi();
	for(int i=1;i<=n;i++){
		pt[i]=readi();
	}
	ht.build(1,n);
}
int main()
{
    init();
    m=readi();
    for(int i=1;i<=m;i++){
    	char op=getchar();
    	int x=readi(),y=readi();
    	switch(op){
    		case 'Q':{
    			int res=ht.ask_max(x,y);
    			printf("%d\n",res);
    			break;
    		}
    		case 'A':{
    			int res=ht.ask_hmax(x,y);
    			printf("%d\n",res);
    			break;
    		}
    		case 'P':{
    			int k=readi();
    			ht.add(x,y,k);
    			break;
    		}
    		case 'C':{
    			int k=readi();
    			ht.mdf(x,y,k);
    			break;
    		}
    	}
    }
    return 0;
}
