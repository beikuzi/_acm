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
    //��a��b-1ȫ�����Ӽ�������1 ,��b�벻���� 
    for(int i=1;i<=n;i++){
    	scanf("%d%d",&l,&r);
    	c[l]++;
    	c[r]--;
    	fst=min(fst,l);
    	end=max(end,r);
    }
    int Bfst=fst;
    int ans1=0,ans2=0;//�����ʱ�䣬����ʱ�� 
    bool b=1;//0��ʾ���ڣ�1��ʾ�� ,�����Ѿ�Ѱ����fst���ض�������Ϊ��ͷ 
    for(int i=fst;i<=end;i++){
    	c[i]+=c[i-1];
    	if(bool(c[i])!=b or i==end){//�����������仯 
	    	if(b==0)ans1=max(ans1,i-Bfst);//������ʱ���������,��������ʱ�� 
			if(b==1)ans2=max(ans2,i-Bfst);//������ʱ���������,��������ʱ�� 
    		Bfst=i;
    		b=!b;
    	}//����ʱ�������ʱ�������������� 
    } 
    cout<<ans2<<' '<<ans1;
	return 0; 
}
