#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<map>
using namespace std;
typedef long long ll;
const int maxn=233;
int c1[maxn],c2[maxn];
//��������123����n�ֵ���Ʊ���޸�������m�ֵķ�����
//����( (1+x)(1+x^2)(1+x^3)����(1+x^n)��x^m��ϵ���Ƕ��� 
void cal(int n,int m){
	for(int i=0;i<=n;i++)c1[i]=1;//��Щ��Ʊ�������У�����ϵ������1 
	for(int i=2;i<=n;i++){//��Ҫ���n-1�Σ����õڶ�����Ʊ��ʼ������2~n 
		for(int j=0;j<=m;j++){//��������������0��m������һ�� 
			for(int k=0;k+j<=m;k+=i){//�������ޱ���һ������������0*i,1*i,2*i����������Ʊ 
				c2[k+j]+=c1[j];//ϵ������ 
			}
		}
		for(int j=0;j<=n;j++){
			c1[j]=c2[j];
		}memset(c2,0,sizeof(c2));
	}
	printf("%d\n",c1[m]);//Ҳ������1������� 
} 
int main()
{
    int x;
	while(cin>>x){
		cal(x,x);
	} 
	return 0;
}


/*
1��ʾ��ȡ����x^0 
������1-4���������� 
(1+x)(1+x^2)(1+x^3)(1+x^4)

=(1+x+x^2+x^4)(1+x^3+^4+x^7)

=1 + x + x^2 + 2x^3 + 2x^4 + 2x^5 + 2x^6 + 2*x^7 + x^8 + x^9 + x^10
���ԳƳ�10�ַ���������ϵ���Ƕ�Ӧ�ķ����� 

������֣������ֽ����������
��ֵķ��������У�<���>��
 
*/ 
