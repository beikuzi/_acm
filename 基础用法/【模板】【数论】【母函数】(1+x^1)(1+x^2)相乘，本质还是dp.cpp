#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<map>
using namespace std;
typedef long long ll;
const int maxn=233;
int c1[maxn],c2[maxn];
//假如你有123……n分的邮票无限个，贴出m分的方案数
//即求( (1+x)(1+x^2)(1+x^3)……(1+x^n)后，x^m的系数是多少 
void cal(int n,int m){
	for(int i=0;i<=n;i++)c1[i]=1;//哪些邮票本来就有，所以系数就是1 
	for(int i=2;i<=n;i++){//你要相乘n-1次，从用第二种邮票开始，所以2~n 
		for(int j=0;j<=m;j++){//对于你想求的项，从0到m都计算一遍 
			for(int k=0;k+j<=m;k+=i){//就像无限背包一样，你这里用0*i,1*i,2*i个这样的邮票 
				c2[k+j]+=c1[j];//系数增加 
			}
		}
		for(int j=0;j<=n;j++){
			c1[j]=c2[j];
		}memset(c2,0,sizeof(c2));
	}
	printf("%d\n",c1[m]);//也包括了1的情况了 
} 
int main()
{
    int x;
	while(cin>>x){
		cal(x,x);
	} 
	return 0;
}


/*
1表示不取，即x^0 
下面有1-4重量的砝码 
(1+x)(1+x^2)(1+x^3)(1+x^4)

=(1+x+x^2+x^4)(1+x^3+^4+x^7)

=1 + x + x^2 + 2x^3 + 2x^4 + 2x^5 + 2x^6 + 2*x^7 + x^8 + x^9 + x^10
可以称出10种方案，并且系数是对应的方案数 

整数拆分：整数分解成若干整数
拆分的方案总数叫：<拆分>数
 
*/ 
