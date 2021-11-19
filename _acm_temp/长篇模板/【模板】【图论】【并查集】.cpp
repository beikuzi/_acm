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
const int maxn=2e5+7;
struct uf{
	int f[maxn],size[maxn];
	void init(int n){
		for(int i=1;i<=n;i++){
			f[i]=i;
		}
	}
	int find(int x){
		return (f[x]==x)?f[x]:f[x]=find(f[x]);
	}
	void merge(int x,int y){
		int u=find(x),v=find(y);
		f[v]=u;
		size[u]+=size[v];
	}
};//有a无b的并查集，有b无a的并查集，ab都有的并查集 
void init(){
	uf f;
	f.init();
}
typedef long long ll;
void solve(){
	
}
int main()
{
	int t=readi();
	while(t--){
		init();solve();
	}
    return 0;
}
