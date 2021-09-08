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
    for(int i=0;i<=(1<<n)-1;i++){//0,1,3,7,对于二进制每一位 
		//cout<<i<<endl;
		vis[i]=1;val=i,cnt=0;//参观，并且 
    	for(int j=0;j<n;j++){//都尽量往后打上相同的标记 
    		int bit=val%2;//val表示的是要右移多少位 
    		val>>=1;
    		next_val=i-(bit<<j)+((bit^1)<<j);//假如有bit位，那么就还原成 
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
	n维的图
	有2的n次方个点
	每个点都可以是0到2^n-1
	两个顶点是相邻的：他们只有一位不同
	对于每个顶点u，他们有两种类型，0或1
	对于每种类型，相邻的点不可以超过根号n个(向上取整
	给n，随意构造出一串2^n这样的字符 
	做法：i枚举每一个位，并枚举这个位的序号的每一个位
		序号的每一个位枚举相反，然后让他视为相同，超过就反过来 
	*/
}
