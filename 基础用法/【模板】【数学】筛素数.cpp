#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath> 
#include<bitset>
using namespace std;
typedef unsigned long long ull;
bool prime(ull x){
	if(x==1)return false;
	for(ull i=2;i*i<=x;i++){
		if(x%i==0){
			//cout<<i<<endl;
			return false;
		}
	}return true;
}
bool sp(int x){//sixprime������ɸ 
	if(x==1)return 0;
	if(x==2 or x==3)return 1;
	if(x%6!=5 and x%6!=1)return 0;
	int r=sqrt(x);
	for(int i=5;i<=r;i+=6)//��Ϊ��������Ļ��п�����(6a+1)*(6a+5) 
		if(x%i==0 or x%(i+2)==0)return 0;
	return 1;
}
//-------------------------------------------------------------
const int maxn=1e8+7;
bitset<maxn>p;//��ʾi�ǲ������� 
int pr[maxn];//��ŵ�i������ 
int n,k;
void ol(){//��������1e8����Ҫ����ʱ��Ԥ�� 
	p[1]=false;
	p.set();
	for(int i=2;i<=n;i++){
		if(p[i])pr[++k]=i;//1.ûɹ��������
		for(int j=1;j<=k and i*pr[j]<=n;j++){//2.ʹ��ɸ������������鷶Χ 
			p[i*pr[j]]=false;//3.����С��������ɸ 
			if(i%pr[j]==0)break;
			//4.˵��i���Էֽ��һ���Ѿ����ڵ�����
			//��ôĳ��*����(֮��)���Ͳ���ֽ�ĳ������Ϊ ���������ڣ�*һ����*������֮��
			//�ڣ�һ����*������֮�󣩣�����ֽ� 
		} 
	}
}
int main()
{
	
	scanf("%d",&n);
    //ol();
//    for(int i=1;i<=k;i++){
//    	printf("%d\n",pr[i]);
//    }
	cout<<sp(n);
	//cout<<k<<' '<<pr[k];
	return 0;
}
