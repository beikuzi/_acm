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
	int x=0,y=0;//x���ַ���sƥ���һ���ַ���λ�ã�y���뵱ǰt��ֵƥ����s��λ��
	while(1){
		
		for(int i=0;i<tlen;i++){
			if(ok[i])break;//����Ѿ�����������ַ� 
			while(t[i]!=s[y]){//t���ַ���s���ַ���ƥ�� 
				y++;//�����ƶ�һλ
				if(y>=slen)return;//������ 
			}
			if(y>=ok[i+1])ok[i+1]=0;//����y���ƶ����³�����һ��ֵ����һ��Ҫ����ƥ�� 
			ok[i]=y;//��¼ƥ���λ�� 
			y++;
		}
		//���㷽�����ظ�������һ�ߴ�����ַ�(+1),һ�ߴ���0���ֿ��� ��+1 
		ans+=(ok[0]-x+1)*(slen-ok[tlen-1]);//����ƫ��һλ�����Ըպú��沿���Դ�+1��ǰ�沿���Դ���һ�ʹ��ں�һλ����
		x=ok[0]+1;y=x;//�����ѵ�λ������ 
		ok[0]=false;//�����ѵ�һ����λ��
		
	}
} 
int main(){
	cal();
	cout<<ans?ans:-1;
	return 0;
} 
