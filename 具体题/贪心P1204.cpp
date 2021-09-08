#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=5050;
pair<int,int>c[maxn];
bool cmp(pair<int,int>x,pair<int,int>y){
	return x.first<y.first;
}
int main()
{
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++){
    	 scanf("%d%d",&c[i].first,&c[i].second);
    }sort(c,c+n,cmp);
    int fst=c[0].first,end=c[0].second;
    int ans1=0,ans2=0;
    for(int i=1;i<n;i++){
    	if(c[i].first<=end){//等号，因为要整数秒，所以假设左闭右开，否则两个时间都会更新错误 
    		end=max(end,c[i].second);//重叠时末尾决定 
    	}
    	else{
    		ans1=max(ans1,end-fst);//更新有人时间 
    		ans2=max(ans2,c[i].first-end);//更新 无人时间 
    		
    		end=c[i].second; 
    		fst=c[i].first;//有人时间要用 
    	}
    }
    ans1=max(ans1,end-fst);
    cout<<ans1<<' '<<ans2;
    return 0;
}
