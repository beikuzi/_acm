#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int maxn=2505;
const double ninf=-1145141919.0;
int head[maxn];
//struct edge{
//	int v,next;
//}e[maxn];

/*
1.����ʽǰ�ǽ�ͼ���õ�����ֵ����Ϊ���ֵ�r
2.���֣�ÿ�ζ���dp��ʼ���ɳ�ֵ����0���ʼ����n�㣬ÿ���㶼��1-m����ֵ��p[i]-mid*s[i]
3.�ѵ�������ֻ��dp��size[u]����ֵ

���ܱ���ÿ��������f[i][j]=p[i]-mid*s[i]
��Ϊ��Щʱ�����պ�Ҫ�㹻�ĸ����������f[i][j]=p[i]-mid*s[i]��������һ���ط�����Ҫȡ2��ʱ
���2����¼(Ӧ��ƽ����������)����ֵʵ������1����������͵����˼�װȡ2ʵ��ȡ1��Ч��
*/ 
struct edge{
	int v,next;
	edge(int v,int next):v(v),next(next){
	};
};
vector<edge>e;
int k=-1;
void add(int u,int v){
	k++;
	e.push_back(edge(v,head[u]));
	head[u]=k;
//	e[++k].next=head[u];
//	head[u]=k;
//	e[k].v=v; 
}
double s[maxn],p[maxn],sums,sump,dp[maxn][maxn],mid,l,r;
int size[maxn];
//�õ���ֵf[x][i]=max(f[x][i],f[x][i-j]+f[v][j])//�Ӹ��������ȡk��������ֵ 
int m,n;
void init(){
	memset(head,-1,sizeof(head));
	scanf("%d%d",&m,&n);
	m+=1;
    for(int i=1,Ri;i<=n;i++){
    	scanf("%lf%lf%d",&s[i],&p[i],&Ri);
    	add(Ri,i);
    	sums+=s[i];
    	sump+=p[i];
    	//r=max(r,p[i]/s[i]);
    }r=2500;
}
void dfs_dp(int u){
	size[u]=1;
	dp[u][1]=p[u]-mid*s[u];
	for(int x=head[u];x!=-1;x=e[x].next){
		int v=e[x].v;
		dfs_dp(v);
		size[u]+=size[v];
		for(int i=min(size[u],m);i>=2;i--){
			for(int j=1;j<=min(size[v],i-1);j++){
				dp[u][i]=max(dp[u][i],dp[u][i-j]+dp[v][j]);
			}
		}
	}
}
bool cal(){
	for(int i=0;i<=n;i++){
		for(int j=2;j<=m;j++){
			dp[i][j]=ninf;
		}
	}
	dfs_dp(0);
	return dp[0][m]>0;
}
void solve(){
	while(r-l>1e-4){
		mid=(r+l)/2.0;
		if(cal())l=mid;
		else r=mid;
	}
	printf("%.3lf",l);
}
int main()
{
    init();
    solve();
    return 0;
}
