#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
using namespace std;
//����double�Ķ���scanf("$%d.%d") 
int npow(int x,int y){
	if(y==0)return 1;
	int t=pow(x,y/2);
	int res=t*t;
	if(y&1)res*=x;
	return res;
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
//ע�⣺����ת��������֮ǰҪ��һ���Ⱦ���С��������Ϊת�������� 
double cmp=1e-6;
int main()
{ 
	double n;n=read();
	if(n-floor(n)>cmp)cout<<"1";//�������� 
	int k=(int)(n+cmp); 
	return 0;
}
