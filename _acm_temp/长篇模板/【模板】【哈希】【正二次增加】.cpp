#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<vector>
#include<queue>
#include<bitset>
using namespace std;
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
const int maxn=2e4+7;
struct prime{
	bitset<maxn>p;
	int pr[maxn];
	int tot;//ӵ�е�����
	prime(int n){//��Ҫ��ķ�Χ1-n
		p[1]=false;//1�������� 
		p.set();//ȫ����Ϊ1
		tot=0;
		for(int i=2;i<=n;i++){
			if(p[i])pr[++tot]=i;
			for(int j=1;j<=tot and i*pr[j]<=n;j++){
				p[i*pr[j]]=false;
				if(i%pr[j]==0)break;
			}
		}
	}
	int ask(int x){//�ҵ���һ�����ڵ���x������ 
		int loc=lower_bound(pr+1,pr+1+tot,x)-pr;
		return pr[loc];
	}
}; 
int n,m;
map<int,int>mp;
void init(){
	prime t(maxn-1);
	m=readi(),n=readi();
	m=t.ask(m);
}
int main()
{
    init();
    int cnt=0;
    for(int i=1;i<=n;i++){
    	int t=readi();
    	int j;
    	for(j=0;j<m;j++){//��Ϊmod��ʽ��������ѭ�� 
    		int loc=(t+j*j)%m;
    		if(mp[loc]==0){
    			mp[loc]=1;
    			printf("%d",loc);
    			break;
    		}
    	}
    	if(j==m)printf("-");
    	if(i!=n)printf(" ");
    } 
    return 0;
}
