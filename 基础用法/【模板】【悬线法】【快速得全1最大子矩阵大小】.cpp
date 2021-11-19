#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<vector>
#include<queue>
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
const int maxn=1e3+7;
int c[maxn][maxn];
int n,m;
int l[maxn],r[maxn],maxl,maxr,h[maxn];
//l/r/h��¼i���������ЧΪl[i]�� ���� �ұߣ����� 
void init(){
	n=readi(),m=readi();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			c[i][j]=readi();
		}
	}
	for(int i=1;i<=m;i++){//������Чֵ��� 
		l[i]=1;
		r[i]=m; 
	}
}
//���ߣ�����Ϊ��Ӧ�е�����ֵ�����ֵ������¼������ 
void solve(){
	int ans=0;
	for(int i=1;i<=n;i++){
		maxl=1;
		for(int j=1;j<=m;j++){
			if(c[i][j]){//����������Ч 
				h[j]++;//j�и������� 
				l[j]=max(l[j],maxl);
			}
			else{
				h[j]=0;//���飬��һ�����Ͼ���Ч�� 
				l[j]=1;
				r[j]=m;
				maxl=j+1;//ʧ���������ֻ�ܸ��µ���һ�� 
			}
			cout<<l[j]<<' ';
		}cout<<endl;
		maxr=m;
		for(int j=m;j;j--){
			if(c[i][j]){
				r[j]=min(r[j],maxr);
				ans=max((r[j]-l[j]+1)*h[j],ans);
			}
			else maxr=j-1;
			cout<<r[j]<<' ';
		}
		cout<<endl;
	}
	cout<<ans;
}
int main()
{
    init();
    solve();
    return 0;
}
