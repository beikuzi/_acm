#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<vector>
#include<queue>
using namespace std;
//写一种结构体，读入一个数值后，记录他所有的数值和对应位数
//倒着压入结构体中，记录他的总长度和值倍数，0的时候表示整个数都在小数点后面,x表示x个数在小数点前面 
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
	}
	return x*b;
}
struct scino{
	string dec;//小数部分
	int pt;//指数部分 
	scino(string s){
		int len=s.length();
		int x=-1,y=len-1,z=s.find('.');//左边取掉前导，右边去掉后导，小数点位置 
		for(int i=0;i<len;i++){
			if(s[i]!='0' and s[i]!='.'){
				x=i;break;
			}
		}
		for(int i=len-1;i>=0;i--){
			if(s[i]!='0' and s[i]!='.'){
				y=i;break;
			}
		}
		pt=0; 
		if(x==-1)dec="0";//刚好是0 
		else if(z-x==1)while(x<=y)dec=dec+s[x++];//刚好就是一个科学小数
		else{ 
			dec=s[x];//小数点前面至少有一位 
			if(z-x>1 or z==-1){//小数点前面有东西，或者没有小数点 
				pt=((z==-1)?len:z)-1-x;//得到指数部分
				if(pt==0)return;
			}
			else pt=z-x;//小数点左右都是前导0，被吃掉了 
			if(x!=y)dec=dec+'.'; //这部分之前是处理小数点前面的东西 
			for(int i=x+1;i<=y;i++){
				if(s[i]=='.')continue;
				dec=dec+s[i];//补充后面的整数 
			}
		}
	}
	void deal(int x){//把小数位改成指定位数（包括小数点 
		int len=dec.length();
		if(len>=x){
			dec=dec.substr(0,x);
		}
		else{
			if(len==1){
				len=2;
				dec=dec+'.';
			}
			while(len++<x){
				dec=dec+'0';
			}
		}
	}
}; 
int n;
void solve(){
	n=readi();
	string s;
	cin>>s;
	scino x(s);
	cin>>s;
	scino y(s);
	if(x.dec!="0")x.pt++;
	if(y.dec!="0")y.pt++;
	x.deal(n+1);
	y.deal(n+1);
	
	if(x.dec==y.dec){
		printf("YES 0.");
		string temp=x.dec;
		int len=temp.length();
		for(int i=0;i<len;i++){
			if(temp[i]=='.')continue;
			printf("%c",temp[i]);
		}
		printf("*10^%d",x.pt);
	}
	else{
		printf("NO 0.");
		string temp=x.dec;
		int len=temp.length();
		for(int i=0;i<len;i++){
			if(temp[i]=='.')continue;
			printf("%c",temp[i]);
		}
		printf("*10^%d 0.",x.pt);
		temp=y.dec;
		len=temp.length();
		for(int i=0;i<len;i++){
			if(temp[i]=='.')continue;
			printf("%c",temp[i]);
		}
		printf("*10^%d",y.pt);
	}
}
int main()
{
	solve();
    return 0;
}
