#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
const int maxn=1e6+7;
typedef long long ll;
int c[maxn],ans[maxn];
map<int,int>mp;
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		mp[c[i]]++;
	}
	ll res=0;
	for(int i=1;i<=n;i++){
		if(ans[c[i]])res+=ans[c[i]];
		else{
			int j;
			for(j=1;j*j<c[i];j++){
				if(c[i]%j==0){
					ans[c[i]]+=mp[j]*mp[c[i]/j]*2;
				}
			}
			if(j*j==c[i])ans[c[i]]+=mp[j]*mp[j];
			res+=ans[c[i]];
		}
	}
	printf("%lld",res);
	return 0;
}
