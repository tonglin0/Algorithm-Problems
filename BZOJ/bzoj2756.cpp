#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cctype>
#include<ctime>
#include<queue>
#include<string>
#include<vector>
#include<map>
#define eps 1e-8
#define lint long long
#define inf (lint)(1LL<<60)
#define llu unsigned long long
#define MN 1605
using namespace std;

lint a[44][42];
int S,T;
int n,m;
struct edge{
	int from,to;lint c,f;
};
vector<edge> es;
vector<int> g[MN]; 
int dis[MN],cur[MN];
bool vis[MN];

void addedge(int from,int to,lint c)
{
  edge x;
  x.from=from;x.to=to;x.c=c;x.f=0;
  es.push_back(x);
  x.from=to;x.to=from;x.c=0;
  es.push_back(x);
  int m=es.size();
  g[from].push_back(m-2);
  g[to].push_back(m-1);
}

bool bfs()
{
  queue<int> q;
  q.push(S);
  dis[S]=0;
  for (int i=0;i<=T;i++)
    vis[i]=false;
  vis[S]=true;
  while(!q.empty())
  {
    int u=q.front();q.pop();
    for (int i=0;i<g[u].size();i++)
    {
      edge e=es[g[u][i]];
      if (e.c>e.f&&!vis[e.to])
      {
        vis[e.to]=true;
        dis[e.to]=dis[u]+1;
        q.push(e.to);
	  }
	}
  }
  return vis[T];
}

lint dfs(int u,lint a)
{
  if (u==T||a==0)
    return a;
  lint flow=0,f;
  for (int i=cur[u];i<g[u].size();i++)
  {
    edge e=es[g[u][i]];
    cur[u]=i;
    if (dis[e.to]==dis[u]+1&&(f=dfs(e.to,min(e.c-e.f,a)))>0)
    {
      flow+=f;
      a-=f;
      es[g[u][i]].f+=f;
      es[g[u][i]^1].f-=f;
      if (a==0)
        return flow;
	}
  }
  return flow;
}

bool check(lint x)
{
  es.clear();
  for (int i=0;i<=T;i++)
    g[i].clear();
  lint askans=0;
  for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++)
      if ((i+j)&1)
        addedge(S,(i-1)*m+j,x-a[i][j]),askans+=x-a[i][j];
      else
        addedge((i-1)*m+j,T,x-a[i][j]);
  for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++)
      if (i+j&1)
      {
        if (i>1)
          addedge((i-1)*m+j,(i-2)*m+j,inf);
        if (j>1)
          addedge((i-1)*m+j,(i-1)*m+j-1,inf);
        if (i<n)
          addedge((i-1)*m+j,i*m+j,inf);
        if (j<m)
          addedge((i-1)*m+j,(i-1)*m+j+1,inf);
	  }
  lint ans=0;
  while(bfs())
  {
    memset(cur,0,sizeof(cur));
    ans+=dfs(S,inf);
  }
  if (ans==askans)
    return true;
  return false;
}

lint Max(lint a,lint b){return a>b?a:b;}

int main()
{
  freopen("2756.in","r",stdin);
  freopen("2756.out","w",stdout);
  int ca,i,j,k,ii=0;
  scanf("%d",&ca);
  while(ca--)
  {
  	lint cnt1=0,cnt2=0,s1=0,s2=0;
  	lint ms=-1;
    scanf("%d%d",&n,&m);
    S=0;T=n*m+1;
    for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
      {
	    scanf("%lld",&a[i][j]);
	    ms=Max(ms,a[i][j]);
		if (((i+j)&1)==1)
	      cnt1++,s1+=a[i][j];
	    else
	      cnt2++,s2+=a[i][j];
	  }
    if (cnt1!=cnt2)
    {
      if ((s1-s2)%(cnt1-cnt2))
      {
        printf("-1\n");
        continue;
	  }
	  else
	  {
	    lint x=(s1-s2)/(cnt1-cnt2);
	    if (x<ms)
	    {
	      printf("-1\n");
	      continue;
		}
	    if (check(x))
	      printf("%lld\n",cnt1*x-s1);
	    else
	      printf("-1\n");
	  }
	}
	else
	{
	  lint l=ms,r=inf>>10;
	  if (s1!=s2)
	  {
	    printf("-1\n");
	    continue;
	  }
	  while(l<r)
	  {
	    lint mid=(l+r)>>1;
	    if (check(mid))
	      r=mid;
	    else
	      l=mid+1;
	  }
	  if (l==inf>>10)
	  {
	    printf("-1\n");
	    continue;
	  }
	  printf("%lld\n",cnt1*l-s1);
	}
  }
  return 0;
}

