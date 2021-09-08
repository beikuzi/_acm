#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
using namespace std;
//���ɣ��Ѵӵ�ǰ���������ӽ�㣬��һ���ӽ���������ȥ��+1��������ǰ������ȣ���ôʣ�µĽ��Ͷ������� 
const int maxn=1e5+7;
typedef long long ll;
int n,m;
int k,head[maxn],dis[maxn];
struct edge{
	int v,next;
}e[maxn];
void add(int u,int v){
	e[++k].next=head[u];
	head[u]=k;
	e[k].v=v;
}
priority_queue<int,vector<int>,less<int> >q;
void dfs(int u){
	priority_queue<int,vector<int>,less<int> >p;
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].v;
		dfs(v);
		p.push(dis[v]);
	} 
	if(p.empty())dis[u]=1;
	else{
		dis[u]=p.top()+1;
		//cout<<u<<' '<<dis[u]<<endl;
		p.pop();
	}
	while(!p.empty()){
		q.push(p.top());
		p.pop();
	}
}
int main(){
	scanf("%d%d",&n,&m);
	int v;
	for(int i=2;i<=n;i++){
		scanf("%d",&v);
		add(v,i);
	}
	dfs(1);
	int ans=dis[1];
	//for(int i=1;i<=n;i++)cout<<dis[i]<<' ';cout<<endl;
	int cnt=q.size();
	cnt=min(cnt+1,m);
	for(int i=2;i<=cnt;i++){
		ans+=q.top();
		//cout<<ans<<' '<<q.top()<<' ';
		q.pop();
	}
	printf("%d",ans);
	return 0;
}
