#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1e6+7;
int c[maxn];
int main()
{
    int fst=2e9,end=-2e9;
    int n;scanf("%d",&n);
    int l,r;
    //从a到b-1全部增加挤奶人数1 ,第b秒不挤奶 
    for(int i=1;i<=n;i++){
    	scanf("%d%d",&l,&r);
    	c[l]++;
    	c[r]--;
    	fst=min(fst,l);
    	end=max(end,r);
    }
    int Bfst=fst;
    int ans1=0,ans2=0;//无人最长时间，有人时间 
    bool b=1;//0表示不在，1表示在 ,由于已经寻找了fst，必定以有人为开头 
    for(int i=fst;i<=end;i++){
    	c[i]+=c[i-1];
    	if(bool(c[i])!=b or i==end){//如果挤奶情况变化 
	    	if(b==0)ans1=max(ans1,i-Bfst);//从无人时间进入有人,结算无人时间 
			if(b==1)ans2=max(ans2,i-Bfst);//从有人时间进入无人,结算有人时间 
    		Bfst=i;
    		b=!b;
    	}//有人时间和无人时间轮流交替来算 
    } 
    cout<<ans2<<' '<<ans1;
	return 0; 
}
