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
}//                                    ���Ⱦɫ�����mtot�� 
int tot,mtot,n,m;//��tot����Ⱦɫ���� ����mtot��ʵȾɫ���� 
int low[maxn],dfn[maxn],vis[maxn];//������������ 
int col[maxn],dye[maxn];//ÿ����Ⱦɫ�����ÿȾɫ����ͨ������ 
stack<int>s;
void tarj(int u)
{
	low[u]=dfn[u]=++tot;//�������Ⱦɫ��tot���� 
	s.push(u);//��uΪ������ǿ��ͨ���� 
	vis[u]=1;//����ǿ��ͨ�����۲��� 
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].v;
		if(!dfn[v])//û����һ�������� ����ԭ��
		{//�����ǣ����kosa()�㷨����û���ý���ʱ����еڶ������� 
			tarj(v);//�õ���һ�����(��v����tarj 
			low[u]=min(low[u],low[v]);//�۲�u��v˭���С 
		} 
		else if(vis[v])low[u]=min(low[u],dfn[v]);
		//���vis��v�������Ļ�
		// ���Ǳ��غ��ѵ�ǿ��ͨ�����ѹ�v 
		//����Ҫ�۲�u�Ƿ�����Ǹ�������ͱ��ı�������� 
		//u�ǻ���u�ѵ�������������㣬u���ǻ�����ǰһ�ڵ�v���� 
		
		//else  ���v������ǰ��ǿ��ͨ���� 
	}
	int tab;//ȡ�����
	if(low[u]==dfn[u])//һ��ǿ��ͬͼ���е������low= ������С��ȵ��Ǹ���dfn 
	{//�Ըõ�Ϊ��׼ȡ��һ��ǿ��ͨ���� 
		mtot++;//�桤��mtotȾɫ���� 
		do
		{
			tab=s.top();s.pop();
		    vis[tab]=0;//�������Ļ�һ���������ǿ��ͨ�����ᱻͬ�� 
		    col[tab]=mtot;//ǿ��ͨ����ͬ��ɫ
		    dye[mtot]++;//��Ⱦɫ������������ 
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
    	if(!dfn[i])tarj(i);//����һ�������tarj��õ��������ǿ��ͨ
		//����һ��ǿ��ͨͼ���������ĵ�һ������������� 
    }
    //���㣺һ��ǿ��ͨ������������һ���� 
    for(int u=1;u<=n;u++)
	{
		for(int i=head[u];i;i=e[i].next)
		{
			int v=e[i].v;
			if(col[u]!=col[v])
			cdu[col[u]]++,//���ڳ��� 
			rdu[col[v]]++;//������� 
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
	//case1 �� ȫ�����õ���Ҫ����ǿ��ͨ������  �� 0��ȵ����� 
	//case2 :  �����Ҫ���ʹ��������ǿ��ͨ  �� 0���ȵ����� (������ 
	cout<<rcnt<<endl;                          //��max��0��ȣ�0����  �� 
	if(mtot==1)cout<<0;
	else cout<<max(rcnt,ccnt);
	return 0;
}
