#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define lint long long
using namespace std;

bool vis[2000000];
lint c[2000000];

int main()
{
  freopen("10791.in","r",stdin);
  freopen("10791.out","w",stdout);
  lint n,i,j,k,m;
  m=(lint)sqrt(1.0*((lint)1<<33));
  memset(vis,0,sizeof(vis));
  lint p=0;
  for (i=2;i<=m;i++)                    //如果要筛到m，i就一定要循环到m，不能只枚举到sqrt(m)
    if (!vis[i])                        //之前的写法可以枚举到sqrt(m)是因为最后还要扫描一遍vis数组。这种写法直接保存素数。
    {
      c[++p]=i;
      for (j=i*i;j<=m;j+=i)
        vis[j]=true;
    }
  lint ii=0;
  while(scanf("%lld",&n)==1&&n)
  {
    printf("Case %lld: ",++ii);
	lint ans=0;
	bool flag=false;
    lint tmpn=n;
    if (n==1)
    {
      printf("2\n");
      continue;
	}
    for (i=1;i<=p;i++)
    {
      lint s=1;
      while(n%c[i]==0)
      {
        s*=c[i];
        n/=c[i];
        flag=true;
	  }
	  if (s!=1)
	  {
	    ans+=s;
	    flag=true;
	  }
	}
	if (n>1)
	{
	  flag=true;
	  ans+=n;
    } 
	if (ans==tmpn)
	  printf("%lld\n",(lint)(tmpn+1));
	else
	  printf("%lld\n",ans);
  }
  return 0;
}
