#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn=1e5+7;
typedef long long ll;
ll ans;
int sti[maxn][25],sta[maxn][25];
int lo2[maxn];
int c[maxn];
int n,m,k;

void lo2_init(){
	int val=0;
	for(int i=1;i<=maxn;i++){
		if(i>(1<<val+1))val++;
		lo2[i]=val;
	}
}
void st_init(){
	for(int i=1;i<=17;i++){//2^17=131072 
		for(int j=1;j+(1<<i)-1<=n;j++){
			sta[j][i]=max(sta[j][i-1],sta[j+(1<<i-1)][i-1]);
			sti[j][i]=min(sti[j][i-1],sti[j+(1<<i-1)][i-1]);
		}
	}
}
int ask1(int l,int r){
	int cnt=lo2[r-l+1];
	return max(sta[l][cnt],sta[r+1-(1<<cnt)][cnt]);
}
int ask2(int l,int r){
	int cnt=lo2[r-l+1];
	return min(sti[l][cnt],sti[r+1-(1<<cnt)][cnt]);
}

void cal(){//ËÑË÷Çø¼ä 
	int l=1,r=1;
	ans=0;
	while(l<=n){
		while(l<=n){
			while(r<n and ask1(l,r)-ask2(l,r)<=k)++r;
			if(ask1(l,r)-ask2(l,r)>k)ans+=(n-r+1);
			l++;
		}
	}
}
int main()
{
	lo2_init();
	scanf("%d%d",&n,&m);
	memset(sti,0x3f,sizeof(sti));
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		sti[i][0]=c[i];
		sta[i][0]=c[i];
	}
	st_init();
	for(int j=1;j<=m;j++){
		scanf("%d",&k);
		cal();
		printf("%lld\n",ans);
	}
	return 0;
}
