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
//���ϴ��ݡ�������� ������ǰ׺�ͣ� 
//add����2^i��¼��1~2^i����ֵ�ĺͣ�2^i~2^(i+1)�����ֵ���Լ�¼���������Ƹ�2^(i+1) 
//ask��11111=11110+11100+11000+10000=30��11101��11110��+28��11001��11010��11100��������11011����+24��17~24��+16��1~16 
//1.(ԭ��)�����޸ģ���ѯ����ǰ׺��
//2.(ԭ��)������ӣ���ѯ������ֵ ����������޸ģ�ֻ���޸�ֵ��ԭ��ֵ�� (С�� 
//3.(���)������������ѯ����ֵ 
//4.(���)������������ѯ����ǰ׺�� 
//5.(����)�����������:ֻ�ܰ��ն���˳��¼����ֵ�������ֵ����c����
					//tree����ʹ����>=v��tree[>=v]++ 
					//ֻ���ڴ˿�ͬʱ��֪��֮ǰ�������ж��ٸ�>���ֵ 
//6.��ά-�����޸ģ���ѯ����-����ǰ׺�� 
//7.��ά-������ӣ���ѯ������ֵ����������޸ģ�ֻ���޸�ֵ��ԭ��ֵ��(С�� 
//8.��ά-�����޸ģ���ѯ����ֵ 
//9.��ά-�����޸ģ���ѯ����-����ǰ׺�� 

void add1(int x,int val){
	for(int i=x;i<=n;i+=lowbit(i)){
		tree[i]+=val;
	}		
}
int ask1(int x){//��ѯ��1-x����ֵ ����add������� 
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

//	//����������뵽�ĸ���,���ֲ�ѯʱ���ܸ��� 
//	void add2(int x,int val){
//		c[x]=val;
//		for(int i=x;i<=n;i+=lowbit(i)){//��2^i��¼�������нڵ�ֵ����ֵ(val-2^i��valֵ���� 
//			tree[i]=max(tree[i],val);
//		}     
//	}

//	//Ϊ�˲�ÿ��ʹ���µ�case������ʼ��һ�����飬�������������Ӻͣ���ѯʱ��Ȼ���ܸ��� 
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

//	//���������ϴ��ݣ������ڹ������������ͺ� ,�����ֲ���ֱ��2^i 
//	int c[maxn];
//	//�����Ҫ��ƣ�һ���ѵ�2^i����ֱ����ԭֵ���Ƚ� 
//	int ask2(int l,int r){
//		int res=c[r];
//		while(l!=r){
//			for(--r;r-lowbit(r)>=l;r-=lowbit(r)){//��Ϊ���ϴ������ԣ�����2^i������ֵ������r��һ������ֵ��
//				//���Ҫ��Ŀ��������������� 
//				//������Ϊ��lowbit�����磬����ǰ������ͨ��--r�����¸��� 
//				res=max(res,tree[r]);
//			}
//			res=max(res,c[r]);//��Ϊ����ֻ��--r�仯��������˳�for������Ҫ���� 
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
		tree[i]+=val;//�����val�ǲ��ֵ 
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
	int temp=0;//��ֶ��� 
	for(int i=1;i<=n;i++){
		scanf("%d",&t);
		add3(i,t-temp);
		temp=t;
	}
	cout<<ask3(5);
}
//--------------------------------------------------------------------
//ʵ���Ͼ��ǶԲ������������ǰ׺��
//��һ��ǰ׺�ͣ���1-i��ǰ׺�ͣ�d(1)��p�Σ�d(2)��p-1�Ρ�����d(i) p-i+1�� 
//�ڶ���ǰ׺�ͣ���i=1��Ŀ��p
//		sum(j,1,p){sum(i,1,j)d[i]} 
//	=>	sum(j,1,p){d[j]*(p-j+1)}
//	=>	(p+1)*sum(j,1,p)d[j] - sum(j,1,p)d[j]*j
//һ����λ��������״���飬ʹ��ask��ѯ����ǰ׺�ͣ�������logn 
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
		res+=(x+1)*tree[i]-tree2[i];//��Ȼ��ѭ�ֲ����� 
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
int a[maxlen+1];//���ݷ�Χ�ĳ��� 
void add5(int x){//ʹ���б仯λ��ֵ+1��a[loc]��¼С����������ж��ٸ� 
	for(int i=x;i<=maxlen;i+=lowbit(i)){//����2����ô���ݵ�4��8��16���� 
		a[x]++;
	}
}
int ask5(int x){
	int res=0;
	for(int i=x;i;i-=lowbit(i)){//�������С��x�����ж��ٸ� 
		res+=a[i];
	}
}
void test5(){
	int ans=0; 
	for(int i=1;i<=n;i++){
		scanf("%d",&t);
		add5(t+1);
		ans+=i-ask5(t+1);//�����=¼������-С�ڵ�������ĸ���=��������ĸ��� 
		//С��t+1	��С�ڵ�������t 
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
	cout<<ask6(5,5)-ask6(4,5);//��ѯ��5�д�1-5��ǰ׺�� 
}
//----------------------------------------------------------------------
//sum[i][j]=(a[i][j])+(sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1])//�������ռ�죬�ݳ�ԭ�� 
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
