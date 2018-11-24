#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>
#define eps 1e-9
#define MN 10009
using namespace std;

vector<int> g[MN];
int fa[MN],lf[MN],cnt[MN];
double a[MN],b[MN],c[MN],t[MN],ki[MN],ei[MN];
int n;
//double f[MN];

void dfs(int u,int pre)
{
  fa[u]=pre;
  if (u!=1)
    cnt[u]++;
  for (int i=0;i<g[u].size();i++)
  {
    int v=g[u][i];
    if (v!=pre)
    {
      cnt[u]++;
      lf[u]++;
      dfs(v,u);
	}
  }
}

double get_a(int i)
{
  if (a[i]>eps)
    return a[i];
  double s=0;
  for (int j=0;j<g[i].size();j++)
    if (g[i][j]!=fa[i])
      s+=a[g[i][j]];
  double ans=ki[i]+t[i]/cnt[i]*s;
  double s2=0;
  for (int j=0;j<g[i].size();j++)
    if (g[i][j]!=fa[i])
	  s2+=b[g[i][j]];
  double ans2=1-t[i]/cnt[i]*s2;
  return ans/ans2;
}

double get_b(int i)
{
  if (b[i]>eps)
    return b[i];
  double ans=t[i]/cnt[i];
  double s2=0;
  for (int j=0;j<g[i].size();j++)
    if (g[i][j]!=fa[i])
	  s2+=b[g[i][j]];
  double ans2=1-t[i]/cnt[i]*s2;
  return ans/ans2;
}

double get_c(int i)
{
  if (c[i]>eps)
    return c[i];
  double s=0;
  for (int j=0;j<g[i].size();j++)
    if (g[i][j]!=fa[i])
	  s+=c[g[i][j]];
  double ans=t[i]/cnt[i]*s+t[i];///cnt[i];
  double s2=0;
  for (int j=0;j<g[i].size();j++)
    if (g[i][j]!=fa[i])
	  s2+=b[g[i][j]];
  double ans2=1-t[i]/cnt[i]*s2;
  return ans/ans2;
}

void work()
{
  queue<int> q;
  int i,j,k;
  for (i=1;i<=n;i++)
    if (!lf[i])
    {
	  q.push(i);
	  a[i]=ki[i];
	  b[i]=c[i]=t[i];
	}
  while(!q.empty())
  {
    i=q.front();q.pop();
    if (i==1)
    {
      if (cnt[i]>0)
	  {
	    a[i]=get_a(i);
        c[i]=get_c(i);
      }
      if (fabs(1-a[i])<eps)
        printf("impossible\n");
      else
        printf("%.6lf\n",c[i]/(1-a[i]));
	  return ; 
	}
	if (cnt[i]>0)
	{
	  a[i]=get_a(i);
	  b[i]=get_b(i);
	  c[i]=get_c(i);
	}
	lf[fa[i]]--;
	if (!lf[fa[i]])
	  q.push(fa[i]);
  }
}

int main()
{
  freopen("4035.in","r",stdin);
  freopen("4035.out","w",stdout);
  int i,j,k,m,ca,u,v,ii;
  scanf("%d",&ca);
  for (ii=1;ii<=ca;ii++)
  {
    printf("Case %d: ",ii);
    scanf("%d",&n);
    memset(fa,0,sizeof(fa));
    memset(lf,0,sizeof(lf));
    memset(cnt,0,sizeof(cnt));
    for (i=0;i<MN;i++)
      g[i].clear();
    for (i=1;i<=n-1;i++)
    {
      scanf("%d%d",&u,&v);
      g[u].push_back(v);
      g[v].push_back(u);
	}
	dfs(1,0);
	for (i=1;i<=n;i++)
	{
	  scanf("%lf%lf",&ki[i],&ei[i]);
	  ki[i]/=100.0;
	  ei[i]/=100.0;
	  t[i]=1-ki[i]-ei[i];
	}
	//memset(f,0,sizeof(f));
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	work();
  }
  return 0;
}

