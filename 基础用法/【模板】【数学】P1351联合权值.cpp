#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const int maxn=1e6+7,maxm=1e6+7;
struct edge{
	int v,w,next;
}e[maxm];
int k,head[maxn],pt[maxn];
void add(int u,int v,int w){
	e[++k].next=head[u];
	head[u]=k;
	e[k].v=v,e[k].w=w;
}
int mod=10007;
int readi(){
	int x=0;
	char ch=getchar();
	while(ch<'0' || ch>'9')ch=getchar();
	while('0'<=ch and ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}return x;
}
int n;
void init(){
	memset(head,-1,sizeof(head));
	n=readi();
	for(int i=1,u,v;i<n;i++){
		u=readi();v=readi();
		add(u,v,1);
		add(v,u,1);
	}
	for(int i=1;i<=n;i++){
		pt[i]=readi();
	}
}
int maxans,sumans; 
void solve(){
	//用点做中转站 
	//联合权值之和等于权值和的平方减去权值的平方和
	//2ab+2bc+2ac=(a+b+c)^2-(a^2+b^2+c^2)
	for(int u=1;u<=n;u++){
		int max1=-1,max2=-1;
		int t1=0,t2=0;//和的平方，平方和
		for(int i=head[u];i!=-1;i=e[i].next){
			int v=e[i].v;
			if(pt[v]>max1){
				max2=max1;
				max1=pt[v];
			}
			else if(pt[v]>max2){
				max2=pt[v];
			}
			t1=(t1+pt[v])%mod;
			t2=(t2+pt[v]*pt[v])%mod;
		}
		t1=t1*t1%mod;
		sumans=(sumans+t1-t2+mod)%mod;
		//因为前面用mod的时候，多mod了很多可能会括号产生负值 
		maxans=max(maxans,max1*max2);
	}
}
int main()
{
    init();
    solve();
    printf("%d %d",maxans,sumans);
    return 0;
}
