#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
typedef long long ll;
int n,m;
const int maxn=1e5+7,maxm=maxn*3;
const int inf=1e8;
int cnt[maxn],dis[maxn],head[maxn];
int k;
queue<int>q;
struct edge{
	int v,w,next;
}e[maxm];
void add(int u,int v,int w){
	e[++k].next=head[u];
	head[u]=k;
	e[k].v=v,e[k].w=w;
}
//����ԭ����ͼ���ܲ�����ȫ��ͨ�ģ������·���ҷ���ȡ��ʱ��ȡ�ò��Ǿֲ��ֵ����ȫ���ֵ������ԭ���ϳ����� 
//���TLE�����԰ѳ���ԭ��Ķ��룬�����ߵĶ��뷽ʽ�ı�ɵ���
//(��ѧ�Ż�����Ϊspfa��djik���ڵ����ٵĻ��ڣ�����Щ���ֿ����ر���ͨ���ر�ǿ�����һ��ǵȼ�ֵ���������ǲ��ַ�������ر�� 
//ע�⣺��ӳ���Դ��Ҳ��Ҫ�ߣ� ����Ҫ��ԭ����3�� 
bool spfa(int x){
	memset(cnt,0,sizeof(cnt));
	//memset(dis,0,sizeof(dis));
	//for(int i=1;i<=n;i++)dis[i]=1; 
	q.push(x);dis[x]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		if(cnt[u]>n+1)return true;
		for(int i=head[u];i!=-1;i=e[i].next){
			int v=e[i].v,w=e[i].w;
			if(dis[v]<dis[u]+w){
				dis[v]=dis[u]+w;
				cnt[v]=cnt[u]+1;
				q.push(v);
			}
		}
	}
	return false;
}
int main()
{
	memset(head,-1,sizeof(head));
    scanf("%d%d",&n,&m);
    int u,v,w;
    for(int i=1;i<=m;i++){
    	scanf("%d%d%d",&w,&u,&v);
    	//���·��д��v<=u+w	ѹ��u��v��w
		//�·��д��v>=u+w		ѹ��u��v��w 
    	if(w==1){
    		add(u,v,0);
    		add(v,u,0);
    	}
    	else if(w==2){
    		add(u,v,1);
    		if(u==v){
    			cout<<-1;return 0;
    		}
    	}
    	else if(w==3)add(v,u,0);
    	else if(w==4){
    		add(v,u,1);
    		if(v==u){
    			cout<<-1;return 0;
    		}
    	}
    	else if(w==5)add(u,v,0);
	}
    for(int i=n;i>=1;i--){
    	add(0,i,0);
    }
	if(spfa(0)){
		cout<<-1;
		return 0;
	}
    ll ans=0;	
    for(int i=1;i<=n;i++){
    	ans+=dis[i];
    }
    printf("%lld",ans);
    return 0;
}
