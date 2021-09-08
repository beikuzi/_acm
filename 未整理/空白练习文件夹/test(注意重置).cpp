#include<iostream>
#include<cstdio>
#include<cstring> 
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=3000;
struct hp{
	int c[maxn];
	hp(){
		memset(c,0,sizeof(c));
	}	
}k[1010];
hp turn(int x){
	hp z;
	while(x){
		z.c[0]++;
		z.c[z.c[0]]=x%10;
		x/=10;
	}
	return z;
}
void hout(const hp&z){
	if(z.c[0]==0){
		printf("0");
		return ;
	}
	for(int i=z.c[0];i>=1;i--){
		printf("%d",z.c[i]);
	}
}
hp operator+(const hp& x,const hp& y){
	hp z;
	z.c[0]=max(x.c[0],y.c[0]);//1.决定基础长度
	for(int i=1;i<=z.c[0];i++){
		z.c[i]+=x.c[i]+y.c[i];//2.for有进位，两个相加
		z.c[i+1]+=z.c[i]/10;//3.进位 
		z.c[i]%=10;
	}if(z.c[z.c[0]+1])z.c[0]++;//4.最高一位处理 
	return z;
}
hp operator*(const hp&x,const hp&y){
	hp z;
	z.c[0]=x.c[0]+y.c[0];
	for(int i=1;i<=x.c[0];i++){
		for(int j=1;j<=y.c[0];j++){
			z.c[i+j-1]+=x.c[i]*y.c[j];
		}
	}
	for(int i=1;i<z.c[0];i++){
		z.c[i+1]+=z.c[i]/10;
		z.c[i]%=10;
	}if(!z.c[z.c[0]])z.c[0]--;
	return z;
}
int main(){
	
	k[1]=turn(1);
	for(int i=2;i<=1000;i++){
		k[i]=turn(i)*k[i-1];
	}
	int t;cin>>t;
	int x,y;
	for(int i=1;i<=t;i++){
		cin>>x>>y;
		//hout(k[x]);cout<<endl;
		int ans=0;
		for(int j=k[x].c[0];j>=1;j--){
			if(k[x].c[j]==y)ans++;
		}cout<<ans<<endl;
	}
	return 0;
}

