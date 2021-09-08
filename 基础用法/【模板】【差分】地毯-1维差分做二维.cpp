#include<iostream>
#include<cstdio> 
using namespace std;
const int maxn=1010;
int a[maxn][maxn];
int b[maxn][maxn];
int main()
{
    int n,m;scanf("%d%d",&n,&m);
    int x1,y1,x2,y2;
    for(int i=1;i<=m;i++){
    	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    	for(int j=x1;j<=x2;j++){
    		b[j][y1]++;
    		b[j][y2+1]--;
    	}
    }
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++){
    		b[i][j]+=b[i][j-1];
    		printf("%d ",b[i][j]);
    	}printf("\n");
    }
    return 0;
}
