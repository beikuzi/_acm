#include<iostream>
#include<cstring>
#include<cstdio> 
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=1e6+7;
long long c[maxn],d[maxn];
double ratio(int l,int r,long long arr[]){
	return 1.0*(arr[r]-arr[l])/(r-l);
}
double ans1,ans2;
int q[maxn],p[maxn];
//本题矩阵w(i,j)=a[i]+b[j],求子矩阵最大平均值，子矩阵至少长宽大于k1、k2，转化后就是两个一维数组的连续子序列 
int main()
{
    int n1,n2,k1,k2; 
    scanf("%d%d%d%d",&n1,&n2,&k1,&k2);
    for(int i=1;i<=n1;i++){
    	scanf("%lld",&c[i]);
    	c[i]+=c[i-1];
    }
    for(int i=1;i<=n2;i++){
    	scanf("%lld",&d[i]);
    	d[i]+=d[i-1];
    }
    int l=1,r=1;
    for(int i=k1;i<=n1;i++){
    	while(l<r and ratio(q[l],i,c)<ratio(q[l+1],i,c)	)l++; 
    	ans1=max(ans1,ratio(q[l],i,c));
    	while(l<r and ratio(q[r-1],q[r],c)>=ratio(q[r],i-k1+1,c)	)r--;
    	q[++r]=i-k1+1;
    }
    l=1,r=1;
    memset(q,0,sizeof(q));
    for(int i=k2;i<=n2;i++){//前提单调上升 ,斜率三角形，原来有两点和1边，无论新点在斜率上方下方，都是下边斜率高
		// 新点在斜率上方时，由中间和右边点组成下方斜率，反之左边和右边 
    	while(l<r and ratio(q[l],i,d)<ratio(q[l+1],i,d)	)l++;//最左边那个点完全没用,下凹情况 ，用中间点一定更好 
		ans2=max(ans2,ratio(q[l],i,d)); 
		while(l<r and ratio(q[r-1],q[r],d)>=ratio(q[r],i-k2+1,d)	)r--;//中间那个点完全没用 ，上凸情况 ,用左边点更好 
		q[++r]=i-k2+1;
    }
    //cout<<ans1<<' '<<ans2<<endl;
    printf("%.10lf",ans1+ans2);
    return 0;
}
