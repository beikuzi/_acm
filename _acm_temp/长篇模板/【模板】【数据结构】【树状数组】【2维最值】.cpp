#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
const int maxn=1e3+7;
typedef long long ll;
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
	}return x;
}
inline ll readl(){
	ll x=0,b=1;
	char ch=getchar();
	while('0'>ch or ch>'9'){
		if(ch=='-')b=-1;
		ch=getchar();
	}
	while('0'<=ch and ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}return x;
}
int n,m;
int mm[maxn];//二进制位数-1 
ll val[maxn][maxn],dp[maxn][maxn][10][10];
//预处理是nm(logn)(logm)
void init(){
	mm[0]=-1;
	for(int i=1;i<maxn;i++){
		mm[i]=(i&(i-1))?mm[i-1]:mm[i-1]+1;
	}
	n=readi(),m=readi();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			val[i][j]=readl();
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[i][j][0][0]=val[i][j];
		}
	}
	for(int p=0;p<=mm[n];p++){
		for(int q=0;q<=mm[m];q++){
			if(p+q){
				for(int i=1;i+(1<<p)-1<=n;i++){
					for(int j=1;j+(1<<q)-1<=m;j++){
						if(p)dp[i][j][p][q]=max(dp[i][j][p-1][q],dp[i+(1<<(p-1))][j][p-1][q]);
						else dp[i][j][p][q]=max(dp[i][j][p][q-1],dp[i][j+(1<<(q-1))][p][q-1]);
					}
				}
			}
		}
	}
}
ll ask(int x1,int y1,int x2,int y2){
	int k1 = mm[x2-x1+1];
	int k2 = mm[y2-y1+1];
	x2 = x2 - (1<<k1) + 1;
	y2 = y2 - (1<<k2) + 1;
	return max(max(dp[x1][y1][k1][k2],dp[x1][y2][k1][k2]),max(dp[x2][y1][k1][k2],dp[x2][y2][k1][k2]));
}
void solve(){
	int t=readi();
	register int x1,y1,x2,y2;
	while(t--){
		x1=readi(),y1=readi(),x2=readi(),y2=readi();
		if(x1>x2)swap(x1,x2);
		if(y1>y2)swap(y1,y2);
		printf("%lld\n",ask(x1,y1,x2,y2));
	}
}
int main()
{
    init();
    solve();
    return 0;
}
