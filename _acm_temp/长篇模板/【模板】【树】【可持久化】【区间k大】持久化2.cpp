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
		int cnt;//统计的是，离散化去重数组，那个节点l，r对应排名的范围， 那个排名的个数 
		//相当于离散化后，线段树做了前缀和 ，统计前i个值对应的排名情况 
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
		//t[x].v=t[lt(x)].v+t[rt(x)].v;初值都是0，不需要上传 
		return x;
	}
	int clone(int x){
		t[++tot]=t[x];
		return tot;
	}
	int mdf(int k,int x=0){// k表示的是要插入的位置，是离散后的排序位置 
		x=clone(x);
		t[x].cnt++;//此时这个结点+1个新数组值 
		
		if(t[x].l==t[x].r)return x;
		int mid=mid(t[x].l,t[x].r);
		if(k<=mid)lt(x)=mdf(k,lt(x));//如果排名在中值左边就往左走 
		else rt(x)=mdf(k,rt(x));
		return x;
	}
//	int ask(int l,int r,int x=0){//查询以x为结点，l到r到底有多少个以输入值 
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
	int ask(int k,int x,int y){//x，y是对应结点，k是询问区间第几大的（区间k个小个数 
		
		int ans=0;
		if(t[x].l==t[x].r)return t[x].l;
		//如果左子树有那么多排名个数，就往左走继续缩减，否则往右走
		int sum=t[lt(y)].cnt-t[lt(x)].cnt;//二者左结点数量差，注意顺序（符号 
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
/*排错
1.读入，建全0树的build 
2.离散化，检查离散数组
3.插入mdf，检查排位rnk和插入的正确性,
4.检查root,temp,nl，l的范围，结点的cnt和ask 
	root	for(int i=1;i<=n;i++)cout<<root[i]<<endl;
	结点数量	for(int i=1;i<=5;i++)cout<<t.ask(i,i,root[1])<<endl; 
	mdf检查cnt		 cout<<x<<' '<<t[x].cnt<<endl;
*/
int main()
{
    init();
    //离散化 
    sort(p+1,p+1+n);
    int cnt=unique(p+1,p+1+n)-(p+1);
    
	//用离散化数组个数建空线段树 
    root[0]=t.build(1,cnt);
    
	//每个原值就是一个新版本 
    for(int i=1;i<=n;i++){
    	//得到对应值的排名，并把对应点插入
		int rnk=lower_bound(p+1,p+cnt+1,pt[i])-p;
		root[i]=t.mdf(rnk,root[i-1]);//插入位置，必须用上一个版本来更新 
    }
    
    for(int i=1;i<=m;i++){
    	int l=readi(),r=readi(),k=readi();
    	int temp=t.ask(k,root[l-1],root[r]);//以整棵树为范围，二分找到对应k个值时，对应的排序 
    	printf("%d\n",p[temp]);
    }
    return 0;
}
