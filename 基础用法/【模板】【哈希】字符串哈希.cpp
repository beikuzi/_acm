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
	//���ϣ��ȡ��ͬ��base��mod������ڶ��Σ����Ҵ�����ͬһ���ṹ������������ȷ������ֵ����ͬ�Ų�ͬ 
	int len=strlen(s);
	ull res=0;
	for(int i=0;i<len;i++){
		res=(res*base+(ull)s[i])%mod+prime;
	}//���������ѵ�0λ��ֵ������λ��ÿ��*base�൱�ڸ���λ���ӣ�Ȼ���پ�����λ��modһ��ֵ���ٱ�֤����0 
	return res;
}
int n;
char s[maxn];
ull h[maxn];
void sl1(){//���ƹ�ϣ������һ���̶�����base����һ���ַ�����Ԫ�ؿ��������ϵ����֣���Ϊ���Ĺ�ϣֵ 
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
//�ⷨ2����vector����sort�����߶��������sort��Ȼ��ֱ��һ��unique����-arr	(����Ǵ�1��ʼ��¼��Ҫ����-1 
int main()
{
    scanf("%d",&n);
    sl1();
    return 0;
}
