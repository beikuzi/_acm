#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn=1e6+7;
int c[maxn]={1,2,3,4,5};
//一个正方形二维数组，保证每行从左到右，每列从上到下都是递增
//二分找出那个值，那么需要修改二分搜索的起始点终止点，然后多次搜索 
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

//二分找一个>= x的值，从高往低找 
int find1(int x){
	int l=-10000,r=123456;
	while(l<r){
		int mid=l+(r-l+1>>1);//向上取 ,让r来变 
		if(cal1(x,mid))r=mid-1;
		//这个值产生的结果满足条件，那么r可以往下一个看看 
		else l=mid;
		//cout<<l<<' '<<mid<<' '<<r<<endl;
	}
	return r+1;
}
//二分找一个<= x的值 ，从低往高找 
int find2(int x){
	int l=-10000,r=123456;
	while(l<r){
		int mid=l+(r-l>>1);//向下取 ,让l来变 
		if(cal2(x,mid))l=mid+1;
		//这个值产生结果满足，l可以往上看看 
		else r=mid;
	}
	return l-1;
}
//二分在数组中找一个>=x的值
int cfind1(int x,int c[],int n){
	int l=-1,r=n;//假如数组开n，那么范围就是 0，n-1,左右增减1单位范围，就是-1和n 
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
