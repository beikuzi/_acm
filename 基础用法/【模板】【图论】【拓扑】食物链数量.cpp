#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
using namespace std;
queue<int>q;
const int maxn=5050,maxm=5e5+7;
const int mod=80112002;
typedef long long ll;
int n,m,in[maxn],out[maxn];
int f[maxn];
struct edge{
	int u,v,next;
}e[maxm];
int k=-1,head[maxn];
void add(int u,int v){
	e[++k].next=head[u];
	head[u]=k;
	e[k].u=u,e[k].v=v;
}
int ans;
void init(){
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
    int u,v;
    for(int i=1;i<=m;i++){
    	scanf("%d%d",&u,&v);
    	add(u,v); 
    	in[v]++,out[u]++;
    }
}
int main()
{
    init();
    for(int i=1;i<=n;i++){
    	if(in[i]==0){
    		//�Ӷ�����ȡ���˳����ʵ����һ���������� 
    		f[i]=1;
    		q.push(i);
    	}
    }
    while(!q.empty()){
    	int u=q.front();
    	q.pop();
    	for(int i=head[u];i!=-1;i=e[i].next){
    		int v=e[i].v;
    		f[v]+=f[u];//��̬�滮�����������Ϊ0��Ϊ��ʼ�㣬Ȼ���ۼӼ̳���ȥ 
    		f[v]%=mod;
    		in[v]--;
    		if(in[v]==0){
    			if(out[v]==0){//�������㴦����ͷ 
    				ans+=f[v];
    				ans%=mod;
    			}
    			else q.push(v);//��������ȫ�����꣬�ٵ�����ʼdp̬���� 
    		}
    	}
    }
    printf("%d",ans);
    return 0;
}
