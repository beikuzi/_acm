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
    	if(c[i].first<=end){//�Ⱥţ���ΪҪ�����룬���Լ�������ҿ�����������ʱ�䶼����´��� 
    		end=max(end,c[i].second);//�ص�ʱĩβ���� 
    	}
    	else{
    		ans1=max(ans1,end-fst);//��������ʱ�� 
    		ans2=max(ans2,c[i].first-end);//���� ����ʱ�� 
    		
    		end=c[i].second; 
    		fst=c[i].first;//����ʱ��Ҫ�� 
    	}
    }
    ans1=max(ans1,end-fst);
    cout<<ans1<<' '<<ans2;
    return 0;
}
