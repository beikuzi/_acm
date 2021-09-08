#include<iostream>
#include<cstdio> 
using namespace std;
const int maxn=1e6+7;
int n,k;
int c[maxn],d[maxn];
int gcd(int x,int y){
	return (!y)?x:gcd(y,x%y);
}
//因为A=B[1]*X[1]+B[2]*X[2] ,提取全体公因数，如果1，也就是存在互质，那么肯定b之间能相互达到1
//否则最大公因数就是可以削减的最小值，只要A的差值一但余他有余数，就会削不完 
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&c[i]);
    for(int j=1;j<=k;j++)scanf("%d",&d[j]);
    int p=d[1]; 
    for(int i=2;i<=k;i++)p=gcd(p,d[i]);
    for(int i=2;i<=n;i++){
    	if((c[i]-c[i-1])%p){
    		cout<<"No";
    		return 0;
    	}
    }
    cout<<"Yes";
    return 0;
}
