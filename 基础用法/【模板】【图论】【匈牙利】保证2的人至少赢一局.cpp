#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=55;
char c[maxn][maxn];
int edge[maxn][maxn];
int girl[maxn],vis[maxn];
int n;
void print(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(c[i][j]==0)c[i][j]='=';
			printf("%c",c[i][j]);
		}
		printf("\n");
	}
}
int cfind(int u){
	//cout<<u<<endl;print();
	for(int v=1;v<=n;v++){
		if(!vis[v] and edge[u][v]){
			vis[v]=1;
			if(c[u][v]==0 or cfind(girl[v])){
				girl[v]=u;
				c[u][v]='+';
				c[v][u]='-';
				return v;
			}
		}
	}
	return 0;
}
void init(){
	memset(c,0,sizeof(c));
    memset(edge,0,sizeof(edge));
    memset(girl,0,sizeof(girl));
}
void deal(int n){
	string s;getline(cin,s);
	char ch;
   	for(int i=1;i<=n;i++){
		scanf("%c",&ch);
		if(ch=='1'){
			c[i][0]='1';
			for(int j=1;j<=n;j++){
				c[i][j]=c[j][i]='=';
			}
		}
		else{
			c[i][0]='2';
		}
		c[i][i]='X';
	}
}
void solve(){
	init();
	scanf("%d",&n);
	deal(n);//把1全部贪成等号 
	
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			if(c[i][j]!='='){
				cnt++;
				edge[i][j]=1;
				edge[j][i]=1;
			}
		}
		if(c[i][0]=='2' and cnt==0){
			printf("NO\n");
			return;
		}
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		if(c[i][0]=='1')continue;
		if(!cfind(i)){
			printf("NO\n");
			return;
		}
		//print();
	}
	printf("YES\n");
	print();
}
int main()
{
	int t;scanf("%d",&t);
    while(t--){
    	solve();
    }
    return 0;
}
