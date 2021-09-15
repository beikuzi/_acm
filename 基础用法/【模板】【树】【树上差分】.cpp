#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const int maxn=1e6+7,maxm=1e6+7;
int readi(){
	int x=0;
	char ch=getchar();
	while('0'>ch || ch>'9')ch=getchar();
	while('0'<=ch and ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x;
}
struct edge{
	int v,w,next;
}e[maxm];
int k,head[maxn];
void add(int u,int v,int w){
	e[++k].next=head[u];
	head[u]=k;
	e[k].v=v,e[k].w=w;
}
int jmp[maxn][30],dep[maxn],pt[maxn];
int n,lg[maxn];
void dfs(int u,int fa){//����������Ծ 
	jmp[u][0]=fa;
	dep[u]=dep[fa]+1;
	for(int i=1;i<=lg[dep[u]];i++){
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
	}if(x==y)return x;
	for(int i=lg[dep[x]]-1;i>=0;i--){
		if(jmp[x][i]!=jmp[y][i]){
			x=jmp[x][i],y=jmp[y][i];
		}
	}
	return jmp[x][0];
}
int val[maxn];
void dfs2(int u,int fa){//��ֻ�ԭ 
	for(int i=head[u];i!=-1;i=e[i].next){
		int v=e[i].v;
		if(v==fa)continue;
		dfs2(v,u);
		val[u]+=val[v];
	}
}

void init(){
	memset(head,-1,sizeof(head));
	for(int i=1;i<maxn;i++){
		lg[i]=lg[i-1]+(1<<lg[i-1]==i);
	}
	n=readi();
	for(int i=1;i<=n;i++){
		pt[i]=readi();
	}
	for(int i=1,u,v;i<n;i++){
		u=readi(),v=readi();
		add(u,v,0);
		add(v,u,0);
	}
	dfs(1,-1);
}
void solve(){
	for(int i=1;i<n;i++){
		int u=pt[i],v=pt[i+1];//��uȥ��v
		int t=LCA(u,v);
		val[u]++;//��u��v��·���϶���Ϊ���������һ�� 
		val[v]++;
		val[t]--;//,��Ϊt�ᱻ·��1�Σ���Ϊ���+2�����Լ�1 
		val[jmp[t][0]]--; //+2-1-1����t���ϵĽ�㶼�������� 
	}
	dfs2(1,-1);
	for(int i=2;i<=n;i++){
		val[pt[i]]--; 
	}//��2��ʼ���յ����һ����������һ�𣬵����Ǹ��㲢��2�� 
}
int main()
{
    init();
    solve();
    for(int i=1;i<=n;i++){
    	printf("%d\n",val[i]);
    }
    return 0;
}
