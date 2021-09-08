#include<iostream>
#include<algorithm>
#include<cstdio> 
using namespace std;
//long long deal(long long x){
//	if(x>=100)return x;
//	if(x<10){
//		if(x<3)return 1;
//		if(x<6)return 2;
//		if(x<9)return 3;
//		return 4;
//	}
//	long long y=4;x-=9;//0-9
//	while(x>=30){
//		x-=30;
//		y+=24;
//	}
//	if(x>10){//20-29
//		y+=14;
//		if(x<13)y-=1;
//		if(x<)
//	}
//	else{//10-19
//		if(x<)
//	}
//}
const int maxn=123;
int c[maxn];
bool b[maxn];
int cnt=0;
void deal(int x){
	if(x<10){
		if(x%3==0)b[x]=true;
	}
	else if(x/10%3==0 or x%10%3==0 or ((x/10+x%10)%3==0))b[x]=true;
	if(!b[x])cnt++;
	c[x]=cnt;
}
void test(){
	for(int i=0;i<100;i++){
		cout<<i<<' '<<c[i]<<' '<<b[i]<<endl;
	}
}
int main()
{
	for(int i=0;i<100;i++){
    	deal(i);
    }//test();
    int n;scanf("%d",&n);
    long long l,r;
    
    while(n--){
    	scanf("%lld%lld",&l,&r);
    	l=l-c[l>99?99:l]-b[l>99?99:l];
    	r-=c[r>99?99:r];
    	//cout<<l<<' '<<r<<' ';
    	printf("%lld\n",r-l);
    }
}
