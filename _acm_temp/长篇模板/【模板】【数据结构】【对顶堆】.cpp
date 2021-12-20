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
priority_queue<int>p;//大根堆 
priority_queue<int,vector<int>,greater<int> >q;//小根堆 
map<string,int>mp;
int cnt1,cnt2;
int main()
{
	int n=readi();
	//mp["Pop"]=1;
	mp["Push"]=2;
	mp["PeekMedian"]=3;
	while(n--){
		string s;
		cin>>s;
		int val=mp[s];
		switch(val){
			case 3:{
				if(p.empty())printf("Invalid\n");
				else{
					printf("%d\n",p.top());
					//p.pop();
				}
				break;
			}
			case 2:{
				cnt2++;
				int t=readi();
				q.push(t);
				break;
			}
			case 1:{
				
				break;
			}
		}
		while(cnt1<cnt2){
			cnt1++;
			cnt2--;
			p.push(q.top());
			q.pop();
		}
	}
	while(!p.empty())cout<<p.top(),p.pop();
    return 0;
}
