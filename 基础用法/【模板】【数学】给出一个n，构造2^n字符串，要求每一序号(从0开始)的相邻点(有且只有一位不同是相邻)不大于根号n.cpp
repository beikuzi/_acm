#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=(1<<23)+7;
int vis[maxn],ans[maxn];
int main()
{
    int n;scanf("%d",&n);
    int val,next_val,max_cnt=sqrt(n),cnt,bit;
    if(max_cnt*max_cnt!=n)max_cnt++;
    //cout<<max_cnt<<endl;
    for(int i=0;i<=(1<<n)-1;i++){//0,1,3,7,���ڶ�����ÿһλ 
		//cout<<i<<endl;
		vis[i]=1;val=i,cnt=0;//�ιۣ����� 
    	for(int j=0;j<n;j++){//���������������ͬ�ı�� 
    		int bit=val%2;//val��ʾ����Ҫ���ƶ���λ 
    		val>>=1;
    		next_val=i-(bit<<j)+((bit^1)<<j);//������bitλ����ô�ͻ�ԭ�� 
    		//cout<<next_val<<' '<<cnt<<endl;
    		if(vis[next_val])continue; 
			
			vis[next_val]=1;
			if(cnt<=max_cnt){
				ans[next_val]=ans[i];
				cnt++;
			}
			else ans[next_val]=ans[i]^1;
    	} 
    }
    for(int i=0;i<=(1<<n)-1;i++){
    	printf("%d",ans[(1<<i)-1]);
    }
    return 0;
    
    /*
	nά��ͼ
	��2��n�η�����
	ÿ���㶼������0��2^n-1
	�������������ڵģ�����ֻ��һλ��ͬ
	����ÿ������u���������������ͣ�0��1
	����ÿ�����ͣ����ڵĵ㲻���Գ�������n��(����ȡ��
	��n�����⹹���һ��2^n�������ַ� 
	������iö��ÿһ��λ����ö�����λ����ŵ�ÿһ��λ
		��ŵ�ÿһ��λö���෴��Ȼ��������Ϊ��ͬ�������ͷ����� 
	*/
}
