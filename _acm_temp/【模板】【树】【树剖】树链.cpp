#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=1e6,maxm=1e6;
typedef long long ll;
struct edge{
	int v,w,next;
}e[maxm];
int k,head[maxn];
void add(int u,int v,int w){
	e[++k].next=head[u];
	head[u]=k;
	e[k].v=v,e[k].w=w;
}
int readi(){
	int x=0;
	char ch=getchar();
	while(ch<'0' || '9'<ch)ch=getchar();
	while('0'<=ch and ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x;
}
//------------------------------------------
struct node{
	int fa,son,size,dep;//���ڵ㣬�ض��ӡ�������С,��� 
	ll val;
}p[maxn]; 
int jmp[maxn][30],lg[maxn];
void dfs(int u,int fa){//������������������ȵ� 
	//p[u].dep=p[fa].dep+1;
	for(int i=1;i<=lg[p[u].dep];i++){
		jmp[u][i]=jmp[jmp[u][i-1]][i-1];
	}
	for(int i=head[u];i!=1;i=e[i].next){
		int v=e[i].v;
		if(v!=fa)dfs(v,u);
	}
}

int dfs2(int u,int fa){//�����������¼���������͸��ڵ㡢�ض��� 
	p[u].dep=p[fa].dep+1;
	p[u].fa=fa;
	p[u].size=1;
	for(int i=head[u];i!=-1;i=e[i].next){
		int v=e[i].v;
		if(v==fa)continue;
		p[u].size+=dfs2(v,u);
		if(p[v].size>p[p[u].son].size)p[u].son=v;
	}
	return p[u].size;
} 
struct link{
	int idx,top;
}l[maxn]; 
int tot,rk[maxn];
void dfs3(int u,int top){//��¼ͷ���λ�ã��Լ�dfs��Ͷ�Ӧ����˫���¼ 
	l[u].top=top;//��¼��������ͷ��� 
	l[u].idx=++tot;//��¼����dfs��λ�� 
	rk[tot]=u;//���µ�dfs��λ���ҵ�u 
	
	if(!p[u].son)return;
	dfs(p[u].son,top);
	for(int i=head[u];i!=-1;i=e[i].next){
		int v=e[i].v;
		if(v!=p[u].son and v!=p[u].fa)dfs3(v,v);//���������������Դ������ʼ������һ������ 
	}
} 
int sum(int x,int y){//��ȡһ�������ϵ�Ȩֵ�� 
	
} 
int n,m,R,mod;
void init(){
	memset(head,-1,sizeof(head));
	for(int i=1;i<maxn;i++){
		lg[i]=lg[i-1]+(1<<lg[i-1]==i);
	}
	n=readi();m=readi();R=readi();mod=readi();
	for(int i=1;i<=n;i++){
		p[i].val=readi();
	}
	for(int i=1,u,v;i<n;i++){
		u=readi();v=readi();
		add(u,v,0);
		add(v,u,0);
	}
	for(int i=1,crt,x,y,z;i<=m;i++){
		crt=readi();
		if(crt==1){
			
		}
		else if(crt==2){
			
		}
	}
}
void solve(){
	
}
int main()
{
    init();
    solve();
    return 0;
}
