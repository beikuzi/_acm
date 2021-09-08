#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int n,m,t;
const int maxn=1010;
char c[maxn][maxn],d[maxn][maxn];
bool b[maxn][maxn];
typedef pair<int,int>pii;
void testd(){
	for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		printf("%c",d[i][j]);
    	}printf("\n");
    }
}
void testc(){
	for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		printf("%c",c[i][j]);
    	}printf("\n");
    }
}
queue<pii>q,p;
#define M(x,y) make_pair(x,y)

void pre_bfs(){
	q.push(M(1,1));
	while(!q.empty()){
		int x=q.front().first,y=q.front().second;
		q.pop();
		if(x<1 or y<1 or x>n or y>m)continue;
		if(b[x][y] or d[x][y]=='#')continue;
		b[x][y]=1;d[x][y]='#';
		q.push(M(x-1,y));
		q.push(M(x+1,y));
		q.push(M(x,y-1));
		q.push(M(x,y+1));
	}
}
void bfs(int x0,int y0){
	int cnt=0;
	q.push(M(x0,y0));
	while(!q.empty()){
		int x=q.front().first,y=q.front().second;
		q.pop();
		if(x<1 or y<1 or x>n or y>m)continue;
		if(b[x][y] or d[x][y]=='#')continue;
		//cout<<x<<' '<<y<<endl;
		p.push(M(x,y));cnt++;
		b[x][y]=1;d[x][y]='#';
		q.push(M(x-1,y));
		q.push(M(x+1,y));
		q.push(M(x,y-1));
		q.push(M(x,y+1));
	}
	//cout<<cnt<<' '<<t<<endl;
	//testd();
	//testc();
	if(cnt<t){
	
		while(!p.empty()){
			int x=p.front().first,y=p.front().second;
			c[x][y]='#';
			p.pop();
		}
	}
	else{
		while(!p.empty())p.pop();
	}
}

int main()
{
    scanf("%d%d%d",&n,&m,&t);
    for(int i=1;i<=n;i++){
    	getchar();
    	for(int j=1;j<=m;j++){
    		scanf("%c",&c[i][j]);
    		d[i][j]=c[i][j];
    		if(c[i][j]=='#')b[i][j]=true;
    	}
    }
    pre_bfs();
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		if(d[i][j]=='.')bfs(i,j);
    	}
    }
    
    //test();
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		printf("%c",c[i][j]);
    	}printf("\n");
    }
    return 0;
}
