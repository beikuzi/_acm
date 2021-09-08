#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
typedef long long ll;
const int maxarr=1e8+3*1e7;
const int maxn=1e5+7;
const int maxm=maxn<<1;
int n,m;
//
int c[maxarr];
struct node{
	int loc,len,val;
}f[maxn];
//
int head[maxn],k=-1;
struct edge{
	int v,next;
}e[maxm]; 
void add(int u,int v){
	e[++k].next=head[u];
	head[u]=k;
	e[k].v=v;
}

int fu[maxn];
//合并某个结点下所有子节点的值，并保证由小到大单调 
int now_loc=-1;
void Merge(int u,int fa){
	c[++now_loc]=f[u].val;
	f[u].loc=now_loc;
	f[u].len=1;

	for(int i=head[u];i!=-1;i=e[i].next){
		int v=e[i].v;
		if(v==fa)continue;
		int fst=f[v].loc,end=fst+f[v].len-1;
		for(int j=fst;j<=end;j++){
			c[++now_loc]=c[j];
		}
		f[u].len+=end-fst+1;
	}
} 
//预处理，用于得知所有节点的父节点 
//并且在回溯的时候，合并所有子节点的序列 
int dfn[maxn];
bool flag=false;
void dfs(int u,int fa){
	for(int i=head[u];i!=-1;i=e[i].next){
		int v=e[i].v;
		if(v==fa)continue;
		fu[v]=u;
		dfn[v]=dfn[u]+1;
		dfs(v,u);
	}
	if(dfn[u]==n)flag=true;
	if(!flag)Merge(u,fa); 
}
//往上找到不超过r的 最高节点 
int up_find(int x,int r){
	if(x==1)return 1;
	int fa=fu[x];
	if(f[fa].val>r)return x;
	return up_find(fa,r);
}
//二分查找，对于节点x，记录他在数组中存储的数列
bool cal[maxn];
int bfind(int x,int l){
	int fst=f[x].loc,len=f[x].len;
	if(!cal[x]){
		sort(c+fst,c+fst+len);
		cal[x]=true;
	}
	
	int bny_fst=lower_bound(c+fst,c+fst+len,l)-c;
    //cout<<fst<<' '<<len<<' '<<bny_fst<<endl;
	return fst+len-1-bny_fst+1;
}


void ctest(){
    for(int i=1;i<=now_loc;i++){
        cout<<c[i]<<' ';
    }cout<<endl;
}
int main(){
	int heal_min=2e9,heal_max=-1;
	memset(head,-1,sizeof(head));
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&f[i].val);
		heal_min=min(heal_min,f[i].val);
		heal_max=max(heal_max,f[i].val);
	}
	dfn[1]=1;
	dfs(1,-1);
	if(flag){
		for(int i=1;i<=n;i++){
            f[i].loc=i;
            f[i].len=n-i+1;
            c[i]=f[i].val;
        }
        now_loc=n;
	}
        
	scanf("%d",&m);
	for(int i=1,x,l,r;i<=m;i++){
		scanf("%d%d%d",&x,&l,&r);
		if(f[x].val>r or f[x].val<l){
			printf("0\n");
			continue;
		}
		if(l<heal_min and heal_max<r){
			printf("%d\n",n);
			continue;
		}
		int point=up_find(x,r);
		printf("%d\n",bfind(point,l));
	}
    //ctest();
	return 0;
}

