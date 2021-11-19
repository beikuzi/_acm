#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<vector>
#include<queue>
using namespace std;
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
const int maxn=1e6+7;
struct edge{
	int v,w,next;
}e[maxn];
int k=-1,head[maxn];
void add(int u,int v,int w){
	e[++k].next=head[u];
	head[u]=k;
	e[k].w=w,e[k].v=v;
} 
int lg[maxn];
struct Low_CA{//������Ծ ,ֻ��ͼ�й� 
	int jmp[maxn][30],dep[maxn];
	void dfs(int u,int fa){
		jmp[u][0]=fa;
		dep[u]=dep[fa]+1;
		for(int i=1;i<=lg[dep[u]];i++){
			jmp[u][i]=jmp[jmp[u][i-1]][i-1];//˫��Ծ=��Ծ+��Ծ 
		}
		for(int i=head[u];i!=-1;i=e[i].next){
			int v=e[i].v;
			if(v!=fa)dfs(v,u);
		}
	}
	int lca(int x,int y){
		if(dep[x]<dep[y])swap(x,y);
		while(dep[x]>dep[y]){
			x=jmp[x][lg[dep[x]-dep[y]]-1];//������Ȳ����2^i�Ĵ��� 
		}
		if(x==y)return x;
		for(int i=lg[dep[x]]-1;i>=0;i--){//�ﵽ��ͬ��ȣ��Ǿ�ͬʱ���� 
			if(jmp[x][i]!=jmp[y][i]){
				x=jmp[x][i],y=jmp[y][i];
			}
		}
		return jmp[x][0];//����һ��ͬʱ�� 
	}
}L;
int pt[maxn];
int n;
void init(){
	memset(head,-1,sizeof(head));
	for(int i=1;i<maxn;i++){
		lg[i]=lg[i-1]+(1<<lg[i-1]==i);
	}
	
	n=readi();
	for(int i=1;i<=n;i++){
		pt[i]=readi();
	}
	int u,v;
	for(int i=1;i<n;i++){
		u=readi(),v=readi();
		add(u,v,0);
		add(v,u,0);
	}
	L.dfs(1,0);
}
int val[maxn];
void dfs(int u,int fa){
	for(int i=head[u];i!=-1;i=e[i].next){
		int v=e[i].v;
		if(v==fa)continue;
		dfs(v,u);
		val[u]+=val[v];
	}
}
void solve(){
	for(int i=1;i<n;i++){
		int u=pt[i],v=pt[i+1];
		int t=L.lca(u,v);		
		val[u]++;//�ӵ��������ӵĲ�� 
		val[v]++;
		val[t]--;//��������-1
		
		val[L.jmp[t][0]]--;//�ǹ������ֲ����� 
	}
	dfs(1,-1);
	for(int i=2;i<=n;i++){
		val[pt[i]]--;//������㣬�����ĵ㶼���ظ������ 
	}
	for(int i=1;i<=n;i++){
		printf("%d\n",val[i]);
	}
}

int main()
{
    init();
    solve();
    return 0;
}
/*

5
1 4 5 3 2
1 2
2 4
2 3
4 5


*/

