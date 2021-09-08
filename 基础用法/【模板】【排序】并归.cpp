#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const int maxn=1e5;
int ex[maxn],t[maxn];
void csort(int l,int r,int c[]){
	if(l==r)return;
	int mid=r+(r-l)>>1;
	csort(l,mid,c);
	csort(mid+1,r,c);
	
	int i=l,j=mid+1;
	int k=l;
	while(i<=mid and j<=r){
		if(c[i]<c[j])ex[k++]=c[i++];
		else ex[k++]=c[j++];
	}
	while(i<=mid)ex[k++]=c[i++];
	while(j<=r)ex[k++]=c[j++];
	for(int k=l;k<=r;k++)c[k]=ex[k];
}
int main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++){
    	scanf("%d",&t[i]);
    }csort(1,n,t);
    for(int i=1;i<=n;i++)printf("%d ",t[i]);
    return 0;
}
