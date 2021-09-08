#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath> 
#include<bitset>
using namespace std;
typedef unsigned long long ull;
bool prime(ull x){
	if(x==1)return false;
	for(ull i=2;i*i<=x;i++){
		if(x%i==0){
			//cout<<i<<endl;
			return false;
		}
	}return true;
}
bool sp(int x){//sixprime，六步筛 
	if(x==1)return 0;
	if(x==2 or x==3)return 1;
	if(x%6!=5 and x%6!=1)return 0;
	int r=sqrt(x);
	for(int i=5;i<=r;i+=6)//因为满足合数的还有可能是(6a+1)*(6a+5) 
		if(x%i==0 or x%(i+2)==0)return 0;
	return 1;
}
//-------------------------------------------------------------
const int maxn=1e8+7;
bitset<maxn>p;//表示i是不是质数 
int pr[maxn];//存放第i个素数 
int n,k;
void ol(){//如果真的搜1e8，需要半秒时间预热 
	p[1]=false;
	p.set();
	for(int i=2;i<=n;i++){
		if(p[i])pr[++k]=i;//1.没晒到的质数
		for(int j=1;j<=k and i*pr[j]<=n;j++){//2.使用筛过的质数，检查范围 
			p[i*pr[j]]=false;//3.用最小质因素来筛 
			if(i%pr[j]==0)break;
			//4.说明i可以分解成一个已经存在的质数
			//那么某数*质数(之后)，就不如分解某数，变为 质数（现在）*一个数*质数（之后）
			//在（一个数*质数（之后））那里分解 
		} 
	}
}
int main()
{
	
	scanf("%d",&n);
    //ol();
//    for(int i=1;i<=k;i++){
//    	printf("%d\n",pr[i]);
//    }
	cout<<sp(n);
	//cout<<k<<' '<<pr[k];
	return 0;
}
