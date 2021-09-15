#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
using namespace std;
//不用double的读入scanf("$%d.%d") 
int npow(int x,int y){
	if(y==0)return 1;
	int t=pow(x,y/2);
	int res=t*t;
	if(y&1)res*=x;
	return res;
}
inline bool isnum(char x){
	return '0'<=x && x<='9';
}
inline int readi(){
	int x=0;
	char ch=getchar();
	while(!isnum(ch))ch=getchar();
	while(isnum(x)){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x;
} 
inline double read()
{
	double x=0;
	char ch=getchar();
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	int cnt=0;
	if(ch=='.'){
		ch=getchar();
		while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();cnt++;}
	}
	
	return x/npow(10,cnt);
}
//注意：浮点转化成整数之前要加一个比精度小的数，因为转化有问题 
double cmp=1e-6;
int main()
{ 
	double n;n=read();
	if(n-floor(n)>cmp)cout<<"1";//不是整数 
	int k=(int)(n+cmp); 
	return 0;
}
