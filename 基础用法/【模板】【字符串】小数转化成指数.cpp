#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
string s;
void cal(){
	int len=s.length();
	int x=-1,y=len-1,z=s.find('.');
	for(int i=0;i<len;i++){
		if(s[i]!='0' and s[i]!='.'){
			x=i;
			break;
		}
	}
	for(int i=len-1;i>=0;i--){
		if(s[i]!='0' and s[i]!='.'){
			y=i;break;
		}
	}
	if(x==-1){//0.0 0. .0
		cout<<0;return;
	}
	//cout<<y<<z<<endl;
	if(z-x==1){//1.234 1. 1.01 
		while(x<=y)cout<<s[x++];
		return;
	}
	int cnt=0;
	if(z-x>1 or z==-1){//12.34,12. 12.01 1234 100. 1 1000
		cout<<s[x];
		if(z==-1)cnt=len-1-x;//1234
		else cnt=z-1-x;//12.34
		if(cnt==0)return;//1-9 
		if(x!=y)cout<<'.';
		for(int i=x+1;i<=y;i++){
			if(s[i]=='.')continue;
			cout<<s[i];
		}cout<<'E'<<cnt;
		return;
	}
	else{//.1 .123 .0101
		cnt=z-x;
		cout<<s[x];
		if(x!=y)cout<<'.';
		for(int i=x+1;i<=y;i++){
			cout<<s[i];
		}cout<<'E'<<cnt;
		return;
		
	}
} 
int main()
{
    cin>>s;
    cal();
    return 0;
}
