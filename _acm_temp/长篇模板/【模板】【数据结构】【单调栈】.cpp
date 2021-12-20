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
#define int long long
const int maxn=1e5+7;
int c[maxn],top=0;//¶ÁÈë 
int n;
int st[maxn];//stack
int l[maxn],r[maxn];
void init(){
	n=readi();
	for(int i=1;i<=n;i++)c[i]=readi();
}
void mstl(){
	
	for(int i=n;i>=1;i--){
		while(top and c[st[top]]>c[i]){
			l[st[top--]]=i+1;
		}
		st[++top]=i;
	}
	while(top){
		l[st[top--]]=1;
	}
}
void mstr(){
	for(int i=1;i<=n;i++){
		while(top and c[st[top]]>c[i]){
			r[st[top--]]=i-1;
		}
		st[++top]=i;
	}
	while(top){
		r[st[top--]]=n;
	}
}
signed main()
{
    init();
    mstr();
    mstl();
    for(int i=1;i<=n;i++)c[i]+=c[i-1];
    int res=0;
    int lt=1,rt=n;
    for(int i=1;i<=n;i++){
    	if((c[i]-c[i-1])*(c[r[i]]-c[l[i]-1])>=res){
    		res=(c[i]-c[i-1])*(c[r[i]]-c[l[i]-1]);
    		lt=l[i],rt=r[i];
    	}
    }
    cout<<res<<'\n'<<lt<<' '<<rt;
    return 0;
}
