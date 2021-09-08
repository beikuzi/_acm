#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
const int maxn=555,maxl=20,maxi=2147483647;
int k[maxl];//最初录入 
struct hp
{
	int c[maxl];
	hp()//???
	{
		memset(c,0,sizeof(c));
	}
}d[maxn],t[1];//t是存放取得的数，小于
void dout(int x)
{
	for(int j=d[x].c[0];j>=1;j--)printf("%d",d[x].c[j]);
}
void cget()
{
	memset(k,0,sizeof(k));
	memset(d,0,sizeof(d));
	string s;cin>>s;
	
	k[0]=s.length();
	for(int i=1;i<=k[0];i++)
	{
		d[i].c[1]=k[i]=int(s[k[0]-i])-48;
		d[i].c[0]=1;
		//dout(i);cout<<endl;
	}
	//d[k[0]].c[1]=k[k[0]];
	//d[k[0]].c[0]=1;//初始化dp[ k[0] ] 
}
int cmp[11]={10,7,4,6,3,8,4,7,4,1,2};
bool getnum(int m,int x,int y)
{
	memset(t,0,sizeof(t));//为甚么t不是数组就初始化不了啊 
	while(k[y]==0 and x!=y)y--;
	//10 9 8 7 6 5 4 3 2 1 0
	//   x       y
	int p=y-x+1;
	int q=p;//cout<<endl<<q<<endl;
	bool flag=1;
	
	for(int i=y;i>=x;i--)//截取应该反过来截取 
	{
		if(flag)
		{
			if(q<10)flag=0;//小于10位 
			else if(k[i]>cmp[p])//直接过掉 
			{
				return 0; 
			}
			else if(k[i]<cmp[p])flag=0;//直接判定为小于 
		}
		t[m].c[p]=k[i];
		p--;
	}t[m].c[0]=q; 
	//tout();cout<<endl;
	return 1;
}
hp operator + (const hp &x,const hp&y)
{
	hp z;
	z.c[0]=max(x.c[0],y.c[0]);
	for(int i=1;i<=z.c[0];i++)
	{
		z.c[i]+=x.c[i]+y.c[i];
		z.c[i+1]+=z.c[i]/10;
		z.c[i]%=10;
	}
	if(z.c[z.c[0]+1])z.c[0]++;
	return z; 
}
hp max(const hp &x,const hp &y)
{
	if(x.c[0]>y.c[0])return x;
	else if (x.c[0]<y.c[0])return y;
	for(int i=x.c[0];i>=1;i--)
	{
		if(x.c[i]>y.c[i])return x;
		else if(x.c[i]<y.c[i])return y;
	}
	return x;
}
int main()
{
    int n;cin>>n;
    
    for(int i=1;i<=n;i++)
    {
    	cget();
    	//getnum(0,1,4);tout();
    	//kout();
    	//ctest();
    	//for(int j=2;j<=k[0];j++)
    	for(int x=k[0]-1;x>=1;x--)
    	{
    		//for(int k=max(1,j-9)+1;k<j;k++)
			for(int y=min(k[0],x+9);y>=x;y--)//10位的话就是1~10 
    		{
    			if(getnum(0,x,y))
    			{
    				//tout();cout<<endl;
    				//1ctest();
    					d[x]=max(d[x],d[y+1]+t[0]);
    				//dout(x);cout<<" "<<x<<endl;
    			}
    		}
    	}
    	dout(1);
    	cout<<endl;
    }
    return 0;
}
