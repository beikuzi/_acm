#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int maxn=10086;
typedef unsigned long long ull;
ull base=233;
ull prime=1145143;
ull mod=1145141919810;
ull hash(char s[]){
	//多哈希：取不同的base和mod，计算第二次，并且储存在同一个结构体里，进行排序后，确保两个值都不同才不同 
	int len=strlen(s);
	ull res=0;
	for(int i=0;i<len;i++){
		res=(res*base+(ull)s[i])%mod+prime;
	}//倒着来，把第0位的值视作高位，每次*base相当于给高位增加，然后再经商新位，mod一个值后再保证他非0 
	return res;
}
int n;
char s[maxn];
ull h[maxn];
void sl1(){//进制哈希：给出一个固定进制base，将一个字符串串元素看做进制上的数字，视为他的哈希值 
	int ans=1;
	for(int i=1;i<=n;i++){
		scanf("%s",s);
		h[i]=hash(s);
	}sort(h+1,h+n+1);
	for(int i=2;i<=n;i++){
		//cout<<h[i]<<' ';
		if(h[i]!=h[i-1])ans++;
	}
	//cout<<h[n]<<endl;
	cout<<ans;
}
//解法2：用vector进行sort，或者对数组进行sort，然后直接一个unique（）-arr	(如果是从1开始记录，要额外-1 
int main()
{
    scanf("%d",&n);
    sl1();
    return 0;
}
