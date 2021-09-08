#include<cstdio>
#include<algorithm>
#include<cstring> 
#include<queue>
#include<vector>
using namespace std;
const int maxn=3*1e5+7,maxm=maxn<<1;//Ҫ���������ݷ�Χ���������� 
struct edge{
	int v,w,next;
}e[maxm];

int k,head[maxn],vis[maxn],cnt;
int n,m;
typedef long long ll;
ll dis[maxn];

void add(int u,int v,int w){
	e[++k].next=head[u];
	e[k].v=v,e[k].w=w;
	head[u]=k;
}


#define M(x,y) make_pair(x,y)
typedef pair<ll,ll> pii;
priority_queue<pii,vector<pii>,greater<pii> >q;
ll tree;
void dijk(int x){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[x]=0;
	q.push(M(0,x));
	while(!q.empty() and cnt<n){//���ͼ�߱Ƚ϶࣬����ѹ��ıߺܶ࣬cnt 
		ll d=q.top().first,u=q.top().second;//Ҫ��ll�ط� 
		q.pop();
		if(vis[u])continue;vis[u]=1;cnt++;
		tree+=d;//ע�⣬���dijk���������ôcnt����Ч�ˣ���Ҫ�ã�������������һ�� 
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].v,w=e[i].w;
			
			//dijk---------------------------
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;//dijk
			//------------------------------
			
			//prim---------------------------------------
//			if(w<dis[v]){
//				dis[v]=w;//prim
			//-----------------------------------------
				q.push(M(dis[v],v));//ѡ��һ�����µ���С�ķ��� 
			}
		}
	}
	if(cnt!=n)tree=-1;
}

int main()
{
	memset(head,0,sizeof(head));
    scanf("%d%d",&n,&m);
    register int u,v,w;
    
    for(int i=1;i<=m;i++){
    	scanf("%d%d%d",&u,&v,&w);
    	add(u,v,w);
    	//add(v,u,w);
    }dijk(1);
    //prim-------------------------
//    if(tree==-1)printf("orz");
//    else printf("%lld",tree);
	//----------------------------
    
    //dijk----------------------------
    for(int i=1;i<=n;i++){
    	if(dis[i]>=0x3f3f3f3f3f3f3f3f)printf("%d ",-1);
    	//ע�⣬��ll��Ϊ�����ʱ��ֵ�Ѿ�����int�ĳ�ʼ���Ǹ��� 
    	//int 	0x3f3f3f3f
    	//ll	0x3f3f3f3f3f3f3f3f
    	else printf("%lld ",dis[i]);
    }
    //----------------------------------
    
	return 0;
}
