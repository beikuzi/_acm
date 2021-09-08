#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int lowbit(int x){
	return x&-x;
}
int n,m;
const int maxn=1e5,maxm=1e3;
int tree1[maxn],tree2[maxn],tree3[maxn],tree4[maxn];
//1.������������ѯ����ǰ׺
//2.������������ѯ����ֵ
//3.������������ѯ����ǰ׺
//4.������ֵ 
int c[maxn];

void read(int x){//����ʽ����,�������ڳ�ʼ���� 
	int val=c[x],dv=c[x]-c[x-1];
	tree1[x]=val;
	tree2[x]=dv;
	tree3[x]=dv*x;
	tree4[x]=val;
	for(int i=1;i<lowbit(x);i<<=1){
		tree1[x]+=tree1[x-i];
		tree2[x]+=tree2[x-i];
		tree3[x]+=tree3[x-i];
		tree4[x]=max(tree4[x-i],tree4[x]);
	}
}
void add1(int x,int val){//��ͨ�����޸� 
	for(int i=x;i<=n;i+=lowbit(i)){
		tree1[i]+=val;
	}
}
void add23(int l,int r,int dv){//�������� 
	//int dv=c[x]-c[x-1];//ֵ����� 
	for(int i=l;i<=n;i+=lowbit(i)){
		tree2[i]+=dv;
		tree3[i]+=dv*l;
	} 
	for(int i=r+1;i<=n;i+=lowbit(i)){
		tree2[i]-=dv;
		tree3[i]-=dv*(r+1);
	}
}
void add4(int x,int val){//ר�������ֵ��ѯ���޸� 
	c[x]=val;
	for(int i=x;i<=n;i+=lowbit(i)){
		int temp=tree4[i];
		tree4[i]=c[i];
		for(int j=1;j<lowbit(i);j<<=1){
			tree4[i]=max(tree4[i],tree4[i-j]);
		}
		if(temp==tree4[i])return;//���û�и��£�֮��Ķ������� 
	}
}
int ask123(int x){
	int res1,res2,res3;
	for(int i=x;i;i-=lowbit(i)){
		res1+=tree1[i];
		res2+=tree2[i];
		res3+=(x+1)*tree2[i]-tree3[i];
	}
	return res1;
}
int ask4(int l,int r){// ��ֵ�����ѯ 
	int res4=c[r];
	while(l!=r){
		for(r--;r-lowbit(r)>=l;r-=lowbit(r)){
			res4=max(res4,tree4[r]);
		}res4=max(res4,c[r]);
	} return res4;
}
void test(){
	scanf("%d",&n);
    for(int i=1;i<=n;i++){
    	scanf("%d",&c[i]);
    	read(i);
    }
	//---------------------------
	int loc=1,loc2=2,val=100;
	add1(loc,val);//ע�⣬�ǵ�������һ���� 
	ask123(loc);//��ֵ1
	//-------------------------
	add23(loc,loc2,10);
	ask123(loc2);//��ֵ2
	//-------------------------
	add23(loc,loc2,10);
	ask123(loc2) -ask123(loc-1);//��ֵ3
	//--------------------------
	add4(loc,val);
	ask4(loc,loc2);
} 

//------------------------------------------------------------------------
int main()
{
    ;
}
