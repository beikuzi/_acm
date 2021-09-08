#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
const int maxn=200;
struct hp{
	int c[maxn];
	hp(){
		memset(c,0,sizeof(c));
	}	
}h[1010];
hp operator+(const hp&x,const hp &y){
	hp z;
	z.c[0]=max(x.c[0],y.c[0]);
	for(int i=1;i<=z.c[0];i++){
		z.c[i]=x.c[i]+y.c[i];
		z.c[i+1]+=z.c[i]/10;
		z.c[i]%=10;
	}if(z.c[z.c[0]])z.c[0]++;
	return z;
}
hp operator*(const hp&x,const hp&y){
	hp z;
	z.c[0]=x.c[0]+y.c[0];
	for(int i=1;i<=x.c[0];i++){
		for(int j=1;j<=y.c[0];j++){
			z.c[i+j-1]=x.c[i]*y.c[j];
		}
	}
	for(int i=1;i<z.c[0];i++){
		z.c[i+1]+=z.c[i]/10;
		z.c[i]%=10;
	}if(z.c[z.c[0]]==0)z.c[0]--;
	return z;
}
bool cmp(const hp&x,const hp &y){
	for(int i=max(x.c[0],y.c[0]);i>=1;i--){
		if(x.c[i]>y.c[i])return true;
		if(x.c[i]<y.c[i])return false;
	}return true;
}
hp max(const hp&x,const hp&y){
	if(cmp(x,y))return x;
	return y;
}
hp turn(int x){
	hp z;
	while(x){
		z.c[0]++;
		z.c[z.c[0]]=x%10;
		x/=10;
	}
	return z;
}
hp hout(const hp&z){
	for(int i=z.c[0];i>=1;i--)printf("%d",z.c[i]);
}
int main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){//询问第i个物品，物品重量为i，价值为i时 
		h[i]=max(h[i],turn(i));
		for(int j=i+1;j<=n;j++){//对于所有这个重量往上的背包 
			h[j]=max(h[j],h[j-i]*turn(i));
		}
	}
	hout(h[n]);
	return 0;
}
