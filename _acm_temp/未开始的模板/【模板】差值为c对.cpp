#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
//����һ��c�����飬�ҳ����������� 
const int maxn=1e6;
typedef long long ll;
int n,f;
long long ans;
ll c[maxn];
void sl1(){//��aԪ�س��ִ���ͳ�ƣ�����mapӳ�䣬a��c������û�ж�Ӧb 
	map<int,int>m;//���֡�����
	for(int i=1;i<=n;i++){
		m[c[i]]++;//ͳ�Ƴ��ִ��� 
		c[i]-=f;//�������a-��������b=f����a-f�͵�����������b�����ֻҪ����������b�Ĵ����ͺ��� 
	} 
	for(int i=1;i<=n;i++){
		ans+=m[c[i]];
	}cout<<ans;
	return;
}
void sl2(){//���֣������������У���ֵΪc�ں����� 
	
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
