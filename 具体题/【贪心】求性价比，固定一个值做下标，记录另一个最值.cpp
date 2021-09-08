#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m;
const int maxm=1010,maxs=1010;
int c[maxs];//记录i寿命下最小价格 
bool b[maxs];//表示当前寿命无法成立 
//因为要用最小寿命的那个零件来做整体的寿命
//就能想到寿命做下标 
struct sp{
	int s,p;
}f[maxm];//记录 
bool cmp(sp x,sp y){
	if(x.p!=y.p)return x.p<y.p;
	return x.s<y.s; 
} 
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
    	for(int j=0;j<m;j++){
    		scanf("%d%d",&f[j].s,&f[j].p);
    	}sort(f,f+m,cmp);
    	int loc=0;
    	f[m].s=1919810;
    	for(int k=1;k<=1000;k++){
    		if(b[k])break;//这个寿命往上都不行 
    		while(f[loc].s<k)loc++;//如果元件寿命小于，达不到目的，那就要下一个 
    		if(loc==m)b[k]=true;
    		else c[k]+=f[loc].p;
    	}
    }
    //如果觉得小数麻烦的话，同时记录最优的寿命和价格，然后把分式变成乘法就不容易出错 
    long long price=1;
    long long save=0;
    for(int i=1;i<=1000;i++){
    	if(b[i])continue;
    	if(price*i>save*c[i]){//单位价值更高 
    		price=c[i];
			save= i;
    	}
    	if(price*i==save*c[i]){
    		if(price>c[i]){
    			price=c[i];
    			save=i;
    		}
    	}
    }
    cout<<price;
    return 0;
}
