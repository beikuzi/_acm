#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
using namespace std;
//���÷���+1ȥ�����һλͳ�ƶ�����1����
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
