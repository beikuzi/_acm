#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<vector>
#include<queue>
using namespace std;
//дһ�ֽṹ�壬����һ����ֵ�󣬼�¼�����е���ֵ�Ͷ�Ӧλ��
//����ѹ��ṹ���У���¼�����ܳ��Ⱥ�ֵ������0��ʱ���ʾ����������С�������,x��ʾx������С����ǰ�� 
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
	}
	return x*b;
}
struct scino{
	string dec;//С������
	int pt;//ָ������ 
	scino(string s){
		int len=s.length();
		int x=-1,y=len-1,z=s.find('.');//���ȡ��ǰ�����ұ�ȥ���󵼣�С����λ�� 
		for(int i=0;i<len;i++){
			if(s[i]!='0' and s[i]!='.'){
				x=i;break;
			}
		}
		for(int i=len-1;i>=0;i--){
			if(s[i]!='0' and s[i]!='.'){
				y=i;break;
			}
		}
		pt=0; 
		if(x==-1)dec="0";//�պ���0 
		else if(z-x==1)while(x<=y)dec=dec+s[x++];//�պþ���һ����ѧС��
		else{ 
			dec=s[x];//С����ǰ��������һλ 
			if(z-x>1 or z==-1){//С����ǰ���ж���������û��С���� 
				pt=((z==-1)?len:z)-1-x;//�õ�ָ������
				if(pt==0)return;
			}
			else pt=z-x;//С�������Ҷ���ǰ��0�����Ե��� 
			if(x!=y)dec=dec+'.'; //�ⲿ��֮ǰ�Ǵ���С����ǰ��Ķ��� 
			for(int i=x+1;i<=y;i++){
				if(s[i]=='.')continue;
				dec=dec+s[i];//������������ 
			}
		}
	}
	void deal(int x){//��С��λ�ĳ�ָ��λ��������С���� 
		int len=dec.length();
		if(len>=x){
			dec=dec.substr(0,x);
		}
		else{
			if(len==1){
				len=2;
				dec=dec+'.';
			}
			while(len++<x){
				dec=dec+'0';
			}
		}
	}
}; 
int n;
void solve(){
	n=readi();
	string s;
	cin>>s;
	scino x(s);
	cin>>s;
	scino y(s);
	if(x.dec!="0")x.pt++;
	if(y.dec!="0")y.pt++;
	x.deal(n+1);
	y.deal(n+1);
	
	if(x.dec==y.dec){
		printf("YES 0.");
		string temp=x.dec;
		int len=temp.length();
		for(int i=0;i<len;i++){
			if(temp[i]=='.')continue;
			printf("%c",temp[i]);
		}
		printf("*10^%d",x.pt);
	}
	else{
		printf("NO 0.");
		string temp=x.dec;
		int len=temp.length();
		for(int i=0;i<len;i++){
			if(temp[i]=='.')continue;
			printf("%c",temp[i]);
		}
		printf("*10^%d 0.",x.pt);
		temp=y.dec;
		len=temp.length();
		for(int i=0;i<len;i++){
			if(temp[i]=='.')continue;
			printf("%c",temp[i]);
		}
		printf("*10^%d",y.pt);
	}
}
int main()
{
	solve();
    return 0;
}
