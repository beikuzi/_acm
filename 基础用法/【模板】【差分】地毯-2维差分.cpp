#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1010;
int a[maxn][maxn];
int b[maxn][maxn];
int main()
{
	//��̺�ص����⣬ѯ��ij�ж��ٿ��̺ 
    int n,m;scanf("%d%d",&n,&m);
    int x1,x2,y1,y2;
    for(int i=1;i<=m;i++){
    	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    	b[x1][y1]++;
    	b[x1][y2+1]--;
    	b[x2+1][y1]--;
    	b[x2+1][y2+1]++;
    }
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++){
    		a[i][j]=a[i-1][j]+a[i][j-1]+b[i][j]-a[i-1][j-1];
    		printf("%d ",a[i][j]);
    	}printf("\n");
    }return 0;
}
