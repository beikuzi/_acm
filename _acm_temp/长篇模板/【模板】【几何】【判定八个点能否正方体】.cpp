#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<vector>
#include<queue>
using namespace std;
inline int readi(){
	int x=0,b=1;
	char ch=getchar();
	while('0'>ch or ch>'9'){
		if(ch=='-')b=-1;
		ch=getchar();
	}
	while('0'<=ch and ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}return x*b;
}
int x[10],y[10],z[10];
void init(){
	for(int i=1;i<=8;i++){
        x[i]=readi(),y[i]=readi(),z[i]=readi();
    }
}
int getdis(int a,int b){
	return (x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b])+(z[a]-z[b])*(z[a]-z[b]);
}
int dis[10];
bool check()
{
    for(int i=1;i<=8;i++){
    	int cnt=1;
    	for(int j=1;j<=8;j++){
	        if(i!=j)dis[cnt++]=getdis(i,j);
	    }
	    sort(dis+1,dis+8);
	    if(dis[1]==0) return false;
	    if(dis[1]!=dis[2]||dis[1]!=dis[3]||dis[2]!=dis[3]) return false;//三短边相等 
	    if(dis[4]!=dis[5]||dis[4]!=dis[6]||dis[5]!=dis[6]) return false;//三中边相等 
	    if(dis[1]+dis[4]!=dis[7]) return false;//沟谷定理 
    }
    return true;
}

int main()
{
	int t=readi();
	while(t--){
		init();
		if(check())cout<<"YES"<<'\n';
		else cout<<"NO"<<'\n';
		for(int i=1;i<=7;i++){
			//cout<<dis[i]<<endl;
		}
	}
    return 0;
}
