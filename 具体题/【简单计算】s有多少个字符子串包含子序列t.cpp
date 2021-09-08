#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=123;
int ok[maxn];
long long ans=0;
string s,t;
int slen,tlen;
void test(){
	for(int i=0;i<tlen;i++){
		cout<<ok[i]<<' ';
	}cout<<endl;
}
void cal(){
	cin>>s>>t;
	slen=s.length(),tlen=t.length();
	int x=0,y=0;//x是字符串s匹配第一个字符的位置，y是与当前t的值匹配在s的位置
	while(1){
		
		for(int i=0;i<tlen;i++){
			if(ok[i])break;//如果已经不用搜这个字符 
			while(t[i]!=s[y]){//t的字符和s的字符不匹配 
				y++;//往后移动一位
				if(y>=slen)return;//算完了 
			}
			if(y>=ok[i+1])ok[i+1]=0;//由于y的移动导致超过下一个值，下一个要重新匹配 
			ok[i]=y;//记录匹配的位置 
			y++;
		}
		//计算方法不重复：假设一边带这个字符(+1),一边带上0这种可能 （+1 
		ans+=(ok[0]-x+1)*(slen-ok[tlen-1]);//由于偏移一位，所以刚好后面部分自带+1，前面部分自带加一和处于后一位抵消
		x=ok[0]+1;y=x;//允许搜的位置往后 
		ok[0]=false;//从新搜第一个的位置
		
	}
} 
int main(){
	cal();
	cout<<ans?ans:-1;
	return 0;
} 
