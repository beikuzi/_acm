#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int n,m,k;
const int maxn=233,maxm=233,maxk=233;
int  c[maxn][maxm],d[maxn][maxm];
bool b[maxn][maxm];
int val[maxn][maxk],dp[maxm][maxk];
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		scanf("%d%d",&c[i][j],&b[i][j]);
    	}
    }
    memcpy(d,c,sizeof(c));
    if(k==0){
    	printf("0");
    	return 0;
    }
    for(int p=1;p<=k;p++){
    	
    }
}
