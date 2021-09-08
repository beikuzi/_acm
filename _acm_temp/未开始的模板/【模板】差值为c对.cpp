#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
//给出一个c，数组，找出数组所有与 
const int maxn=1e6;
typedef long long ll;
int n,f;
long long ans;
ll c[maxn];
void sl1(){//将a元素出现次数统计，并用map映射，a减c后找有没有对应b 
	map<int,int>m;//数字、次数
	for(int i=1;i<=n;i++){
		m[c[i]]++;//统计出现次数 
		c[i]-=f;//这个数字a-其他数字b=f，则a-f就等于其他数字b，因此只要找其他次数b的次数就好了 
	} 
	for(int i=1;i<=n;i++){
		ans+=m[c[i]];
	}cout<<ans;
	return;
}
void sl2(){//二分，对于有序数列，差值为c在后面搜 
	
}
int main()
{
    scanf("%d%d",&n,&f);
    for(int i=1;i<=n;i++){
    	scanf("%lld",&c[i]);
    }
    sl1();
    return 0;
}
