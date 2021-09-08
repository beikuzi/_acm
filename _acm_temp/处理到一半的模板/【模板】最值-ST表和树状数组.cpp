#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath> 
using namespace std;
const int maxn=1e3+7;
int tree[maxn];
int t,n;
int lowbit(int x){
	return x&-x;
}
//向上传递、区间归纳 ，变相前缀和？ 
//add：让2^i记录从1~2^i所有值的和，2^i~2^(i+1)里面的值各自记录，再往上推给2^(i+1) 
//ask：11111=11110+11100+11000+10000=30（11101、11110）+28（11001、11010、11100（包含了11011））+24（17~24）+16（1~16 
//1.(原数)单点修改，查询单点前缀和
//2.(原数)单点添加，查询区间最值 （如果单点修改，只能修改值比原来值大 (小） 
//3.(差分)区间增减，查询单点值 
//4.(差分)区间增减，查询单点前缀和 
//5.(个数)求逆序对数量:只能按照读入顺序录入新值，将这个值插入c数组
					//tree数组使所有>=v的tree[>=v]++ 
					//只能在此刻同时得知，之前的数组有多少个>这个值 
//6.二维-单点修改，查询单点-矩阵前缀和 
//7.二维-单点添加，查询矩阵最值（如果单点修改，只能修改值比原来值大(小） 
//8.二维-区间修改，查询单点值 
//9.二维-区间修改，查询单点-矩阵前缀和 

void add1(int x,int val){
	for(int i=x;i<=n;i+=lowbit(i)){
		tree[i]+=val;
	}		
}
int ask1(int x){//查询从1-x的最值 ，是add反向操作 
	int res=0;
	for(int i=x;i;i-=lowbit(i)){
		res+=tree[i];
	} return res;
}
void test1(){
	for(int i=1;i<=n;i++){
		scanf("%d",&t);
		add1(i,t);
	}
	cout<<ask1(5);
	int l=2,r=4;
	cout<<ask1(r)-ask1(l-1);
}
//------------------------------------------------------------------

//	//最初最容易想到的更新,这种查询时不能更新 
//	void add2(int x,int val){
//		c[x]=val;
//		for(int i=x;i<=n;i+=lowbit(i)){//让2^i记录下属所有节点值的最值(val-2^i的val值更新 
//			tree[i]=max(tree[i],val);
//		}     
//	}

//	//为了不每次使用新的case，都初始化一次数组，改良，反过来加和，查询时仍然不能更新 
//	void add2(int x,int val){
//		tree[x]=val;
//		for(int j=1;j<lowbit(x);j<<=1){
//			tree[x]=max(tree[x],tree[x-j]);
//		}
//	}

void add2(int x,int val){
	tree[x]=val;
	for(int i=x;i<=n;i+=lowbit(i)){
		tree[i]=val;
	}
}

//	//由于是往上传递，所以在归纳区间搜索就好 ,但是又不能直接2^i 
//	int c[maxn];
//	//因此需要设计，一旦搜到2^i，就直接用原值来比较 
//	int ask2(int l,int r){
//		int res=c[r];
//		while(l!=r){
//			for(--r;r-lowbit(r)>=l;r-=lowbit(r)){//因为向上传递特性，所以2^i必是最值，但是r不一定落最值上
//				//因此要在目标区间从上往下找 
//				//不能因为减lowbit减出界，出界前跳出，通过--r来重新更新 
//				res=max(res,tree[r]);
//			}
//			res=max(res,c[r]);//因为可能只有--r变化后就立刻退出for，所以要再判 
//		}return res;
//	} 

void test2(){
	for(int i=1;i<=n;i++){
		scanf("%d",&t);
		add2(i,c[i]);
	}
	int l=2,r=4;
	add2(3,100);
	cout<<ask2(l,r);
}
//----------------------------------------------------------------

