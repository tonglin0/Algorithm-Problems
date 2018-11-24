#include<cstdio>
#include<stack>
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
#define INF (int)1e9
#define lint long long
#define llu unsigned long long
#define MN 10009
using namespace std;

vector<int> g[MN];
int sccno[MN],pre[MN],low[MN];
int dfstime=0;
stack<int> st;
int scccnt=0;
int sz[MN];
vector<int> G[MN];
int outd[MN],popu[MN];

void dfs(int u)
{
  pre[u]=low[u]=++dfstime;
  st.push(u);
  for (int i=0;i<g[u].size();i++)
  {
    int v=g[u][i];
    if (!pre[v])
    {
      dfs(v);
      low[u]=min(low[u],low[v]);
	}
	else if (!sccno[v])
	  low[u]=min(low[u],pre[v]);
  }
  if (low[u]==pre[u])
  {
    scccnt++;
    int x=st.top();st.pop();
    while(x!=u)
    {
      sccno[x]=scccnt;
      sz[scccnt]++;
      x=st.top();
      st.pop();
	}
	sccno[x]=scccnt;
	sz[scccnt]++;
  }
}

void dfs2(int u)
{
  for (int i=0;i<G[u].size();i++)
  {
    popu[G[u][i]]=sz[G[u][i]]+popu[u];
    dfs2(G[u][i]);
  }
}

int main()
{
  freopen("1051.in","r",stdin);
  freopen("1051.out","w",stdout);
  int ca,n,i,j,k,m,ii=0;
  scanf("%d%d",&n,&m);
  for (i=1;i<=m;i++)
  {
    int u,v;
    scanf("%d%d",&u,&v);
    g[u].push_back(v);
  }
  for (i=0;i<=n;i++)
    pre[i]=sccno[i]=low[i]=0;
  for (i=1;i<=n;i++)
    if (!pre[i])
      dfs(i);
  if (scccnt==1)
  {
    printf("%d\n",n);
    return 0;
  }
  for (i=1;i<=n;i++)
    for (j=0;j<g[i].size();j++)
      if (sccno[i]!=sccno[g[i][j]])
      {
	    G[sccno[i]].push_back(sccno[g[i][j]]);
	    outd[sccno[i]]++;
	  }
  int cnt=0,ans;
  for (i=1;i<=scccnt;i++)
    if (outd[i]==0)
    {
      cnt++;
      ans=i;
	}
  if (cnt>1)
    printf("0\n");
  else
    printf("%d\n",sz[ans]);
  return 0;
}

