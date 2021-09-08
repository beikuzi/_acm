#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn=40,maxm=600;
int k=0,head[maxn],next[maxn],vis[maxn];
struct edge{
	int v,w,next;
}e[maxm];
void add(int u,int v,int w){
	k++;
	e[k].v=v,e[k].w=w;
	e[k].next=head[u];
	head[u]=k;
}
int main()
{
    int a,b;scanf("%d",&a,&b);
    for(int i=1;i<=b;i++){
    	int u,v;scanf("%d%d",&u,&v);
    	add(u,v);
    }
}
