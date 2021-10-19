#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<bitset>
using namespace std;
typedef long long ll;
const int maxn=1e8+7;
inline int readi(){
	int x=0,b=1;
	char ch=getchar();
	while('0'>ch or ch>'9'){
		if(ch=='-')b=-1;
		ch=getchar();
	}
	while('0'<=ch and ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}return x*b;
}
inline ll readl(){
	ll x=0,b=1;
	char ch=getchar();
	while('0'>ch or ch>'9'){
		if(ch=='-')b=-1;
		ch=getchar();
	}
	while('0'<=ch and ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}return x*b;
}
bool sp(int x){//���� 
	switch(x){
		case 1:return 0;
		case 2:return 1;
		case 3:return 1;
		default:{
			if(x%6!=5 and x%6!=1)return 0;
			int r=sqrt(x);
			for(int i=5;i<=r;i+=6){
				if(x%i==0 or x%(i+2)==0)return 0;
			}
			return 1;
		}
	}return '?'; 
}
//----------------------------------------------------------------------
bitset<maxn>p;//��ʾi�ǲ������� 
int pr[maxn];//��������i��������ɶ 
int n,k;//k��ʾ���ڵ�������ӵ�м������� 
void ol(){
	p[1]=false;
	p.set();//ȫ����Ϊ1
	for(int i=2;i<=n;i++){
		if(p[i])pr[++k]=i;//���������� 
		for(int j=1;j<=k and i*pr[j]<=n;j++){//�ڷ�Χ����������ɸ 
			p[i*pr[j]]=false;
			if(i%pr[j]==0)break;
			//i�ֽܷ��һ���Ѿ����ڵ�������i=z*f    ��z�Ǳ��д������� 
			//������z*f���ϳɣ�����֮�����µ���*z���ϳɣ������ظ� 
		}
	} 
}
void init(){
	n=readi();
	ol();
}
void solve(){
	for(int i=1;i<=k;i++){
		printf("%d,",pr[i]);
	} 
}
int main()
{
    init();
    solve();
    return 0;
}
