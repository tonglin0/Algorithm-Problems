#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<vector>
#include<string>
#include<queue>
#define INF (int)1e9
#define MN 604
using namespace std;

vector<string> ss;
struct edge{int from,to,c,f;};
bool map[MN][MN];
vector<edge> es;
vector<int> g[MN];
int cur[MN],dis[MN];
bool vis[MN];
int T;

void addedge(int from,int to,int c)
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
  memset(vis,0,sizeof(vis));
  memset(dis,0,sizeof(dis));
  queue<int> q;
  vis[0]=true;
  q.push(0);
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

int dfs(int u,int a)
{
  if (u==T||a==0) return a;
  int flow=0,f;
  for (int i=cur[u];i<g[u].size();i++)
  {
    edge &e=es[g[u][i]];
    if (dis[e.to]==dis[u]+1&&(f=dfs(e.to,min(a,e.c-e.f)))>0)
    {
      flow+=f;
      a-=f;
      e.f+=f;
      es[g[u][i]^1].f-=f;
      if (a==0) return flow;
    }
  }
  return flow;
}

int find(int d,string s)
{
  for (int i=1;i<=d;i++)
    if (ss[i].compare(s)==0)
      return i;
  return 0;
}

int main()
{
  //freopen("1087.in","r",stdin);
  //freopen("1087.out","w",stdout);
  int n,i,j,k,m,M;
  scanf("%d",&n);
  ss.clear();
  es.clear();
  for (i=0;i<MN;i++) g[i].clear();
  ss.push_back("");
  //printf("ori size=%d\n",ss.size());
  T=400;
  for (i=1;i<=n;i++)
  {
    string s;
    cin>>s;
    ss.push_back(s);
    addedge(i,T,1);
  }
  //printf("ori size=%d\n",ss.size());
  scanf("%d",&m);
  M=m;
  for (i=1;i<=m;i++)
  {
    string s;
    char ch[MN];
    scanf("%s",ch);
    scanf("%s",ch);
    s=ch;
    bool flag=false;
    for (j=1;j<ss.size();j++)
      if (ss[j].compare(s)==0)
      {
        flag=true;
        addedge(0,j+n,1);
        break;
      }
    if (!flag)
    {
      ss.push_back(s);
      //printf("size=%d\n",ss.size());
      addedge(0,ss.size()+n-1,1);
    }
  }
  memset(map,0,sizeof(map));
  m=ss.size()-1;
  scanf("%d",&k);
  for (i=1;i<=k;i++)
  {
    string a,b;
    cin>>a>>b;
    m=ss.size()-1;
    int va=find(m,a);
    int vb=find(m,b);
    if (va&&vb)
      map[va][vb]=true;
    if (va&&!vb)
    {
      ss.push_back(b);
      map[va][ss.size()-1]=true;
    }
    if (vb&&!va)
    {
      ss.push_back(a);
      map[ss.size()-1][vb]=true;
    }
    if (!va&&!vb)
    {
      ss.push_back(a);
      ss.push_back(b);
      map[ss.size()-2][ss.size()-1]=true;
    }
  }
  int mm=ss.size()-1;
  for (i=1;i<=mm;i++)
    map[i][i]=true;
  for (k=1;k<=mm;k++)
    for (i=1;i<=mm;i++)
      for (j=1;j<=mm;j++)
        if (map[i][k]&&map[k][j])
          map[i][j]=true;
  /*for (i=1;i<=m;i++)
    for (j=1;j<=m;j++)
      if (map[i][j])
        printf("%d %d\n",i,j);*/
  for (i=1;i<=m;i++)
    for (j=1;j<=n;j++)
      if (map[i][j])
        addedge(i+n,j,INF);
  int ans=0;
  while(bfs())
  {
    memset(cur,0,sizeof(cur));
    ans+=dfs(0,INF);
  }
  //printf("%d\n",ans);
  printf("%d\n",M-ans);/*
  for (i=0;i<es.size();i++)
    if (es[i].f>0)
      printf("from=%d to=%d c=%d f=%d\n",es[i].from,es[i].to,es[i].c,es[i].f);*/
  //for (i=0;i<ss.size();i++)
    //cout<<ss[i]<<endl;
  return 0;        
}