void add3(int x,int val){
	for(int i=x;i<=n;i+=lowbit(i)){
		tree[i]+=val;//读入的val是差分值 
	}
}
void add3_range(int l,int r,int val){
	add3(l,val);
	add3(r+1,-val);
}
int ask3(int x){
	int res=0;
	for(int i=x;i;i-=lowbit(i)){
		res+=tree[i];
	}return res;
}
void test3(){
	int temp=0;//差分读入 
	for(int i=1;i<=n;i++){
		scanf("%d",&t);
		add3(i,t-temp);
		temp=t;
	}
	cout<<ask3(5);
}
//--------------------------------------------------------------------
//实际上就是对差分数组用两次前缀和
//第一次前缀和：从1-i的前缀和：d(1)用p次，d(2)用p-1次……，d(i) p-i+1次 
//第二次前缀和：从i=1到目标p
//		sum(j,1,p){sum(i,1,j)d[i]} 
//	=>	sum(j,1,p){d[j]*(p-j+1)}
//	=>	(p+1)*sum(j,1,p)d[j] - sum(j,1,p)d[j]*j
//一步到位，两个树状数组，使得ask查询的是前缀和，并且是logn 
int tree2[maxn];
void add4(int x,int val){
	for(int i=x;i<=n;i=lowbit(i)){
		tree[i]+=val,tree2[i]+=val*x; 
	}
} 
void add4_range(int l,int r,int val){
	add4(l,val);
	add4(r+1,-val);
}
int ask4(int x){
	int res=0;
	for(int i=x;i;i-=lowbit(x)){
		res+=(x+1)*tree[i]-tree2[i];//任然遵循分步叠加 
	}return res;
}
void test4(){
	int temp=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&t);
		add4(i,t-temp);
		temp=t;
	}
	cout<<ask4(5); 
} 
//--------------------------------------------------------------
const int maxlen=maxn;
int a[maxlen+1];//数据范围的长度 
void add5(int x){//使所有变化位置值+1，a[loc]记录小于自身的数有多少个 
	for(int i=x;i<=maxlen;i+=lowbit(i)){//假如2，那么传递到4、8、16…… 
		a[x]++;
	}
}
int ask5(int x){
	int res=0;
	for(int i=x;i;i-=lowbit(i)){//彻底算出小于x的数有多少个 
		res+=a[i];
	}
}
void test5(){
	int ans=0; 
	for(int i=1;i<=n;i++){
		scanf("%d",&t);
		add5(t+1);
		ans+=i-ask5(t+1);//逆序对=录入总数-小于等于自身的个数=大于自身的个数 
		//小于t+1	即小于等于自身t 
	} 
	cout<<ans;
} 
//------------------------------------------------------------------
int tree1[maxn][maxn];
void add6(int x,int y,int val){
	for(int i=x;i<=n;i+=lowbit(i)){
		for(int j=y;j<=n;j+=lowbit(j)){
			tree1[i][j]+=val;
		}
	}
}
int ask6(int x,int y){
	int res=0;
	for(int i=x;i;i-=lowbit(i)){
		for(int j=y;j;j-=lowbit(j)){
			res+=tree1[i][j];
		}
	}return res;
}

void test6(){
	int m=n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&t);
			add6(i,j,t);
		}
	}
	cout<<ask6(5,5)-ask6(4,5);//查询第5行从1-5的前缀和 
}
//----------------------------------------------------------------------
//sum[i][j]=(a[i][j])+(sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1])//想象面积占领，容斥原理 
void add8(int x,int y,int val){
	for(int i=x;i<=n;i+=lowbit(i)){
		for(int j=y;j<=n;j+=lowbit(j)){
			tree1[i][j]+=val;
		}
	}
}
void add8_range(int x1,int y1,int x2,int y2,int val){
	add8(x1,y1,val);
	add8(x1,y1+1,-val);
	add8(x1+1,y1,-val);
	add8(x1+1,y1+1,val);
} 
int ask8(int x,int y){
	int res=0;
	for(int i=x;i;i-=lowbit(i)){
		for(int j=y;j;j-=lowbit(j)){
			res+=tree1[i][j];
		}
	}return res;
}
void test8(){
	int m=n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&t);
			add6(i,j,t);
		}
	}
	add8_range(3,3,5,5,100);
	cout<<ask8(4,4);
}
//-----------------------------------------------------------------------------
int main()
{
	scanf("%d",&n);
}
