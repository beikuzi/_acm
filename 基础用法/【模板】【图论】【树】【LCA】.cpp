#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=5e5+7,maxm=1e6+7;
typedef long long ll;
inline int readi(){
	int x=0;
	char ch=getchar();
	while(ch<'0' || ch>'9')ch=getchar();
	while('0'<=ch and ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x;
}
int head[maxn],k;
struct edge{
	int v,w,next;
}e[maxm];
void add(int u,int v,int w){
	e[++k].next=head[u];
	head[u]=k;
	e[k].v=v,e[k].w=w;
}
int lg[maxn],dep[maxn],jmp[maxn][22];//用来保存log2（i）+1的 值 
void dfs(int u,int fa){
	jmp[u][0]=fa;//跳2的0次方步 
	dep[u]=dep[fa]+1;
	for(int i=1;i<=lg[dep[u]];i++){//2分上跳可以跳的步数 
		jmp[u][i]=jmp[jmp[u][i-1]][i-1]; 
	}
	for(int i=head[u];i!=-1;i=e[i].next){
		int v=e[i].v;
		if(v!=fa)dfs(v,u);
	}
}
int LCA(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	while(dep[x]>dep[y]){
		x=jmp[x][lg[dep[x]-dep[y]]-1];
	}//先快速大回跳到相同深度 
	if(x==y)return x;
	for(int i=lg[dep[x]]-1;i>=0;i--){
		if(jmp[x][i]!=jmp[y][i]){
			x=jmp[x][i],y=jmp[y][i];
		}
	}//再一起共同回跳 
	return jmp[x][0];
}
int n,m,r;
void init(){
	memset(head,-1,sizeof(head));
	for(int i=1;i<maxn;i++){
		lg[i]=lg[i-1]+(1<<lg[i-1]==i);//每当到2的指数的时候就+1 
	}
	n=readi();m=readi();r=readi();
	for(int i=1,u,v;i<n;i++){
    	u=readi();v=readi();
    	add(u,v,0);
    	add(v,u,0);
    }
	dfs(r,-1);
	
}
void solve(){
	for(int i=1,x,y;i<=m;i++){
		x=readi();y=readi();
		printf("%d\n",LCA(x,y));
	}
}
int main()
{
    init();
    solve();
    return 0;
}
