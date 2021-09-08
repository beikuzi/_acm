#include<iostream>
#include<algorithm>
using namespace std;
int maxn=0,minn=0;
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
    	int x;
    	cin>>x;//给定位置 
    	minn=max(minn,min(x,n-x+1));//往反方向or往前走 
    	maxn=max(maxn,max(x,n-x+1));
    }
    cout<<minn<<' '<<maxn;
    return 0;
}
