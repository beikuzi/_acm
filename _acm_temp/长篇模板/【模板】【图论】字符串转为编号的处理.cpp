#include<iostream>
#include<cstdio>
#include<map>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=520;
string s[maxn];
map<string,int>node;
void cal(int n){
	for(int i=1;i<=n;i++){
		cin>>s[i];
		node[s[i]]=i;
	}
}
void add(int u,int v){
	
}
int main()
{
    int n;scanf("%d",&n);
    cal(n);
    int m;scanf("%d",&m);
    string us,vs;
    for(int i=1;i<=m;i++){
    	cin>>us>>vs;
    	int u=node[us],v=node[vs];
    	add(u,v);
    }
}
