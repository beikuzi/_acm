#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn=1e5+7;
typedef long long ll;
int d[maxn][25];
int l2[maxn];//用来储存log2的所有结果 

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
	}return x*b;
}
//-------------------------------------------------------- 
int n,m;
int query(int l,int r){
	int cnt=l2[r-l+1];
	return max(d[l][cnt],d[r+1-(1<<cnt)][cnt]);
	//mid+2^k-1==r
}
void init(){
	int j=0;
    for(int i=1;i<=n;i++){
    	if(i>(1<<j+1))j++;
    	//2^j<i<=2^(j+1)	1,2=>0	3,4=>1	5,6,7,8=>2	9,10,11,12,13,14,15,16	=>3
    	l2[i]=j;
    }
    
    
	n=readi(),m=readi(); 
	for(int i=1;i<=n;i++){
		d[i][0]=readi();
    }
    for(int i=1;i<=21;i++){
    	for(int j=1;j+(1<<i)-1<=n;j++){
    		//从1（2长度）开始合并0，然后一直合并下去
			d[j][i]=max(d[j][i-1],d[j+(1<<i-1)][i-1]) ;
			//mid=l+(1<<i-1),1<<i长 
    	}
    }
    
}
void solve(){
	register int l,r;
    for(int i=1;i<=m;i++){
    	l=readi(),r=readi();
    	printf("%d\n",query(l,r));
    }
} 
void test(int c[]){
	for(int i=1;i<=n;i++){
		cout<<c[i]<<' ';
	}cout<<endl;
}
int main()
{
    init();
    solve();
    return 0;
}
