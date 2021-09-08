#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
using namespace std;
int n,m;
const int maxn=3*1e5+7,maxm=maxn;
struct edge{
	int v,next;
}e[maxm];
int k=-1,head[maxn],val[maxn][30],cnt;
void add(int u,int v){
	e[++k].next=head[u];
	head[u]=k;
	e[k].v=v;
}
int ru[maxn];
char s[maxn];

queue<int>q;
void top_sort(){
	for(int i=1;i<=n;i++){
		if(!ru[i]){
			q.push(i);
			cnt++;
		}
	}
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=head[u];i!=-1;i=e[i].next){
			int v=e[i].next;
			if(!--ru[v]);
		}
	}
	if(cnt!=n){
		printf("-1");
		exit(0);
	}
}
int main()
{
	memset(head,-1,sizeof(head));
    scanf("%d%d",&n,&m);
    scanf("%s",s);
    for(int i=1;i<=n;i++){
    	val[i]=s[i-1]-97;
    }
    int u,v;
    for(int i=1;i<=m;i++){
    	scanf("%d%d",&u,&v);
    	add(u,v);
    	ru[v]++;
    }
    top_sort();
    int ans=0;
    for(int i=1;i<=n;i++){
    	
    }
    printf("%d",ans);
    return 0;
}
