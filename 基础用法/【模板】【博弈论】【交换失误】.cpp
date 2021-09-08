#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
typedef long long ll;
//轮流由a或b来开局，成功开局者+1，失误对方+1，问双方得分a和b的情况下，有几种失误次数
 
//特判0，然后如果发球总数是偶数，所有的 值相差2，因为min(a,b) 是可以稳定失误的 ，一失误就要双方都失误来抵消 
//如果是奇数，谁先发球就可以决定失误/不失误， 所有值相差1 
//cmin=abs(b-a)/2;//都不失误，剩下失误强制一半,向下取整 
//cmax=(abs(b-a)+1)/2+min(a,b)*2;//min(a,b）都失误,强制一半向上取整 
void solve(){
	int a,b;
	scanf("%d%d",&a,&b);
    int cmin,cmax;
    cmin=abs(b-a)/2;//都不失误，剩下失误强制一半,向下取整 
    cmax=(abs(b-a)+1)/2+min(a,b)*2;//min(a,b）都失误,强制一半向上取整 
    int cnt;
    if(a==0 or b==0){
    	int n=a+b;
    	if(n%2){
    		printf("2\n%d %d\n",n/2,n/2+1);
    	}
    	else{
    		printf("1\n%d\n",n/2);
    	}
    	return;
    }
    if((a+b)%2){
    	cnt=cmax-cmin+1;
    	printf("%d\n",cnt);
    	for(int i=cmin;i<=cmax;i++){
    		printf("%d ",i);
   		}
    }
    else{
    	
    	cnt=(cmax-cmin+2)/2;
    	printf("%d\n",cnt);
    	for(int i=cmin;i<=cmax;i+=2){
    		printf("%d ",i);
   		}
    }
    printf("\n");
} 
int main()
{
    int t;scanf("%d",&t);
    while(t--){
		solve();
    }
    return 0;
}
