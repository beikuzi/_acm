#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<cstring> 
using namespace std;
const int maxn=123;
int edge[maxn][maxn];
int n,m;
int girl[maxn],vis[maxn];
bool cfind(int x){
	for(int j=1;j<=n;j++){
		if(!vis[j] and edge[x][j]){//ʹ���ڽӾ����ͼ������ÿ���� 
			vis[j]=1;//��ż�ҵ��µ� 
			if(!girl[j] or cfind(girl[j])){//û����ż\��������ż��һ���µ� 
				girl[j]=x;//���¸ı���� 
				return true;
			}
		}
	}
	return false;
} 

int main()
{
	int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
    	scanf("%d%d",&n,&m);
    	memset(girl,0,sizeof(girl));
		memset(edge,0,sizeof(edge));
		int u,v;
    	for(int i=1;i<=m;i++){
    		scanf("%d%d",&u,&v);
    		edge[u][v]=1;
    	}
    	int ans=0;
    	for(int i=1;i<=n;i++){
    		memset(vis,0,sizeof(vis));
    		if(!cfind(i))ans++;
    	}
    	printf("%d\n",ans);
    }
    return 0;
}
