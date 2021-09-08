#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const int maxn=520;
const ll inf=1e9;
ll dis[maxn][maxn],path[maxn][maxn],e[maxn][maxn];
queue<int>p,ept;//用来记录最小环的路径
int n,m; 
void init(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			e[i][j]=dis[i][j]=inf;
		}
	}
}

void add(int u,int v,ll w){
	e[u][v]=min(e[u][v],w);//重边
	dis[u][v]=e[u][v];
}
void get_path(int x,int y){
	if(!path[x][y])return;
	int k=path[x][y];
	get_path(x,k);
	p.push(k);
	get_path(k,y);
}
ll minlen=inf;
void read(){
	int u,v,w;
    for(int i=1;i<=m;i++){
    	scanf("%d%d%d",&u,&v,&w);
    	add(u,v,w);
    	add(v,u,w);
    }
}
void cal(){//处两点理1点自环和2点自环 
	
} 
void solve(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				if(dis[i][j]+e[j][k]+e[k][i]<minlen){
    				minlen=dis[i][j]+e[j][k]+e[k][i];
    				p=ept;//清空队列 
    				p.push(i);
    				get_path(i,j);
    				p.push(j);
    				p.push(k);
    			}
    			if(dis[i][j]>dis[i][k]+dis[k][j]){
    				dis[i][j]=dis[i][k]+dis[k][j];
    				path[i][j]=k;
    			}
			}
		}
	}
}
void pt_path(){
	while(!p.empty()){
    	cout<<p.front()<<' ';
    	p.pop();
    }
}
int main()
{
	scanf("%d%d",&n,&m);
    init();
    read();
    solve();
    cal();
    if(minlen==inf){
    	printf("No solution.");
    	return 0;
    }
    printf("%lld\n",minlen); 
    pt_path();
    return 0;
}
