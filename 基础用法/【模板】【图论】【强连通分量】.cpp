#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<stack>
using namespace std;
const int maxn=1e4+7,maxm=1e5+7;
struct edge{
	int v,next;
}e[maxm];
int k=-1;
int head[maxn];
void add(int u,int v){
	e[++k].next=head[u];
	head[u]=k;
	e[k].v=v;
}
stack<int>s;
int low[maxn],dfn[maxn],vis[maxn];
int col[maxn],cnt[maxn];
int tot,mtot;
int n,m;
//1.��Ч����low[v]
//2.��Ч���γɻ�dfn[v]
//3.ȡ���� 
void tarj(int u){
	low[u]=dfn[u]=++tot;//tot����ȣ�ÿ��tarj��һ���㸳��� 
	s.push(u);vis[u]=1;
	for(int i=head[u];i!=-1;i=e[i].next){
		int v=e[i].v;
		if(!dfn[v]){//���ҵ�����ʱ��Ż��γ�dfn[v]==true���Ȿ����һ������ 
			tarj(v);
			low[u]=min(low[u],low[v]);
		}
		else if(vis[v]){//���������������ҵ��Ļ� �������֮ǰ�ҵ�����ôû��vis 
			low[u]=min(low[u],dfn[v]);
		}
	}
	int tab;
	if(low[u]==dfn[u]){//������γɵĻ���������㿪ʼȡһ�ξͿ����� 
		//����ѵ�����ǰ�ѹ���dfn���ͻᵼ��dow�仯����������ʵ����һ�����Ͳ���ѹ����
		//������һ����Ҳ�ᱻ����ǿ��ͨ 
		mtot++;//Ⱦɫ������
		do{
			tab=s.top();
			s.pop();
			vis[tab]=0;
			col[tab]=mtot;
			cnt[mtot]++;
		}while(tab!=u);
	}
}
void init(){
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		add(u,v);
	}
} 
int in[maxn],out[maxn];
void get_deg(){
	for(int u=1;u<=n;u++){
		for(int i=head[u];i!=-1;i=e[i].next){
			int v=e[i].v;
			if(col[u]!=col[v]){//u��v���������ǲ���ͬɫ
				in[col[v]]++;
				out[col[u]]++; 
			}
		}
	}
}
//case1:	ȫ�����õ�����Ҫ����ǿ��ͨ������  �� 0��ȵ����� 
//case2:	������ȣ�ʹ��������ǿ��ͨ  �� 0���ȵ�����
//case3:	��С�����ߣ�ʹ��ͼǿ��ͨ�� max(0��ȣ�0���ȣ� 
int find_out(){//Ѱ��Ψһ0���ȵĵ� 
	int time=0;
	for(int i=1;i<=mtot;i++){
		if(out[i]==0){
			if(time)return -1;
			time=i;
		}
	}
	return time;
}
bool vis2[maxn];
void solve(){
	for(int i=1;i<=n;i++){
    	if(vis2[i])continue;
    	int cl=col[i];
    	for(int j=i;j<=n;j++){
    		if(vis2[j])continue;
    		if(col[j]==cl){
    			printf("%d ",j);
    			vis2[j]=true;
    		}
    	}
    	printf("\n");
    }
}
int main()
{
    init();
    for(int i=1;i<=n;i++){
    	if(!dfn[i])tarj(i);
    }
    get_deg();
    int ans=find_out();
    return 0;
    
}
