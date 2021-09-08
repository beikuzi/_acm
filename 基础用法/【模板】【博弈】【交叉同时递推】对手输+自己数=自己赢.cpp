#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=5050,maxm=123;
int n,m;
bool aw[maxn],bw[maxn];
int at[maxm],bt[maxm];
//1.拿不到	L
//2.拿了，之后别人输	W
//3.根本拿不到别人输	L 
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
    	scanf("%d",&at[i]);
    }
    for(int i=1;i<=m;i++){
    	scanf("%d",&bt[i]);
    }
    bool win;
    for(int i=1;i<=n;i++){
    	win=false;
    	for(int j=1;j<=m;j++){
    		if(at[j]>i)break;
    		if(bw[i-at[j]]==0){
    			win=true;
    			break;
    		}
    	}
    	aw[i]=win;
    	
    	win=false;
    	for(int j=1;j<=m;j++){
    		if(bt[j]>i)break;
    		if(aw[i-bt[j]]==0){
    			win=true;
    			break;
    		}
    	}
    	bw[i]=win;
    }
    if(aw[n])printf("Long Long nb!");
    else printf("Mao Mao nb!");
    return 0;
}
