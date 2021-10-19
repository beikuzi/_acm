#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn=1e6+7;
int c[maxn]={1,2,3,4,5};
//һ�������ζ�ά���飬��֤ÿ�д����ң�ÿ�д��ϵ��¶��ǵ���
//�����ҳ��Ǹ�ֵ����ô��Ҫ�޸Ķ�����������ʼ����ֹ�㣬Ȼ�������� 
void func(int n){
	cout<<lower_bound(c,c+n,3)-c<<endl;//>=
	cout<<upper_bound(c,c+n,3)-c;//>
}
int m,n,t;

bool cal1(int x,int mid) {
	//cout<<x<<' '<<mid<<endl;
	return x<=mid;
}
bool cal2(int x,int mid){
	//cout<<x<<' '<<mid<<endl;
	return x>mid;
}

//������һ��>= x��ֵ���Ӹ������� 
int find1(int x){
	int l=-10000,r=123456;
	while(l<r){
		int mid=l+(r-l+1>>1);//����ȡ ,��r���� 
		if(cal1(x,mid))r=mid-1;
		//���ֵ�����Ľ��������������ôr��������һ������ 
		else l=mid;
		//cout<<l<<' '<<mid<<' '<<r<<endl;
	}
	return r+1;
}
//������һ��<= x��ֵ ���ӵ������� 
int find2(int x){
	int l=-10000,r=123456;
	while(l<r){
		int mid=l+(r-l>>1);//����ȡ ,��l���� 
		if(cal2(x,mid))l=mid+1;
		//���ֵ����������㣬l�������Ͽ��� 
		else r=mid;
	}
	return l-1;
}
//��������������һ��>=x��ֵ
int cfind1(int x,int c[],int n){
	int l=-1,r=n;//�������鿪n����ô��Χ���� 0��n-1,��������1��λ��Χ������-1��n 
	while(l<r){
		int mid=l+(r-l+1>>1);
		if(cal1(x,c[mid]))r=mid-1;
		else l=mid;
	}
	if(r==n)return -233;
	return r+1;
}
int cfind2(int x,int c[],int n){
	int l=-1,r=n;
	while(l<r){
		int mid=l+(r-l>>1);
		if(cal2(x,c[mid]))l=mid+1;
		else r=mid;
	}
	if(l==-1)return -233;
	return l-1;
}
int main()
{
//	cout<<find1(100)<<endl;
//	cout<<find1(99)<<endl;
//	cout<<find2(100)<<endl;
//	cout<<find2(99)<<endl;
//	
//	cout<<cfind1(0,c,5);
//	cout<<cfind1(2,c,5);
//	cout<<cfind1(3,c,5);
//	cout<<cfind1(4,c,5);
//	cout<<cfind1(7,c,5);
//	cout<<cfind1(5,c,5);
//	cout<<cfind1(1,c,5);
	func(5);
}
