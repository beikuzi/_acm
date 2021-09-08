#include<iostream>
#include<stack>
#include<algorithm>
#include<cstdio>
#include<cstring> 
#include<set>
using namespace std;
const int maxn=123,maxm=10101;
typedef pair<int,int> pii;
set<int>f;
struct edge
{
	int v,next;
}e[maxm];
int k;
int head[maxn];
void add(int u,int v)
{
	k++;
	e[k].v=v;
	e[k].next=head[u];
	head[u]=k;
}//                                    最后染色情况共mtot种 
int tot,mtot,n,m;//第tot可能染色方案 ，第mtot真实染色方案 
int low[maxn],dfn[maxn],vis[maxn];//搜索深和最低深 
int col[maxn],dye[maxn];//每个点染色情况，每染色（连通）数量 
stack<int>s;
void tarj(int u)
{
	low[u]=dfn[u]=++tot;//赋予可能染色第tot方案 
	s.push(u);//以u为基制作强连通分量 
	vis[u]=1;//本次强连通分量观察标记 
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].v;
		if(!dfn[v])//没有下一个点的深度 拓扑原理？
		{//并不是，相比kosa()算法，并没有用结束时间进行第二次深搜 
			tarj(v);//得到下一点深度(把v归入tarj 
			low[u]=min(low[u],low[v]);//观察u和v谁深度小 
		} 
		else if(vis[v])low[u]=min(low[u],dfn[v]);
		//如果vis【v】成立的话
		// 就是本回合搜的强连通分量搜过v 
		//我们要观察u是否早就是个环（早就被改变了最低深 
		//u是环按u搜到的最低深来计算，u不是环按以前一节点v来算 
		
		//else  这个v他是以前的强连通分量 
	}
	int tab;//取出标记
	if(low[u]==dfn[u])//一个强连同图所有点最低深low= 其中最小深度的那个点dfn 
	{//以该点为基准取出一个强连通分量 
		mtot++;//真·第mtot染色方案 
		do
		{
			tab=s.top();s.pop();
		    vis[tab]=0;//不消除的话一个单向进入强连通的量会被同化 
		    col[tab]=mtot;//强连通打上同颜色
		    dye[mtot]++;//该染色方案点数增加 
		}
		while(tab!=u);
	} 
}
int rdu[maxn],cdu[maxn];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	f.clear();
    	while(1)
    	{
    		int y;
    		scanf("%d",&y);
    		if(y==0)break;
    		if(f.find(y)!=f.end() or i==y)continue;
    		add(i,y);
    		f.insert(y);
    	}
    }
    for(int i=1;i<=n;i++)
    {
    	if(!dfn[i])tarj(i);//当对一个点进行tarj会得到整个店的强连通
		//对于一个强连通图，你搜他的第一个点就是最低深…… 
    }
    //缩点：一个强连通分量可以视作一个点 
    for(int u=1;u<=n;u++)
	{
		for(int i=head[u];i;i=e[i].next)
		{
			int v=e[i].v;
			if(col[u]!=col[v])
			cdu[col[u]]++,//存在出度 
			rdu[col[v]]++;//存在入度 
		}
	}
	int maxdu=0;
	int rcnt=0,ccnt=0; 
	for(int i=1;i<=mtot;i++)
	{
		//cout<<dye[i]<<' '<<cdu[i]<<' '<<rdu[i]<<endl; 
		if(rdu[i]==0)rcnt++;
		if(cdu[i]==0)ccnt++;
	}
	//case1 ： 全部都得到需要进入强连通的数量  ： 0入度的数量 
	//case2 :  扩充必要结点使得整体变成强连通  ： 0出度的数量 (并不是 
	cout<<rcnt<<endl;                          //求max（0入度，0出度  √ 
	if(mtot==1)cout<<0;
	else cout<<max(rcnt,ccnt);
	return 0;
}
