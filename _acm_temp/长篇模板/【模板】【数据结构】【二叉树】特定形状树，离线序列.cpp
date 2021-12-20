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
const int maxn=1e3+7;
int n;
int pt[maxn];

struct tree{
	struct node{
		int l,r;
		int val;
	}t[maxn];
	int tot;
	void build(int n){
		tot=0;
		for(int i=1;i<=n;i++){
			t[tot].l=readi();
			t[tot].r=readi();
			tot++;	
		}
	}
	void midOrder(int rt){
		if(t[rt].l!=-1)midOrder(t[rt].l);
		t[rt].val=pt[++tot];
		if(t[rt].r!=-1)midOrder(t[rt].r);
	}
	void fstOrder(int rt){
		printf("%d ",t[rt].val);
		if(t[rt].l!=-1)fstOrder(t[rt].l);
		if(t[rt].r!=-1)fstOrder(t[rt].r);
	}
	
	void bfs(int rt){
		queue<int>q;
		q.push(rt);
		while(!q.empty()){
			int u=q.front();
			q.pop();
			printf("%d ",t[u].val);
			if(t[u].l!=-1)q.push(t[u].l);
			if(t[u].r!=-1)q.push(t[u].r);
		}
	}
}tr;
void init(){
	n=readi();
	tr.build(n);
	for(int i=1;i<=n;i++){
		pt[i]=readi();
	}
	sort(pt+1,pt+1+n);
}
int main()
{
    init();
    tr.tot=0;
    tr.midOrder(0);
	//tr.fstOrder(0);
	tr.bfs(0);
    return 0;
}
