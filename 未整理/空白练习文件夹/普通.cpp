#include<iostream>
using namespace std;
int cal(int m,int n){
	
}
const int maxn=1010;
long long f[maxn];
int main()
{
    int m,n;cin>>m>>n;
    f[m]=f[m+1]=1;
    for(int i=m+2;i<=n;i++){
    	f[i]=f[i-1]+f[i-2];
    }
    cout<<f[n];
    return 0;
}
