#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<vector>
#include<queue>
using namespace std;
#define int long long
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
	}return x*b;
}
int n,m,ta,tb,t;
int mod=55555555;
const int maxn=5000;
struct CB{
	int c[maxn][maxn];
	int calc(int n,int k){
		if(c[n][k])return c[n][k];
		if(n==k or k==0)return c[n][k]=1;
		return c[n][k]=(calc(n-1,k)+calc(n-1,k-1))%mod;
	}
}c;
int ans;

signed main()
{
    n=readi(),m=readi(),ta=readi(),tb=readi(),t=readi();
	ans=0;
	int p=min(n,ta),q=min(m,tb);
	for(int i=0;i<=p;i++){
		for(int j=0;j<=q;j++){
			if(t==i*m+j*n-2*i*j){
				if((ta-i)%2==0 and (tb-j)%2==0){
					int sum=c.calc(n,i)%mod*c.calc(m,j)%mod*c.calc(n-1+(ta-i)/2,n-1)%mod*c.calc(m-1+(tb-j)/2,m-1)%mod;
					ans+=sum;
					ans%=mod;
				}
			}
		}
	}
	cout<<ans<<endl;
    return 0;
}
