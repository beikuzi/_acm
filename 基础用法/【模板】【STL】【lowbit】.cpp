#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
using namespace std;
//利用反码+1去掉最后一位统计二进制1个数
int lwb(int x){
	return x&-x;
}
int main(){
	long long n;cin>>n;
	int cnt=0;
	while(n){
		n-=lwb(n);
		cnt++;
	}
	cout<<cnt;
	return 0;
}
