#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#define lint long long
using namespace std;

bool vis[100000];
lint c[100000];
lint t[2000009];
lint mi[100000];
lint top;

void dfs(lint k,lint s,lint sum)
{
  if (k==s+1)
  {
    t[++top]=sum;
    return ;
  }
  lint tmp=1;
  for (int i=0;i<=mi[k];i++)
  {
    dfs(k+1,s,sum*tmp);
    tmp*=c[k];
  }
}

lint gcd(lint a,lint b)
{
  lint t;
  while(b)
  {
    t=a;
    a=b;
    b=t%b;
  }
  return a;
}

int main()
{
  freopen("10892.in","r",stdin);
  freopen("10892.out","w",stdout);
  lint n,i,j,k,m;
  memset(vis,0,sizeof(vis));
  m=(lint)sqrt(2000000000+0.5);
  for (i=2;i<=(lint)sqrt(m+0.5);i++)
    if (!vis[i])
      for (j=i*i;j<=m;j+=i)
        vis[j]=true;
  lint p=0;
  for (i=2;i<=m;i++)
    if (!vis[i])
      c[++p]=i;
  while(scanf("%d",&n)==1)
  {
    if(n==0) break;
    memset(mi,0,sizeof(mi));
    lint tmp=n;
    k=0;
    for (i=1;i<=p;i++)
    {
      while(tmp%c[i]==0)
      {
        mi[i]++;
        tmp/=c[i];
        k=i;
	  }
	}
	if (tmp>1)
	  {
	    k=p+1;
	    c[k]=tmp;
	  }
	top=0;
	dfs(1,k,1);	
    lint ans=0;
    for(i=1;i<=top;i++)
      for (j=1;j<i;j++)
        if (t[i]/gcd(t[i],t[j])*t[j]==n)
          ans++;
    printf("%lld %lld\n",n,ans+1);
  } 
}
