#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn=1e5+7;
int d[maxn][25];
int l2[maxn];//��������log2�����н�� 
int query(int l,int r){
	int cnt=l2[r-l+1];
	return max(d[l][cnt],d[r+1-(1<<cnt)][cnt]);
	//mid+2^k-1==r
}
int n,m;
void test(int c[]){
	for(int i=1;i<=n;i++){
		cout<<c[i]<<' ';
	}cout<<endl;
}
void init(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
    	scanf("%d",&d[i][0]);
    }
    for(int i=1;i<=21;i++){
    	for(int j=1;j+(1<<i)-1<=n;j++){
    		//��1��2���ȣ���ʼ�ϲ�0��Ȼ��һֱ�ϲ���ȥ
			d[j][i]=max(d[j][i-1],d[j+(1<<i-1)][i-1]) ;
			//mid=l+(1<<i-1),1<<i�� 
    	}
    }
    int j=0;
    for(int i=1;i<=n;i++){
    	if(i>(1<<j+1))j++;
    	//2^j<i<=2^(j+1)	1,2=>0	3,4=>1	5,6,7,8=>2	9,10,11,12,13,14,15,16	=>3
    	l2[i]=j;
    }
}
int main()
{
    init();
    
    int l,r;
    for(int i=1;i<=m;i++){
    	scanf("%d%d",&l,&r);
    	printf("%d\n",query(l,r));
    }
    return 0;
}
