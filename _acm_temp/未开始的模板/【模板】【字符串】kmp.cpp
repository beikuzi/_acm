#include<iostream>
#include<algorithm>
#include<cstdio> 
using namespace std;
int n,ans;
string s[10086];
int main()
{
    int t;cin>>t;
    while(t--){
    	cin>>n;
    	ans=0;
    	for(int i=1;i<=n;i++){
    		cin>>s[i];
    	}cin>>s[0];
    	for(int i=1;i<=n;i++){
    		if(s[0].find(s[i])!=-1)ans++;
    	}
    	cout<<ans;
    	if(t)cout<<'\n';
    }
}
