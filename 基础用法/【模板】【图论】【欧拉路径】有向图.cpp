#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<queue>
#include<stack>
using namespace std;
//ŷ��·����һ��·�� ǡ�� �������б�1��
//ŷ����·��ŷ��·���γɵĻ�·
//����Ҫ���ظ���·����±�������·�������Ҫ��ԭ����ǻ�· 
const int maxn=1e5+7,maxm=2e5+7;
int in[maxn],out[maxn];
int n,m;
typedef pair<int,int>pii;
#define M make_pair
priority_queue<int,vector<int>,greater<int> >q[maxn]; 
//priority_queue<int>q[maxn];
void init(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		out[u]++;
		in[v]++;
		q[u].push(v);//������С�ֵ���ѹ���¸�Ŀ��,������ջ������ŷ��·������ջ 
	}
}
//�������ֵ�����С�ĵ���ӣ����Ų�������Ϊʧȥ�����еĳ��ȶ�����ջ��Խ���ѵ�������Ϊ0�Ļ���Խ��Խ��������ջ
//��֮���Ǳ�����ĺͳ����ٵģ�����Խ�������ҪԽ�� 
//����������ŷ��·������Ҫôȥ��һ���ֵ���С�Ļ���Ҫô�ѵ��� 
//���һ����������߱�ȥ�����൱��ȫ����ȡ�����-1 
stack<int>ans;
void dfs(int u){
	while(!q[u].empty()){
		int v=q[u].top();q[u].pop();
		dfs(v); 
	}
	ans.push(u);
}
//����ͼ�ж�����㣺��ȱȳ�����1���յ㣺�ȳ��ȶ�1�������ĵ���ȳ���һ�� 
//����ͼ��·�����е���ȵ��ڳ���
//����ͼ·����2�����������������ż��
//����ͼ��·��ȫż��
//ֻ�����ж������Ժ����ȥ�� ,�����ò��鼯ȥ�ж����������ͨ,���������Ϊ�������ͨ 
bool solve(){
	int srt=-1,end=-1,cnt=0;
	for(int i=1;i<=n;i++){
		if(in[i]!=out[i]){
			cnt++;
			if(in[i]==out[i]-1)srt=i;
			else if(in[i]==out[i]+1)end=i;
		}
	}
	if(cnt==0)srt=end=1;
	if(cnt!=0 and cnt!=2){//���ǻ�������1��1�� 
		return false;
	}
	if(srt==-1 or end==-1)return false;
	dfs(srt);
	while(!ans.empty()){
		printf("%d ",ans.top());
		ans.pop();
	}
	return true;
}
int main()
{
    init();
    if(!solve())printf("No");
    return 0;
}
