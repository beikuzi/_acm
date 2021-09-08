#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn=2525;
int n,k;
struct node{
	double x,y;
}d[maxn];
double cal(node a,node b){
	return a.x*b.y-a.y*b.x;
}

long double c[maxn][maxn];
void deal(){
	for(int i=0;i<maxn;i++)c[0][i]=0,c[i][0]=1;
    for(int i=1;i<maxn;i++){
    	for(int j=1;j<=i;j++){
    		c[i][j]=c[i-1][j]+c[i-1][j-1];
    	}
    }
} 
double ans=0; 
int main()
{
	deal();
	scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
    	scanf("%d%d",&d[i].x,&d[i].y);
    }

    for(int i=0;i<n;i++){//选择每一个定点 
    	for(int j=k-1;j<n;j++){
    		int aim=(i+j)%n;
    		ans+=cal(d[i],d[aim])*c[j-1][k-2]/c[n][k];
    		//概率是 
    	}
    }
    printf("%.6lf",ans/2.0);
    return 0;
}
