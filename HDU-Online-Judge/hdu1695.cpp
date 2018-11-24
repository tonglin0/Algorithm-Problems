#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#define lint long long
#define MN 100009
using namespace std;

lint phi[MN];
vector<lint> g[MN];
bool vis[MN];
lint a;

void eular()
{
  memset(phi,0,sizeof(phi));
  phi[1]=1;
  for (int i=2;i<=100000;i++)
    if (!phi[i])
      for (int j=i;j<=100000;j+=i)
      {
        if (!phi[j])
          phi[j]=j;
        phi[j]=phi[j]/i*(i-1);
	  }
}

lint dfs(lint x,lint k)
{
  if (k==g[x].size())
  {
    lint ans=1,s=0;
    for (int i=0;i<g[x].size();i++)
      if (vis[i])
      {
        s++;
        ans*=g[x][i];
	  }
	if (ans==1)
	  return 0;
	if (s&1)
	  return a/ans;
	else
	  return -a/ans;
  }
  lint ans=0;
  vis[k]=true;
  ans=dfs(x,k+1);
  vis[k]=false;
  ans+=dfs(x,k+1);
  return ans;
}

void init()
{
  for (lint i=2;i<=100000;i++)
    if (g[i].size()==0)
    {
      g[i].push_back(i);
      for (lint j=i+i;j<=100000;j+=i)
        g[j].push_back(i);
	}
}

int main()
{
  freopen("1695.in","r",stdin);
  freopen("1695.out","w",stdout);
  lint ii=0,ta,tb,n,ca,i,j,k,m,b;
  eular();
  init();
  scanf("%I64d",&ca);
  for (ii=1;ii<=ca;ii++)
  {
    scanf("%I64d%I64d%I64d%I64d%I64d",&ta,&a,&tb,&b,&k);
    if (k==0)
    {
      printf("Case %I64d: 0\n",ii);
      continue;
	}
	a/=k;b/=k;
    if (a>b) 
      swap(a,b);
    lint ans=0;
    for (i=1;i<=a;i++)
      ans+=phi[i];
    for (i=a+1;i<=b;i++)
      ans+=(a-dfs(i,0));
    printf("Case %I64d: %I64d\n",ii,ans);
  }
}
