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
int n,m;
const int maxn=2e5+7;
int pt[maxn],p[maxn];
int root[maxn];
#define mid(x,y) (x+(y-x>>1))
struct tree{
	int tot;
	struct seg{
		int l,r,nl,nr;
		int cnt;//ͳ�Ƶ��ǣ���ɢ��ȥ�����飬�Ǹ��ڵ�l��r��Ӧ�����ķ�Χ�� �Ǹ������ĸ��� 
		//�൱����ɢ�����߶�������ǰ׺�� ��ͳ��ǰi��ֵ��Ӧ��������� 
		void set(int x,int y){
			l=x,r=y;
		}
		bool range(int x,int y){
			return x<=l and r<=y;
		}
	}t[maxn*4+maxn*20];
#define lt(x) t[x].nl
#define rt(x) t[x].nr
	int build(int l,int r){
		int x=++tot;
		t[x].set(l,r);
		if(l==r){
			//t[x].v=pt[l];
			t[x].cnt=0;
			return x;
		}
		int mid=mid(l,r);
		lt(x)=build(l,mid);
		rt(x)=build(mid+1,r);
		//t[x].v=t[lt(x)].v+t[rt(x)].v;��ֵ����0������Ҫ�ϴ� 
		return x;
	}
	int clone(int x){
		t[++tot]=t[x];
		return tot;
	}
	int mdf(int k,int x=0){// k��ʾ����Ҫ�����λ�ã�����ɢ�������λ�� 
		x=clone(x);
		t[x].cnt++;//��ʱ������+1��������ֵ 
		
		if(t[x].l==t[x].r)return x;
		int mid=mid(t[x].l,t[x].r);
		if(k<=mid)lt(x)=mdf(k,lt(x));//�����������ֵ��߾������� 
		else rt(x)=mdf(k,rt(x));
		return x;
	}
//	int ask(int l,int r,int x=0){//��ѯ��xΪ��㣬l��r�����ж��ٸ�������ֵ 
//		if(t[x].range(l,r)){
//			return t[x].cnt;
//		}
//		int ans=0;
//		int mid=mid(t[x].l,t[x].r);
//		
//		if(l<=mid)ans+=ask(l,r,lt(x));
//		if(r>mid) ans+=ask(l,r,rt(x));
//		return ans;
//	}
	int ask(int k,int x,int y){//x��y�Ƕ�Ӧ��㣬k��ѯ������ڼ���ģ�����k��С���� 
		
		int ans=0;
		if(t[x].l==t[x].r)return t[x].l;
		//�������������ô�������������������߼�������������������
		int sum=t[lt(y)].cnt-t[lt(x)].cnt;//�������������ע��˳�򣨷��� 
		if(sum>=k)ans=ask(k,lt(x),lt(y));
		else ans=ask(k-sum,rt(x),rt(y));
		return ans;
	}
}t;
void init(){
	n=readi(),m=readi();
	for(int i=1;i<=n;i++){
		p[i]=pt[i]=readi();
	}
}
/*�Ŵ�
1.���룬��ȫ0����build 
2.��ɢ���������ɢ����
3.����mdf�������λrnk�Ͳ������ȷ��,
4.���root,temp,nl��l�ķ�Χ������cnt��ask 
	root	for(int i=1;i<=n;i++)cout<<root[i]<<endl;
	�������	for(int i=1;i<=5;i++)cout<<t.ask(i,i,root[1])<<endl; 
	mdf���cnt		 cout<<x<<' '<<t[x].cnt<<endl;
*/
int main()
{
    init();
    //��ɢ�� 
    sort(p+1,p+1+n);
    int cnt=unique(p+1,p+1+n)-(p+1);
    
	//����ɢ��������������߶��� 
    root[0]=t.build(1,cnt);
    
	//ÿ��ԭֵ����һ���°汾 
    for(int i=1;i<=n;i++){
    	//�õ���Ӧֵ�����������Ѷ�Ӧ�����
		int rnk=lower_bound(p+1,p+cnt+1,pt[i])-p;
		root[i]=t.mdf(rnk,root[i-1]);//����λ�ã���������һ���汾������ 
    }
    
    for(int i=1;i<=m;i++){
    	int l=readi(),r=readi(),k=readi();
    	int temp=t.ask(k,root[l-1],root[r]);//��������Ϊ��Χ�������ҵ���Ӧk��ֵʱ����Ӧ������ 
    	printf("%d\n",p[temp]);
    }
    return 0;
}
