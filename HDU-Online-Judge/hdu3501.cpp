#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#define MOD 1000000007
#define lint long long
using namespace std;

vector<lint> g;
bool vis[100000];
lint c[100000];

lint dfs(lint x,lint k)
{
  if (k==g.size())
  {
    lint ans=1,s=0;
    for (lint i=0;i<g.size();i++)
      if (vis[i])
      {
        ans*=g[i];
        s++;
	  }
	if (ans==1)
	  return 0;
	lint t=x/ans;
	if (s&1)
	  return (ans*t%MOD+t*(t-1)/2%MOD*ans%MOD)%MOD;//x/ans*ans%MOD;
	else
	  return -(ans*t%MOD+t*(t-1)/2%MOD*ans%MOD)%MOD;//-x/ans*ans%MOD;
  }
  lint ans=0;
  vis[k]=true;
  ans=dfs(x,k+1);
  vis[k]=false;
  ans=(ans+dfs(x,k+1))%MOD;
  return (ans%MOD+MOD)%MOD;
}

int main()
{
  freopen("3501.in","r",stdin);
  freopen("3501.out","w",stdout);
  lint n,i,j,k,p,m;
  p=0;
  m=(lint)sqrt(MOD);
  memset(vis,0,sizeof(vis));
  for (i=2;i<=m;i++)
    if (!vis[i])
    {
	  c[++p]=i;
	  for (j=i*i;j<=m;j+=i)
        vis[j]=true;
	}
  while(scanf("%I64d",&n)==1&&n)
  {
    lint ans=0;
    g.clear();
    lint tn=n;
	for (i=1;i<=p;i++)
      if (n%c[i]==0)
      {
	    g.push_back(c[i]);
	    while(n%c[i]==0)
	      n/=c[i];
	  }
    if (n>1)
      g.push_back(n);
    n=tn;
    ans=dfs(n-1,0);
    printf("%I64d\n",(ans%MOD+MOD)%MOD);
  }
  return 0;
}
