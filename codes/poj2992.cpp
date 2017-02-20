#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define lint int
using namespace std;

lint c[1000];
bool vis[1000];
lint s[1000];
lint p;

void work(lint n,lint d)
{
  for (lint i=1;i<=p;i++)
  {
    lint tn=n;
    lint k=c[i];
    while(tn>=k)
    {
      s[i]+=d*tn/k;
      k*=c[i];
	}
  }
}

int main()
{
  freopen("2992.in","r",stdin);
  freopen("2992.out","w",stdout);
  lint n,i,j,k,m;
  memset(vis,0,sizeof(vis));
  p=0;
  for (i=2;i<=431;i++)
    if (!vis[i])
    {
      c[++p]=i;
      for (j=i*i;j<=431;j+=i)
	    vis[j]=true;   
	}
  while(scanf("%d%d",&n,&m)==2)
  {
    memset(s,0,sizeof(s));
    work(n,1);
    work(m,-1);
    work(n-m,-1);
    long long ans=1;
    for (i=1;i<=p;i++)
      ans*=(long long)(s[i]+1);
    printf("%I64d\n",ans);
  }
  return 0;
}
