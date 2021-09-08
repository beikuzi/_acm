#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring> 
#include<queue>
#include<map>
#include<vector>
#include<cstdlib>
#include<cmath>
using namespace std;
const int maxn=101;
typedef unsigned long long ull;
typedef long long ll;
ll c[maxn];
//ϰ��������˵��ģ���˵���棩��n��m�� 
//���ù�ʽC(n,r)=C(n-1,r-1)+C(n-1,r)��������⣺
ll cal1(int n,int m){//���飬n2 
	for(int i=0;i<=m;i++)c[i]=1;
	for(int i=1;i<=n-m;i++){
		for(int j=1;j<=m;j++){
			c[j]+=c[j-1];
		}
	}
	return c[m];
}
ull pow(ull x,ull y,ull c){
	if(y==0)return 1;
	ull t=pow(x,y/2,c);
	ull ans=(t%c)*(t%c);
	if(y&1)ans*=(x%c);
	return ans%c;
}
//------------------------------------------------------------

// (2^p + 1)^n = C(n,0) + C(n,1)2^p + C(n,2)(2^p)^2 + ... + C(n,n)(2^p)^n 
void cal2(ull n,ull m){//logn,������� ��������ull��n����<=10�������б�Ҫ�߾��ȸ��� 
	ull x=(1<<n)+1;
	ull y=(1<<n)-1;
	ull res=pow(x,n,1e19);
	for(int i=0;i<=(n^1)/2;i++,res>>=n){
		printf("c(%llu,%d)=%llu\n",n,i,res&y) ;
	}
}
int main()
{
    cal2(10,1);
}
