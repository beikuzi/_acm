#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath> 
using namespace std;
const int maxn=2020;
int dp[maxn][maxn];//在1，x区间用y个邮票集的最值 
int up[maxn];
int main()
{
    int t;scanf("%d",&t);
    int n,m,cnt;
    for(int x=1;x<=t;x++){
    	memset(dp,0,sizeof(dp));
    	memset(up,0,sizeof(up));
    	scanf("%d%d%d",&n,&m,&cnt);
    	
    	int l,r;
    	for(int j=1;j<=m;j++){// 1.将二维，压缩成某个点最多能往右更新到哪个区间 
    		scanf("%d%d",&l,&r);
    		for(int k=l;k<=r;k++)up[k]=max(up[k],r);
    	}
    	
    	for(int i=1;i<=n;i++){
    		for(int j=1;j<=cnt;j++){
    			dp[i][j]=max(dp[i][j],dp[i-1][j]);//2.因为会被之前的区间扩增导致的更新,继承之前的或者上一轮的 
    			dp[up[i]][j]=max(dp[up[i]][j],dp[i-1][j-1]+up[i]-i+1); //3.当前位置的所有扩展位更新 
    		}
    	}
    	printf("Case #%d: %d\n",x,dp[n][cnt]);
    }
}
