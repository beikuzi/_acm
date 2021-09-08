#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<map>
#include<stack>
using namespace std;
const int maxn=1e5+7,maxm=1e6+7,mod=1e9+7;
stack<int>s;
queue<int>p;
map<int,int>mp;
vector<int>v;
#define M make_pair
typedef long long ll;
typedef pair<int,int>pii;
priority_queue<pii,vector<pii>,greater<pii> >q;
int k=-1,m,n;
struct edge{
	int v,w,next;
}e[maxm];
int head[maxn];
void add(int u,int v,int w){
	e[++k].next=head[u];
	head[u]=k;
	e[k].v=v,,e[k].w=w;
}
inline int readi(){
	
}
int main()
{
    ;
}
