#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
//用struct和运算符重载做高精
//问题：怎么让计算每次只计算到x位就停下来（减法、除法不用
const int maxl=5050;
struct hp{//high-precision
	int c[maxl];
	hp(){
		memset(c,0,sizeof(c));
	} 
}; 
void hout(const hp &z){//高精度输出 
	if(!z.c[0]){
		printf("0");
	}
	else for(int i=z.c[0];i>=1;i--)printf("%d",z.c[i]);
}
ostream& operator<<(ostream &out,const hp&z){
	for(int i=z.c[0];i>0;i--){
		out<<z.c[i];
	}
	return out;
}
hp turn(int x){
	hp z;
	while(x){
		z.c[++z.c[0]]=x%10;
		x/=10;
	}return z;
}
hp empty(hp &z){
	memset(&z,0,sizeof(z));
}
hp read(string s){
	hp z;
	z.c[0]=s.length();
	for(int i=z.c[0];i>=1;i--){
		z.c[i]=s[z.c[0]-i]-'0';
	}
	return z;
}
bool cmp(const hp &x,const hp &y){
	for(int i=max(x.c[0],y.c[0]);i>=1;i--)//从最高位判定 
	{
		if(x.c[i]>y.c[i])return true;
		if(x.c[i]<y.c[i])return false;
	}
	return true;
}
hp max(const hp &x,const hp &y){
	if(cmp(x,y))return x;
	return y;
}
//---------------------------------------------------------- 
hp operator+(const hp& x,const hp& y){
	hp z;
	z.c[0]=max(x.c[0],y.c[0]);//1.决定基础长度
	for(int i=1;i<=z.c[0];i++){
		z.c[i]+=x.c[i]+y.c[i];//2.for有进位，两个相加
		z.c[i+1]+=z.c[i]/10;//3.进位 
		z.c[i]%=10;
	}if(z.c[z.c[0]+1])z.c[0]++;//4.最高一位处理 
	return z;
}
hp operator-(const hp&x,const hp&y){
	hp z;
	z.c[0]=max(x.c[0],y.c[0]);//1.基础长度 
	for(int i=1;i<=z.c[0];i++){
		z.c[i]+=x.c[i]-y.c[i];//2.for相减 
		if(z.c[i]<0){
			z.c[i]+=10;//3.借位 
			z.c[i+1]--;
		}
	}while(!z.c[z.c[0]])z.c[0]--;//4.最高一位处理
	return z; 
}
hp operator*(const hp&x,const hp&y){
	hp z;
	z.c[0]=x.c[0]+y.c[0];//1.基础长度 
	for(int i=1;i<=x.c[0];i++){
		for(int j=1;j<=y.c[0];j++){
			z.c[i+j-1]+=x.c[i]*y.c[j];//2.双重for制造算式 
		}
	}
	for(int i=1;i<z.c[0];i++){ 
			z.c[i+1]+=z.c[i]/10;
			z.c[i]%=10;//3.借位 
	}if(z.c[z.c[0]]==0)z.c[0]--;//4.范围是i+j-1,i+j 
	return z;
}
hp operator/(const hp&x,const hp&y){
	hp z,mod;
	int len=x.c[0];
	while(len){
		mod=turn(10)*mod+turn(x.c[len]); //2.每次都增加一位来运算 
		while(cmp(mod,y)){
			if(z.c[0]==0)z.c[0]=len;//1.从第一个可以除那一位一次性决定位数
			mod=mod-y;
			z.c[len]++;//3.逐次减到余数不能用为之 
		}
		len--;//4.下一位 
	}
	return z;
}
hp pow(const hp &x,const hp&y){
	if(y.c[0]==0)return turn(1);
	hp t=pow(x,y/turn(2));//优化一个/2的算法，同时求余的话把除法改一下 
	hp ans=t*t;
	//hout(t);cout<<endl;
	if(y.c[1]&1)ans=ans*x;
	return ans;
} 
hp k[50];
int main()
{
	int n=5;
	string s;
	for(int i=1;i<=n;i++){
		cin>>s;
		k[i]=read(s);
	}
	hp ans;
	for(int i=1;i<=n;i++){
		ans=ans+k[i];
	}
	cout<<ans;
	return 0;
}
