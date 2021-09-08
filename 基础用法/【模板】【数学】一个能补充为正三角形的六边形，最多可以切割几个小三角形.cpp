#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long ll; 
ll len[6]; 

int main(){
	for(int i=0;i<6;i++){
		scanf("%lld",&len[i]);
	}
	ll max_tri=len[0]+len[1]+len[2];
	max_tri*=max_tri;
	ll ans=max_tri-len[0]*len[0]-len[2]*len[2]-len[4]*len[4];
	printf("%lld",ans);
	return 0;
}

