#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<string>
#define INF (int)1e9
using namespace std;

int cur[203],dis[203],ta[100],tb[100];
struct edge{int from,to,c,f;};
vector<edge> es;
vector<int> g[203];
bool vis[203];
char s1[103],s2[103];
int ans=0,l=0,r=0;

void addedge(int u,int v,int w)
{
  edge x;
  x.from=u;x.to=v;x.c=w;x.f=0;
  es.push_back(x);
  x.from=v;x.to=u;x.c=0;
  es.push_back(x);
  int m=es.size();
  g[u].push_back(m-2);
  g[v].push_back(m-1);
}

bool bfs()
{
  memset(vis,0,sizeof(vis));
  for (int i=1;i<=200;i++) dis[i]=INF;
  dis[0]=0;
  vis[0]=true;
  queue<int> q;
  q.push(0);
  while(!q.empty())
  {
    int u=q.front();q.pop();
    for (int i=0;i<g[u].size();i++)
    {
      edge e=es[g[u][i]];
      if (e.f<e.c&&!vis[e.to])
      {
        dis[e.to]=dis[u]+1;
        vis[e.to]=true;
        q.push(e.to);
      }
    }
  }
  return vis[200];
}

int find(int x,int a)
{
  int flow=0,f;
  if (x==200||a==0) return a;
  for (int i=cur[x];i<g[x].size();i++)
  {
    cur[x]=i;
    edge& e=es[g[x][i]];
    if (dis[e.to]==dis[x]+1&&(f=find(e.to,min(a,e.c-e.f)))>0)
    {
      e.f+=f;
      es[g[x][i]^1].f-=f;
      flow+=f;
      a-=f;
      if (a==0) return flow; 
    }
  }
  return flow;
}

int main()
{
  //freopen("poj2159.in","r",stdin);
  //freopen("poj2159.out","w",stdout);
  es.clear();
  for (int i=0;i<=200;i++)g[i].clear();
  memset(ta,0,sizeof(ta));
  memset(tb,0,sizeof(tb));
  int n,m,i,j,k;
  scanf("%s",s1);
  string s=s1;
  for (i=0;i<s.length();i++)
    ta[s[i]]++;
  n=0;
  for (i=1;i<=99;i++)
    if (ta[i])
    {
      if (!l)l=i;
      r=i;
      ++n;
      addedge(0,i,1);
    }
  scanf("%s",s1);
  s=s1;
  for (i=0;i<s.length();i++)
    tb[s[i]]++;
  for (i=65;i<=90;i++)
    if (tb[i])
    {
      for (j=l;j<=r;j++)
        if (ta[j]==tb[i])
          addedge(j,i+100,1);
      addedge(i+100,200,1);
    }
  while(bfs())
  {
    memset(cur,0,sizeof(cur));            
    ans+=find(0,INF);
  }
  bool flag=true;
  for (i=0;i<g[0].size();i++)
    if (es[g[0][i]].f<=0) 
    {
      flag=false;
      break;
    }
  if (flag) printf("YES\n");
    else printf("NO\n");
  return 0;
}
