#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring> 
using namespace std;
typedef long long ll;
const int maxn=1e6;
int c[maxn];
int main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++){
    	scanf("%d",&c[i]);
    }sort(c+1,c+1+n);
    ll ans=0,add=0;
    int loc=1;
    for(int i=2;i<=n;i++){
    	if(i&1^1){
    		add+=c[n-loc+1]-c[loc];
    		loc++;
    	}
    	ans+=add;
    	printf("%lld ",ans);
    }return 0;
}
