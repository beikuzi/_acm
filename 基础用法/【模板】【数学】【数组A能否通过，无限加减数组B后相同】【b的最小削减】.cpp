#include<iostream>
#include<cstdio> 
using namespace std;
const int maxn=1e6+7;
int n,k;
int c[maxn],d[maxn];
int gcd(int x,int y){
	return (!y)?x:gcd(y,x%y);
}
//��ΪA=B[1]*X[1]+B[2]*X[2] ,��ȡȫ�幫���������1��Ҳ���Ǵ��ڻ��ʣ���ô�϶�b֮�����໥�ﵽ1
//��������������ǿ�����������Сֵ��ֻҪA�Ĳ�ֵһ���������������ͻ������� 
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&c[i]);
    for(int j=1;j<=k;j++)scanf("%d",&d[j]);
    int p=d[1]; 
    for(int i=2;i<=k;i++)p=gcd(p,d[i]);
    for(int i=2;i<=n;i++){
    	if((c[i]-c[i-1])%p){
    		cout<<"No";
    		return 0;
    	}
    }
    cout<<"Yes";
    return 0;
}
