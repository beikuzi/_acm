#include<iostream>
#include<cstring>
#include<cstdio> 
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=1e6+7;
long long c[maxn],d[maxn];
double ratio(int l,int r,long long arr[]){
	return 1.0*(arr[r]-arr[l])/(r-l);
}
double ans1,ans2;
int q[maxn],p[maxn];
//�������w(i,j)=a[i]+b[j],���Ӿ������ƽ��ֵ���Ӿ������ٳ������k1��k2��ת�����������һά��������������� 
int main()
{
    int n1,n2,k1,k2; 
    scanf("%d%d%d%d",&n1,&n2,&k1,&k2);
    for(int i=1;i<=n1;i++){
    	scanf("%lld",&c[i]);
    	c[i]+=c[i-1];
    }
    for(int i=1;i<=n2;i++){
    	scanf("%lld",&d[i]);
    	d[i]+=d[i-1];
    }
    int l=1,r=1;
    for(int i=k1;i<=n1;i++){
    	while(l<r and ratio(q[l],i,c)<ratio(q[l+1],i,c)	)l++; 
    	ans1=max(ans1,ratio(q[l],i,c));
    	while(l<r and ratio(q[r-1],q[r],c)>=ratio(q[r],i-k1+1,c)	)r--;
    	q[++r]=i-k1+1;
    }
    l=1,r=1;
    memset(q,0,sizeof(q));
    for(int i=k2;i<=n2;i++){//ǰ�ᵥ������ ,б�������Σ�ԭ���������1�ߣ������µ���б���Ϸ��·��������±�б�ʸ�
		// �µ���б���Ϸ�ʱ�����м���ұߵ�����·�б�ʣ���֮��ߺ��ұ� 
    	while(l<r and ratio(q[l],i,d)<ratio(q[l+1],i,d)	)l++;//������Ǹ�����ȫû��,�°���� �����м��һ������ 
		ans2=max(ans2,ratio(q[l],i,d)); 
		while(l<r and ratio(q[r-1],q[r],d)>=ratio(q[r],i-k2+1,d)	)r--;//�м��Ǹ�����ȫû�� ����͹��� ,����ߵ���� 
		q[++r]=i-k2+1;
    }
    //cout<<ans1<<' '<<ans2<<endl;
    printf("%.10lf",ans1+ans2);
    return 0;
}
