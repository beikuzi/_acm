#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=333;
long long ans[maxn][maxn];
int n,H,S;
int main()
{
    scanf("%d%d%d",&n,&H,&S);
    int h,s,w;
    for(int i=1;i<=n;i++){
    	scanf("%d%d%d",&h,&s,&w);
    	if(h+s>=H+S)continue;
    	for(int j=H;j>h;j--){
    		for(int k=S;k>=0;k--){
    			if(k>=s){
    				ans[j][k]=max(ans[j][k],ans[j-h][k-s]+w);
    			}
    			else{
    				if(j+k<=h+s)break;
    				ans[j][k]=max(ans[j][k],ans[j+k-h-s][0]+w);
    			}
    		}
    	}
    }
    printf("%lld",ans[H][S]);
    return 0;
}
