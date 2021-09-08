#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn=1e6;
int f[maxn];
int mfind(int x){//路径压缩并查集 
	if(f[x]==x)return x;
	return f[x]=cfind(f[x]);
}
int main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)f[i]=i;
    f[mfind(1)]=mfind(2);//1的上头的父节点是2的上头 
}
