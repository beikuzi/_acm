#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=5*1e5+7;
typedef long long ll;
int t[maxn],ex[maxn];
ll res;
void msort(int l,int r,int c[]){//并归排序 merge
	if(l==r)return;
	int mid=l+(r-l>>1);
	msort(l,mid,c);
	msort(mid+1,r,c);
	int i=l,j=mid+1,k=l;
	while(i<=mid and j<=r){
		if(c[i]<=c[j])ex[k++]=c[i++];
		else{
			ex[k++]=c[j++];
			res+=mid-i+1;//因为j是顺序的，那么逆序的就是i里面还没有被并归的数，[i,mid] 
		}
	}
	while(i<=mid) ex[k++]=c[i++];
	while(j<=r)ex[k++]=c[j++];
	for(int i=l;i<=r;i++)c[i]=ex[i];
}
int main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++){
    	scanf("%d",&t[i]);
    }msort(1,n,t);
    printf("%lld",res);
    return 0;
}
